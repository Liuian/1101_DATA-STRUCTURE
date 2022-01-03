#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

//we need to use these two variable in the function, so set these as goble variable
int numOfVertex;
fstream OutputFile;

//do deepth first search
void dfs(int startVertex, int *adjMatrix[numOfVertex], int visited[numOfVertex], string output){
	//print the startvertex
	OutputFile.open(output, ios::app);
	OutputFile << startVertex << " ";
	OutputFile.close();
	//record that we ever went to startvertex
	visited[startVertex] = 1;
	//when we find the smallest point connected to startvertex && we never visit it, do dfs recursively
	for(int i = 0; i < numOfVertex; i++){
		if(adjMatrix[startVertex][i] == 1 && visited[i] == 0)
			dfs(i, adjMatrix, visited, output);
	}
}

int main(){
	//open the input file
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
		//create adj matrix to record if there is a path between two vertex
		int *adjMatrix[numOfVertex];
		for(int i = 0; i < numOfVertex; i++){
			adjMatrix[i] = new int[numOfVertex];
		}
		//create an array to record weather we visited the vertex or not(0 : never visited, 1 : visited)
		int visited[numOfVertex];
		for(int j = 0; j < numOfVertex; j++){
			for(int k = 0; k < numOfVertex; k++){
				//read the adjmatrix
				InputFile >> adjMatrix[j][k];
			}
			visited[j] = 0;
		}
		//do the deepth first search recrusively
		dfs(startVertex, adjMatrix, visited, output);
		OutputFile.open(output, ios::app);
		OutputFile << '\n';
		OutputFile.close();
		//cout << '\n';
	}
	return 0;
}
