#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, K;
int sol = 0;
int visit[200001] = { 0, };

void bfs(int num) {

	queue<pair<int,int>> que;
	pair<int, int> p;

	p.first = num;
	p.second = 0;

	que.push(p);
	visit[num] = 1;

	while (1) {
		pair<int, int> p2;

		if (que.front().first == K) {
			sol = que.front().second;
			break;
		}

		p = que.front();
		que.pop();

		if (p.first * 2 - K < K - p.first && visit[p.first * 2] == 0) {
			p2.first = p.first * 2;
			p2.second = p.second + 1;
			que.push(p2);
			visit[p.first * 2] = 1;
		}
		if (visit[p.first + 1] == 0) {
			p2.first = p.first + 1;
			p2.second = p.second + 1;
			que.push(p2);
			visit[p.first + 1] = 1;
		}

		if (visit[p.first - 1] == 0) {
			p2.first = p.first - 1;
			p2.second = p.second + 1;
			que.push(p2);
			visit[p.first - 1] = 1;
		}

		
		

	}
}

int main() {

	cin >> N >> K;

	bfs(N);

	cout << sol << endl;

	return 0;
}