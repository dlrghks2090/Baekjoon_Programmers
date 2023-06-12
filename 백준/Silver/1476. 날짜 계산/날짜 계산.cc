#include<iostream>

using namespace std;

int main() {

	int E, S, M;
	int e = 0;
	int s = 0;
	int m = 0;
	int sol = 0;

	cin >> E >> S >> M;

	while (1) {
		if (E == e && S == s && M == m) {
			break;
		}

		sol++;
		++e;
		++s;
		++m;

		if (e > 15) {
			e = 1;
		}
		if (s > 28) {
			s = 1;
		}
		if (m > 19) {
			m = 1;
		}
		
	}

	cout << sol;

	return 0;
}