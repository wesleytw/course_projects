// use boost union to combine polygons and use envelop to find outter shape
#include "read_spec.hpp"
#include <iostream>
#include <fstream> // svg
#include <vector>
#include <deque>
#include <algorithm>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_polygon.hpp>
#include <boost/foreach.hpp>
using namespace std;
namespace bg = boost::geometry;

typedef boost::geometry::model::d2::point_xy<double> point;
typedef boost::geometry::model::polygon<point> polygon;
typedef read_spec::spec::layer layer;
using read_spec::func::readSpecFile;
using read_spec::spec::vec_layers;

void checkOverlap();
void checkEOL();
typedef boost::polygon::rectangle_data<int> rect;

class waring
{
public:
  string str_warning;
  point points;
  waring(string w, point p)
  {
    str_warning = w;
    points = p;
  }
};
vector<waring> vec_warnings;

int main()
{
  readSpecFile(vec_layers);
  ofstream output_svg("output.svg");
  boost::geometry::svg_mapper<point> output_mapper(output_svg, 200, 200);
  checkOverlap();
  checkEOL();
  for (int i = 0; i < vec_layers[0].vec_rects.size(); i++)
  {
    output_mapper.add(vec_layers[0].vec_rects[i].poly_rect);
    output_mapper.add(vec_layers[0].vec_rects[i].poly_end1);
    output_mapper.add(vec_layers[0].vec_rects[i].poly_end2);
  }
  for (int i = 0; i < vec_layers[0].vec_rects.size(); i++)
  {
    string color = "fill-opacity:0.9;fill:" + vec_layers[0].vec_rects[i].color_fill;
    output_mapper.map(vec_layers[0].vec_rects[i].poly_end1, "fill:" + vec_layers[0].vec_rects[i].color_end1);
    output_mapper.map(vec_layers[0].vec_rects[i].poly_end2, "fill:" + vec_layers[0].vec_rects[i].color_end2);
    output_mapper.map(vec_layers[0].vec_rects[i].poly_rect, color);
  }
  for (int i = 0; i < vec_warnings.size(); i++)
  {
    output_mapper.text(vec_warnings[i].points, vec_warnings[i].str_warning, "fill-opacity:0.9;fill:rgb(220,220,220);font-size:4px;", 10, -2, 0);
  }
  return 0;
}

void checkOverlap()
{
  int vec_size = vec_layers[0].vec_rects.size();
  for (int i = 0; i < vec_size; i++)
  {
    layer::rect &rect_now = vec_layers[0].vec_rects[i];
    for (int j = i + 1; j < vec_size; j++)
    {
      layer::rect &rect_next = vec_layers[0].vec_rects[j];
      std::deque<polygon> intersections;
      boost::geometry::intersection(rect_now.poly_rect, rect_next.poly_rect, intersections);
      if (intersections.size() != 0)
      {
        rect_now.members.push_back(j);
        rect_next.members.push_back(i);
      }
    }
  }
}

void checkEOL()
{
  int vec_size = vec_layers[0].vec_rects.size();
  for (int i = 0; i < vec_size; i++)
  {
    layer::rect &rect_now = vec_layers[0].vec_rects[i];
    if (rect_now.w <= 0.600001)
    {
      for (int j = i + 1; j < vec_size; j++)
      {
        if (binary_search(rect_now.members.begin(), rect_now.members.end(), j))
        {
          continue;
        }
        layer::rect &rect_next = vec_layers[0].vec_rects[j];
        std::deque<polygon> intersections1, intersections2;
        boost::geometry::intersection(rect_now.poly_end1, rect_next.poly_rect, intersections1);
        if (intersections1.size() != 0)
        {
          rect_now.color_fill = "rgb(220,0,0)";
          rect_now.color_end1 = "rgb(220,20,0);fill-opacity:0.4;stroke:rgb(220,60,60);stroke-width:0.5";
          waring w("EOL violation!", point(rect_now.lx, rect_now.ly));
          vec_warnings.push_back(w);
          int mem = rect_now.members.size();
          for (int k = 0; k < mem; k++)
          {
            vec_layers[0].vec_rects[rect_now.members[k]].color_fill = "rgb(220,0,0)";
          }
        }
        boost::geometry::intersection(rect_now.poly_end2, rect_next.poly_rect, intersections2);
        if (intersections2.size() != 0)
        {
          rect_now.color_fill = "rgb(220,0,0)";
          rect_now.color_end2 = "rgb(220,20,0);fill-opacity:0.4;stroke:rgb(220,60,60);stroke-width:0.5";
          waring w("EOL violation!", point(rect_now.lx, rect_now.ly));
          vec_warnings.push_back(w);
          int mem = rect_now.members.size();
          for (int k = 0; k < mem; k++)
          {
            vec_layers[0].vec_rects[rect_now.members[k]].color_fill = "rgb(220,0,0)";
          }
        }
      }
    }
  }
}

/*
cd "/Users/wesley/Documents/清大/四下/eda/course_projects/proj2/" && g++ proj2.cpp -o proj2.out && "/Users/wesley/Documents/清大/四下/eda/course_projects/proj2/"proj2.out
*/