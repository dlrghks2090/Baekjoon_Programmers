#include<iostream>
#include<queue>
#include<string>

using namespace std;

int N, M;
string str[101];
int arr[102][102] = { 0, };
int visit[102][102] = { 0, };
int sol;

queue<pair<int, int>> que;
pair<int, int> p;
int idx1, idx2;


void bfs(int x, int y) {

	idx1 = x;
	idx2 = y;
	p.first = (idx1 - 1) * M + idx2;
	p.second = 1;
	que.push(p);	

	while (true) {
		pair<int, int> p2;

		if (idx1 == N && idx2 == M) {
			sol = p.second;
			break;
		}

		p = que.front();


		if (p.first % M == 0) {
			idx2 = M;
			idx1 = p.first / M;
		}
		else {
			idx2 = p.first % M;
			idx1 = p.first / M + 1;
		}

		/*cout << " 현재 단계 " << endl;
		cout << "x = " << idx1 << "   y = " << idx2 << endl;*/

		que.pop();

		/*cout << "  방문목록  " << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << visit[i][j];
			}
			cout << endl;
		}*/
		
		if (arr[idx1 + 1][idx2] == 1 && visit[idx1 + 1][idx2] == 0) {
			p2.first = (idx1 + 1 - 1) * M + idx2;
			p2.second = p.second + 1;
			que.push(p2);
			visit[idx1 + 1][idx2] = 1;
		}
		if (arr[idx1 - 1][idx2] == 1 && visit[idx1 - 1][idx2] == 0) {
			p2.first = (idx1 - 1 - 1) * M + idx2;
			p2.second = p.second + 1;
			que.push(p2);
			visit[idx1 - 1][idx2] = 1;
		}
		if (arr[idx1][idx2 + 1] == 1 && visit[idx1][idx2 + 1] == 0) {
			p2.first = (idx1 - 1) * M + idx2 + 1;
			p2.second = p.second + 1;
			que.push(p2);
			visit[idx1][idx2 + 1] = 1;
		}
		if (arr[idx1][idx2 - 1] == 1 && visit[idx1][idx2 - 1] == 0) {
			p2.first = (idx1 - 1) * M + idx2 - 1;
			p2.second = p.second + 1;
			que.push(p2);
			visit[idx1][idx2 - 1] = 1;
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr[i][j] = str[i-1][j-1] - '0';
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}*/

	bfs(1, 1);

	cout << sol;

	return 0;
}