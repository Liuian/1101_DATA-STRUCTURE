# 3-1
create
1. a struct node include data, * left node and * right node.  
procedure  
1. open the input file and read all the data.  
2. judge the input file is what kind of file.  
3. if(the input is preorder-inorder). 
4. do Recursive function(buildTreePre) to construct binary of size len from Inorder traversal in[] and Preorder traversal pre[]. Initial values of inStrt and inEnd should be 0 and len -1. The function doesn't do any error checking for cases where inorder and preorder do not form a tree.  
4-1. Pick current node from Preorder traversal using preIndex and increment preIndex  
4-2. If this node has no children then return.  
4-3. Else find the index of this node in Inorder traversal.  
4-4. Using index in Inorder traversal, construct left and right subtress. 
5. do the same thing for postorder-inorder input.  
# 3-2  
create  
1. a matrix(adjMatrix[][]) to record if there is a path between two vertex  
2. an(visited[]) array to record weather we visited the vertex or not(0 : never visited, 1 : visited)  
procedure  
1.  open the input file and read all the data.  
2.  put the matrix's data into adjMatrix[][] and set visited's element as 0(never visited)  
3.  print out the start vertex  
4.  set visited[startvertex] as 1.  
5.  when we find the smallest point connected to startvertex && we never visit it, do dfs recursively do step3, step4, step5  
# 3-3  
create  
1. create the adjmatrix to record if the path exist between two vertex  
2. create an array visited to record if we visite the vertex yet(0 : didn't visited 1 : visited)  
3. queue  
procedure  
1. open the input file and read all the data.  
2. put the matrix's data into adjMatrix[][] and set visited's element as 0(never visited).  
3. if true, put vertex i into the queue and mark i as visited.  
4. when queue is not empty, the function do NOT finish yet. output the first number in queue and pop out the e.ement. and do do step3, 4 repetely.  
# 3-4  
create 3 variables  
1. vector<pair<int, edge> > G; - to store edge's start, end point and weight of the whole graph.  
2. vector<pair<int, edge> > T; - to store the selected edge(and it's weight.  
3. parent[] - used in union find algorithm.  
procedure  
1. open the input file and read all the data.  
2. store the edge's start, end point and weight in vector G.  
3. sort the datas in G in nondecreasing order.  
4. pick the smallest edge and do union find algorithm to determine if it will generate a cycle. if not put the edge into vector T.  
5. repet step 4 in #edge times.  
# 3-5  
describtion:  
bscause the problem give us some hint  
1. The input describes a tree topology in a graph way. 
2. there are only #vertex - 1 edges  
3. there is only one path to connect  𝑣  and  𝑢  
thus, i decided to use depth first search as tihs code's base, and when bfs reach a new vertex, add the weight into that vertex. 
create  
1. create the adjMatrix to record the weight between two vertex.  
2. create an array - pathLength to record the shortest path's weight(-1 : no path to this vertex from the start vertex)  
precedure  
1. open the input file and read all the data.  
2. do BFS, if this vertex connect to another never visited vertex, add the weight into recorded weight.  
# execution results
## 3-1
output.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147930760-cb9a0a1e-dce7-4af7-b7a9-610d49fd17b7.png">  
output_01.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147930806-dd0d93e1-5e3f-4f7f-9b7c-bf93ff083e4a.png">  
output_02.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147930828-9b84cdfc-72a9-46f3-8fea-7ff7ab99502d.png">  
## 3-2  
output.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147930904-39973639-f296-4754-968f-0d1187065565.png">  
output_01.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147930983-dc7ee666-c549-4fc4-9033-76d852548cfa.png">
## 3-3
output.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931082-ad97e2d7-3e35-4a73-bc77-37ad0470ef76.png">  
output_01.txt 
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931100-86e2df22-1350-4f40-ae80-0538335b17b1.png">  
## 3-4
output.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931189-8c8d3fc7-5d40-4f70-870e-c20194f9370b.png">
output_01.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931216-df76fcc2-3881-427f-8b64-234311e8f4be.png">
output_02.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931249-95826488-32a1-484a-8fa4-01dd2400aefb.png">

## 3-5  
output.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931341-4663d766-1c8d-4c49-a030-4ce6c66355a0.png">  
output_01.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931364-0c6918f6-62b6-4287-a33d-de88a619fd08.png">
output_02.txt 
output.txt  
<img width="1440" alt="image" src="https://user-images.githubusercontent.com/70461575/147931383-0921a4d0-1831-49e2-93ab-d392b0eb5180.png">
