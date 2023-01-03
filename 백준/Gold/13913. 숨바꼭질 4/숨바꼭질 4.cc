#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, K;
int visit[100001] = { 0, };
vector<int> sol;


void bfs(int n) {
	queue<pair<int, int>> que;
	pair<int, int> p;
	int x = n;
	int count = 0;

	p.first = x;
	p.second = count;
	que.push(p);
	visit[x] = 0;

	while (1) {

		/*if (que.empty() == true) {
			break;
		}*/

		if (que.front().first == K) {
			x = que.front().first;
			count = que.front().second;

			for (int i = count; i >= 0; i--) {
				sol.push_back(x);
				x = visit[x];
			}

			cout << count << endl;

			for (int i = sol.size() - 1; i >= 0; i--) {
				cout << sol[i] << " ";
			}

			break;
		}
		x = que.front().first;
		count = que.front().second;
		que.pop();

		if (x + 1 <= 100000 && visit[x + 1] == -2) {
			p.first = x + 1;
			p.second = count + 1;
			que.push(p);
			visit[x + 1] = x;
		}
		if (x - 1 >= 0 && visit[x - 1] == -2) {
			p.first = x - 1;
			p.second = count + 1;
			que.push(p);
			visit[x - 1] = x;
		}
		if (x * 2 <= 100000 && visit[x * 2] == -2) {
			p.first = x * 2;
			p.second = count + 1;
			que.push(p);
			visit[x * 2] = x;
		}
	}
}

void init_visit() {

	for (int i = 0; i < 100001; i++) {
		visit[i] = -2;
	}

}

int main() {

	cin >> N >> K;

	init_visit();

	bfs(N);

	return 0;
}