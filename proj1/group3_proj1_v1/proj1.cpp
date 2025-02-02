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
using read_spec::func::readSpecFile;
using read_spec::spec::vec_layers;
// using read_spec::spec::layer::texts;

void getMultiSvgs(multi_polygon);
tuple<multi_polygon, box> getMaxUnion(vector<layer>);
void setPins(vector<layer> vec_layers, multi_polygon mp, box box);

int main()
{
  readSpecFile(vec_layers);
  auto [mp, box] = getMaxUnion(vec_layers);
  setPins(vec_layers, mp, box); // rects  == pins

  return 0;
}

tuple<multi_polygon, box> getMaxUnion(const vector<layer> vec_layers)
{
  string multi_blocks;
  for (int i = 0; i < vec_layers[0].polygons.size(); i++)
  {
    multi_blocks = multi_blocks + "((" + vec_layers[0].polygons[i] + ")),";
  }
  for (int i = 0; i < vec_layers[0].rectangles.size(); i++)
  {
    multi_blocks = multi_blocks + "((" + vec_layers[0].rectangles[i] + ")),";
  }
  multi_blocks = "MULTIPOLYGON(" + multi_blocks + ")";

  boost::geometry::model::multi_polygon<polygon> mp;
  boost::geometry::read_wkt(multi_blocks, mp);
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
boost::geometry::strategy::buffer::join_miter join_strategy;
boost::geometry::strategy::buffer::distance_symmetric<double> distance_strategy(0.5);
boost::geometry::strategy::buffer::end_flat end_strategy;
boost::geometry::strategy::buffer::side_straight side_strategy;
boost::geometry::strategy::buffer::point_circle point_strategy;
boost::geometry::model::multi_polygon<polygon> lg_pins;
void setPins(vector<layer> vec_layers, multi_polygon mp, box box)
{
  for (int i = 0; i < vec_layers[0].polygons.size(); i++)
  {
    boost::geometry::model::polygon<point> po;
    boost::geometry::read_wkt("POLYGON((" + vec_layers[0].polygons[i] + "))", po);
    for (int j = 0; j < vec_layers[0].texts.size(); j++)
    {
      if (boost::geometry::within(point(vec_layers[0].texts[j].p1, vec_layers[0].texts[j].p2), po))
      {
        vec_layers[0].pins.push_back(vec_layers[0].polygons[i]);
      }
    }
  }
  for (int i = 0; i < vec_layers[0].rectangles.size(); i++)
  {
    boost::geometry::model::polygon<point> po;
    boost::geometry::read_wkt("POLYGON((" + vec_layers[0].rectangles[i] + "))", po);
    for (int j = 0; j < vec_layers[0].texts.size(); j++)
    {
      if (boost::geometry::within(point(vec_layers[0].texts[j].p1, vec_layers[0].texts[j].p2), po))
      {
        vec_layers[0].pins.push_back(vec_layers[0].rectangles[i]);
      }
    }
  }

  string multi_pins;
  for (int i = 0; i < vec_layers[0].pins.size(); i++)
  {
    multi_pins = multi_pins + "((" + vec_layers[0].pins[i] + ")),";
  }
  multi_pins = "MULTIPOLYGON(" + multi_pins + ")";
  boost::geometry::model::multi_polygon<polygon> pins;
  boost::geometry::read_wkt(multi_pins, pins);

  boost::geometry::buffer(pins, lg_pins,
                          distance_strategy, side_strategy,
                          join_strategy, end_strategy, point_strategy);
  boost::geometry::model::multi_polygon<polygon> no_pins;
  boost::geometry::difference(box, lg_pins, no_pins);
  std::ofstream with_pins_svg("with_pins.svg");
  boost::geometry::svg_mapper<point> with_pins_mapper(with_pins_svg, 100, 100);
  with_pins_mapper.add(no_pins);
  with_pins_mapper.map(no_pins, "fill-opacity:0.8;fill:rgb(0,0,220);stroke:rgb(0,0,230);stroke-width:0.5");
  with_pins_mapper.add(mp);
  with_pins_mapper.map(mp, "fill-opacity:0.55;fill:rgb(160,0,0);");
  with_pins_mapper.add(pins);
  with_pins_mapper.map(pins, "fill-opacity:1;fill:rgb(0,110,0);");
  for (int i = 0; i < vec_layers[0].texts.size(); i++)
  {
    with_pins_mapper.text(point(vec_layers[0].texts[i].p1, vec_layers[0].texts[i].p2), vec_layers[0].texts[i].name, "fill-opacity:0.9;fill:rgb(220,220,220);font-size:6px;", 0, 0);
  }

  std::ofstream pins_union_blockage_svg("pins_union_blockage.svg");
  boost::geometry::svg_mapper<point> pins_union_blockage_mapper(pins_union_blockage_svg, 100, 100);
  pins_union_blockage_mapper.add(no_pins);
  pins_union_blockage_mapper.map(no_pins, "fill-opacity:1;fill:rgb(0,0,220);stroke:rgb(0,0,230);stroke-width:0.5");
  pins_union_blockage_mapper.add(pins);
  pins_union_blockage_mapper.map(pins, "fill-opacity:1;fill:rgb(0,110,0);");
  for (int i = 0; i < vec_layers[0].texts.size(); i++)
  {
    pins_union_blockage_mapper.text(point(vec_layers[0].texts[i].p1, vec_layers[0].texts[i].p2), vec_layers[0].texts[i].name, "fill-opacity:0.9;fill:rgb(220,220,220);font-size:6px;", 0, 0);
  }
}
