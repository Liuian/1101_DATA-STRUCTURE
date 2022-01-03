#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

//these three variable will be used in the function, so we set the variables as gobal variable
queue<int> q;
int numOfVertex;
fstream OutputFile;

void bfs(int startVertex, int *adjMatrix[numOfVertex], int visited[numOfVertex], string output){
	for(int i = 0; i < numOfVertex; i++){
		//find the smallest vertex (i) that connect to the start vertex, and check if that vertex isn't visited yet
		if(adjMatrix[startVertex][i] == 1 && visited[i] == 0){
			//put vertex i into the queue and mark i as visited
			q.push(i);
			visited[i] = 1;
		}
	}
	//when queue is not empty, the function do NOT finish yet
	if(!q.empty()){
		//output the first vertex and pop out that vertex
		OutputFile.open(output, ios::app);
		OutputFile << q.front() <<" ";
		OutputFile.close();
		q.pop();
		//set first vertex in the queue as startvertex and do bfs function recursively
		bfs(q.front(), adjMatrix, visited, output);
	}
}

int main(){
	//open the indicated file
	cout << "please type input file's name : ";
	string input;
	cin >> input;
	ifstream InputFile(input);
	if(!InputFile.is_open())
		cout << "fild open fail";
	//create output's filename
	string output = "out";
	int length = input.length();
	output.append(input, 2, length - 2);
	OutputFile.open(output, ios::out);
	OutputFile.close();
	int round;
	InputFile >> round;
	for(int i = 0; i < round; i++){
		int startVertex;
		InputFile >> numOfVertex;
		InputFile >> startVertex;
		//create the adjmatrix to record if the path exist between two vertex
		int *adjMatrix[numOfVertex];
		for(int i = 0; i < numOfVertex; i++){
			adjMatrix[i] = new int[numOfVertex];
		}
		//create an array visited to record if we visite the vertex yet(0 : didn't visited 1 : visited)
		int visited[numOfVertex];
		for(int j = 0; j < numOfVertex; j++){
			for(int k = 0; k < numOfVertex; k++){
				//read the adjmatrix
				InputFile >> adjMatrix[j][k];
			}
			visited[j] = 0;
		}
		//push the start vertex into the queue
		q.push(startVertex);
		//mark start vertex as visited
		visited[startVertex] = 1;
		//di the bfs function
		bfs(startVertex, adjMatrix, visited, output);
		OutputFile.open(output, ios::app);
		OutputFile << '\n';
		OutputFile.close();
		//cout << '\n';
	}
	return 0;
}
