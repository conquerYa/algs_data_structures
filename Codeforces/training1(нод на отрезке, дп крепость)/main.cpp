#include <iostream>
#include <vector>
using namespace std;
void a();
void b();
void c();
int gcd(int a, int b);
void build(int *a, int v, int l, int r);
int min(int a, int b);
int max(int a, int b);
int getGCD(int v, int tl, int tr, int l, int r);

int main(){
	//a();
	b();
	//c();
	system("pause");
	return 0;
}

/*
НОД НА ОТРЕЗКЕ с помощью дерева отрезков
GCD on SEGMENT
*/

int *tree;
void c(){
	int n, m;
	cin >> n >> m;
	int *a = new int[n];
	int *res = new int[m];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	tree = new int[4 * n];
	build(a, 1, 0, n - 1);
	int l, r;
	for (int i = 0; i < m; i++){
		cin >> l >> r;
		l--;
		r--;
		res[i] = getGCD(1, 0, n - 1, l, r);
	}
	for (int i = 0; i < m; i++){
		cout << res[i] << endl;
	}
}
void build(int *a, int v, int tl, int tr) {
	if (tl == tr)
		tree[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		tree[v] = gcd(tree[v * 2],tree[v * 2 + 1]);
	}
}
int getGCD(int v, int tl, int tr, int l, int r){
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return tree[v];
	int tm = (tl + tr) / 2;
	return gcd(getGCD(v * 2, tl, tm, l, min(r, tm)),getGCD(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int min(int a, int b){
	return a > b ? b : a;
}
int max(int a, int b){
	return a > b ? a : b;
}

/*Задача на перебор сочетаний*/

void b(){
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i + 1;

}

/*ДП. задача крепость*/

void a(){
	int n;
	cin >> n;
	vector<long long> dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++){
		int j = i - 1;
		while (j >= 0){
			dp[i] += dp[j];
			j -= 2;
		}
	}
	cout << dp[n];
}
