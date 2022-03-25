#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

vector<int> solution(string msg) {
    vector<int> answer;


    for (char i = 'A'; i <= 'Z'; i++) {
        string s = "";
        s = s + i;
        m[s] = i - 'A' + 1;
    }

    int cnt = 27;
    int a = 0;
    int b = 1;
    while (1) {
        if (a == msg.length() || b == msg.length()) {
            string nowword = msg.substr(a, b - a);
            answer.push_back(m[nowword]);
            break;
        }
        string word = msg.substr(a, b - a + 1);
        if (m.count(word) == 0) {
            m[word] = cnt;
            cnt++;
            string nowword = msg.substr(a, b - a);
            answer.push_back(m[nowword]);
            a = b;
            b = a + 1;
        }
        else {
            b++;
        }
    }

    return answer;
}

int main() {

    solution("ABABABABABABABAB");

    return 0;
}