#include <iostream>
#include <cmath>
using namespace std;
/*
	the task is to add element in i position and move right elements
*/
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int max = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int v,k;
	cin >> v;
	cin >> k;
	int *b = new int[n+1];
	for (int i = 0; i<k-1; i++){
		b[i] = a[i];
	}
	b[k - 1] = v;
	for(int i=k;i<=n;i++){
		b[i] = a[i - 1];
	}
	for(int i=0;i<=n;i++){
		cout << b[i]<<" ";
	}	
	//system("pause");
	return 0;
}

