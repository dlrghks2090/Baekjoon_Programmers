#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

	int N;
	int* A;

	stack<int> s;

	cin >> N;
	A = new int[N];
	vector<int> sol(N, -1);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = N-1; 0<=i; i--) {

		while (!s.empty() && A[i] >= s.top()) {
			s.pop();
		}
		if (!s.empty() && A[i] < s.top())
			sol[i] = s.top();
		s.push(A[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << sol[i] << " ";
	}


	delete[] A;

	return 0;
}