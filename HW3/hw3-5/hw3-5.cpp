#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

queue<int> q;
int numOfVertex;
fstream OutputFile;

void bfs(int startVertex, int *adjMatrix[numOfVertex], int visited[numOfVertex], string output){
	for(int i = 0; i < numOfVertex; i++){
		if(adjMatrix[startVertex][i] != 0 && visited[i] == -1){
			q.push(i);
			visited[i] = visited[startVertex] + adjMatrix[startVertex][i];
		}
	}
	if(!q.empty()){
		//write the result into the outputfile
		//OutputFile.open(output, ios::app);
		//OutputFile << q.front() <<" ";
		//OutputFile.close();
		//------------------------------------
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
	//-------------------------

		InputFile >> numOfVertex;
		//create the adjMatrix
		int *adjMatrix[numOfVertex];
		for(int i = 0; i < numOfVertex; i++){
			adjMatrix[i] = new int[numOfVertex];
		}
		//--------------------
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
		for(int i = 0; i < numOfVertex - 1; i++){
			InputFile >> start;
			InputFile >> end;
			InputFile >> weight;
			adjMatrix[start - 1][end - 1] = weight;
			adjMatrix[end - 1][start - 1] = weight;
		}
		int startVertex;
		InputFile >> startVertex;
		q.push(startVertex);
		pathLength[startVertex - 1] = 0;
		bfs(startVertex - 1, adjMatrix, pathLength, output);
		//write the result into the output file
	for(int i = 0; i < numOfVertex; i++){
		OutputFile.open(output, ios::app);
		OutputFile << i + 1 << " " << pathLength[i] << '\n';
		OutputFile.close();
	}
		//-------------------------------------
	return 0;
}
