/*
  todo:
  1. texts touch pins
  2. input error detection
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
namespace read_spec
{
  namespace spec
  {
    class layer
    {
    public:
      string layer_name;
      int number_of_layers, number_of_polygons, number_of_rectngles, number_of_texts;
      vector<string> polygons, rectangles, pins;
      layer(string layer_name)
      {
        layer_name = layer_name;
      }
      class text
      {
      public:
        string name;
        int p1, p2;
        text(string s, int x, int y)
        {
          name = s;
          p1 = x;
          p2 = y;
        };
      };
      vector<text> texts;
    };
    vector<layer> vec_layers; // vec_layers[No.metal-1]
  }
  namespace func
  {
    void readSpecFile(vector<read_spec::spec::layer> &vec_layers)
    {
      string spec_text;
      ifstream spec_file("./spec.txt");
      getline(spec_file, spec_text);

      int number_of_layers = stoi(spec_text.substr(16));

      for (int i = 0; i < number_of_layers; i++)
      {
        getline(spec_file, spec_text); // layer 1   M1
        read_spec::spec::layer m(spec_text.substr(8));
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
        int m;
        string hx, lx, ly;
        string hy, text_name;
        spec_file >> m >> hx >> hy >> lx >> ly; // 1    0  0,  0 10,  10 10,  10 0,  0  0
        // 1  0 20, 0 24, 3 24, 3 20, 0 20
        // 1  hx0  hy20,  lx3  ly24
       vec_layers[m - 1].rectangles.push_back(hx + " " + hy + hx + " " + ly + ", " + lx + " " + ly + ", " + lx + " " + hy + hx + " " + hy);
      }
      getline(spec_file, spec_text); // end_of_rectangles
      getline(spec_file, spec_text); // \n
      getline(spec_file, spec_text); // number_of_texts

      int number_of_texts = stoi(spec_text.substr(15));

      for (int i = 0; i < number_of_texts; i++)
      {
        int m, p1, p2;
        string text_name;
        spec_file >> m; // 1    0  0,  0 10,  10 10,  10 0,  0  0
        spec_file >> text_name;
        spec_file >> p1;
        spec_file >> p2;
        vec_layers[m - 1].texts.push_back(read_spec::spec::layer::text(text_name, p1, p2));
      }
      spec_file.close();
    }
  }
}
