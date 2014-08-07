#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct pupil{
	int cls;
	string name;
};
bool operator<(const pupil& a, const pupil& b){
	return a.cls < b.cls;
}
int main(){
	vector<pupil> pupils;
	int cls;
	string name;
	while (cin>>cls>>name){
		pupils.push_back({ cls, name });
	}
	sort(pupils.begin(), pupils.end());

	for (int i = 0; i<pupils.size(); i++)
		cout << pupils[i].cls << " " << pupils[i].name<< endl;
	//system("pause");
	return 0;
}
