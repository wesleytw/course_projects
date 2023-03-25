/*
 * https://www.boost.org/doc/libs/1_53_0/libs/geometry/doc/html/geometry/reference/algorithms/union_.html
 */
#include <iostream>
#include <vector>
#include <fstream> // svg
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/io/wkt/wkt.hpp>

#include <boost/foreach.hpp>
namespace bg = boost::geometry;

int main()
{
    typedef bg::model::d2::point_xy<double> point;

    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double>> polygon;

    polygon green, blue;

    boost::geometry::read_wkt(
        // "POLYGON((0 1.0, 0 1.6, 6.1 1.6, 6.1 1.0, 0 1.0,))", green);
        "POLYGON((2.0 2.0, 2.0 2.6, 4.0 2.6, 4.0 2.0, 2.0 2.0,))", green);

    boost::geometry::read_wkt(
        // "POLYGON((2.0 2.0, 2.0 2.6, 4.0 2.6, 4.0 2.0, 2.0 2.0,))", blue);
        "POLYGON((0 1.0, 0 1.6, 6.1 1.6, 6.1 1.0, 0 1.0,))", blue);

    std::vector<polygon> output;
    boost::geometry::union_(green, blue, output);

    int i = 0;
    std::cout << "green || blue:" << std::endl;
    BOOST_FOREACH (polygon const &p, output)            // output is an array because it may contain more than one area like "differences"
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }

    std::ofstream blue_svg("blue.svg");                          // create a file named blue.svg, and assign it as var "blue_svg"  
    bg::svg_mapper<point> blue_mapper(blue_svg, 100, 100);       // write the pattern into .svg file 
    blue_mapper.add(blue);
    blue_mapper.map(blue, "fill-opacity:0.5;fill:rgb(0,0,153);stroke:rgb(0,0,200);stroke-width:2");

    // std::ofstream green_svg("green.svg");
    // bg::svg_mapper<point> green_mapper(green_svg, 100, 100);
    // green_mapper.add(green);
    // green_mapper.map(green, "fill-opacity:0.5;fill:rgb(0,153,0);stroke:rgb(0,200,0);stroke-width:2");

    std::ofstream union_svg("union.svg");
    bg::svg_mapper<point> union_mapper(union_svg, 100, 100);
    union_mapper.add(green);
    union_mapper.add(blue);
    union_mapper.map(green, "fill-opacity:0.5;fill:rgb(0,153,0);stroke:rgb(0,200,0);stroke-width:2");
    union_mapper.map(blue, "fill-opacity:0.5;fill:rgb(0,0,153);stroke:rgb(0,0,200);stroke-width:2");

    std::ofstream output_svg("output.svg");
    bg::svg_mapper<point> output_mapper(output_svg, 100, 100);
    output_mapper.add(output[0]);
    output_mapper.map(output[0], "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(0,200,0);stroke-width:2");


    return 0;
}

// number_of_layers 1
// layer 1   M1
// end_of_layer
// number_of_polygons  5
// 1    0  0,  0 10,  10 10,  10 0,  0  0
// 1   12  3,   12  30,   32 30,  32  3,   12 3
// 1   30  0,   30  5,    40  5,    40 0,    30 0
// 1    0 40,    0  50,    6  50,    6  40,   0 40
// 1   30  42,  30 50,   40  50,  40 42,  30 42
  
// end_of_polygon
// number_of_rectangles  3
// 1  0 20,  3  24
// 1  13  46,  17 50
// 1  38  10,  40  13
// end_of_rectangle
// number_of_texts   3
// 1  C    21  21 
// 1  A   14  47
// 1  B   39  12    
// end_of_text
