#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;
vector<int> vec;
int arr[102][102] = { 0, };
int visit[102][102] = { 0, };

void bfs(int a, int b, int num) {

	queue<pair<int,int>> que;
	pair<int, int> p;
	int x = a;
	int y = b;

	p.first = x;
	p.second = y;
	que.push(p);

	while (1) {
		if (que.empty() == true) {
			break;
		}

		x = que.front().first;
		y = que.front().second;
		que.pop();

		if (visit[x + 1][y] == 0 && arr[x + 1][y] > num) {
			p.first = x + 1;
			p.second = y;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (visit[x - 1][y] == 0 && arr[x - 1][y] > num) {
			p.first = x - 1;
			p.second = y;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (visit[x][y + 1] == 0 && arr[x][y + 1] > num) {
			p.first = x;
			p.second = y + 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (visit[x][y - 1] == 0 && arr[x][y - 1] > num) {
			p.first = x;
			p.second = y - 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}

	}

}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = 0;
		}
	}
}

int area(int num) {
	int count = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == 0 && arr[i][j] > num) {
				bfs(i, j, num);
				count++;
			}
		}
	}

	return count;
}

int main() {
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 100; i++) {
		vec.push_back(area(i));
		init();
	}

	sort(vec.begin(), vec.end());

	cout << vec[vec.size() - 1];
	

	return 0;
}