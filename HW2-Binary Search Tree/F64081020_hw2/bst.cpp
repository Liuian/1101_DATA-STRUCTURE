#include <iostream>
#include <queue>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

/*create a 'struct node' to form  a node.*/
struct node {
  int key;
  struct node *left, *right;
};

int RecordDel = 0;

/*------------Create a node-------------------------------------------*/
/*use malloc function to create a node--------------------------------*/
/*put the value into node->key and set node->left, node->right as NULL*/
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

/*-------------------Insert a node for Part1---------------------------------------*/
/*1. check if root->key is NULL or not. if root->key is NULL, put the value into it*/
/*2. if not, put the key into correct place----------------------------------------*/
/*3. if we found that there is a same key in the tree, output 'Error'--------------*/
/*4. do 1,2,3 recruservely---------------------------------------------------------*/
struct node *insert(struct node *node, int key) {
	// Return a new node if the tree is empty
	if (node == NULL) {
		cout << "Number " << key << " is inserted.\n";
		return newNode(key);
}
	// Traverse to the right place and insert the node
	if (key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	else if(key == node->key)
		cout << "Error. Number " << key << " exists." << '\n';
  return node;
}

/*-------------Find the inorder successor(used in deleting a node)--*/
/*find the node right subtree's smallest node(leftmost node)--------*/
struct node *minValueNode(struct node *node) {
	struct node *current = node;
	//Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;
	return current;
}

/*--------------Deleting a node-------------------------------------*/
/*1. find the node we want to delete first--------------------------*/
/*2. figure out that node have zero, one or two childern(s)---------*/
/*3. do the correspond action depand on how many children(s) it have*/
struct node *deleteNode(struct node *root, int key) {
	// Return if the tree is empty
	if (root == NULL) return root;
	// Find the node to be deleted
	if (key < root->key){
		if(root->left == NULL) 
			RecordDel = 0;
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key){
		if(root->right == NULL)
			RecordDel = 0;
		root->right = deleteNode(root->right, key);
	}
	else{
		// If the node is with only one child or no child
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		//If the node has two children
		struct node *temp = minValueNode(root->right);
		// Place the inorder successor in position of the node to be deleted
		root->key = temp->key;
		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

/*-------------search a node------------------*/
bool search(struct node *root, int key){
	if(root == NULL)
		return false;
	else if(key < root->key)
		return search(root->left, key);
	else if(key > root->key)
		return search(root->right, key);
	else if(key == root->key)
		return true;
}

/*-------------preorder traversal--------------------------------*/
/*output node->key first and then treverse left and right subtree*/
/*search left and right subtree recruservly----------------------*/
void preorder(struct node *root){
	if(root != NULL){
		// Traverse root
		cout << root->key << " ";
		// Traverse left
		preorder(root->left);
		// Traverse right
		preorder(root->right);
	}
}

/*--------------Inorder Traversal--------------*/
/*same logic with preorder traversal-----------*/
void inorder(struct node *root){
	if (root != NULL) {
		// Traverse left
		inorder(root->left);
		// Traverse root
		cout << root->key << " ";
		// Traverse right
		inorder(root->right);
	}
}

/*------------postorder traversal-----------------*/
/*same logic with preorder traversal-----------*/
void postorder(struct node *root){
	if (root != NULL) {
		// Traverse left
		postorder(root->left);
		// Traverse right
		postorder(root->right);
		// Traverse root
		cout << root->key << " ";
	}
}

/*-----------level order traversal--------------------------------------------*/
/*put the outputed node's subtree into the queue------------------------------*/
/*pop out one node from queue, print the key and do these two step recursively*/
void levelorder(struct node *root){
	//create a queue and put the nodes into it in order
	queue<node*> q;
	//if the tree is NULL, don't do q.push()
	if(root != NULL){
		q.push(root);
	}
	while(!q.empty()){
		root = q.front();
		q.pop();
		cout << root->key << " ";
		if(root->left != NULL)
			q.push(root->left);
		if(root->right != NULL)
			q.push(root->right);
	}
}

/*------------freeBST-------------------*/
//search the tree inorder and free(root)*/
void freeBST(struct node *root){
	if (root != NULL) {
		// Traverse left
		freeBST(root->left);
		// Traverse right
		freeBST(root->right);
		// Free root
		free(root);
	}
}

/*------Insert a node for Part2-------------------*/
struct node *insertPart2(struct node *node, int key) {
	// Return a new node if the tree is empty
	if (node == NULL) {
		//cout << "Number " << key << " is inserted.\n";
		return newNode(key);
}
	// Traverse to the right place and insert the node
	if (key < node->key)
		node->left = insertPart2(node->left, key);
	else if(key > node->key)
		node->right = insertPart2(node->right, key);
	//else if(key == node->key)
		//cout << "Error. Number " << key << " exists." << '\n';
  return node;
}

int NumStore[4096];
int CountNum;
/*------------postorder traversal-----------------*/
/*same logic with preorder traversal-----------*/
void postorderPart2(struct node *root){
	if (root != NULL) {
		// Traverse left
		postorderPart2(root->left);
		// Traverse right
		postorderPart2(root->right);
		// Traverse root
		//cout << root->key << " ";
		//cout << "test";
		NumStore[CountNum] = root->key;
		CountNum = CountNum + 1;
	}
}


int RecRoud[4096];
int count0;
stack<node*> st;
/*-------------search a node for part2------------------*/
/*this function is bascally same with search function---*/
/*only different is to puch the reached node into stack,*/
/*and put the path into the array-----------------------*/
bool searchPart2(struct node *root, int key){
	if(root == NULL)
		return false;
	else if(key < root->key){
		st.push(root);
		RecRoud[count0] = root->key;
		count0 = count0 + 1;
		return searchPart2(root->left, key);
	}
	else if(key > root->key){
		st.push(root);
		RecRoud[count0] = root->key;
		count0 = count0 + 1;
		return searchPart2(root->right, key);
	}
	else if(key == root->key){
		RecRoud[count0] = root->key;
		count0 = count0 + 1;
		return true;
	}
}

int main(){
	int tmp0;	//record main menu's input number
	char tmp1;	//record BST action menu's input number
	while(1){
	struct node *root = NULL;	//build a root node for BST tree
	cout << "(1)Binary searching tree." << '\n';
	cout << "(2)Finding Meaty." << '\n';
	cout << "(0)Escape and find the meaty next year." << '\n';
	cin >> tmp0;
	switch(tmp0){
		case 1:
			BST:
			cout << "(I)nsert a number." << '\n';
			cout << "(S)earch a number." << '\n';
			cout << "(D)elete a number" << '\n';
			cout << "(P)rint 4 kinds of order." << '\n';
			cout << "(R)eturn." << '\n';
			cin >> tmp1;
			switch(tmp1){
				//insert
				case 'i':
					int InsVal;
					cout << "Enter Numbers : ";
					cin >> InsVal;
					while(InsVal != -1){	//do insert function till the input number is -1
						root = insert(root, InsVal);
						cin >> InsVal;
					}
					goto BST;	//use same BST to do other functions
				//search
				case 's':
					int SarVal;
					cout << "Enter elements to searching : ";
					cin >> SarVal;
					while(SarVal != -1){	//do insert function till the input number is -1
						if(search(root, SarVal) ==true)
							cout << "Bingo! " << SarVal << " is found.\n";
						else
							cout << "SORRY " << SarVal << " is not found.\n";
						cin >> SarVal;
					}
					goto BST;
				//delete
				case 'd':
					int DelVal;
					cout << "Enter numbers to delete : ";
					cin >> DelVal;
					while(DelVal != -1){	//do insert function till the input number is -1
						RecordDel = 1;
						root = deleteNode(root, DelVal);
						if(RecordDel == 0)
							cout << "Number " << DelVal << " is not exist\n";
						else
							cout << "Number " << DelVal << " is deleted.\n";
						cin >> DelVal;
					}
					goto BST;
				//print
				case 'p':
					cout << "The tree in prefix order : ";
					preorder(root);
					cout << "\nThe tree in infix order : ";
					inorder(root);
					cout << "\nThe tree in post order : ";
					postorder(root);
					cout << "\nThe tree in level order : ";
					levelorder(root);
					cout << '\n';
					goto BST;
				//restart
				case 'r':
					freeBST(root);	//clear link list BST
					break;
			}
			break;
		case 2:{
			CountNum = 0;
			/*Read all the data we need--*/
			/*and read the input file----*/
			cout << "Please input the map file:";	
			string MapFile;
			cin >> MapFile;
			ifstream InputFile(MapFile);
			int num;
			struct node *root = NULL;
			if(InputFile.is_open()){
				while(InputFile >> num){
					root = insertPart2(root, num);
				}
			cout << "Load file success.\n\n";
			}
			cout << "Please input the sword's location:";
			int sword;
			cin >> sword;
			cout << "Please input the Meaty's location:";
			int meaty;
			cin >> meaty;
			cout << "Please input the broccoli traps' index(0~9):";
			int Trap;
			cin >> Trap;
			/*record postorder node's key into an array*/
			postorderPart2(root);
			/*delete the Trap's node*/
			int dividenum;
			//cout << "\nCountNum" << CountNum;
			for(int j = 0; j < CountNum; j++){
				dividenum = NumStore[j];
				while(dividenum != 0){
					if(dividenum % 10 == Trap){ 
						root = deleteNode(root, NumStore[j]);
						cout << "Number " << NumStore[j] << " is dedeted\n";
						break;
					}
					dividenum = dividenum / 10;
				}
			}
			cout << '\n';
			/*Find the road to take the sword and find meaty-------------------*/
			/*when capoo go to take the sword----------------------------------*/
			/*, record the road in the stack and array-------------------------*/
			/*when capoo want to go to meaty's node from sword's node----------*/
			/*, pop out the node in order -------------------------------------*/
			/*and find if that node can reach the meaty's node-----------------*/
			/*if that node can reach meaty's node, record the node in the array*/
			struct node *cur = NULL;
			cur = root;
			count0 = 0;
			searchPart2(root, sword);
			cur = st.top();
			st.pop();
			while(search(cur, meaty) == false){
				RecRoud[count0] = cur->key;
				count0 = count0 + 1;
				cur = st.top();
				st.pop();
			}
			searchPart2(cur, meaty);
			cout << "Capoo successfully found his favorite meaty<3\n\n";
			cout << "shortest path to find the meaty : \n";
			for(int j = 0; j < count0 - 1; j++){
				cout << RecRoud[j] << "->";
			}
			cout << RecRoud[count0 - 1];
			cout << '\n';
			freeBST(root);
			break;
		}
		case 0:
			return 0;
	}
	}
	return 0;
}
