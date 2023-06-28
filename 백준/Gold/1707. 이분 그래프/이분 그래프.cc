#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int V, E;

int bfs(vector<vector<int>>vec, int* visit, int idx, int V) {
	queue<int> que;

	que.push(idx);
	visit[idx] = 1;

	while (!que.empty()) {
		int tmp = que.front();
		int color;
		que.pop();

		if (visit[tmp] == 1) {
			color = 2;
		}
		else {
			color = 1;
		}

		for (int i = 0; i < vec[tmp].size(); i++) {
			if (visit[vec[tmp][i]] == 0) {
				visit[vec[tmp][i]] = color;
				que.push(vec[tmp][i]);
			}
			else {
				if (visit[tmp] == visit[vec[tmp][i]]) {
					return 1;
				}
			}

		}
	}

	return 0;

}

void init_visit(int n, int* visit) {
	for (int i = 0; i <= n; i++) {
		visit[i] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;
	vector<string> sv;

	cin >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		int sol = 0;
		cin >> V >> E;

		// 방문체크와 색체크를 담당할 visit 배열을 V 크기로 동적할당
		int* visit = new int[V + 1];
		
		init_visit(V, visit);
		
		vector<int> v;
		
		vector<vector<int>> vec(V+1,v);

		for (int j = 1; j <= E; j++) {
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		// 비연결 그래프인 경우에도 모두 탐색할 수 있도록 
		for (int j = 1; j <= V; j++) {
			if (visit[j] == 0) {
				if (bfs(vec, visit, j, V) == 1) {
					sol = 1;
					break;
				}
			}
		}

		if (sol == 0) {
			sv.push_back("YES");
		}
		else {
			sv.push_back("NO");
		}
		delete[] visit;
	}

	for (int i = 0; i < sv.size(); i++) {
		cout << sv[i] << '\n';
	}


	return 0;
}