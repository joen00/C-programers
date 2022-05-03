#include<iostream>
#include <string>
#include <vector>

using namespace std;

void make_string(int k, string s) {
	string arr[1000];

	int flag = 0;
	int j = 0;

	while(1) {
		if (j >= s.length() - 1)break;
		if (flag % 2 == 0) {
			for (int i = 0; i < k; i++) {
				if (j == s.length())break;
				arr[i] = arr[i] + s[j];
				j++;
			}
		}
		else {
			for (int i = k - 1; i >= 0; i--) {
				if (j == s.length())break;
				arr[i] = arr[i] + s[j];
				j++;
			}
		}
		flag++;
	}
	for (int i = 0; i < k; i++) {
		cout << arr[i];
	}
	cout << endl;
	return;
}


int main()
{
	int T, K;
	string S;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> S >> K;
		make_string(K, S);
	}



	return 0;
}