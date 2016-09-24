#include <fstream>
#include <iostream>
#include <sstream>

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

int main (int argc, char *argv[]) {
  if (argc !=2) {
    cout << "usage: " << argv[0] << " <filename>\n";
  } else {
    ifstream the_file(argv[1]);

    if (!the_file.is_open()) {
      cout << "Could not open file\n";
    } else {
      string sentences;
      stringstream buffer;
      /* Read the file containing sentences */
      buffer << the_file.rdbuf();
      sentences = buffer.str();

      /* Print out the contents of the file */
      cout << sentences;
      cout << "\n\n\n\n\n\n\n";

      /* Remove newline and punctuation characters */
      sentences = replace(sentences, "\n", " ");
      sentences = replace(sentences, "'", "");
      sentences = replace(sentences, ",", "");
      sentences = replace(sentences, "?", "");
      
      
      cout << sentences;

      
      /* Save string to file */
      ofstream out("output.txt");
      out << sentences;
      out.close();
    }
  }

  return 0;
}
