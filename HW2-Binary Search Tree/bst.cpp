#include <iostream>
#include <queue>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

int RecordDel = 0;

/*------------Create a node----------------*/
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

/*---------Insert a node for Part1-------------------*/
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
struct node *minValueNode(struct node *node) {
	struct node *current = node;
	//Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;
	return current;
}

/*--------------Deleting a node-------------------*/
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

/*-------------preorder traversal--------------*/
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

/*-----------level order traversal---------------*/
void levelorder(struct node *root){
	queue<node*> q;
	q.push(root);
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

//******????//
int RecRoud[64];
int count0 = 0;
stack<node*> st;
/*-------------search a node for part2------------------*/
bool searchPart2(struct node *root, int key){
	if(root == NULL)
		return false;
	else if(key < root->key){
		st.push(root);
		RecRoud[count0] = key;
		count0 = count0 + 1;
		return search(root->left, key);
	}
	else if(key > root->key){
		st.push(root);
		RecRoud[count0] = key;
		count0 = count0 + 1;
		return search(root->right, key);
	}
	else if(key == root->key){
		RecRoud[count0] = key;
		count0 = count0 + 1;
		return true;
	}
}

int main(){
	int tmp0;
	char tmp1;
	struct node *root = NULL;
	while(1){
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
				case 'I':
					int InsVal;
					cout << "Enter Numbers : ";
					cin >> InsVal;
					while(InsVal != -1){
						root = insert(root, InsVal);
						cin >> InsVal;
					}
					goto BST;
				case 'S':
					int SarVal;
					cout << "Enter elements to searching : ";
					cin >> SarVal;
					while(SarVal != -1){
						if(search(root, SarVal) ==true)
							cout << "Bingo! " << SarVal << " is found.\n";
						else
							cout << "SORRY " << SarVal << " is not found.\n";
						cin >> SarVal;
					}
					goto BST;
				case 'D':
					int DelVal;
					cout << "Enter numbers to delete : ";
					cin >> DelVal;
					while(DelVal != -1){
						RecordDel = 1;
						root = deleteNode(root, DelVal);
						if(RecordDel == 0)
							cout << "Number " << DelVal << " is not exist\n";
						else
							cout << "Number " << DelVal << " is deleted.\n";
						cin >> DelVal;
					}
					goto BST;
				case 'P':
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
				case 'R':
					//clear link list BST
					break;
			}
			break;
		case 2:{
			//Read all the data we need
			cout << "Please input the map file:";	
			string MapFile;
			cin >> MapFile;
			ifstream InputFile(MapFile);
			int num;
			int NumStore[64];
			int i = 0;
			while(InputFile >> num){
				root = insertPart2(root, num);
				NumStore[i] = num;
				i = i + 1;
			}
			cout << "Load file success.\n\n";
			
			cout << "Please input thr sword's location:";
			int sword;
			cin >> sword;
			cout << "Please input the Meaty's location:";
			int meaty;
			cin >> meaty;
			cout << "Please input the broccoli traps' index(0~9):";
			int Trap;
			cin >> Trap;
			//delete the Trap's node
			int dividenum;
			for(int j = 0; j < i; j++){
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
			//Find the road to take the sword and find meaty
			struct node *cur = NULL;
			cur = root;
			searchPart2(root, sword);
			cur = st.top();
			st.pop();
			while(search(cur, meaty) == false){
				cur = st.top();
				st.pop();
				RecRoud[count0] = cur->key;
				count0 = count0 + 1;
			}
			cout << "Capoo successfully found his favorite meaty<3\n\n";
			cout << "shortest path to find the meaty : \n";
			for(int j = 0; j < count0; j++){
				cout << RecRoud[j] << "->";
			}
			cout << '\n';
			break;
		}
		case 0:
			return 0;
	}
	}
	return 0;
}
