#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string X, Y;
	string Z;
	int si = 0;
	int sol = 0;


	cin >> X >> Y;

	reverse(X.begin(), X.end());
	reverse(Y.begin(), Y.end());

	//cout << X << " " << Y << endl;

	sol = stoi(X) + stoi(Y);

	//cout << sol << endl;

	Z = to_string(sol);

	//cout << Z << endl;
	
	reverse(Z.begin(), Z.end());
	sol = stoi(Z);
	Z = to_string(sol);
	cout << Z;
	

	return 0;
}