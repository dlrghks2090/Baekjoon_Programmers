#include<iostream>
#include<cstdlib>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int beer;
int start[2] = { 0, };
int market[101][2] = { 0, };
int visit[101] = { 0, };
int goal[2] = { 0, };

void init_market() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j <= 1; j++) {
			market[i][j] = 0;
		}
	}
}

void init_visit() {
	for (int i = 1; i <= 100; i++) {
		visit[i] = 0;
	}
}

void bfs(int x, int y) {
	
	int x1 = x;
	int y1 = y;
	int total = x + y;
	int beer_distance = beer * 50;
	queue < pair<int, int>> que;
	pair<int, int> p1;

	p1.first = x;
	p1.second = y;
	que.push(p1);

	while (1) {

		if (que.empty() == true) {
			cout << "sad" << endl;
			break;
		}

		if (abs(goal[0] - que.front().first) + abs(goal[1] - que.front().second) <= beer_distance) {
			cout << "happy" << endl;
			break;
		}
		else {

			x1 = que.front().first;
			y1 = que.front().second;
			que.pop();

			for (int i = 1; i <= n; i++) {
				if (visit[i] == 0 && abs(market[i][0] - x1) + abs(market[i][1] - y1) <= beer_distance) {
					//cout << "편의점 " << market_num << " 들름" << endl;
					//cout << endl;
					p1.first = market[i][0];
					p1.second = market[i][1];
					que.push(p1);
					visit[i] = 1;

					//cout << "x 좌표 : " << x1 << endl;
					//cout << "y 좌표 : " << y1 << endl;
				}

			}
		}

	}
}

int main() {

	int t;
	int x, y;


	cin >> t;

	for (int i = 0; i < t; i++) {
		beer = 20;
		cin >> n;
		cin >> start[0] >> start[1];
		for (int j = 1; j <= n; j++) {
			cin >> market[j][0] >> market[j][1];
		}
		cin >> goal[0] >> goal[1];

		x = start[0];
		y = start[1];

		bfs(x, y);
		init_market();
		init_visit();

	}

	return 0;
}