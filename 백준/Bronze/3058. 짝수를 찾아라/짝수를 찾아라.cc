#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {

	int T;
	int arr[7] = { 0, };
	vector<int> v;
	int sum;

	cin >> T;

	for (int i = 0; i < T; i++) {
		sum = 0;
		for (int j = 0; j < 7; j++) {
			cin >> arr[j];
			if (arr[j] % 2 == 0) {
				v.push_back(arr[j]);
				sum += arr[j];
			}
		}
		sort(v.begin(), v.end());
		cout << sum << " " << v[0] << endl;
		v.clear();
	}

	return 0;
}