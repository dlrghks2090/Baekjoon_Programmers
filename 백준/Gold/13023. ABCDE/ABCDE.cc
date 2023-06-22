#include<iostream>
#include<vector>

using namespace std;

int N,M;
int sol = 0;

void dfs(int count, int idx, vector<vector<int>> &vec, vector<bool> &visit) {


	if (count == 4) {
		sol = 1;
		return;
	}



	for (int i = 0; i < vec[idx].size(); i++) {
		if (visit[vec[idx][i]] == 0) {
			visit[vec[idx][i]] = 1;
			dfs(count + 1, vec[idx][i], vec, visit);
			visit[vec[idx][i]] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;

	cin >> N >> M;

	vector<vector<int>> vec(N);
	vector<bool> visit(N);

	for (int i = 1; i <= M; i++) {
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		dfs(0, i, vec, visit);
		visit[i] = 0;
		if (sol == 1)
			break;
	}

	cout << sol;


	return 0;
}