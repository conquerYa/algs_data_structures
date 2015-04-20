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


bool comp(int i, int j) { return (i>j); }
void print(vector<int> p){
	for (int i : p)
		cout << i << " ";
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		p[i] = i + 1;
	print(p);
	int a = 0, b;
	int ai, bi;
	for (;;){
		for (int i = n - 2; i>=0; i--){
			if (p[i] < p[i + 1]){
				a = p[i];
				ai = i;
				break;
			}
		}
		if (a == 0) {
			break;
		}
		for (int i = n - 1; i>=0; i--){
			if (p[i] > a){
				b = p[i];
				bi = i;
				break;
			}
		}
		iter_swap(p.begin() + ai, p.begin() + bi);
		sort(p.begin() + ai+1, p.end());
		print(p);
		a = 0;
	}
	return 0;
}
