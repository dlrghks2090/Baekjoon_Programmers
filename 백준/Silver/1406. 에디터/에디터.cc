#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {

	string str;
	stack<char> stk1;
	stack<char> stk2;
	int N, M;
	char comm;
	char ele;

	cin >> str;

	N = str.size();

	cin >> M;

	for (int i = 0; i < N; i++) {
		stk1.push(str[i]);
	}

	for (int i = 0; i < M; i++) {
		cin >> comm;


		if (comm == 'L') {
			if (!stk1.empty()) {
				stk2.push(stk1.top());
				stk1.pop();
			}
			
		}
		else if (comm == 'D') {
			if (!stk2.empty()) {
				stk1.push(stk2.top());
				stk2.pop();
			}
		}
		else if (comm == 'B') {
			if (!stk1.empty()) {
				stk1.pop();
			}
		}
		else if (comm == 'P') {
			cin >> ele;
			stk1.push(ele);
		}
	}

	while (!stk1.empty()) {
		stk2.push(stk1.top());
		stk1.pop();
	}

	while (!stk2.empty()) {
		cout << stk2.top();
		stk2.pop();
	}


	return 0;
}