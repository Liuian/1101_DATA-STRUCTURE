#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <stack>

using namespace std;

int SIZE = 17;	//maze's size
int tmp = 0;	//record the the number of output step
int x_start, y_start, x_exit, y_exit, tmp_x, tmp_y;	//tmp_x & tmp_y record where the rat is
/*setup a struct. This struct is to record the point that the rat on and push it into stack*/
struct coordinate{
	int x;
	int y;
}coordi;
stack<coordinate>st;
/* for function : bool haveroud(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit)
 * 		this fouction help us check if the point we tend to go is avaliable
 * 		(it is a road and the rat will go to that point in next step) or not.*/
bool haveroud(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit){
	coordi.x = x_start;
	coordi.y = y_start;
	/*If following three situation happened, return false. If not, return true.
	 *1.check the start and exit point are in the maze
	 *2.if the start point or exit point is wall, return false
	 *3.if we already went throuth the input point, returm false*/
	if(!(x_start >= 1 && x_start <= 15 && x_exit >= 1 && x_exit <= 15 && y_start >= 1 && y_start <= 15 && y_exit >= 1 && y_exit <= 15)) return false;
	else if(InputMaze[x_start][y_start] == '1' || InputMaze[x_exit][y_exit] == '1') return false;
	else if(mark[x_start][y_start] == 1) return false;
	else return true;
}
/* for function : bool visit(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit)
 * 		this function use three steps to visit whloe maze
 * 		1. judge if the input point(x_start, y_start) equals to exit point, if it is, return true
 * 		2. wait for 4 nearby point's return value orderly. In addition befor visit the nearby point, check if the point we tend to go is avaliable or not first.
 * 		3. if all the point's return value is false or no nearby point is avaliable return false, else return true */
bool visit(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit){
	/*if the input point(x_start, y_start) equals to the exit point, mark the point as we went through & return true*/
	if(x_start == x_exit && y_start == y_exit){
		mark[x_start][y_start] = 1;
		return true;
	}
	/*else search next point*/
	else{
		mark[x_start][y_start] = 1;
		if(haveroud(InputMaze, mark, x_start, y_start + 1, x_exit, y_exit)/*(x, y + 1) 是可以走過去的 */){
			//record where the rate is to judge if the rate successfully escaped or not*/
			tmp_x = x_start;
			tmp_y = y_start + 1;
			//print out
			cout << tmp++ << ":" << x_start << "," << y_start + 1 << "\n";
			//push into stack
			coordi.x = x_start;
			coordi.y = y_start + 1;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start, y_start + 1, x_exit, y_exit)) return true;
		}
		/*the following code is the same*/
		else if(haveroud(InputMaze, mark, x_start + 1, y_start, x_exit, y_exit)){
			tmp_x = x_start + 1;
			tmp_y = y_start;
			cout << tmp++ << ":" << x_start + 1 << "," << y_start << "\n";
			coordi.x = x_start + 1;
			coordi.y = y_start;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start + 1, y_start, x_exit, y_exit)) return true;
		}
		else if(haveroud(InputMaze, mark, x_start - 1, y_start, x_exit, y_exit)){
			tmp_x = x_start - 1;
			tmp_y = y_start;
			cout << tmp++ << ":" << x_start - 1 << "," << y_start << "\n";
			coordi.x = x_start - 1;
			coordi.y = y_start;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start - 1, y_start, x_exit, y_exit)) return true;
		}
		else if(haveroud(InputMaze, mark, x_start, y_start - 1, x_exit, y_exit)){
			tmp_x = x_start;
			tmp_y = y_start - 1;
			cout << tmp++ << ":" << x_start << "," << y_start - 1 << "\n";
			coordi.x = x_start;
			coordi.y = y_start - 1;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start, y_start - 1, x_exit, y_exit)) return true;
		}
		/*(x_start, y_start) is avaliable but it's nearby 4 points is not or can't reach exit point*/
		else{
			//pop out stack
			st.pop();
			return false;
		}
	}
}

int main(void){
	/*--------------setup parameter-----------------*/
	char *InputMaze[SIZE];
	int *mark[SIZE];
	for(int i = 0; i < SIZE; i++){
		InputMaze[i] = new char[SIZE];
		mark[i] = new int[SIZE];
	}
	/*open file & read data into "InputMaze" array & initialize "mark" array*/
	cout << "enter filename : ";
	char file[20];	//to record input file name
	cin >> file;
	string filename(file);	//ste filename as file
	FILE* input_file = fopen(filename.c_str(), "r");	//open the indicated file
	int c = 0;//to rcord & pass the input map
	//initialize "mark" array & InputMaze
    for (int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE + 1; j++){
			c = getc(input_file);
			InputMaze[i][j] = c;
			mark[i][j] = 0;	
			cout << InputMaze[i][j];
		}
	}
	while(1){	//do the whole process repetely
	tmp = 0;	//reset tmp when we get go through the map again
	/*----read start & exit point from command line-----*/
	cout << "enter start position : ";
	cin >> x_start >> y_start;
	tmp_x = x_start;
	tmp_y = y_start;
	/*-----if start point == (-1, -1), end the program-------*/
	if(x_start == -1 && y_start == -1){
		printf("end the code.");
		return 0;	//when input point == (-1, -1), end the program
	}
	cout << "enter exit position : ";
	cin >> x_exit >> y_exit;
	/*---------put start point into struct---------------*/
	coordi.x = x_start;
	coordi.y = y_start;
	st.push(coordi);
	/*--------reinitialize array mark------*/
	for(int i = 0; i < SIZE; i++){
		mark[i] = new int[SIZE];
	}
	/*------visit the maze------*/
	if(haveroud(InputMaze, mark, x_start, y_start, x_exit, y_exit)){
		//print out tne point that the rat on
		cout << tmp++ << ":" << x_start << "," << y_start << "\n";
		bool record;
		record = visit(InputMaze, mark, x_start, y_start, x_exit, y_exit);
		/* 1. if the rat need to go back & not reach exit point yet, 
		 *    the visit function will ended, but we still need to go ahead, 
		 *    so we use while loop to implement it
		 * 2. when record == false && stack is not empty, 
		 *    we need to run visit function again*/
		while(record == false && st.empty() == false){
			x_start = st.top().x;
			y_start = st.top().y;
			//print out tne point that the rat on
			cout << tmp++ << ":" << x_start << "," << y_start << "\n";
			record = visit(InputMaze, mark, x_start, y_start, x_exit, y_exit);
		}
	}
	//print out the result, and do while loop repetly
	if(tmp_x == x_exit && tmp_y == y_exit) cout << "succesfully escaped!!" << "\n";
	else cout << "Failed to escape." << "\n";
	while(!st.empty()){
		st.pop();
	}
	}
}
