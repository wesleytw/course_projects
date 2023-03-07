// https://www.w3schools.com/cpp/cpp_files.asp
/*
  todo:
  1. input error detection
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class layer;
void readSpecFile(vector<layer> &);

class layer
{
public:
  string layer_name;
  int number_of_layers, number_of_polygons, number_of_rectngles, number_of_texts;
  vector<string> polygons, rectangles, texts;
  layer(string layer_name)
  {
    layer_name = layer_name;
  }
};
void readSpecFile(vector<layer> &);

int main()
{
  vector<layer> vec_layers; // vec_layers[No.metal-1]

  readSpecFile(vec_layers);
  cout 
  << vec_layers[0].polygons[2]<<endl
  << vec_layers[0].texts[2]<<endl
    << vec_layers[0].rectangles[2]
  <<vec_layers[0].layer_name;
}

void readSpecFile(vector<layer> &vec_layers)
{
  string spec_text;
  ifstream spec_file("../../spec.txt");
  getline(spec_file, spec_text);

  int number_of_layers = stoi(spec_text.substr(16));

  for (int i = 0; i < number_of_layers; i++)
  {
    getline(spec_file, spec_text); // layer 1   M1
    layer m(spec_text.substr(8));
    vec_layers.push_back(m);
  }
  getline(spec_file, spec_text); // end_of_layer
  getline(spec_file, spec_text); // number_of_polygons

  int number_of_polygons = stoi(spec_text.substr(18));

  for (int i = 0; i < number_of_polygons; i++)
  {
    getline(spec_file, spec_text);                          // 1    0  0,  0 10,  10 10,  10 0,  0  0
    int m = stoi(spec_text.substr(0, spec_text.find(' '))); // https://stackoverflow.com/questions/18624345/split-string-at-space-and-return-first-element-in-c
    vec_layers[m - 1].polygons.push_back(spec_text.substr((to_string(m)).length()));
  }
  getline(spec_file, spec_text); // end_of_polygon
  getline(spec_file, spec_text); // number_of_rectangles

  int number_of_rectangles = stoi(spec_text.substr(20));

  for (int i = 0; i < number_of_rectangles; i++)
  {
    getline(spec_file, spec_text);                          // 1    0  0,  0 10,  10 10,  10 0,  0  0
    int m = stoi(spec_text.substr(0, spec_text.find(' '))); // https://stackoverflow.com/questions/18624345/split-string-at-space-and-return-first-element-in-c
    vec_layers[m - 1].rectangles.push_back(spec_text.substr((to_string(m)).length()));
  }
  getline(spec_file, spec_text); // end_of_rectangles
  getline(spec_file, spec_text); // number_of_texts

  int number_of_texts = stoi(spec_text.substr(15));

  for (int i = 0; i < number_of_texts; i++)
  {
    getline(spec_file, spec_text);                          // 1    0  0,  0 10,  10 10,  10 0,  0  0
    int m = stoi(spec_text.substr(0, spec_text.find(' '))); // https://stackoverflow.com/questions/18624345/split-string-at-space-and-return-first-element-in-c
    vec_layers[m - 1].texts.push_back(spec_text.substr((to_string(m)).length()));
  }
  spec_file.close();
  // cout << number_of_layers << number_of_rectangles << endl;
}