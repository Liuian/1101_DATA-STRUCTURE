#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

queue<int> q;

int numOfVertex;
void bfs(int startVertex, int *adjMatrix[numOfVertex], int visited[numOfVertex]){
	//cout << startVertex << " ";
	//visited[startVertex] = 1;
	for(int i = 0; i < numOfVertex; i++){
		if(adjMatrix[startVertex][i] == 1 && visited[i] == 0){
			q.push(i);
			visited[i] = 1;
		}
			//bfs(i, adjMatrix, visited);
	}
	if(!q.empty()){
		cout << q.front() << " ";
		q.pop();
		bfs(q.front(), adjMatrix, visited);
	}
}

int main(){
	cout << "please type input file's name : ";
	string input;
	cin >> input;
	ifstream InputFile(input);
	if(!InputFile.is_open())
		cout << "fild open fail";
	int round;
	InputFile >> round;
	for(int i = 0; i < round; i++){
		int startVertex;
		InputFile >> numOfVertex;
		InputFile >> startVertex;
		int *adjMatrix[numOfVertex];
		for(int i = 0; i < numOfVertex; i++){
			adjMatrix[i] = new int[numOfVertex];
		}
		int visited[numOfVertex];
		for(int j = 0; j < numOfVertex; j++){
			for(int k = 0; k < numOfVertex; k++){
				InputFile >> adjMatrix[j][k];
			}
			visited[j] = 0;
		}
		q.push(startVertex);
		visited[startVertex] = 1;
		bfs(startVertex, adjMatrix, visited);
		cout << '\n';
	}
	return 0;
}
