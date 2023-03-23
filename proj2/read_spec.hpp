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
      // int number_of_layers, number_of_polygons, number_of_rectngles, number_of_texts;
      layer(string layer_name)
      {
        layer_name = layer_name;
      }
      class rect
      {
      public:
        string str_poly;
        int p1, p2;
        rect(string s, int x, int y)
        {
          str_poly = s;
          p1 = x;
          p2 = y;
        };
      };
      vector<rect> vec_rects;
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
      getline(spec_file, spec_text); // number_of_rectangles

      int number_of_rectangles = stoi(spec_text.substr(20));

      for (int i = 0; i < number_of_rectangles; i++)
      {
        int m = 0;
        string hx, lx, ly;
        string hy, text_name;
        spec_file >> m >> hx >> hy >> lx >> ly; // 1    0  0,  0 10,  10 10,  10 0,  0  0
        // 1  0 20, 0 24, 3 24, 3 20, 0 20
        // 1  hx0  hy20,  lx3  ly24
        // vec_layers[m - 1].vec_rects.push_back(hx + " " + hy + hx + " " + ly + ", " + lx + " " + ly + ", " + lx + " " + hy + hx + " " + hy);
        string str_rect = hx + " " + hy + hx + " " + ly + ", " + lx + " " + ly + ", " + lx + " " + hy + hx + " " + hy;
        read_spec::spec::layer::rect in_rect(str_rect);
      }
      getline(spec_file, spec_text); // end_of_rectangles
      spec_file.close();
    }
  }
}
