#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;


int find_item(vector<char> arr, char item);
string shuffle(string array, int n);
string decode(vector<char> arr1, vector<char> arr2, string msg);
string encode(vector<char> arr1, vector<char> arr2, string msg, int mlen);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string msg;
	getline(cin, msg);
	int mlen = msg.size();

	vector<char> arr1;
	vector<char> arr2;
	string alphs = "абвгдежзийклмнопрстуфхцчшщъыьэюя .,";//7x5
	alphs = shuffle(alphs, 35);
	for (int i = 0; i < 35; i++){
		arr1.push_back(alphs[i]);
	}

	alphs = shuffle(alphs, 35);
	for (int i = 0; i < 35; i++){
		arr2.push_back(alphs[i]);
	}

	cout << endl;
	for (int i = 0; i < 35; i++){
		if (!(i % 5) && i>0){
			cout << " ";
			for (int j = i - 5; j < i; j++){
				cout << arr2[j] << " ";
			}
			cout << endl;
		}
		cout << arr1[i]<<" ";
	}
	cout << " ";
	for (int j = 30; j < 35; j++){
		cout << arr2[j] << " ";
	}
	cout << endl;
	cout << endl;

	string code = encode(arr1,arr2, msg, mlen);
	cout << code << endl << endl;
	cout << decode(arr1, arr2, code) << endl;

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

string shuffle(string array, int n)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(array.begin(), array.end(), std::default_random_engine(seed));
	return array;
}

string encode(vector<char> arr1, vector<char> arr2, string msg, int mlen){
	char bigram[2];
	string res = "";
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

		f = find_item(arr1, bigram[0]);
		s = find_item(arr2, bigram[1]);

		fi = f / 5;
		fj = f - 5 * fi;
		si = s / 5;
		sj = s - 5 * si;

		if (fi == si){//одинаковая строка
			bigram[0] = arr2[fi * 5 + fj];
			bigram[1] = arr1[si * 5 + sj];
		}
		else{//разные строки,столбцы
			bigram[0] = arr2[fi * 5 + sj];
			bigram[1] = arr1[si * 5 + fj];
		}
		res += bigram[0];
		res += bigram[1];
	}
	return res;
}

string decode(vector<char> arr1, vector<char> arr2, string msg){
	char bigram[2];
	string res = "";
	int f, s, fi, fj, si, sj;
	for (int i = 0; i < msg.size(); i += 2){

		bigram[0] = msg[i];
		bigram[1] = msg[i + 1];

		f = find_item(arr2, bigram[0]);
		s = find_item(arr1, bigram[1]);

		fi = f / 5;
		fj = f - 5 * fi;
		si = s / 5;
		sj = s - 5 * si;

		if (fi == si){//одинаковая строка
			bigram[0] = arr1[si * 5 + fj];
			bigram[1] = arr2[si * 5 + sj];
		}
		else{//разные строки,столбцы
			bigram[0] = arr1[fi * 5 + sj];
			bigram[1] = arr2[si * 5 + fj];
		}
		res += bigram[0];
		res += bigram[1];
	}
	return res;
}