#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

char arr[5] = { 'A','E','I','O','U' };

vector<string> dic;

void dfs(string s, int level) {

    if (s.size() == level) {
        dic.push_back(s);
        return;
    }

    for (int i = 0; i < 5; i++) {
        dfs(s + arr[i], level);
    }

}


int solution(string word) {

    int answer = 0;

    for (int i = 1; i <= 5; i++) {
        dfs("", i);
    }

    sort(dic.begin(), dic.end());

    for (int i = 0; i < dic.size(); i++) {
        if (word == dic[i]) {
            cout << i + 1;
            return i + 1;
        }
    }
    return answer;
}
int main() {

    solution("I");

    return 0;
}