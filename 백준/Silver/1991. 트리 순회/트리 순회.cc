#include<iostream>
#include<vector>

using namespace std;

vector<char> map[27];

void pre_order(int idx) {

	cout << (char)('A' + idx);

	if (map[idx][0] != '.') {
		pre_order(map[idx][0] - 'A');
	}
	
	if (map[idx][1] != '.') {
		pre_order(map[idx][1] - 'A');
	}
}

void in_order(int idx) {

	if (map[idx][0] != '.') {
		in_order(map[idx][0] - 'A');
	}
	cout << (char)('A' + idx);
	if (map[idx][1] != '.') {
		in_order(map[idx][1] - 'A');
	}
}

void post_order(int idx) {

	if (map[idx][0] != '.') {
		post_order(map[idx][0] - 'A');
	}
	if (map[idx][1] != '.') {
		post_order(map[idx][1] - 'A');
	}
	cout << (char)('A' + idx);
}

int main() {

	int N;
	char a, b, c;
	int idx = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		idx = (a - 'A');

		//cout << "== " << idx << " " << b <<  " " << c << '\n';
		map[idx].push_back(b);
		map[idx].push_back(c);
	}

	pre_order(0);
	cout << '\n';
	in_order(0);
	cout << '\n';
	post_order(0);
	cout << '\n';


	return 0;
}