// https://www.w3schools.com/cpp/cpp_files.asp

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string myText;
  // Read from the text file
  ifstream MyReadFile("spec.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline(MyReadFile, myText))
  {
    // Output the text from the file
    cout << myText << endl;
  }

  // Close the file
  MyReadFile.close();
}