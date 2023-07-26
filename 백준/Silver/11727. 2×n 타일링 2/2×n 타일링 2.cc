// 백준_실버3_DP_2*n타일링2
/*
풀이>
문제에서 주어졌다시피, 타일의 끝은 총 3가지 경우만 올 수 있다.
	1. ~~~|
	2. ~~~~=
	3. ~~~~ㅁ 

=> 따라서 dp[n]을 구할때도 이 세 경우의 수를 구해 더한값이 2*n타일의  모든 경우를 센것이 된다.

=> dp[n] = dp[n-1] + dp[n-2] + dp[n-2];
*/


#include<iostream>


using namespace std;

int main() {

	int n;
	int* dp;

	cin >> n;

	dp = new int[n + 1]{ 0, };

	

	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2])%10007;
	}
	
	cout << dp[n];

	delete[] dp;

	return 0;
}