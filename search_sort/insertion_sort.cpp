#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int *x = new int[n];
	for(int i=0;i<n;i++)
		cin >> x[i];
	for(int i = 1;i < n;i++)     
   		for(int j = i;j > 0 && x[j-1] > x[j];j--){
			int tmp = x[j];
			x[j] = x[j-1];
			x[j-1] = tmp;  
		}
	for(int i=0;i<n;i++)
		cout << x[i] << " ";
	return 0;
}