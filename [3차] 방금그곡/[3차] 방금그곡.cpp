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

    // m에 대한 악보를 #를 붙은거 없애고 완성본 변수
    string main_song = change(m);

    // 가장 긴 시간 저장하기 위해 만든 변수
    int MAX_time = 0;

    // 곡이 몇개 일지 모르기 때문에 size만큼 돌리면서 그때 그때 비교를 해준다.
    for (int i = 0; i < musicinfos.size(); i++) {
        // 곡의 메인 제목
        string title = "";
        // 현재악보를 저장하기 위한 임의 변수
        string temp = "";
        // musicinfos에 대한 악보를 #를 붙은거 없애고 완성본 변수
        string music = "";
        // 시간 구하기
        int time = make_time(musicinfos[i]);
        temp = musicinfos[i].substr(musicinfos[i].find(",", 12) + 1, musicinfos[i].length());
        title = musicinfos[i].substr(12, musicinfos[i].find(",", 12) - 12);
        music = make_song(time, change(temp));
        // 비교하기 string::npos을 통해 있는지 없는지 비교하고 있으면 MAX_time으로 저장하기
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