# HW1 The rate in a maze  
**Contributor : F64081020 成大不分系119 劉翊安**  
* Program language : C++  
* Execution environment : terminal(iTerm2 on macos)
* Method :    
  1. Parameters introduce  
      * struct-coordi : to store coordinate x and y.  
      * stack-st : to record the path that the rat pass.  
      * array-InputMaze : record the whole maze.  
      * array-mark : record the path thet the rat passed.     
  2. Functions introduce  
      * bool haveroud(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit)  
          recognize input point (x_start, y_start) is a point that the rat can go to or not.  
      * bool visit(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit)  
          recognize if input point (x_start, y_start) is exit point or it's nearby 4 point's return value is true.  
  3. Program process overview  
      * Recursive visit nearby point in order, if any of theses return value is true, this point will return true.  
      * When the point equal to exit point, return true.
      * Brfore check the bearby point's return value, we need to makee sure that point is avaliable(not wall, nexer passed, that point is in the maze)first.
