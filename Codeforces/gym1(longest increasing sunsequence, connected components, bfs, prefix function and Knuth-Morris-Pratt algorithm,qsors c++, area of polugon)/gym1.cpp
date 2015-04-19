#include <iostream>
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <queue>
# include <string>
using namespace std;
void a();
int max(int a, int b);
void b();
void dfs(int v);
void c();
void e();
vector<int> prefix_function(string s);
void f();
int compare(const void * a, const void * b);
void G();
int main(){

	//freopen("lis.in", "r", stdin);
	//freopen("lis.out", "w", stdout);
	//a();
	//b();
	//c();
	//e();
	//f();
	G();
	system("pause");
	return 0;
}

/* Longest increasing subsequence */
void a(){
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int *d = new int[n];
	for (int i = 0; i < n; ++i) {
		d[i] = 1;
		for (int j = 0; j < i; ++j)
		if (a[j] < a[i])
			d[i] = max(d[i], 1 + d[j]);
	}

	int ans = d[0];
	for (int i = 0; i<n; ++i)
		ans = max(ans, d[i]);
	cout << ans << endl;
}
int max(int a, int b){
	return a>b ? a : b;
}

/*number of connected components*/
int n, m;
vector<vector<int>> g;
vector<char> used;
vector<int> comp;
void b(){
	cin >> n >> m;
	used.assign(n, false);
	g.resize(n);
	int a, b;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	if (!used[i]){
		dfs(i);
		res++;
	}
	cout << res << endl;
}
void dfs(int v){
	used[v] = true;
	for (vector<int>::iterator it = g[v].begin(); it != g[v].end(); it++)
	if (!used[*it])
		dfs(*it);
}
/*BFS AND SHORTEST_PATH FROM S TO F*/
void c(){
	int n, s, f;
	cin >> n >> s >> f;
	--s; --f;
	vector<vector<int>> g(n);
	int tmp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> tmp;
			if (tmp)
				g[i].push_back(j);
		}
	}
	queue<int> q;
	q.push(s);
	vector<bool> used(n);
	vector<int> d(n), p(n);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (size_t i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}
	cout << d[f] << endl;
}

/*PREFIX FUNCTION AND Knuth–Morris–Pratt algorithm*/
void e(){
	string t;
	string s;
	cin >> t >> s;
	vector<int> pi = prefix_function(s+"#"+t);
	int n = s.length();
	int m = t.length();
	vector<int> res;
	for (int i = 0; i < (n + m + 1); i++){
		if (pi[i] == n){
			res.push_back(i -2*n+1);
		}
	}
	if (!res.empty())
	for (int i : res){
		cout << i << " ";
	}
	else{
		cout << "none";
	}
	
}
vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i<n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

/*QSORT C++*/
void f(){
	int n;
	cin >> n;
	long long *a = new long long[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	qsort(a,n,sizeof(long long),compare);
	for (int i = 0; i < n; i++)
		cout << a[i]<<" ";
}
int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

/*AREA OF POLYGON*/
void G(){
	struct point{
		int x;
		int y;
	};
	int n;
	cin >> n;	
	vector<point> fig;
	int a, b;
	point tmp;
	for (int i = 0; i <n; i++){
		cin >>a >> b;
		tmp.x = a;
		tmp.y = b;
		fig.push_back(tmp);
	}
	double res = 0;
	for (unsigned i = 0; i<fig.size(); i++)
	{
		point p1 = i ? fig[i - 1] : fig.back(),	p2 = fig[i];
		res += (p1.x - p2.x) * (p1.y + p2.y);
	}
	cout << abs((double)(res/2));
}