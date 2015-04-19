#include <iostream>
#include <algorithm>

using namespace std;

void print(int q,int* u,int* v);
int main()
{
	int a, n, q=0;
	cout << "Enter n, a" << endl;
	cin >> n >> a;
	int u[3] = {0,1,n};
	int v[3] = { 1, 0, a };
	int* t = new int[3];
	while (u[2] != 1){
		print(q,u,v);
		q = u[2] / v[2];
		for (int i = 0; i < 3; i++){
			t[i] = u[i] - v[i] * q;
		}
		for (int i = 0; i < 3; i++){
			u[i] = v[i];
			v[i] = t[i];
		}
	}
	print(q, u, v);
	if (u[0] < 0) u[0] += n;
	cout <<(u[0] % n)<<endl;
	system("pause");
	return 0;
}

void print(int q, int* u, int* v){
	cout << q << " ";
	for (int i = 0; i < 3; i++){
		cout << u[i] << " ";
	}
	for (int i = 0; i < 3; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}
