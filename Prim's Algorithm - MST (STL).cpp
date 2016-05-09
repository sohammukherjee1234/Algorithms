/*input
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
	std::vector< pair<int, int> > *adj;
public:
	Graph(int n);
	void add(int u, int v, int w);
	int prim(int src);
};

Graph::Graph(int n) {
	this->n = n;
	adj = new std::vector< pair<int, int> > [n];
}

void Graph::add(int u, int v, int w) {
	adj[v].pb(mp(u, w));
	adj[u].pb(mp(v, w));
}

int Graph::prim(int src) {
	// Min Heap Priority Queue of pairs used with weight as first and vertex as second in pair (as priority_queue for pairs use first for comparison by default)
	priority_queue< pair<int, int>, std::vector< pair <int, int> >, greater< pair<int, int> > > pq;
	std::vector<int> key(n, INT_MAX); // stores minimum weight to reach each vertex
	std::vector<int> parent(n, -1); // stores vertex from which edge is incident with minimum weight for each vertex
	std::vector<bool> inMST(n, false); // check if a vertex has already been covered in MST
	pq.push(mp(0, src));
	key[src] = 0; // To reach source vertex, minimum weight = 0
	while ( ! pq.empty() ) {
		int u = pq.top().second;
		pq.pop();
		inMST[u] = true;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if ( ! inMST[v] && key[v] > w) {
				key[v] = w;
				pq.push(mp(w, v));
				parent[v] = u;
			}
		}
	}

	/* Print All Edges in the final MST
	for (int i = 0; i < n; i++) {
		if (i != src)
			printf("%d - %d\n", parent[i], i);
	}
	*/

	int min_weight = 0;
	for (int i = 0; i < n; i++)
		min_weight += key[i];
	return min_weight;
}

int main() {
	int n = 9;
    Graph g(n);
    g.add(0, 1, 4);
    g.add(0, 7, 8);
    g.add(1, 2, 8);
    g.add(1, 7, 11);
    g.add(2, 3, 7);
    g.add(2, 8, 2);
    g.add(2, 5, 4);
    g.add(3, 4, 9);
    g.add(3, 5, 14);
    g.add(4, 5, 10);
    g.add(5, 6, 2);
    g.add(6, 7, 1);
    g.add(6, 8, 6);
    g.add(7, 8, 7);
    printf("MST Weight = %d\n", g.prim(0));
	return 0;
}
