#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int visit[101][101];
int direct[4][2] = {
    1,0,
    0,1,
    -1,0,
    0,-1
};

int bfs(int x, int y, int num, int m, int n, vector<vector<int>> picture) {

    queue<pair<int, int>> q;
    q.push({ x,y });
    visit[x][y] = 1;
    int cnt = 1;
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = a + direct[i][0];
            int dy = b + direct[i][1];
            if (dx<0 || dy<0 || dx>m - 1 || dy>n - 1)continue;
            if (visit[dx][dy] == 1 || picture[dx][dy] == 0)continue;
            if (picture[dx][dy] == num) {
                visit[dx][dy] = 1;
                q.push({ dx,dy });
                cnt++;
            }

        }
    }
    return cnt;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && visit[i][j] == 0) {
                int s = bfs(i, j, picture[i][j], m, n, picture);
                if (s > max_size_of_one_area)max_size_of_one_area = s;
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    cout << answer[0] << " " << answer[1];

    return answer;
}

int main() {

    solution(6, 4, { {1, 1, 1, 0 }, { 1, 2, 2, 0 }, { 1, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 3 }, { 0, 0, 0, 3 }
        });

    return 0;
}