//#include <stdio>
#include <fstream>
#include <iostream>
//#include <string>
#include <map>
#include <vector>

using namespace std;

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
   if (argc < 3) {
      // Tell the user how to run the program
      std::cerr << "Usage: " << argv[0] << " FILE_NAME" << " CHAIN_LENGTH" << std::endl;
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
   
   while( fileReader >> word ) {

     // remove punctuation
     word = replace(word, ".", "");
     word = replace(word, ",", "");
     word = replace(word, ";", "");
     word = replace(word, ":", "");
     word = replace(word, "?", "");
     word = replace(word, "'", "");
     word = replace(word, "!", "");

     // add word to vector of strings
     words.push_back(word);

   }

   // add ENDING for words
   words.push_back("THE_END");
 
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
   
   // TODO: Generate markovian sentences

   
   return 0;
}
