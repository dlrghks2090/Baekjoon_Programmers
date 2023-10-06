#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[101][101];
int goal_min;


void init_visit(int idx1, int idx2) {
    for (int i = 0; i <= idx1; i++) {
        for (int j = 0; j <= idx2; j++) {
            visit[i][j] = 0;
        }
    }
}

void bfs(vector<string> maps, pair<int, int> start_point, char goal) {
    queue<pair<pair<int, int>, int>> que;
    pair<pair<int, int>, int> p;
    int arr1[4] = { 0,1,0,-1 };
    int arr2[4] = { 1,0,-1,0 };

    que.push(make_pair(start_point, 0));
    visit[start_point.first][start_point.second] = 1;

    while (!que.empty()) {
        int idx1 = que.front().first.first;
        int idx2 = que.front().first.second;
        int count = que.front().second;

        que.pop();

        if (maps[idx1][idx2] == goal) {
            goal_min = count;
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (0 <= idx1 + arr1[i] && idx1 + arr1[i] < maps.size() && 0 <= idx2 + arr2[i] && idx2 + arr2[i] < maps[0].size()) {
                if (maps[idx1 + arr1[i]][idx2 + arr2[i]] != 'X' && visit[idx1 + arr1[i]][idx2 + arr2[i]] == 0) {
                    visit[idx1 + arr1[i]][idx2 + arr2[i]] = 1;
                    que.push(make_pair(make_pair(idx1 + arr1[i], idx2 + arr2[i]), count + 1));
                }
            }
        }



    }
}

int solution(vector<string> maps) {
    int answer = 0;
    int maps_size = maps.size();
    int maps_one_size = maps[0].length();
    pair<int, int> start;
    pair<int, int> lever;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
            else if (maps[i][j] == 'L') {
                lever.first = i;
                lever.second = j;
            }
        }
    }


    bfs(maps, start, 'L');
    answer += goal_min;
    if (goal_min == 0) {
        return -1;
    }
    goal_min = 0;
    init_visit(maps_size, maps_one_size);
    bfs(maps, lever, 'E');
    answer += goal_min;
    if (goal_min == 0) {
        return -1;
    }

    return answer;
}