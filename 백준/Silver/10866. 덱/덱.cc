#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> d_q;
	string str;
	int N;
	int num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push_front") {
			cin >> num;
			d_q.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			d_q.push_back(num);
		}

		else if (str == "pop_front") {
			if (!d_q.empty()) {
				cout << d_q.front() << '\n';
				d_q.pop_front();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (str == "pop_back") {
			if (!d_q.empty()) {
				cout << d_q.back() << '\n';
				d_q.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}

		else if (str == "size") {
			cout << d_q.size() << '\n';
		}
		else if (str == "empty") {
			if (d_q.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "front") {
			if (!d_q.empty()) {
				cout << d_q.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (str == "back") {
			if (!d_q.empty()) {
				cout << d_q.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}


	return 0;
}