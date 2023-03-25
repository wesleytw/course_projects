// only check weather the points are at the same position. 
// NOT CHECK WITHIN
// USE intersaction


#include <iostream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

namespace bg = boost::geometry; 

int main()
{
    // Checks if the two geometries touch
    bg::model::polygon<bg::model::d2::point_xy<double> > poly1;
    bg::read_wkt("POLYGON((0 0,0 4,4 4,4 0,0 0))", poly1);
    bg::model::polygon<bg::model::d2::point_xy<double> > poly2;
    bg::read_wkt("POLYGON((0 0,0 1,1 1,1 0,0 0))", poly2);
    bool check_touches = bg::touches(poly1, poly2);
    if (check_touches) {
         std::cout << "Touches: Yes" << std::endl;
    } else {
        std::cout << "Touches: No" << std::endl;
    }

    bg::model::polygon<bg::model::d2::point_xy<double> > poly3;
    bg::read_wkt("POLYGON((1 1,0 -4,-4 -4,-4 0,1 1))", poly3);
    check_touches = bg::touches(poly1, poly3);
    if (check_touches) {
         std::cout << "Touches: Yes" << std::endl;
    } else {
        std::cout << "Touches: No" << std::endl;
    }

    return 0;
}