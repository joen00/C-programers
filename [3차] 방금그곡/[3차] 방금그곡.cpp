#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_map<string, char> map;

int make_time(string s) {
    int a1 = stoi(s.substr(0, 2));
    int b1 = stoi(s.substr(3, 2));
    int a2 = stoi(s.substr(6, 2));
    int b2 = stoi(s.substr(9, 2));
    return ((a2 * 60) + b2) - ((a1 * 60) + b1);
}

string make_song(int s_time, string s) {

    string song = "";
    int i = 0;
    while (s_time) {
        if (i >= s.length()) {
            i = 0;
        }
        song = song + s[i];
        s_time--;
        i++;
    }
    return song;

}

string change(string m) {

    string main_song = "";
    for (int i = 0; i < m.length(); i++) {
        if (m[i] == '#') {
            string u = "";
            u = u + m[i - 1] + m[i];
            main_song[main_song.length() - 1] = map[u];
        }
        else if (m[i] != '#') {
            main_song = main_song + m[i];
        }
    }
    return main_song;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    map["C#"] = 'c';
    map["D#"] = 'd';
    map["F#"] = 'f';
    map["G#"] = 'g';
    map["A#"] = 'a';

    // m�� ���� �Ǻ��� #�� ������ ���ְ� �ϼ��� ����
    string main_song = change(m);

    // ���� �� �ð� �����ϱ� ���� ���� ����
    int MAX_time = 0;

    // ���� � ���� �𸣱� ������ size��ŭ �����鼭 �׶� �׶� �񱳸� ���ش�.
    for (int i = 0; i < musicinfos.size(); i++) {
        // ���� ���� ����
        string title = "";
        // ����Ǻ��� �����ϱ� ���� ���� ����
        string temp = "";
        // musicinfos�� ���� �Ǻ��� #�� ������ ���ְ� �ϼ��� ����
        string music = "";
        // �ð� ���ϱ�
        int time = make_time(musicinfos[i]);
        temp = musicinfos[i].substr(musicinfos[i].find(",", 12) + 1, musicinfos[i].length());
        title = musicinfos[i].substr(12, musicinfos[i].find(",", 12) - 12);
        music = make_song(time, change(temp));
        // ���ϱ� string::npos�� ���� �ִ��� ������ ���ϰ� ������ MAX_time���� �����ϱ�
        if (music.find(main_song) != string::npos) {
            if (MAX_time < time) {
                answer = title;
                MAX_time = time;
            }
        }
    }
    cout << answer;
    return answer;
}

int main() {

    solution("A#", { "12:00,12:01,HELLO,A#" });

    return 0;
}