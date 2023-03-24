/*
  todo:
  1. texts touch pins
  2. input error detection
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/io/wkt/wkt.hpp>
using namespace std;

typedef boost::geometry::model::d2::point_xy<double> point;
typedef boost::geometry::model::polygon<point> polygon;

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
        string str_rect;
        double hx, hy, lx, ly, x, y, w, l;
        boost::geometry::model::polygon<point> poly_rect;

        rect(string x1, string y1, string x2, string y2)
        {
          str_rect = (x2 + " " + y2 + ", ") + (x2 + " " + y1 + " ") + (x1 + " " + y1 + " ") + (x1 + " " + y2 + ", ") + (x2 + " " + y2);
          boost::geometry::read_wkt("POLYGON((" + str_rect + "))", poly_rect);
          hx = stod(x1);
          hy = stod(y1);
          lx = stod(x2);
          ly = stod(y2);
          x = abs(hx - lx);
          y = abs(hy - ly);
          if (x > y)
          {
            l = x;
            w = y;
          }
          else
          {
            w = x;
            l = y;
          }
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
        string hx, hy, lx, ly;
        spec_file >> m >> hx >> hy >> lx >> ly; // 1    0  0,  0 10,  10 10,  10 0,  0  0
        read_spec::spec::layer::rect input_rect(hx, hy, lx, ly);
        vec_layers[m - 1].vec_rects.push_back(input_rect);
      }
      getline(spec_file, spec_text); // end_of_rectangles
      spec_file.close();
    }
  }
}
