#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int sol = 0;
vector <pair<int, int>> v;

int main() {

	int t;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end());

	t = v[0].first;
	sol++;
	for (int i = 1; i < N; i++) {
		if (v[i].second >= t) {
			t = v[i].first;
			sol++;
		}
	}

	cout << sol;

	return 0;
}