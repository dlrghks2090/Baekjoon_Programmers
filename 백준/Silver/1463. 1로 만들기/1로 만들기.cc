#include<iostream>

using namespace std;

int N;
int sol[1000001] = { 0, };

int main() {

	

	cin >> N;

	sol[2] = 1;
	sol[3] = 1;

	for (int i = 4; i <= N; i++) {
		int tmp = i;
		int count = 0;

		sol[i] = sol[i - 1] + 1;

		if (tmp % 3 == 0) {
			if (sol[tmp / 3] + 1 < sol[i])
				sol[i] = sol[tmp / 3] + 1;
		}
		if (tmp % 2 == 0) {
			if (sol[tmp / 2] + 1 < sol[i])
				sol[i] = sol[tmp / 2] + 1;
		}
	}

	cout << sol[N];

	return 0;
}