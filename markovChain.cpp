#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

/*
 This function takes an integer as an input 
 then generates a random number and returns it
 -- should generate a number between 0 and 'limit'
*/
int randomNumber(int limit)
{
   srand(time(0));
   int rnd = rand() % limit;
   return rnd;
}

bool explode(string key, string data)
{
  string arr="";
  stringstream ssin(data);
  if(ssin.good())
  {
    ssin >> arr;
  }
  else
  {
    return false;
  }

  if(arr==key)
    return true;
  else
    return false;
}

/*
This function is for retriving an element from map based on an index value
*/
string* getMapPairByIndex(int index, map< string, vector< string > > map)
{
  int counter = 0;
  int rnd = 0;
  string* mapPair = new string[2];
  for(auto itr = map.begin(); itr!=map.end(); itr++) {
     if(counter == index)
     {
        std::cout<<"\n Key: "<<itr->first<<" ";
        mapPair[0] = itr-> first;

        if(itr->second.size()==1)
        {
          cout << "\n value:0 "<<itr->second.at(0) << "\n";
          mapPair[1] = itr->second.at(0);
        }
        else
        {
          rnd = randomNumber(itr->second.size());
          cout << "\n value:"<<rnd<<" :"<<itr->second.at(rnd) << "\n";
          mapPair[1] = itr->second.at(rnd);
        }
        std::cout<<std::endl;
        break; // break the loop!
     } // End of IF
     counter++;
   } // End of FOR
   return mapPair;
} // End of FUNCTION

string* getNPairValueByKey(int chain_length, string key, map< string, vector< string > > map)
{
  int counter = 0;
  int rnd = 0;
  string* mapPair = new string[2];
  std::map< string, vector< string > > smap;

  for(auto itr = map.begin(); itr!=map.end(); itr++) {
     if(explode(key, itr-> first))
     {
        for(auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++){
          smap[itr-> first].push_back(*vitr);
        }
     } // End of IF
   } // End of FOR

   if(smap.size()==1)
   {
    mapPair = getMapPairByIndex(0, smap);
   }
   else if(smap.size()>0)
   {
    rnd = randomNumber(smap.size());
    mapPair = getMapPairByIndex(rnd, smap);
   }
   else
   {
    cout << "Unexpected error in getNPairValueeByKey" << endl;
   }
   
   return mapPair;
} // End of FUNCTION

string getRandomPairValueByKey(string keyv, map< string, vector< string > > map)
{
   string value = "";
   int rnd = map.find(keyv)->second.size();
   if(rnd==1)
   {
      value = map.find(keyv)->second.at(0); 
   }
   else if(rnd>1)
   {
      rnd = randomNumber(rnd);
      value = map.find(keyv)->second.at(0);
   }
   else
   {
    cout<<"Unexpected Error in getRandomPairValueByKey!"<<endl;
   }

   return value;
}

string replace(string text, string sub_string, string replace_string) {
  int index = 0;

  while (true) {
    /* locate substring to replace */
    index = text.find(sub_string, index);
    if (index == string::npos)
      return text;

    /* make replacement */
    text.replace(index, sub_string.length(), replace_string);

    index += sub_string.length();
  }
}

