/*input
12
7
0 1
1 2
4 0
5 6
7 5
3 1
8 9
*/

/*~~~~~~~~~~~~~~~~~~~~dwij28 == Abhinav Jha~~~~~~~~~~~~~~~~~~~~*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
using namespace std;

template<typename T>void scan(T&x){bool n=false;register T c=getchar();x=0;if(c=='-'){n=true;c=getchar();}for(;(c>47&&c<58);c=getchar()){x=(x<<1)+(x<<3)+c-48;}if(n){x*=-1;}}
template<typename T>void allocate(T **x,T n){*x=(T*)malloc(sizeof(T)*n);}

class Graph {
	int n;
	std::vector<int> *adj;
	bool *visited;
public:
	Graph(int n);
	void add(int u, int v);
	void dfs_util(int x);
	void dfs();
};

Graph::Graph(int n) {
	this->n = n;
	adj = new std::vector<int> [n];
	visited = new bool[n];
	memset(visited, false, sizeof(visited));
}

void Graph::add(int u, int v) { // Assumes Undirected Graph
	adj[v].pb(u);
	adj[u].pb(v);
}

void Graph::dfs_util(int x) {
	printf("-->%d", x);
	visited[x] = true;
	for (int i = 0; i < adj[x].size(); i++) {
		if ( ! visited[adj[x][i]] )
			dfs_util(adj[x][i]);
	}
}

void Graph::dfs() {
	for (int i = 0; i < n; i++) {
		if ( ! visited[i] )
			dfs_util(i);
	}
}

int main() {
	int n, e, u, v;
	scanf("%d%d", &n, &e);
	Graph g(n);
	for (int i = 1; i <= e; i++) {
		scanf("%d%d", &u, &v);
		g.add(u, v);
	}
	g.dfs();
	return 0;
}
