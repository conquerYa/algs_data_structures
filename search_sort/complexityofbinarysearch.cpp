#include <iostream>
#include <cmath>
using namespace std;
/*
	the task is to find a complexity of binary search
*/
int binarySearch(int r);
int main()
{
	int n;
	cin >> n;
	cout << ceil(log2(n));
	//system("pause");
	return 0;
}

