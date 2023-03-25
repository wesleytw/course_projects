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
    // vector<string> vec_warnings;
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
        string str_rect, color_fill, color_stroke, color_end1 = "rgb(0,90,0);fill-opacity:0;", color_end2 = "rgb(0,90,0);fill-opacity:0;";
        double hx, hy, lx, ly, x, y, w, l;
        boost::geometry::model::polygon<point> poly_rect, poly_end1, poly_end2;

        rect(string x1, string y1, string x2, string y2)
        {
          str_rect = (x2 + " " + y2 + ", ") + (x2 + " " + y1 + " ") + (x1 + " " + y1 + " ") + (x1 + " " + y2 + ", ") + (x2 + " " + y2);
          // cout << str_rect;
          boost::geometry::read_wkt("POLYGON((" + str_rect + "))", poly_rect);
          lx = stod(x1);
          ly = stod(y1);
          hx = stod(x2);
          hy = stod(y2);
          x = abs(hx - lx);
          y = abs(hy - ly);
          if (x > y)
          {
            l = x;
            w = y;
            // po
            // point p = point(3, 3);
            //
            //   multi_polys = multi_polys + "((" + arr[i] + ")),";
            // multi_polys = "MULTIPOLYGON(" + multi_polys + ")";
            string end_left = (to_string(lx - 1) + " " + to_string(ly - 0.4)) + "," + (to_string(lx - 1) + " " + to_string(hy + 0.4)) + "," + (to_string(lx + 0.7) + " " + to_string(hy + 0.4)) + "," + (to_string(lx + 0.7) + " " + to_string(ly - 0.4)) + "," + (to_string(lx - 1) + " " + to_string(ly - 0.4));
            string end_right = (to_string(hx - 0.7) + " " + to_string(ly - 0.4)) + "," + (to_string(hx - 0.7) + " " + to_string(hy + 0.4)) + "," + (to_string(hx + 1) + " " + to_string(hy + 0.4)) + "," + (to_string(hx + 1) + " " + to_string(ly - 0.4)) + "," + (to_string(hx - 0.7) + " " + to_string(ly - 0.4));
            boost::geometry::read_wkt("POLYGON((" + end_left + "))", poly_end1);
            boost::geometry::read_wkt("POLYGON((" + end_right + "))", poly_end2);
          }
          else
          {
            w = x;
            l = y;
            string end_top = (to_string(lx - 0.4) + " " + to_string(hy - 0.7)) + "," + (to_string(lx - 0.4) + " " + to_string(hy + 1)) + "," + (to_string(hx + 0.4) + " " + to_string(hy + 1)) + "," + (to_string(hx + 0.4) + " " + to_string(hy - 0.7)) + "," + (to_string(lx - 0.4) + " " + to_string(hy - 0.7));
            string end_bottom = (to_string(lx - 0.4) + " " + to_string(ly - 1)) + "," + (to_string(lx - 0.4) + " " + to_string(ly + 0.7)) + "," + (to_string(hx + 0.4) + " " + to_string(ly + 0.7)) + "," + (to_string(hx + 0.4) + " " + to_string(ly - 1)) + "," + (to_string(lx - 0.4) + " " + to_string(ly - 1));
            boost::geometry::read_wkt("POLYGON((" + end_top + "))", poly_end1);
            boost::geometry::read_wkt("POLYGON((" + end_bottom + "))", poly_end2);
          }
          color_fill = "rgb(10,220,0)";
          color_stroke = "rgb(50,110,0)";
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
        spec_file >> m >> lx >> ly >> hx >> hy; // 1    0  0,  0 10,  10 10,  10 0,  0  0
        read_spec::spec::layer::rect input_rect(lx, ly, hx, hy);
        vec_layers[m - 1].vec_rects.push_back(input_rect);
      }
      getline(spec_file, spec_text); // end_of_rectangles
      spec_file.close();
    }
  }
}
