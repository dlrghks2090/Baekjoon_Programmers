#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int map[27][27] = { 0, };
int visit[27][27] = { 0, };

int bfs(int N, int a, int b) {
	queue<pair<int, int>> que;
	pair<int, int> p;
	int idx1[4] = { 0,1,0,-1 };
	int idx2[4] = { 1,0,-1,0 };
	int sol = 0;

	p.first = a;
	p.second = b;
	que.push(p);
	sol++;
	visit[a][b] = 1;
	while (!que.empty()) {
		int a2 = que.front().first;
		int b2 = que.front().second;
		que.pop();

		
		for (int i = 0; i < 4; i++) {
			if (map[a2 + idx1[i]][b2 + idx2[i]] == 1 && visit[a2 + idx1[i]][b2 + idx2[i]] == 0) {
				p.first = a2 + idx1[i];
				p.second = b2 + idx2[i];
				que.push(p);
				sol++;
				visit[p.first][p.second] = 1;
			}
		}

	}
	return sol;
}

int main() {

	vector<int> num;
	int N;
	string str;
	int count = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == 0 && map[i][j] == 1) {
				num.push_back(bfs(N, i, j));
				count++;
			}
		}
	}

	sort(num.begin(), num.end());

	cout << count << '\n';
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << '\n';
	}

	return 0;
}