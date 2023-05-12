#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

	int N;
	int arr[1001] = { 0, };
	int num;
	vector<int> v;
	int sol = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			sol += v[j];
		}
	}

	cout << sol;


	return 0;
}