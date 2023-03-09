# Projects of Design Automation 2 (11120CSR530300)  

### project 1:
Merge several M1 shapes and produce M1 blockages as big as possible. Then, there are shapes defining a pin. We need to carve out those pin shapes for connection.  
Please write a parser to read in all the polygons, rectangles and texts.
1) Find the smallest enclosing rectangle of all these objects. This rectangle serves as a big blockage.
2) From the texts and their locations, please identify which shapes will be touched by them. Those shapes will become pins for future connections.
3) Then, carve out pin shapes from the big blockage obtained in (1). In this exercise, please use 0.5 as min spacing for M1 (in other words, you need to leave 0.5 spacing around the pin shapes.)    

### Spec:  
the first number indicates the ```No.metal```  

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
