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
    // ��� �ڸ��� ���� ������ �ٲ� ǥ��
    for (int i = 0; i < m * t; i++) {
        s = s + change(i, n);
    }

    // s�� ��� ���� ǥ���� p�� �ڸ��� �ش��ϴ� �͸� �̱�
    // ���� Ƚ���� t�̸� ���ᰡ �ȴ�.
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