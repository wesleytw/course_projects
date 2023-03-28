# Projects of Design Automation 2 (11120CSR530300)  
### [view on github](https://github.com/wesleytw/eda_course_projects/tree/master/proj2/group3_proj2)  
## Project 2 (end-of-line rule) intro
Please see a picture below, which describes this rule. Let’s say
EOL spacing between objects 1 and 2 is at least 1 (um).  
Length of end is 0.6 (um) (i.e., if the width of object-1 is smaller & equal than 0.6, consider.)  
Parallel length from the top of edge 1 is 0.7 (um).  
Parallel halo away from object-1 is 0.4 (um)  
Layout patterns are described below.  


## How to use
Execute the following commands in terminal:
```bash
cd "/path/to/dir/"
```
```bash
g++ -std=c++17 proj2.cpp -o proj2.out 
```
```bash
"/path/to/dir/"proj2.out
```  
SVG output result: ```output.svg```  
```RED``` line: DRC violation exists.  
```GREEN``` line: No DRC violation.

## Implementation  
### spec.txt 
spec.txt contains the spec of polygons, rectangles and texts. 
The first number indicates the ```No.metal```  
```
number_of_layers 1
layer 1   M1
end_of_layer
number_of_rectangles  6
1  0  4.0,   7.8  0.6  # should be 4.0 0, 7.8 0.6?  
1  0 1.0,   6.1  1.6
1  2.0  2.0,  4.0  2.6
1  7.0  1.0,  14 1.6
1  10.4 0.8,  11 1.8
1   8.6  2.2,  14  2.8
end_of_rectangle
```  

### read_spec.hpp  
This program reads the spec from spec.txt and saves the shapes as OBJECTS.  

### proj2.cpp  
#### 1. Check min length. If length < 0.6um, show the warning text and turn the color of line into red. Test using 0.4um as min length. ```/test_demo/min_length.svg```
![min_length](https://raw.githubusercontent.com/wesleytw/eda_course_projects/master/proj2/group3_proj2/test_demo/min_length.svg)

#### 2. Check overlappings of line. If one line overlap another line, turn both lines' colors into red and show the warning text. 
![min_length](https://raw.githubusercontent.com/wesleytw/eda_course_projects/master/proj2/group3_proj2/test_demo/line_overlap.svg)

#### 3. EOL checking. Define the EOL area of each line. If the EOL area overlap any line, turn the line's color into red and show the warning text.  
![eol](https://raw.githubusercontent.com/wesleytw/eda_course_projects/master/proj2/group3_proj2/test_demo/eol.svg)

#### 4. Check all the rules mentioned above.
![output](https://raw.githubusercontent.com/wesleytw/eda_course_projects/master/proj2/group3_proj2/output.svg)



