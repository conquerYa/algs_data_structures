#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int n, l;
vector < vector<int> > g;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (size_t i = 0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			dfs(to, v);
	}
	tout[v] = ++timer;
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
	if (upper(a, b))  return a;
	if (upper(b, a))  return b;
	for (int i = l; i >= 0; --i)
	if (!upper(up[a][i], b))
		a = up[a][i];
	return up[a][0];
}

int main() {
	string s = "";
	cin >> n;
	g.resize(n);
	int r;
	int tmp;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		if (tmp)
			g[tmp - 1].push_back(i);
		else
			r = i;

	}
	tin.resize(n), tout.resize(n), up.resize(n);
	l = 1;
	while ((1 << l) <= n)  ++l;
	for (int i = 0; i<n; ++i)  up[i].resize(l + 1);
	dfs(r);
	int m;
	cin >> m;
	for (int i = 0; i<m; i++) {
		int a, b; // текущий запрос
		cin >> a >> b;
		--a; --b;
		int res = lca(a, b); // ответ на запрос
		if (res == a)
			s += "1\n";
		else
			s += "0\n";
	}
	cout << s;

}