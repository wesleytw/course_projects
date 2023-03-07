#include <iostream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <fstream> // svg

int main()
{
  typedef boost::geometry::model::d2::point_xy<double> point;
  typedef boost::geometry::model::polygon<point> polygon;

  // boost::geometry::model::polygon<point> polygon;

  // boost::geometry::read_wkt(
  //     "POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3)"
  //         "(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))", polygon);
  // Declare/fill a multi polygon
  boost::geometry::model::multi_polygon<polygon> mp;
  boost::geometry::read_wkt("MULTIPOLYGON(((5 5,7 8,9 5,5 5)),((8 7,8 10,11 10,11 7,8 7)))", mp);

  boost::geometry::model::box<point> box;
  boost::geometry::envelope(mp, box);

  std::ofstream mp_svg("mp.svg");
  boost::geometry::svg_mapper<point> mp_mapper(mp_svg, 100, 100);
  mp_mapper.add(mp);
  mp_mapper.map(mp, "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(0,200,0);stroke-width:2");

  std::cout << "envelope:" << boost::geometry::dsv(box) << std::endl;
  std::ofstream output_svg("output.svg");
  boost::geometry::svg_mapper<point> output_mapper(output_svg, 100, 100);
  output_mapper.add(box);
  output_mapper.map(box, "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(0,200,0);stroke-width:2");
  output_mapper.add(mp);
  output_mapper.map(mp, "fill-opacity:0.5;fill:rgb(10,0,110);stroke:rgb(0,20,110);stroke-width:2");
      polygon p1, p2, p3, p4, p5;

    boost::geometry::read_wkt(
        "POLYGON((0  0,  0 10,  10 10,  10 0,  0  0))", p1);

    boost::geometry::read_wkt(
        "POLYGON((12  3,   12  30,   32 30,  32  3,   12 3))", p2);
  boost::geometry::model::multi_polygon<polygon> output;

    // std::vector<polygon> output;
    boost::geometry::union_(p1, p2, output);
      boost::geometry::model::box<point> box2;
  boost::geometry::envelope(output, box2);
  std::ofstream box2_svg("box2.svg");
  boost::geometry::svg_mapper<point> box2_mapper(box2_svg, 100, 100);
  box2_mapper.add(box2);
  box2_mapper.map(box2, "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(0,200,0);stroke-width:2");
  box2_mapper.add(p1);
  box2_mapper.map(p1, "fill-opacity:0.5;fill:rgb(10,0,0);stroke:rgb(0,200,0);stroke-width:2");
  box2_mapper.add(p2);
  box2_mapper.map(p2, "fill-opacity:0.5;fill:rgb(10,0,0);stroke:rgb(0,200,0);stroke-width:2");
  
  return 0;
}