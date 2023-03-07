// https://www.w3schools.com/cpp/cpp_files.asp
/*
  undo:
  store m layer info
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class layer
{
public:
  string layer_name;
  int number_of_layers, number_of_polygons, number_of_rectngles, number_of_texts;
  vector<string> polygons, rectangles, texts;
  layer(string layer_name, int number_of_layers, int number_of_rectngles, int number_of_texts)
  {
    layer_name = layer_name;
    number_of_layers = number_of_layers;
    number_of_rectngles = number_of_rectngles;
    number_of_texts = number_of_texts;
  }
};
void readSpecFile(vector<layer> &);

int main()
{
  // int number_of_layers;
  // string arr_layers[];
  // int number_of_polygons;
  // string arr_polygons[];
  // int number_of_rectangles;
  // string arr_rectangles[];
  // int number_of_texts;
  // string arr_texts[];

  vector<layer> vec_layers;

  readSpecFile(vec_layers);
}

void readSpecFile(vector<layer> &vec_layers)
{
  string spec_text;
  ifstream spec_file("../../spec.txt");
  getline(spec_file, spec_text);

  int number_of_layers = stoi(spec_text.substr(16));
  string arr_layers[number_of_layers];

  for (int i = 0; i < number_of_layers; i++)
  {
    getline(spec_file, spec_text); // layer 1   M1
    arr_layers[i] = spec_text.substr(8);
  }
  getline(spec_file, spec_text); // end_of_layer
  getline(spec_file, spec_text); // number_of_polygons

  int number_of_polygons = stoi(spec_text.substr(18));
  string arr_polygons[number_of_polygons];

  for (int i = 0; i < number_of_polygons; i++)
  {
    getline(spec_file, spec_text); // 1    0  0,  0 10,  10 10,  10 0,  0  0
    arr_polygons[i] = spec_text.substr((to_string(number_of_polygons)).length());
  }
  getline(spec_file, spec_text); // end_of_polygon
  getline(spec_file, spec_text); // number_of_rectangles

  int number_of_rectangles = stoi(spec_text.substr(20));
  string arr_rectangles[number_of_rectangles];

  for (int i = 0; i < number_of_rectangles; i++)
  {
    getline(spec_file, spec_text); // 1    0  0,  0 10,  10 10,  10 0,  0  0
    arr_rectangles[i] = spec_text.substr((to_string(number_of_rectangles)).length());
  }
  getline(spec_file, spec_text); // end_of_rectangles
  getline(spec_file, spec_text); // number_of_texts

  int number_of_texts = stoi(spec_text.substr(15));
  string arr_texts[number_of_texts];

  for (int i = 0; i < number_of_texts; i++)
  {
    getline(spec_file, spec_text); // 1    0  0,  0 10,  10 10,  10 0,  0  0
    arr_texts[i] = spec_text.substr((to_string(number_of_texts)).length());
  }
  // getline(spec_file, spec_text); // end_of_texts

  spec_file.close();
  cout << number_of_layers << arr_layers[0] << number_of_rectangles << arr_polygons[3] << endl;
}