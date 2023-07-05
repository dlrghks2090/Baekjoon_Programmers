// 백준_골드5_7576번_토마토

/*
풀이>
익은 토마토를 모두 queue에 넣고 시작한다.
*/

#include<iostream>
#include<queue>

using namespace std;

int N, M;
int map[1002][1002] = { 0, };
vector<pair<int, int>> v;
int visit[1002][1002] = { 0, };
int sol = 0;


void init() {
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			map[i][j] = 2;
		}
	}
}

void bfs() {

	queue<pair<pair<int, int>,int>> que;
	pair<pair<int, int>, int> p2;
	pair<int, int> p;
	int arr1[4] = { 0,1,0,-1 };
	int arr2[4] = { 1,0,-1,0 };

	for (int i = 0; i < v.size(); i++) {
		p2.first = v[i];
		p2.second = 0;
		que.push(p2);
		visit[v[i].first][v[i].second] = 1;
	}

	while (!que.empty()) {
		int a = que.front().first.first;
		int b = que.front().first.second;
		int count = que.front().second;

		que.pop();
		if (sol < count) {
			sol = count;
		}

		for (int i = 0; i < 4; i++) {
			if (map[a + arr1[i]][b + arr2[i]] == 0 && visit[a + arr1[i]][b + arr2[i]] == 0) {
				p.first = a + arr1[i];
				p.second = b + arr2[i];
				p2.first = p;
				p2.second = count + 1;
				que.push(p2);
				
				visit[a + arr1[i]][b + arr2[i]] = 1;
			}
		}
	}
}


int main() {

	pair<int, int> p;

	cin >> M >> N;

	init();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				p.first = i;
				p.second = j;
				v.push_back(p);
			}
		}
	}

	bfs();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << sol;

	return 0;
}