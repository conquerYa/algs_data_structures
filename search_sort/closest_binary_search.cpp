//#include <iostream>
//#include <cmath>
//using namespace std;
///*
//	closest binary search
//	0 < N, K < 100001
//*/
//int closestBinarySearch(int a[], int v, int l, int r);
//int main()
//{
//	int n, k;
//	cin >> n;
//	cin >> k;
//	int *arr = new int[n];
//	for (int i = 0; i < n; i++){
//		cin >> arr[i];
//	}
//	int tmp = 0;
//	for (int i = 0; i < k; i++){
//		cin >> tmp;
//		cout << arr[closestBinarySearch(arr, tmp, 0, n - 1)]<<endl;
//	}
//	//system("pause");
//	return 0;
//}
//
//int closestBinarySearch(int a[], int v, int l, int r){
//	for (int i = 0; i < 100; ++i) {
//		int m = (r + l) / 2;
//		if (a[m] > v)
//			r = m;
//		else
//			l = m;
//	}
//	if (l != r)
//		return (abs(a[r] - v) < abs(a[l] - v) ? r : l);
//	return l;
//}