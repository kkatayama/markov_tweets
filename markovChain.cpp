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
   if (argc < 2) {
      // Tell the user how to run the program
      std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
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
 
   // close the opened file.
   fileReader.close();

   // print vector of words
   for (int i = 0; i <  words.size(); i++) {
     cout << words[i] << ", ";
   }

   // TODO: Generate markovian sentences

   return 0;
}
