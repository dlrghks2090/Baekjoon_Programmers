#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;
//int map[3002][3002] = { 0, };
vector<int> map[3002];
int visit_dot[3002] = { 0, };
int sol[3002];
int visit_bfs[3002] = {0, };
vector<int> v;
int flag = 0;
queue<pair<int, int>> que;
pair<int, int> p;
int start = 0;

void cycle_dfs(int idx, int count) {

	if (flag == 1) {
		return;
	}
	/*
	for (int i = 0; i < v.size(); i++) {
		cout << "==== "<< v[i] << " ";
	}
	cout << '\n';
	*/
	if (count > 2 && idx == start) {
		flag = 1;

		//cout << "사이클 발견!  start = " << start << '\n';
		for (int i = 0; i < v.size() - 1; i++) {
			//cout << v[i] << " ";
			p.first = v[i];
			p.second = 0;
			que.push(p);
			visit_bfs[v[i]] = 1;
		}
		//cout << '\n';
		return;
	}

	


	for (int i = 0; i < map[idx].size(); i++) {
		if (count > 2) {
			visit_dot[start] = 0;
		}
		else {
			visit_dot[start] = 1;
		}

		if (flag == 1) {
			return;
		}
		if (visit_dot[map[idx][i]] == 0) {
			
			visit_dot[map[idx][i]] = 1;
			v.push_back(map[idx][i]);
			cycle_dfs(map[idx][i], count+1);
			visit_dot[map[idx][i]] = 0;
			v.pop_back();
		}
	}
}

void bfs() {
	

	

	while (!que.empty()) {
		int a = que.front().first;
		int dis = que.front().second;
		que.pop();

		if (dis == 0) {
			sol[a] = 0;
		}
		else {
			if (sol[a] > dis) {
				sol[a] = dis;
			}
		}

		for (int j = 0; j < map[a].size(); j++) {
			if (visit_bfs[map[a][j]] == 0) {
				p.first = map[a][j];
				p.second = dis + 1;
				que.push(p);
				visit_bfs[map[a][j]] = 1;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	vector<int> vec;

	cin >> N;

	fill_n(sol, N + 1, 1000000);

	for (int i = 0; i < N; i++) {

		cin >> a >> b;
		//map[a][b] = map[b][a] = 1;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		visit_dot[i] = 1;
		start = i;
		cycle_dfs(i, 1);
		visit_dot[i] = 0;

		if (flag == 1) {
			break;
		}

		v.clear();
	}

	bfs();

	for (int i = 1; i <= N; i++) {
		cout << sol[i] << " ";
	}

	return 0;
}