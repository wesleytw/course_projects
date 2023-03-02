# Projects of Design Automation 2 (11120CSR530300)  
## lecturer: 李炯霆教授  
### project 1:
Merge several M1 shapes and produce M1 blockages as big as possible. Then, there are shapes defining a pin. We need to carve out those pin shapes for connection.  
Please write a parser to read in all the polygons, rectangles and texts.
1) Find the smallest enclosing rectangle of all these objects. This rectangle serves as a big blockage.
2) From the texts and their locations, please identify which shapes will be touched by them. Those shapes will become pins for future connections.
3) Then, carve out pin shapes from the big blockage obtained in (1). In this exercise, please use 0.5 as min spacing for M1 (in other words, you need to leave 0.5 spacing around the pin shapes.)
