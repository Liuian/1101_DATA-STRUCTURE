// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

#define edge pair<int, int>

using namespace std;
fstream OutputFile;

class Graph{
  public:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print(string output);
};

//cerare the functions that we needed
Graph::Graph(int V){
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;
  G.clear();
  T.clear();
}

void Graph::AddWeightedEdge(int u, int v, int w){
  G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i){
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v){
  parent[u] = parent[v];
}

void Graph::kruskal(){
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {	//check weather it will gengrate a cycle or not when the edge selected
      T.push_back(G[i]);  // if not, add to tree
      union_set(uRep, vRep);	//mark the end as the 
    }
  }
}

//add all the selected edgs weight and print
void Graph::print(string output){
  int sum = 0;
  for (int i = 0; i < T.size(); i++) {
	sum = sum + T[i].first;
  }
	OutputFile.open(output, ios::app);
	OutputFile << sum  <<" ";
	OutputFile.close();
}

int main(){
	//open the indicated file
	cout << "please type input file's name : ";
	string input;
	cin >> input;
	ifstream InputFile(input);
	if(!InputFile.is_open())
		cout << "fild open fail";
	//create output file
	string output = "out";
	int length = input.length();
	output.append(input, 2, length - 2);
	OutputFile.open(output, ios::out);
	OutputFile.close();
	int v;
	int e;
	InputFile >> v >> e;
	Graph g(v);
	//build the graph
	for(int i = 0; i < e; i++){
		int start;
		int end;
		int weight;
		InputFile >> start >> end >> weight;
		g.AddWeightedEdge(start, end, weight);
	}
  //do kruskl algorithm
  g.kruskal();
  //print the result
  g.print(output);
  return 0;
}
