//#include <stdio>
#include <fstream>
#include <iostream>
using namespace std;
 
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
   while( fileReader >> word ) {
      // write the data to screen for now. We will use this info to build the vector of words
      cout << word << endl;
      // TODO: punctuation removal
      // TODO: Assign word to our vector

    }
 
   // close the opened file.
   fileReader.close();

   // TODO: Generate markovian sentences

   return 0;
}