int main (int argc, char ** argv)
{
   std::cout << "*******************************************************" << std::endl;
   std::cout << "* Secure System: Project 1: Markovian-tweets ver 0.1  *" << std::endl;
   std::cout << "*********************** Authors ***********************" << std::endl;
   std::cout << "* Kaoru (Teddy) Katayama                              *" << std::endl;
   std::cout << "* Alparslan Sari                                      *" << std::endl;
   std::cout << "*******************************************************" << std::endl;
   // Check the number of parameters
   if (argc < 4) {
      // Tell the user how to run the program
      std::cerr << "Usage: " << argv[0] << " FILE_NAME" << " CHAIN_LENGTH" << " SENTENCE_LENGTH" << std::endl;
      /* "Usage messages" are a conventional way of telling the user
       * how to run a program if they enter the command incorrectly.
       */
      return 1;
   }
   
   // Inform user about file opening
   std::cout << argv[0] << " Attempting to open " << argv[1] << "!" << std::endl;

   // open a file in read mode.
   ifstream fileReader;
   fileReader.open(argv[1]); 

   // Check if the file is opened!
   if (!fileReader) {
      cout << "Could not open file" << endl;
       return 1;
    }

   // File open is a success! 
   cout << "Reading from the file:" << endl; 
   string word; // We will use the word as a temp variable.
   vector<string> words;
   int chain_length = stoi(argv[2]);
   int sentenceSize = stoi(argv[3]);
   while( fileReader >> word ) {

     // remove punctuation
     word = replace(word, ".", "");
     word = replace(word, ",", "");
     word = replace(word, ";", "");
     word = replace(word, ":", "");
     word = replace(word, "?", "");
     word = replace(word, "'", "");
     word = replace(word, "!", "");
     word = replace(word, "(", "");
     word = replace(word, ")", "");

     // add word to vector of strings
     words.push_back(word);

   }

   // add ENDING for words
   //   words.push_back("THE_END");
 
   // close the opened file.
   fileReader.close();

   // print vector of words
   cout << "| ";
   for (int i = 0; i <  words.size(); i++) {
     cout << words[i] << " | ";
   }
   cout << "\n";

   // generate Markov chain table of fixed length
   map< string, vector< string > > map;

   for (int i = 0; i < words.size(); i++) {
     if (i < (words.size() - chain_length)) {
       if (chain_length == 1) 
         map[words[i]].push_back(words[i+chain_length]);
       if (chain_length == 2)
         map[words[i]+' '+words[i+1]].push_back(words[i+chain_length]);
     }
   }
     
   // print Markov chain table
   for(auto itr = map.begin(); itr!=map.end(); itr++) {
     std::cout<<itr->first<<":";
     for(auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++){
       std::cout<<*vitr<<",";
     }
     std::cout<<std::endl;
   }

   // print first key of Markov chain table
   cout << "--------\n";
   if (chain_length == 1) {     
     auto itr = map.find(words[0]);
     cout << itr->first << ":";
     for (auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++) {
       //     cout << vitr->size();
       cout << *vitr << ",";
     }
   }
   if (chain_length == 2) {     
     auto itr = map.find(words[0]+' '+words[1]);
     cout << itr->first << ":";
     for (auto vitr = itr->second.begin(); vitr != itr->second.end(); vitr++) {
       //     cout << vitr->size();
       cout << *vitr << ",";
     }
   }
   cout << "\n--------\n";
   
   // Generate markovian sentences
   cout << "Generating markovian sentece..." << "\n";
   cout << "Vector size=" << map.size() << "\n";
   // generate random number
   int rnd = randomNumber(map.size());
   cout << "randomNumber="<< rnd << "\n";
   // Grab the first word from map
   
   int sentenceCounter = 0;
   string finalSentence = "";
   string nextWord = ""; 
   string* mapPair = new string[2];
   mapPair = getMapPairByIndex(rnd, map);


  // Based on Chain Length
  if(chain_length==1)
  {
    finalSentence = mapPair[0] + " " + mapPair[1];
    nextWord = mapPair[1];
    sentenceCounter=sentenceCounter+2;
    while(sentenceSize>sentenceCounter)
    {
      nextWord = getRandomPairValueByKey(nextWord, map);
      finalSentence = finalSentence + " " + nextWord;
      sentenceCounter++;
    }
  }
  else if (chain_length>1)
  {
    finalSentence = mapPair[0];
    nextWord = mapPair[1];
    sentenceCounter=sentenceCounter+chain_length+1;
    while(sentenceSize>sentenceCounter)
    {
      mapPair = getNPairValueByKey(chain_length,mapPair[1],map);
      finalSentence = finalSentence + " " + mapPair[0];
      sentenceCounter=sentenceCounter+chain_length;
    }

  }
  else
  {
    cout << "Unexpected chain length:"<<chain_length <<"! Exiting...\n";
    return -1;
  }

 cout << "\nSentence:"<< finalSentence<<"\n";


   return 0;
}
