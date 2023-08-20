#include<iostream>
#include<queue>

using namespace std;

int map[102][102] = { 0, };
int visit[102][102] = { 0, };
vector<queue<pair<pair<int, int>, int>>> v;
int arr1[4] = { 0,1,0,-1 };
int arr2[4] = { 1,0,-1,0 };

void bfs(int idx1, int idx2, int num) {

	queue<pair<int, int>> que;
	queue<pair<pair<int, int>, int>> que2;

	que.push(make_pair(idx1, idx2));
	que2.push(make_pair(make_pair(idx1, idx2), 0));
	visit[idx1][idx2] = 1;
	map[idx1][idx2] = num;

	while (!que.empty()) {

		int a = que.front().first;
		int b = que.front().second; 
		que.pop();

		//cout << "=============== a = " << a << " b = " << b << " ================\n";
		for (int i = 0; i < 4; i++) {
			//cout << "i =" << i << "일때!! "<< '\n';
			//cout << "a = " << a << "     b = " << b << '\n';
			//cout << "arr1[i] = " << arr1[i] << "   arr2[i] = " << arr2[i] << '\n';
			//cout << "map = " << map[a + arr1[i]][b + arr2[i]] << "  visit =" << visit[a + arr1[i]][b + arr2[i]] << '\n';
			if (map[a + arr1[i]][b + arr2[i]] == 1 && visit[a + arr1[i]][b + arr2[i]] == 0) {
				que.push(make_pair(a + arr1[i], b + arr2[i]));
				que2.push(make_pair(make_pair(a + arr1[i], b + arr2[i]), 0));
				visit[a + arr1[i]][b + arr2[i]] = 1;
				map[a + arr1[i]][b + arr2[i]] = num;

				//cout << "idx1 = " << a + arr1[i] << " idx2 = " << b + arr2[i] << '\n';
			}
		}
		//cout << "==============================================\n";
	}

	v.push_back(que2);
}

void init_visit(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = 0;
		}
	}
}

int main() {

	int N;
	int num = 2;
	int sol = 10000;



	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				bfs(i, j, num);
				++num;
			}
		}
	}

	num = 2;
	for (int i = 0; i < v.size(); i++) {
		queue<pair<pair<int, int>, int>> que = v[i];



		init_visit(N);

		//cout << "========== " << i + 1 << "번째 ==========" << '\n';
		while (!que.empty()) {
			int a = que.front().first.first;
			int b = que.front().first.second;
			int count = que.front().second;
			que.pop();

			//cout << "a,b = " << a << " " << b << "  count = " << count << '\n';

			if (map[a][b] != num && map[a][b] != 0) {
				if (sol > count) {
					sol = count;
				}
			}

			for (int j = 0; j < 4; j++) {
				if (a + arr1[j] > 0 && a + arr1[j] <= N && b + arr2[j] > 0 && b + arr2[j] <= N && map[a + arr1[j]][b + arr2[j]] != num && visit[a + arr1[j]][b + arr2[j]] == 0) {
					que.push(make_pair(make_pair(a + arr1[j], b + arr2[j]), count + 1));
					visit[a + arr1[j]][b + arr2[j]] = 1;
				}
			}

		}

		++num;
	}

	cout << sol-1;

	return 0;
}