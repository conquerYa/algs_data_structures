#include <iostream>
#include <cmath>
using namespace std;
/*
	entry array is sorted
	closest binary search
	0 < N, K < 100001
*/
int binarySearch(int a[], int v, int l, int r);
int main()
{
	int n, k;
	cin >> n;
	cin >> k;
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int tmp = 0;
	for (int i = 0; i < k; i++){
		cin >> tmp;
		if(binarySearch(arr, tmp, 0, n - 1)>=0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	//system("pause");
	return 0;
}

int binarySearch(int a[], int v, int l, int r){
	while(l<=r){
		int m = (l+r)/2;
		if(a[m]==v)
			return m;
		else if(a[m]<v)	
			l =  m + 1;
		else
			r = m - 1;
	}
	return -1;
}