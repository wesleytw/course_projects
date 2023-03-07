// use boost union to combine polygons and use envelop to find outter shape
#include "read_spec.hpp"
#include <iostream>
#include <fstream> // svg
#include <vector>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/foreach.hpp>
using namespace std;

typedef boost::geometry::model::d2::point_xy<double> point;
typedef boost::geometry::model::polygon<point> polygon;
typedef boost::geometry::model::multi_polygon<polygon> multi_polygon;
typedef boost::geometry::model::box<point> box;
typedef read_spec::spec::layer layer;
using read_spec::spec::vec_layers;
using read_spec::func::readSpecFile;

void getMultiSvgs(multi_polygon);
tuple<multi_polygon, box> getMaxUnion(vector<layer>);
void setPins(const vector<layer> vec_layers, multi_polygon mp, box box);

int main()
{
  // vector<layer> vec_layers; // vec_layers[No.metal-1]
  readSpecFile(vec_layers);
  auto [mp, box] = getMaxUnion(vec_layers);
  setPins(vec_layers, mp, box); // rects  == pins

  return 0;
}

tuple<multi_polygon, box> getMaxUnion(const vector<layer> vec_layers)
{
  string multi_polys;
  for (int i = 0; i < vec_layers[0].polygons.size(); i++)
  {
    multi_polys = multi_polys + "((" + vec_layers[0].polygons[i] + ")),";
  }
  multi_polys = "MULTIPOLYGON(" + multi_polys + ")";

  boost::geometry::model::multi_polygon<polygon> mp;
  boost::geometry::read_wkt(multi_polys, mp);
  getMultiSvgs(mp);

  boost::geometry::model::box<point> box;
  boost::geometry::envelope(mp, box);
  std::ofstream box_svg("box.svg");
  boost::geometry::svg_mapper<point> box_mapper(box_svg, 100, 100);
  box_mapper.add(box);
  box_mapper.map(box, "fill-opacity:0.8;fill:rgb(0,0,220);stroke:rgb(0,0,230);stroke-width:2");
  box_mapper.add(mp);
  box_mapper.map(mp, "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(200,20,0);stroke-width:2");
  return {mp, box};
}

void getMultiSvgs(multi_polygon mp)
{
  std::ofstream mp_svg("mp.svg");
  boost::geometry::svg_mapper<point> mp_mapper(mp_svg, 100, 100);
  mp_mapper.add(mp);
  mp_mapper.map(mp, "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(200,20,0);stroke-width:2");
}

void setPins(const vector<layer> vec_layers, multi_polygon mp, box box)
{
  string multi_pins;
  for (int i = 0; i < vec_layers[0].rectangles.size(); i++)
  {
    multi_pins = multi_pins + "((" + vec_layers[0].rectangles[i] + ")),";
  }
  multi_pins = "MULTIPOLYGON(" + multi_pins + ")";
  boost::geometry::model::multi_polygon<polygon> pins;
  boost::geometry::read_wkt(multi_pins, pins);

  std::ofstream with_pins_svg("with_pins.svg");
  boost::geometry::svg_mapper<point> with_pins_mapper(with_pins_svg, 100, 100);
  with_pins_mapper.add(box);
  with_pins_mapper.map(box, "fill-opacity:0.8;fill:rgb(0,0,220);stroke:rgb(0,0,230);stroke-width:2");
  with_pins_mapper.add(mp);
  with_pins_mapper.map(mp, "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(200,20,0);stroke-width:2");
  with_pins_mapper.add(pins);
  with_pins_mapper.map(pins, "fill-opacity:0.5;fill:rgb(0,110,0);stroke:rgb(0,110,0);stroke-width:2");
  // with_pins_mapper.text(point(5,5), "(5,5)", "fill-opacity:0.5;fill:rgb(0,0,0);",1,1);
}

