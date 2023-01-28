#include<iostream>
#include<queue>

using namespace std;

int l;
int start_row, start_col;
int goal_row, goal_col;

int visit[302][302] = { 0, };


void bfs() {
	queue<pair<pair<int, int>, int>> que;
	pair<pair<int, int>, int> p;
	pair<int, int> p2;
	int arr_row[8] = { 1,2,2,1,-1,-2,-2,-1 };
	int arr_col[8] = { 2,1,-1,-2,-2,-1,1,2 };

	p2.first = start_row;
	p2.second = start_col;
	p.first = p2;
	p.second = 0;
	que.push(p);
	visit[start_row][start_col] = 1;

	while (1) {
		int row, col, count;

		row = que.front().first.first;
		col = que.front().first.second;
		count = que.front().second;
		que.pop();

		if (row == goal_row && col == goal_col) {
			cout << count << endl;
			break;
		}

		for (int i = 0; i < 8; i++) {
			if (row + arr_row[i] < l && col + arr_col[i] < l) {
				if (row + arr_row[i] >= 0 && col + arr_col[i] >= 0 && visit[row + arr_row[i]][col + arr_col[i]] == 0) {
					p2.first = row + arr_row[i];
					p2.second = col + arr_col[i];
					p.first = p2;
					p.second = count + 1;
					que.push(p);
					visit[p2.first][p2.second] = 1;
				}
			}
		}

	}
}

void init_visit() {
	for (int i = 0; i < 302; i++) {
		for (int j = 0; j < 302; j++) {
			visit[i][j] = 0;
		}
	}
}


int main() {

	int T;


	cin >> T;

	for (int i = 0; i < T; i++) {
		//cout << i + 1 << " 번째 테스트 케이스 !!=========" << endl;

		cin >> l;
		cin >> start_row >> start_col;
		cin >> goal_row >> goal_col;


		
		init_visit();
		bfs();

	}


	return 0;
}