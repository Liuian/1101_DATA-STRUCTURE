#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <stack>

using namespace std;

int SIZE = 17;
int tmp = 0;
int x_start, y_start, x_exit, y_exit, tmp_x, tmp_y;

struct coordinate{
	int x;
	int y;
}coordi;
stack<coordinate>st;

bool haveroud(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit){
	coordi.x = x_start;
	coordi.y = y_start;
	/*1.//check the start an d exit point are in the maze
	 *2.if the start point or exit point is wall, return false
	 *4.//if we already went throuth the input point, returm false*/
	if(!(x_start >= 1 && x_start <= 15 && x_exit >= 1 && x_exit <= 15 && y_start >= 1 && y_start <= 15 && y_exit >= 1 && y_exit <= 15)) return false;
	else if(InputMaze[x_start][y_start] == '1' || InputMaze[x_exit][y_exit] == '1') return false;
	else if(mark[x_start][y_start] == 1) return false;
	else return true;
}

bool visit(char *InputMaze[17], int *mark[17], int x_start, int y_start, int x_exit, int y_exit){
	if(x_start == x_exit && y_start == y_exit){
		mark[x_start][y_start] = 1;
		return true;
	}
	else{	//else search next point
		mark[x_start][y_start] = 1;
		if(haveroud(InputMaze, mark, x_start, y_start + 1, x_exit, y_exit)/*(x, y + 1) 是可以走過去的 */){
			tmp_x = x_start;
			tmp_y = y_start + 1;
			//印出位置
			cout << tmp++ << ":" << x_start << "," << y_start + 1 << "\n";
			//推進stack...
			coordi.x = x_start;
			coordi.y = y_start + 1;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start, y_start + 1, x_exit, y_exit)) return true;
		}
		else if(haveroud(InputMaze, mark, x_start + 1, y_start, x_exit, y_exit)/*(x, y + 1) 是可以走過去的 */){
			tmp_x = x_start + 1;
			tmp_y = y_start;
			//印出位置
			cout << tmp++ << ":" << x_start + 1 << "," << y_start << "\n";
			//推進stack...
			coordi.x = x_start + 1;
			coordi.y = y_start;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start + 1, y_start, x_exit, y_exit)) return true;
		}
		else if(haveroud(InputMaze, mark, x_start, y_start - 1, x_exit, y_exit)/*(x, y + 1) 是可以走過去的 */){
			tmp_x = x_start;
			tmp_y = y_start - 1;
			//印出位置
			cout << tmp++ << ":" << x_start << "," << y_start - 1 << "\n";
			//推進stack...
			coordi.x = x_start;
			coordi.y = y_start - 1;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start, y_start - 1, x_exit, y_exit)) return true;
		}
		else if(haveroud(InputMaze, mark, x_start - 1, y_start, x_exit, y_exit)/*(x, y + 1) 是可以走過去的 */){
			tmp_x = x_start - 1;
			tmp_y = y_start;
			//印出位置
			cout << tmp++ << ":" << x_start - 1 << "," << y_start << "\n";
			//推進stack...
			coordi.x = x_start - 1;
			coordi.y = y_start;
			st.push(coordi);
			if(visit(InputMaze, mark, x_start - 1, y_start, x_exit, y_exit)) return true;
		}
		else{//這個位置是可以走過去的，但它四周的位置都不能走了
			//拉出stack..
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
	/*read data into "InputMaze" array & initialize "mark" array*/
	cout << "enter filename : ";
	char file[20];
	cin >> file;
	string filename(file);
	FILE* input_file = fopen(filename.c_str(), "r");
	int c = 0;
    for (int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE + 1; j++){
			c = getc(input_file);
			InputMaze[i][j] = c;
			mark[i][j] = 0;
			cout << InputMaze[i][j];
		}
	}
	while(1){	//do the whole process repetely
	tmp = 0;
	/*----read start & exit point from command line-----*/
	cout << "enter start position : ";
	cin >> x_start >> y_start;
	tmp_x = x_start;
	tmp_y = y_start;
	if(x_start == -1 && y_start == -1){
		printf("end the code.");
		return 0;	//when input point == (-1, -1), end the program
	}
	cout << "enter exit position : ";
	cin >> x_exit >> y_exit;
	/*-----------------------------*/
	coordi.x = x_start;
	coordi.y = y_start;
	st.push(coordi);
	/*--------reinitialize array mark------*/
	for(int i = 0; i < SIZE; i++){
		mark[i] = new int[SIZE];
	}
	/*------visit the maze------*/
	if(haveroud(InputMaze, mark, x_start, y_start, x_exit, y_exit)){
		//印出位置
		cout << tmp++ << ":" << x_start << "," << y_start << "\n";
		bool record;
		record = visit(InputMaze, mark, x_start, y_start, x_exit, y_exit);
		while(record == false && st.empty() == false){
			x_start = st.top().x;
			y_start = st.top().y;
			//印出
			cout << tmp++ << ":" << x_start << "," << y_start << "\n";
			record = visit(InputMaze, mark, x_start, y_start, x_exit, y_exit);
		}
	}
	//cout << tmp_x << tmp_y << "\n";
	if(tmp_x == x_exit && tmp_y == y_exit) cout << "succesfully escaped!!" << "\n";
	else cout << "Failed to escape." << "\n";
	}
}

//questions
//1. ok 會不會有起點跟終點同一個的狀況（起點就是終點，不用考慮）
//2. ok 走過的路可以再走嗎？（應該是不行）
//to complete
//1. ok 可以重複做
//2. 把路徑放進stack
//3. ok load file from command line
//		set string with no length
//cout << tmp++ << ":" << x_start << ", " << y_start << "+" << "\n";
//ref program design L.12
