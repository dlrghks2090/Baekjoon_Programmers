#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string N;
	int B;
	long long sol = 0;

	cin >> N >> B;

	for (int i = 0; i < N.size(); i++) {
		if (0 <= (N[i] - '0') && (N[i] - '0') <= 9) {
			sol = sol + N[i] - '0';
		} 
		else {
			for (int j = 0; j < str.size(); j++) {
				if (str[j] == N[i]) {
					sol = sol + 10 + j;
				}
			}
		}
		if(i != N.size()-1)
			sol *= B;
	}

	cout << sol;


	return 0;
}