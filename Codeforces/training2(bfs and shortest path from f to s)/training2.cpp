
#include <iostream>
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <queue>
# include <set>
using namespace std;
void a();
void bfs_shortest_path(vector<vector<int>> g, int n, int s, int to);
void d();
int cost(int a, int b);
int main(){

	//freopen("bfs.in", "r", stdin);
	//freopen("bfs.out", "w", stdout);
	a();
	//d();
	system("pause");
	return 0;
}

void a(){
	int n, s, f;
	cin >> n >> s >> f;
	s--;
	f--;
	vector<vector<int>> g(n);
	int tmp;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++){
		cin >> tmp;
		if (tmp)
			g[i].push_back(j);
	}
	bfs_shortest_path(g, n, s, f);
}
/*BFS g and shortest path from s to f*/
void bfs_shortest_path(vector<vector<int>> g, int n, int s, int to){
	vector<char> used(n);
	vector<int> d(n), p(n);
	queue<int> q;
	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}
	if (!used[to])
		//cout << "No path!";
		cout << 0;
	else {
		int tmp = 0;
		for (int v = to; v != -1; v = p[v])
			tmp++;
		cout << --tmp;
		/*
		vector<int> path;
		for (int v = to; v != -1; v = p[v])
		path.push_back(v);
		reverse(path.begin(), path.end());
		cout << "Path: ";
		for (size_t i = 0; i<path.size(); ++i)
		cout << path[i] + 1 << " ";
		*/
	}
}

void d(){
	// входные данные
	int n, m, a, b;
	cin >> n >> m;
	vector <vector <int>> g(n);
	const int INF = 10;
	int *owner = new int[n];
	for (int i = 0; i < n; i++){
		cin >> owner[i];
	}
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
	}
	
}
int cost(int a, int b){
	if (a == b) return 0;
	else{
		if (!(a % 2)) return 2;
		else return 1;
	}
}