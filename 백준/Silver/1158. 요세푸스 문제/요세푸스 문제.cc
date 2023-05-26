#include<iostream>
#include<vector>

using namespace std;

int main() {

	int N, K;
	int idx = 0;

	cin >> N >> K;

	vector<int> v(N,0);
	vector<int> sol;

	for (int i = 0; i < N; i++) {
		v[i] = i + 1;
	}

	while ( v.size() !=0 ) {
		idx += K - 1;
		if (idx > v.size() - 1) {
			while(idx > v.size()-1)
				idx = idx - (v.size() - 1) - 1;
			sol.push_back(v[idx]);
			//cout << v[idx] << '\n';
			v.erase(v.begin() + idx);
		}
		else {
			sol.push_back(v[idx]);
			v.erase(v.begin() + idx);
		}
		
	}

	cout << "<";
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i];
		if (i != sol.size() - 1) {
			cout << ", ";
		}
	}
	cout << ">";

	return 0;
}