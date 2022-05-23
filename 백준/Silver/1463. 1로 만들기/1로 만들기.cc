// 백준 1463번_DP_실버3_1로 만들기 문제

// arr 을 main()함수안의 지역변수로 선언했을때 메모리의 제한때문에 계속 오류가 났었다.
// 메모리의 사용이 많은경우 data영역에 자료를 저장하는 전역변수나 정적변수(static)을 사용하자.
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1000001];

int main() {

	

	cin >> N;

	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;	// -1한 경우
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i/2]+1);		// -1한 경우와 2로 나눈경우 중 최솟값
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);		// (-1한 경우 or 2로 나눈 경우)와 3으로 나눈경우 중 최솟값
		}
	}

	cout << arr[N];


	return 0;
}