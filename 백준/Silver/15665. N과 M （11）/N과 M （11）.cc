#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[8];
int sol[8];
int tmp;

void sequence(int count) {
	if (count > M) {
		for (int i = 1; i <= M; i++) {
			cout << sol[i] << " ";
		}
		cout << '\n';
	}
	else {
		tmp = 0;
		for (int i = 1; i <= N; i++) {

			if (arr[i] != tmp) {
				sol[count] = arr[i];
				sequence(count + 1);
			}

			tmp = arr[i];
		}
	}

}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + N);

	sequence(1);

	return 0;
}