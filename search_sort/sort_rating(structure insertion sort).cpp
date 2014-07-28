#include <iostream>
using namespace std;

int main(){
	struct rating{
		int id;
		int mark;
	};
	int n;
	cin >> n;
	rating *x = new rating[n];
	for (int i = 0; i<n; i++){
		cin >> x[i].id;
		cin >> x[i].mark;
	}
	for (int i = 1; i < n; i++)
	for (int j = i; j > 0 && x[j - 1].mark < x[j].mark; j--){
		rating tmp = x[j];
		x[j] = x[j - 1];
		x[j - 1] = tmp;
	}
	for (int i = 0; i<n; i++)
		cout << x[i].id << " " << x[i].mark<<endl;
	//system("pause");
	return 0;
}