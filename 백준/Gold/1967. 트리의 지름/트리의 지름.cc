#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int>> map[10001];
int node, node2, value;
pair<int, int> p;
int check = 0;
int sol = 0;
int start;
vector<int> tmp;

void init_visit(int n) {

	for (int i = 0; i <= n; i++) {
	}
}

void dfs(int idx, int count) {

	int a, num;

	if (map[idx].size() == 0) {
		if (check == tmp.size()) {
			if (tmp[check-1] < count) {
				//cout << check << " 번째 인덱스 갱신 거리: " << count << '\n';
				tmp[check - 1] = count;
			}
		}
		else {
			//cout << "새로 추가된 거리: " << count << '\n';
			tmp.push_back(count);
		}

		return;
	}

	
	if (idx == start) {
		for (int i = 0; i < map[idx].size(); i++) {
			a = map[idx][i].first;
			num = map[idx][i].second;
			
			++check;
			dfs(a, num);
			
		}
	}
	else {
		for (int i = 0; i < map[idx].size(); i++) {

			a = map[idx][i].first;
			num = map[idx][i].second;

			dfs(a, count + num);
		}
	}
}

bool comp(int a, int b) {
	return a > b;
}

int main() {

	

	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> node >> node2 >> value;
		p.first = node2;
		p.second = value;
		map[node].push_back(p);
	}

	for (int i = 1; i <= n; i++) {
		if (map[i].size() > 1) {
			start = i;
			dfs(i, 0);

			sort(tmp.begin(), tmp.end(), comp);

			if (tmp[0] + tmp[1] > sol) {
				sol = tmp[0] + tmp[1];
			}
			tmp.clear();
			init_visit(n);
			check = 0;
		}

		if (map[i].size() == 1) {
			start = i;
			dfs(i, 0);

			sort(tmp.begin(), tmp.end(), comp);

			if (tmp[0] > sol) {
				sol = tmp[0];
			}
			tmp.clear();
			init_visit(n);
			check = 0;
		}
	}

	cout << sol;



	return 0;
}