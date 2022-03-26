#include <string>
#include <vector>
#include <iostream>


using namespace std;

int check[8];
int MAX = 0;

void dfs(int level, int k, vector<vector<int>> dungeons) {

    if (MAX < level) {
        MAX = level;
    }
    for (int i = 0; i < dungeons.size(); i++) {
        if (!check[i] && dungeons[i][0] <= k) {
            check[i] = 1;
            dfs(level + 1, k - dungeons[i][1], dungeons);
            check[i] = 0;
        }
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    dfs(0, k, dungeons);
    cout << MAX;
    return MAX;
}