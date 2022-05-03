#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void block(int N) {

	int a;
	vector<int> arr;
	int MAX = -21e8;
	int MIN = 21e8;

	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;
			arr.push_back(b);
			if (b > MAX) {
				MAX = b;
			}
			if (b < MIN) {
				MIN = b;
			}
			cout << MIN << " " << MAX << endl;
		}
		else {
			int t = arr[arr.size() - 1];
			arr.erase(arr.begin() + arr.size() - 1);
			if (t == MAX) {
				MAX = -21e8;
				for (int j = 0; j < arr.size(); j++) {
					if (arr[j] > MAX) {
						MAX = arr[j];
					}
				}
			}
			else if (t == MIN) {
				MIN = 21e8;
				for (int j = 0; j < arr.size(); j++) {
					if (arr[j] < MIN) {
						MIN = arr[j];
					}
				}
			}
		}
	}
	return;
}


int main()
{
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		block(N);
	}
	return 0;
}