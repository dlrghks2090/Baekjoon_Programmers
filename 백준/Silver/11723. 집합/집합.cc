#include<iostream>
#include<string>
#include<vector>


using namespace std;


int M;
vector<int> v;


void Check_Array(string s, int n) {

	int flag = 0;
	int idx = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == n) {
			flag = 1;
			idx = i;
			break;
		}
	}


	if (s == "add" && flag == 0) {
		v.push_back(n);
	}
	else if (s == "remove" && flag ==1) {
		v.erase(v.begin() + idx);
	}
	else if (s == "check") {
		if (flag == 1) {
			cout << 1 << '\n';
		}
		else if (flag == 0) {
			cout << 0 << '\n';
		}
	}
	else if (s == "toggle") {
		if (flag == 1) {
			v.erase(v.begin() + idx);
		}
		else if (flag == 0) {
			v.push_back(n);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> M;

	for (int i = 0; i < M; i++) {
		string str;
		int n;
		cin >> str;

		if (str == "all") {
			v.clear();
			v = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if (str == "empty") {
			v.clear();
		}
		else {
			cin >> n;
			Check_Array(str,n);
		}
		

	}


	return 0;
}