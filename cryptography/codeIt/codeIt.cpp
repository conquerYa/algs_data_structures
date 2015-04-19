#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
int* sort(int *sorted, string key, int klen);
string decode(string code, string key, int klen, int rows, int mlen, int* sorted);
string encode(string msg, string key, int klen, int rows, int mlen, int* sorted);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string msg;
	string key;
	getline(cin, msg);
	getline(cin, key);

	int klen = key.size();
	int mlen = msg.size();
	
	int* sorted = new int[klen];
	for (int i = 0; i < klen; i++) {
		sorted[i] = i;
	}
	sorted = sort(sorted, key, klen);

	int rows = mlen / klen;
	double drows = ((double)mlen / (double)klen);
	rows = ((double)drows > (double)rows) ? rows+1 : rows;

	string code = encode(msg, key, klen, rows, mlen, sorted);
	cout << code<<endl;
	cout<<decode(code, key, klen, rows, mlen, sorted)<<endl;
	system("pause");
	return 0;
}

string encode(string msg, string key, int klen, int rows, int mlen, int* sorted) {
	string code = "";

	char *arr = new char[rows*klen];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < klen; j++) {
			int pos = i * klen + j;
			if (pos < mlen) {
				arr[i*klen+j] = msg[pos];
			}
			else {
				arr[i*klen + j] = ' ';
			}
		}
	}
	for (int i = 0; i < klen; i++) {
		for (int j = 0; j < rows; j++) {
			code += arr[j*klen+sorted[i]];
		}
	}

	return code;
}

string decode(string code,string key, int klen, int rows, int mlen, int* sorted) {
	string msg = "";

	char* arr = new char[rows*klen];
	int c = 0;
	for (int i = 0; i < klen; i++) {
		for (int j = 0; j < rows; j++) {
			arr[j*klen+sorted[i]] = code[c++];
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < klen; j++) {
			msg += arr[i*klen+j];
		}
	}
	return msg;
}


 int* sort(int *sorted, string key, int klen) {
		int temp;
		char tmp;
		for (int i = 1; i < klen; i++) {
			for (int j = i; j > 0; j--) {
				if (key[j] < key[j - 1]) {
					temp = sorted[j];
					sorted[j] = sorted[j - 1];
					sorted[j - 1] = temp;
					tmp = key[j];
					key[j] = key[j - 1];
					key[j - 1] = tmp;
				}
			}
		}
		return sorted;
	}



