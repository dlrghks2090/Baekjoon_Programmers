#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, K;
int visit[500001] = { 0, };
int sol = 10000000;

void init() {
	for (int i = 0; i < 500001; i++) {
		visit[i] = 1000000;
	}
}


void bfs(int time) {
	queue<pair<int, int>> que;
	pair<int, int> p;
	int d = N;
	int t = time;

	p.first = d;
	p.second = t;
	que.push(p);
	visit[d] = 0;

	while (1) {
		
		/*cout << "======= 현재 위치 =======" << endl;
		cout << "수빈의 위치 : " << que.front().first << endl;
		cout << "거린 시간 : " << que.front().second << endl;*/

		if (que.empty()) {
			break;
		}

		if (que.front().first == K) {
			if (sol > que.front().second)
				sol = que.front().second;
		}

		d = que.front().first;
		t = que.front().second;
		que.pop();

		
		if (d > 0 && d * 2 <= 150000 && visit[d * 2] > t) {
			p.first = d * 2;
			p.second = t;
			que.push(p);
			visit[d * 2] = t;
		}

		if (d + 1 <= 100000 && visit[d + 1] > t + 1) {
			p.first = d + 1;
			p.second = t + 1;
			que.push(p);
			visit[d + 1] = t + 1;
		}

		if (d - 1 >= 0 && visit[d - 1] > t + 1) {
			p.first = d - 1;
			p.second = t + 1;
			que.push(p);
			visit[d - 1] = t + 1;
		}

	}
}

int main() {

	cin >> N >> K;

	init();

	bfs(0);

	cout << sol;

	return 0;
}