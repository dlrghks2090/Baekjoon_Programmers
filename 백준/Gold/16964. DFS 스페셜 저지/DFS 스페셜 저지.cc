#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int arr[100001];
int arr2[100001];
int visit[100001];
vector<int> map[100001];
vector<int> sol;
int flag;

void dfs(int idx) {
	visit[idx] = 1;
	sol.push_back(idx);
	for (int i = 0; i < map[idx].size(); i++) {
		if (visit[map[idx][i]] == 0) {
			dfs(map[idx][i]);
		}
	}
}


bool comp(int& a, int& b) {
	return arr[a] < arr[b];
}

int main() {
	int a, b;
	

	cin >> N;
	
	vector<int> tmp(N + 1);
	tmp.push_back(0);
	sol.push_back(0);

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;

		map[a].push_back(b);
		map[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++) {
		cin >> tmp[i];
		arr[tmp[i]] = i;
	}

	for(int i=1; i<=N; i++) {
		sort(map[i].begin(), map[i].end(), comp);
	}

	dfs(1);

	/*
	cout << "모은 정답: ";
	for (int i = 0; i <= N; i++) {
		cout << sol[i] << " ";
	}
	cout << '\n';

	cout << "제공 정답: ";
	for (int i = 0; i <= N; i++) {
		cout << tmp[i] << " ";
	}
	cout << '\n';
	*/


	for (int i = 1; i <= N; i++) {
		if (tmp[i] != sol[i]) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << 0;
	}
	else {
		cout << 1;
	}


	return 0;
}