#include <stdio.h>
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node  //作為資料結構儲存圖
{
	int start;
	int end;
	int length;
};
bool compare(Node a, Node b)
{
	return a.length < b.length;
}
void Kruskal(vector<Node> &arr, vector<bool> &visited)
{
	int M, N;
	M = visited.size();
	N = arr.size();
	sort(arr.begin(), arr.end(), compare);
	int weight = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[arr[i].start] || !visited[arr[i].end])
		{
			weight += arr[i].length;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
		}
	}
	cout << "最小生成樹權值為:";
	cout << weight << endl;
}
int main(){
	cout << "please type input file's name : ";
	string input;
	cin >> input;
	ifstream InputFile(input);
	if(!InputFile.is_open())
		cout << "fild open fail";
	int vertix;
	int edge;
	InputFile >> vertix;
	InputFile >> edge;
	vector<Node> arr(edge);
	vector<bool> visited(vertix);
	for (int i = 0; i < edge; i++)
	{
		InputFile >> arr[i].start >> arr[i].end >> arr[i].length;
		//cin >> arr[i].start >> arr[i].end >> arr[i].length;
	}
	Kruskal(arr,visited);
	return 0;
}
/*
#include<iostream>
using namespace std;
int main()
{
	int M,N;
	cin>>M>> N;
	vector<Node> arr(N);
	vector<bool> visited(M);
	Kruskal(arr,visited);
}
*/
