#include <iostream> 
#include <cstdio> //getchar()
#include <algorithm> //sort()
#include <vector>
using namespace std;
/*
	is 2nd word an anagram of 1st one?
*/
int main(void)
{
	vector<char> word1;
	vector<char> word2;
	char c;
	while ((c = getchar())!= '\n')
		word1.push_back(c);
	while ((c = getchar()) != '\n')
		word2.push_back(c);
	sort(word1.begin(), word1.end());
	sort(word2.begin(), word2.end());
	for (int i = 0; i < word1.size(); ++i) {
		if (word1[i] != word2[i]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}