#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
namespace std
{
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
}