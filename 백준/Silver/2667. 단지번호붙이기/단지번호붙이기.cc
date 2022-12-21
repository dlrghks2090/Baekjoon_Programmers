#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;
string str[26];
int arr[27][27] = { 0, };
int visit[27][27] = { 0, };
int total=0;
vector<int> vec;


void bfs(int x, int y) {

	queue<pair<int,int>> que;
	int count = 0;
	pair<int, int> p1;

	p1.first = x;
	p1.second = y;
	que.push(p1);
	visit[x][y] = 1;
	count++;

	while (1) {
		int x1, y1;

		if (que.empty() == true) {
			vec.push_back(count);
			break;
		}

		x1 = que.front().first;
		y1 = que.front().second;
		que.pop();

		if (arr[x1 + 1][y1] == 1 && visit[x1 + 1][y1] == 0) {
			p1.first = x1 + 1;
			p1.second = y1;
			que.push(p1);
			visit[x1 + 1][y1] = 1;
			count++;
		}
		if (arr[x1 - 1][y1] == 1 && visit[x1 - 1][y1] == 0) {
			p1.first = x1 - 1;
			p1.second = y1;
			que.push(p1);
			visit[x1 - 1][y1] = 1;
			count++;
		}
		if (arr[x1][y1 + 1] == 1 && visit[x1][y1 + 1] == 0) {
			p1.first = x1;
			p1.second = y1 + 1;
			que.push(p1);
			visit[x1][y1 + 1] = 1;
			count++;
		}
		if (arr[x1][y1 - 1] == 1 && visit[x1][y1 - 1] == 0) {
			p1.first = x1;
			p1.second = y1 - 1;
			que.push(p1);
			visit[x1][y1 - 1] = 1;
			count++;
		}

	}


}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = str[i - 1][j - 1] - '0';
		}
	}

	/*cout << "arr 확인!!!" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}*/

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == 0 && arr[i][j] == 1) {
				total++;
				bfs(i, j);
			}
		}
	}

	sort(vec.begin(), vec.end());

	cout << total << endl;

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	return 0;
}