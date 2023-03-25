#include <iostream>
#include <deque>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

#include <boost/foreach.hpp>

int main()
{
  typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double>> polygon;

  polygon green, blue;

  boost::geometry::read_wkt(
      "POLYGON((0 0 0 1 1 1 1 0 0 0))", green);

  boost::geometry::read_wkt(
      "POLYGON((0 1 0 2 1 2 1 1 0 1))", blue);
  // "POLYGON((0 0.5 0 2 0.5 2 0.5 0.5 0 0.5))", blue);

  std::deque<polygon> output;
  boost::geometry::intersection(green, blue, output);

  int i = 0;
  std::cout << "green && blue:" <<  output.size() << std::endl;
  BOOST_FOREACH (polygon const &p, output)
  {
    std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
  }

  return 0;
}