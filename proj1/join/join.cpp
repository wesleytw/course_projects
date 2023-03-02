// strategy::buffer::join_round
// https://www.boost.org/doc/libs/1_81_0/libs/geometry/doc/html/geometry/reference/strategies/strategy_buffer_join_round.html
// !! https://www.boost.org/doc/libs/1_81_0/libs/geometry/doc/html/geometry/reference/strategies/strategy_buffer_join_miter.html
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/geometries.hpp>

#include <fstream> // svg
#include <boost/foreach.hpp>

int main()
{
  typedef boost::geometry::model::d2::point_xy<double> point;
  typedef boost::geometry::model::polygon<point> polygon;

  // Declare the join_miter strategy
  boost::geometry::strategy::buffer::join_miter join_strategy;

  // Declare other strategies
  boost::geometry::strategy::buffer::distance_symmetric<double> distance_strategy(0.1);
  boost::geometry::strategy::buffer::end_flat end_strategy;
  boost::geometry::strategy::buffer::side_straight side_strategy;
  boost::geometry::strategy::buffer::point_circle point_strategy;

  // Declare/fill a multi polygon
  boost::geometry::model::multi_polygon<polygon> mp;
  boost::geometry::read_wkt("MULTIPOLYGON(((5 5,7 8,9 5,5 5)),((8 7,8 10,11 10,11 7,8 7)))", mp);

  // Create the buffered geometry with sharp corners
  boost::geometry::model::multi_polygon<polygon> result;
  boost::geometry::buffer(mp, result,
                          distance_strategy, side_strategy,
                          join_strategy, end_strategy, point_strategy);

  std::ofstream o1_svg("o1.svg");                                 // create a file named p2.svg, and assign it as var "p2_svg"
  boost::geometry::svg_mapper<point> o1_mapper(o1_svg, 100, 100); // write the pattern into .svg file
  o1_mapper.add(result);
  o1_mapper.map(result, "fill-opacity:0.5;fill:rgb(0,0,153);stroke:rgb(0,0,200);stroke-width:2");
  o1_mapper.add(mp);
  o1_mapper.map(mp, "fill-opacity:0.5;fill:rgb(0,110,15);stroke:rgb(0,110,200);stroke-width:2");

  // std::cout << "envelope:" << result << std::endl;
  int i = 0;
  BOOST_FOREACH (polygon const &p, mp) // output is an array because it may contain more than one area like "differences"
  {
    std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
  }

    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double>> polygon;

    polygon p1, p2, p3, p4, p5;

    boost::geometry::read_wkt(
        "POLYGON((0  0,  0 10,  10 10,  10 0,  0  0))", p1);

    boost::geometry::read_wkt(
        "POLYGON((12  3,   12  30,   32 30,  32  3,   12 3))", p2);



  return 0;
}