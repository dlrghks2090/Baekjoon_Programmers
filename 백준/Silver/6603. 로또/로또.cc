#include<iostream>
#include<stack>

using namespace std;



int arr[14];
stack<int> st;
int sol[6];
int k;


void dfs(int n, int count) {

	if (count == 6) {
		for (int i = 0; i < 6; i++) {
			cout << sol[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = n; i < k; i++) {
		sol[count] = arr[i];
		dfs(i + 1, count + 1);
	}


}

int main() {


	while (1) {

		cin >> k;
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		dfs(0,0);
		cout << '\n';
	}




	return 0;
}