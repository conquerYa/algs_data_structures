/*
bignum arithmetic, the number may consist of 255 bits
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
	char num[256];
	gets(num);
	int sum = 0;
	for (int i = 0; i < strlen(num); i++){
		sum += num[i];
	}
	if (sum % 3)
		cout << "NO";
	else
		cout << "YES";
	//system("pause");
	return 0;
}
