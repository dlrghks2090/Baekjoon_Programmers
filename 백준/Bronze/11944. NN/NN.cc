#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "";
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		str = str + to_string(N);
	}
	if (str.size() > M) {
		for (int i = 0; i < M; i++) {
			cout << str[i];
		}
	}
	else {
		cout << str;
	}

	return 0;
}