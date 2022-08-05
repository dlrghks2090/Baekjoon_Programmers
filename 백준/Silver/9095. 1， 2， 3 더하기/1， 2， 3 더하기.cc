#include<iostream>

using namespace std;

int main() {

	int T;
	int sol[12] = { 0, };

	sol[1] = 1;
	sol[2] = 2;
	sol[3] = 4;

	cin >> T;

	for (int i = 4; i <= 10; i++) {
		sol[i] = sol[i - 1] + sol[i - 2] + sol[i - 3];
	}

	for (int i = 0; i < T; i++) {
		int n;

		cin >> n;

		cout << sol[n] << endl;
	}


	return 0;
}