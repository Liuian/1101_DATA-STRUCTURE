#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

//use these variable in the funvtion, so we set these as global variable
queue<int> q;
int numOfVertex;
fstream OutputFile;

void bfs(int startVertex, int *adjMatrix[numOfVertex], int visited[numOfVertex], string output){
	for(int i = 0; i < numOfVertex; i++){
		if(adjMatrix[startVertex][i] != 0 && visited[i] == -1){
			q.push(i);
			//if this vertex connect to another never visited vertex, add the weight into recorded weight
			visited[i] = visited[startVertex] + adjMatrix[startVertex][i];
		}
	}
	if(!q.empty()){
		q.pop();
		bfs(q.front(), adjMatrix, visited, output);
	}
}

int main(){
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
	InputFile >> numOfVertex;
	//create the adjMatrix to record the weight between two vertex
	int *adjMatrix[numOfVertex];
	for(int i = 0; i < numOfVertex; i++){
		adjMatrix[i] = new int[numOfVertex];
	}
	//create an array - pathLength to record the shortest path's weight(-1 : no path to this vertex from the start vertex)
	int pathLength[numOfVertex];
	for(int j = 0; j < numOfVertex; j++){
		for(int k = 0; k < numOfVertex; k++){
			adjMatrix[j][k] = 0;
		}
		pathLength[j] = -1;
	}
	int start;
	int end;
	int weight;
	//read the weight into the adj matrix
	for(int i = 0; i < numOfVertex - 1; i++){
		InputFile >> start;
		InputFile >> end;
		InputFile >> weight;
		adjMatrix[start - 1][end - 1] = weight;
		adjMatrix[end - 1][start - 1] = weight;
	}
	int startVertex;
	InputFile >> startVertex;
	//push the start vertex into the queue and atart the function
	q.push(startVertex);
	//set path length of start vertex as 0
	pathLength[startVertex - 1] = 0;
	//do bfs function
	bfs(startVertex - 1, adjMatrix, pathLength, output);
	//write the result into the output file
	for(int i = 0; i < numOfVertex; i++){
		OutputFile.open(output, ios::app);
		OutputFile << i + 1 << " " << pathLength[i] << '\n';
		OutputFile.close();
	}
	return 0;
}
