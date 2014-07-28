#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int *x = new int[n];
	for(int i=0;i<n;i++)
		cin >> x[i];
	for(int i=0; i<n; i++)
   		 for(int j=i+1; j<n; j++)
   		 if(x[j]<x[i]){
			int tmp = x[j];
			x[j] = x[i];
			x[i] = tmp;  
		}
	for(int i=0;i<n;i++)
		cout << x[i] << " ";
	return 0;
}