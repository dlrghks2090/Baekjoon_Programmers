#include<iostream>
#include<queue>

using namespace std;

int N, K;
int visit[100001] = { 0, };

void bfs(int n, int k) {

	queue<pair<int, int>> que;
	pair<int, int> p;

	p.first = n;
	p.second = 0;
	visit[n] = 1;
	que.push(p);

	while (!que.empty()) {
		int idx = que.front().first;
		int count = que.front().second;

		que.pop();

		//cout << "idx = " << idx << " count = " << count <<'\n';

		if (idx == k) {
			cout << count;
			return;
		}

		if (idx + 1 <= 100000) {
			if (visit[idx + 1] == 0) {
			//if (idx < k &&  visit[idx + 1] == 0) {
				p.first = idx + 1;
				p.second = count + 1;
				que.push(p);
				visit[p.first] = 1;
			}
		}

		if (0 <= idx - 1) {
			if (visit[idx - 1] == 0) {
			//if (idx > k && visit[idx - 1] == 0) {
				p.first = idx - 1;
				p.second = count + 1;
				que.push(p);
				visit[p.first] = 1;
			}
		}

		if (idx * 2 <= 100000) {
			if (visit[idx * 2] == 0) {
			//if (idx * 2 - k < k - idx && visit[idx * 2] == 0) {
				p.first = idx * 2;
				p.second = count + 1;
				que.push(p);
				visit[p.first] = 1;
			}
		}
	}



}

int main() {

	cin >> N >> K;

	bfs(N,K);


	return 0;
}