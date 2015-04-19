#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <vector>

using namespace std;


int find_item(vector<char> arr, char item);
string encode(vector<char> arr, string msg, int mlen);
string decode(vector<char> arr, string msg, int mlen);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string msg;
	string key;
	cin >> msg;
	cin >> key;

	int mlen = msg.size();
	int klen = key.size();

	vector<char> arr;
	string alph = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
	arr.push_back(key[0]);
	bool tr = true;
	for (int i = 1; i < klen + 32; i++){
		char tmp = i<klen ? key[i] : alph[i - klen];
		for (int j = 0; j < arr.size(); j++){
			if (tmp == arr[j]){
				tr = false;
			}
		}
		if (tr)
			arr.push_back(tmp);
		else
			tr = true;
	}
	string code = encode(arr, msg, mlen);
	cout << code << endl;
	cout << decode(arr, code, mlen)<<endl;

	system("pause");
	return 0;
}

int find_item(vector<char> arr, char item)
{
	for (int i = 0; i < arr.size(); i++){
		if (item == arr[i])
			return i;
	}
	return 0;
}

string encode(vector<char> arr, string msg, int mlen){
	char bigram[2];
	string res="";
	int f, s, fi, fj, si, sj;
	for (int i = 0; i < mlen; i += 2){
		if (i == (mlen - 1)){
			bigram[0] = msg[i];
			bigram[1] = 'ь';
		}
		else if (msg[i] == msg[i + 1]){
			bigram[0] = msg[i];
			bigram[1] = 'ь';
		}
		else{
			bigram[0] = msg[i];
			bigram[1] = msg[i + 1];
		}

		f = find_item(arr, bigram[0]);
		s = find_item(arr, bigram[1]);

		fi = f / 8;
		fj = f - 8 * fi;
		si = s / 8;
		sj = s - 8 * si;

		if (fi == si){//одинаковая строка
			bigram[0] = fj<7 ? arr[fi * 8 + fj + 1] : arr[fi * 8];
			bigram[1] = sj<7 ? arr[fi * 8 + sj + 1] : arr[fi * 8];
		}
		else if (fj == sj){//одинаковый столбец
			bigram[0] = fi<3 ? arr[(fi + 1) * 8 + fj] : arr[fj];
			bigram[1] = si<3 ? arr[(fi + 1) * 8 + sj] : arr[sj];
		}
		else{//разные строки,столбцы
			bigram[0] = arr[fi * 8 + sj];
			bigram[1] = arr[si * 8 + fj];
		}
		res+=bigram[0];
		res+=bigram[1];
	}
	return res;
}
string decode(vector<char> arr, string msg, int mlen){
	char bigram[2];
	string res = "";
	int f, s, fi, fj, si, sj;
	for (int i = 0; i < mlen; i += 2){

		bigram[0] = msg[i];
		bigram[1] = msg[i + 1];

		f = find_item(arr, bigram[0]);
		s = find_item(arr, bigram[1]);

		fi = f / 8;
		fj = f - 8 * fi;
		si = s / 8;
		sj = s - 8 * si;

		if (fi == si){//одинаковая строка
			bigram[0] = fj>1 ? arr[fi * 8 + fj - 1] : arr[fi * 8+7];
			bigram[1] = sj>1 ? arr[fi * 8 + sj - 1] : arr[fi * 8+7];
		}
		else if (fj == sj){//одинаковый столбец
			bigram[0] = fi>1 ? arr[(fi - 1) * 8 + fj] : arr[fj+3*fi];
			bigram[1] = si>1 ? arr[(fi - 1) * 8 + sj] : arr[sj+3*fi];
		}
		else{//разные строки,столбцы
			bigram[0] = arr[fi * 8 + sj];
			bigram[1] = arr[si * 8 + fj];
		}
		res += bigram[0];
		res += bigram[1];
	}
	return res;
}
