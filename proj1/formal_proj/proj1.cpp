// use boost union to combine polygons and use envelop to find outter shape

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

class layer;
void readSpecFile(vector<layer> &);
void getMultiSvgs(multi_polygon);
void get5Uni(string, string, string, string, string);
tuple<multi_polygon, box> getMaxUnion(vector<layer>);
tuple<string *, string *> parser(); // return type: address of string array
void setPins(const vector<layer> vec_layers, multi_polygon mp, box box);

class layer
{
public:
  string layer_name;
  int number_of_layers, number_of_polygons, number_of_rectngles, number_of_texts;
  vector<string> polygons, rectangles, texts;
  layer(string layer_name)
  {
    layer_name = layer_name;
  }
};

int main()
{
  vector<layer> vec_layers; // vec_layers[No.metal-1]
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

void get5Uni(string s1, string s2, string s3, string s4, string s5)
{
  polygon p1, p2, p3, p4, p5;
  boost::geometry::read_wkt(
      "POLYGON((0  0,  0 10,  10 10,  10 0,  0  0))", p1);
  boost::geometry::read_wkt(
      "POLYGON((12  3,   12  30,   32 30,  32  3,   12 3))", p2);
  boost::geometry::model::multi_polygon<polygon> output;
  boost::geometry::union_(p1, p2, output);
  boost::geometry::model::box<point> box;
  boost::geometry::envelope(output, box);
  std::ofstream box_svg("box.svg");
  boost::geometry::svg_mapper<point> box_mapper(box_svg, 100, 100);
  box_mapper.add(box);
  box_mapper.map(box, "fill-opacity:0.5;fill:rgb(160,0,0);stroke:rgb(0,200,0);stroke-width:2");
  box_mapper.add(p1);
  box_mapper.map(p1, "fill-opacity:0.5;fill:rgb(10,0,0);stroke:rgb(0,200,0);stroke-width:2");
  box_mapper.add(p2);
  box_mapper.map(p2, "fill-opacity:0.5;fill:rgb(10,0,0);stroke:rgb(0,200,0);stroke-width:2");
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

void readSpecFile(vector<layer> &vec_layers)
{
  string spec_text;
  ifstream spec_file("../spec.txt");
  getline(spec_file, spec_text);

  int number_of_layers = stoi(spec_text.substr(16));

  for (int i = 0; i < number_of_layers; i++)
  {
    getline(spec_file, spec_text); // layer 1   M1
    layer m(spec_text.substr(8));
    vec_layers.push_back(m);
  }
  getline(spec_file, spec_text); // end_of_layer
  getline(spec_file, spec_text); // number_of_polygons

  int number_of_polygons = stoi(spec_text.substr(18));

  for (int i = 0; i < number_of_polygons; i++)
  {
    getline(spec_file, spec_text);                          // 1    0  0,  0 10,  10 10,  10 0,  0  0
    int m = stoi(spec_text.substr(0, spec_text.find(' '))); // https://stackoverflow.com/questions/18624345/split-string-at-space-and-return-first-element-in-c
    vec_layers[m - 1].polygons.push_back(spec_text.substr((to_string(m)).length()));
  }
  getline(spec_file, spec_text); // end_of_polygon
  getline(spec_file, spec_text); // number_of_rectangles

  int number_of_rectangles = stoi(spec_text.substr(20));

  for (int i = 0; i < number_of_rectangles; i++)
  {
    getline(spec_file, spec_text);                          // 1    0  0,  0 10,  10 10,  10 0,  0  0
    int m = stoi(spec_text.substr(0, spec_text.find(' '))); // https://stackoverflow.com/questions/18624345/split-string-at-space-and-return-first-element-in-c
    vec_layers[m - 1].rectangles.push_back(spec_text.substr((to_string(m)).length()));
  }
  getline(spec_file, spec_text); // end_of_rectangles
  getline(spec_file, spec_text); // number_of_texts

  int number_of_texts = stoi(spec_text.substr(15));

  for (int i = 0; i < number_of_texts; i++)
  {
    getline(spec_file, spec_text);                          // 1    0  0,  0 10,  10 10,  10 0,  0  0
    int m = stoi(spec_text.substr(0, spec_text.find(' '))); // https://stackoverflow.com/questions/18624345/split-string-at-space-and-return-first-element-in-c
    vec_layers[m - 1].texts.push_back(spec_text.substr((to_string(m)).length()));
  }
  spec_file.close();
  // cout << number_of_layers << number_of_rectangles << endl;
}
