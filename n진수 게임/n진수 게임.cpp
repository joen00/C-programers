#include <string>
#include <vector>
#include <iostream>

using namespace std;

string change(int num, int n) {
    string arr = "0123456789ABCDEF";
    string s = "";
    while (num / n != 0) {
        s = arr[num % n] + s;
        num = num / n;
    }
    s = arr[num % n] + s;
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string s = "";
    // 모든 자리의 수를 진수로 바꿔 표현
    for (int i = 0; i < m * t; i++) {
        s = s + change(i, n);
    }

    // s에 담긴 진수 표현중 p인 자리에 해당하는 것만 뽑기
    // 말한 횟수가 t이면 종료가 된다.
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (cnt > t)break;
        if (i % m + 1 == p) {
            answer = answer + s[i];
            cnt++;
   
        }
    }

    return answer;
}
