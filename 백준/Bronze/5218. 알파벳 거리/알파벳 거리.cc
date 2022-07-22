#include<iostream>
#include<string>

using namespace std;

int main() {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		string A;
		string B;

		cin >> A >> B;

		cout << "Distances:";

		for (int j = 0; j < A.size(); j++) {
			
			if (B[j] - A[j] < 0) {
				cout << " " << 26 - (A[j] - B[j]);
			}
			else {
				cout << " " << B[j] - A[j];
			}
		}
		cout << endl;

	}

	return 0;
}