#include<iostream>
#include<string>

using namespace std;

int N, M;
int sol_count = 0;
int A[51][51] = { 0, };
int B[51][51] = { 0, };

void change_A(int x, int y) {

	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (A[i][j] == 1) {
				A[i][j] = 0;
			}
			else {
				A[i][j] = 1;
			}
		}
	}
}

int isSame() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				return -1;
			}
		}
	}

	return 0;
}


int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;
		
		for (int j = 0; j < M; j++) {
			A[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;

		for (int j = 0; j < M; j++) {
			B[i][j] = str[j] - '0';
		}
	}


	for (int i = 0; i + 2 < N; i++) {
		for (int j = 0; j + 2 < M; j++) {
			if (A[i][j] != B[i][j]) {
				change_A(i, j);
				sol_count++;
			}
		}
	}

	if (isSame() == -1) {
		cout << -1;
	}
	else {
		cout << sol_count;
	}



	return 0;
}