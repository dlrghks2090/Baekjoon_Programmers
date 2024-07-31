#include<iostream>

using namespace std;

int arr[500][500];
int max_r;
int max_c;
int r_tmp[4] = {0, 1, 0, -1};
int c_tmp[4] = {1, 0, -1, 0};
int dp[500][500];
int check=0;

int dfs(int row, int col) {
    check +=1;
    if (row == max_r && col == max_c) {
        return 1;
    }

    // 중복을 방문을 방지
    if(dp[row][col] != -1) {
        return dp[row][col];
    }
    dp[row][col] = 0;

    for (int i=0; i<4; i++) {
        if (row+r_tmp[i]>=0 && row+r_tmp[i] <= max_r && col+c_tmp[i] >=0 && col+c_tmp[i] <= max_c) {
            if (arr[row+r_tmp[i]][col+c_tmp[i]] < arr[row][col]){
                dp[row][col] += dfs(row+r_tmp[i], col+c_tmp[i]);
            }
        }
    }
    return dp[row][col];
}

int main() {

    ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

    int n,m;

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    max_r = n-1;
    max_c = m-1;

    cout << dfs(0,0) << '\n';
    //cout << "count= " << check << '\n';

    return 0;
}