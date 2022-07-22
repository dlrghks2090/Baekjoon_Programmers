#include<iostream>
#include<string>

using namespace std;

int main() {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		int count = 0;

		cin >> N >> M;

		if (N == 0)
			count++;
		for (int i = N; i <= M; i++) {
			int num = i;
			while (num != 0) {
				if (num % 10 == 0) {
					count++;
				}
				num = num / 10;;
			}
		}

		cout << count << endl;
	}

	return 0;
}