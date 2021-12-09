# Goals:
## For part 1  
Implement a BST with linked list.
1. Insert a node to the BST.
2. Delete a node from the BST.
3. Search if a node is exist int the BST or not.
4. Print the BST in inorder, preorder, postorder, and postorder.
5. Clear the BST tree.
## For part 2
1. Delete the nodes(traps) first.
2. Reach two nodes(sword & Meaty) in shortest path and print out the path.
# procedures :
## Prat1
1. create struct node to implement link list BST.
2. Build insert(), search(), delete(), preorder(), inorder(), ostorder(), levelorder() function to implement these actions.
3. Design a function free() to free all the nodes in the BST.
4. use swich: to to do the indicated action. And print the message in proper place.
## Part2
1. open input file and load the numbers to create a BST.
2. Scan the input informations from command line.
3. Delete the trap's node.
4. Find the road to pick up sword.And then find Meaty.  
  4-1. Record the nodes from root to the sword's node, and put it into a stack. In the mean time, record the node's number into an array.  
  4-2. Search if the first node pop out from node can reach meaty or not. If not, pop uot next node and do it repetly.  
  4-3. Put the node's number into array every time pop out a node from stack.  
  4-4. when the node can reach meaty, record the path into the array.  
# execute result
## part1
1. Insert a node to the BST.
<img width="824" alt="image" src="https://user-images.githubusercontent.com/70461575/145405219-d207a6fe-f19f-4ab1-b4b5-ff81f33e2f2c.png">
2. Delete a node from the BST.
<img width="826" alt="image" src="https://user-images.githubusercontent.com/70461575/145405272-fedcf34a-b9b2-4b2a-83b4-170800c936af.png">
3. Search if a node is exist int the BST or not.
<img width="756" alt="image" src="https://user-images.githubusercontent.com/70461575/145405335-a7311f01-3f41-4aa2-a91b-160eb45148e6.png">
4. Print the BST in inorder, preorder, postorder, and postorder.
<img width="515" alt="image" src="https://user-images.githubusercontent.com/70461575/145405388-3d33ab89-0293-4d30-8e35-f70deb047c41.png">
5. Clear the BST tree.
## For part 2
<img width="816" alt="image" src="https://user-images.githubusercontent.com/70461575/145405755-7b4b2317-0803-4210-8376-b2bb16e964d5.png">
