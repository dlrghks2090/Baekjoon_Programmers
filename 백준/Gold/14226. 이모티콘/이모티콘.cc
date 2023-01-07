#include<iostream>
#include<queue>

using namespace std;

int S;
int visit[2001][1001] = { 0, };


void bfs(int num, int time) {
	queue<pair<pair<int, int>, int>> que;
	pair<pair<int, int>, int> p;
	pair<int, int> p_2;
	int n = num;
	int t = time;
	int save = 0;

	p_2.first = n;
	p_2.second = t;
	p.first = p_2;
	p.second = save;

	que.push(p);
	visit[n][save] = 1;

	while (1) {

		/*cout << "=====큐 현황=====" << endl;
		cout << "인형 수 : " << que.front().first.first << endl;
		cout << "카운트 수 : " << que.front().first.second << endl;
		cout << "저장된 개수 : " << que.front().second << endl;
		cout << endl;*/


		if (que.empty()) {
			break;
		}

		if (que.front().first.first == S) {
			cout << que.front().first.second;
			break;
		}

		n = que.front().first.first;
		t = que.front().first.second;
		save = que.front().second;
		que.pop();

		if (0 < n && n < 1001) {

			if (n != save && visit[n][n] == 0) {
				p_2.first = n;
				p_2.second = t + 1;
				p.first = p_2;
				p.second = n;
				que.push(p);
				visit[n][n] == 1;
			}


			if (save > 0 && n+save < 1001 && visit[n + save][save] == 0) {
				p_2.first = n + save;
				p_2.second = t + 1;
				p.first = p_2;
				p.second = save;
				que.push(p);
				visit[n + save][save] = 1;
			}

			if (n > 0 && visit[n - 1][save] == 0) {
				p_2.first = n - 1;
				p_2.second = t + 1;
				p.first = p_2;
				p.second = save;
				que.push(p);
				visit[n - 1][save] = 1;
			}
		}


	}

}

int main() {

	cin >> S;

	bfs(1, 0);



	return 0;
}