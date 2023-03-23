Project-2 (end-of-line rule) (10%)  
Please see a picture below, which describes this rule. Let’s say
EOL spacing between objects 1 and 2 is at least 1 (um).  
Length of end is 0.6 (um) (i.e., if the width of object-1 is smaller & equal than 0.6, consider.)  
Parallel length from the top of edge 1 is 0.7 (um).  
Parallel halo away from object-1 is 0.4 (um)  
Layout patterns are described below.  
```
number_of_layers 1
layer 1   M1
end_of_layer
number_of_rectangles  6
1  0  4.0,   7.8  0.6
1  0 1.0,   6.1  1.6
1  2.0  2.0,  4.0  2.6
1  7.0  1.0,  14 1.6
1  10.4 0.8,  11 1.8
1   8.6  2.2,  14  2.8
end_of_rectangle
```