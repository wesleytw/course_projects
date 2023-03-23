# Projects of Design Automation 2 (11120CSR530300)  

## Project 1 intro
Merge several M1 shapes and produce M1 blockages as big as possible. Then, there are shapes defining a pin. We need to carve out those pin shapes for connection.  
Please write a parser to read in all the polygons, rectangles and texts.
1) Find the smallest enclosing rectangle of all these objects. This rectangle serves as a big blockage.
2) From the texts and their locations, please identify which shapes will be touched by them. Those shapes will become pins for future connections.
3) Then, carve out pin shapes from the big blockage obtained in (1). In this exercise, please use 0.5 as min spacing for M1 (in other words, you need to leave 0.5 spacing around the pin shapes.)    

## How to use
Execute the following commands in terminal:
```bash
cd "/path/to/dir/"
```
```bash
g++ -std=c++17 proj1.cpp -o proj1.out 
```
```bash
"/path/to/dir/"proj1.out
```

## Implementation  
### spec.txt 
spec.txt contains the spec of polygons, rectangles and texts. 
The first number indicates the ```No.metal```  
```
number_of_layers 1
layer 1   M1
end_of_layer
number_of_polygons  5
1    0  0,  0 10,  10 10,  10 0,  0  0
1   12  3,   12  30,   32 30,  32  3,   12 3
1   30  0,   30  5,    40  5,    40 0,    30 0
1    0 40,    0  50,    6  50,    6  40,   0 40
1   30  42,  30 50,   40  50,  40 42,  30 42
  
end_of_polygon
number_of_rectangles  3
1  0 20,  3  24
1  13  46,  17 50
1  38  10,  40  13
end_of_rectangle
number_of_texts   3
1  C    1  21 
1  A   14  47
1  B   39  12    
end_of_text
```  

### read_spec.hpp  
This program reads the spec from spec.txt and saves the shapes and texts as OBJECTS.  

### proj1.cpp  
#### 1. Put all shapes together as a MULTIPOLYGON  
![mp](https://raw.githubusercontent.com/wesleytw/eda_course_projects/d2d609181d56a2b28765cac07f5dbe287a4958b7/proj1/formal_proj/mp.svg)

#### 2. Find the smallest enclosing of the shapes by using ```boost::geometry::envelope```. The blue region is the envelope, which is defined as a big blockage. 
![box](https://raw.githubusercontent.com/wesleytw/eda_course_projects/d2d609181d56a2b28765cac07f5dbe287a4958b7/proj1/formal_proj/box.svg)

#### 3. Find which shapes are touched by texts and define them as pins by using ```boost::geometry::within```. If a text locates in a shape, that shape serves as pin. Then, carve out pin shapes from the big blockage by using the enlarged pins. Check out the result in ```pins_union_blockage.svg```. 
![box](https://raw.githubusercontent.com/wesleytw/eda_course_projects/d2d609181d56a2b28765cac07f5dbe287a4958b7/proj1/group3_proj1_v1/pins_union_blockage.svg)

#### 3. Test if the program could find the correct pins and blockage with different spec. Check out the result in ```test_diff_text.svg```. 
![box](https://raw.githubusercontent.com/wesleytw/eda_course_projects/d2d609181d56a2b28765cac07f5dbe287a4958b7/proj1/group3_proj1_v1/test_diff_text.svg)




