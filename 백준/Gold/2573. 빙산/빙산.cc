#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;
int map[302][302] = { 0, };
int tmp[302][302] = { 0, };
int visit[302][302] = { 0, };

int sol = 0;

void bfs(int i, int j) {
	queue<pair<int, int>> que;
	pair<int, int> p;
	int x;
	int y;

	p.first = i;
	p.second = j;
	que.push(p);
	visit[i][j] = 1;

	//cout << "!!!!!!bfs 입성!!!!!" << endl;

	while (1) {
		if (que.empty() == true) {

			/*cout << "======== 방문 목록 ============" << endl;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					cout << visit[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
			break;
		}
		
		x = que.front().first;
		y = que.front().second;
		que.pop();

		if (map[x + 1][y] != 0 && visit[x+1][y] == 0) {
			p.first = x + 1;
			p.second = y;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x - 1][y] != 0 && visit[x - 1][y] == 0) {
			p.first = x - 1;
			p.second = y;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x][y + 1] != 0 && visit[x][y+1] == 0) {
			p.first = x;
			p.second = y + 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x][y - 1] != 0 && visit[x][y - 1] == 0) {
			p.first = x;
			p.second = y - 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}

	}

}

void ice_throw() {
	int count = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] != 0) {
				if (map[i+1][j] == 0) {
					count++;
				}
				if (map[i-1][j] == 0) {
					count++;
				}
				if (map[i][j+1] == 0) {
					count++;
				}
				if (map[i][j-1] == 0) {
					count++;
				}
				tmp[i][j] = map[i][j] - count;
				if (tmp[i][j] < 0) {
					tmp[i][j] = 0;
				}
				count = 0;
			}
		}
	}
}

void init_visit() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visit[i][j] = 0;
		}
	}
}

void init_tmp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp[i][j] = 0;
		}
	}
}

void duplication() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

int main() {

	int k = 0;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		
		
		init_visit();
		init_tmp();

		sol = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (visit[i][j] == 0 && map[i][j] != 0) {
					bfs(i, j);
					sol++;
				}
			}
		}

		if (sol > 1) {
			cout << k;
			return 0;
			/*cout << "******* 최종 정답 map *******" << endl;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					cout << map[i][j] <<  " ";
				}
				cout << endl;
			}*/
		}
		else if (sol == 0) {
			cout << 0;
			return 0;
		}

		ice_throw();
		duplication();
		k++;

		/*cout << k + 1 << "  년 후 줄어든 빙하 @@@@@@@@@" << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/

	}


	return 0;
}