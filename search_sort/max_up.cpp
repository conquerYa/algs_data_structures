#include <iostream>
#include <cmath>
using namespace std;
/*
	the task is to swap max element with first element
*/
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int max = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]>a[max])
			max = i;
	}
	int tmp = a[0];
	a[0] = a[max];
	a[max] = tmp;
	for(int i=0;i<n;i++){
		cout << a[i]<<" ";
	}	
	//system("pause");
	return 0;
}

