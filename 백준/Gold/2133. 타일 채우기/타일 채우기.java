/*
    dp[1] = ?
    dp[2] = 3*1 + 2*0 = 3
    dp[3] = ?
    dp[4] = 3*3 + 2*1 = 11
    dp[5] = ?
    dp[6] = 3*3*3 + 3*2*2 + 2*1 = 27+12+2 = 41
    dp[7] = 0
    dp[8] = 3*3*3*3 + 3*2*3*3 + 2*2 + 2*3*2 + 2*1 = 81+54+12+4+2 = 153
    .
    .
    dp[n] = 4*dp[n-2] - dp[n-4];
 */

import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n+1];

        if (n == 1) {
            bw.write(0 + "");
        }
        else {

            dp[0] = 1;
            dp[2] = 3;
            for (int i = 4; i <= n; i = i + 2) {
                dp[i] = dp[i - 2] * 4 - dp[i - 4];
            }

            bw.write(dp[n] + "");
        }
        bw.flush();
        bw.close();
    }
}