#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int map[102][102] = { 0, };
int visit[102][102] = { 0, };
int sol = 0;

void bfs() {

	queue<pair<pair<int, int>, int>> que;
	pair<pair<int, int>, int> p2;
	pair<int, int> p;
	int arr1[4] = { 0,1,0,-1 };
	int arr2[4] = { 1,0,-1,0 };
	
	p.first = 1;
	p.second = 1;

	p2.first = p;
	p2.second = 1;

	que.push(p2);
	visit[1][1] = 1;

	while (!que.empty()) {
		int a = que.front().first.first;
		int b = que.front().first.second;
		int count = que.front().second;

		//cout << "a = " << a << " b = " << b << endl;

		if (a == N && b == M) {
			sol = que.front().second;
		}

		que.pop();

		for (int i = 0; i < 4; i++) {
			if (map[a + arr1[i]][b + arr2[i]] == 1 && visit[a + arr1[i]][b + arr2[i]] == 0) {
				p.first = a + arr1[i];
				p.second = b + arr2[i];
				p2.first = p;
				p2.second = count + 1;

				que.push(p2);

				visit[p.first][p.second] = 1;
				
			}
		}
	}
	



}


int main() {

	string str;

	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j + 1] = str[j] - '0';
		}
	}

	bfs();
	
	cout << sol;

	return 0;
}