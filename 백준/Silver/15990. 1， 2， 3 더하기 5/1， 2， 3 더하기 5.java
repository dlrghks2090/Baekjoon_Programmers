import java.io.*;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long[][] dp = new long[100001][4];
        int top=0;

        dp[1][1] = 1;
        dp[2][2] = 1;
        dp[3][1] = 1;
        dp[3][2] = 1;
        dp[3][3] = 1;

        // dp[n][1] = dp[n-1][2] + dp[n-1][3];
        // dp[n][2] = dp[n-2][1] + dp[n-2][3];
        // dp[n][3] = dp[n-3][1] + dp[n-3][2];

        int T = Integer.parseInt(br.readLine());
        int[] test = new int[T];

        for (int i=0; i<T; i++) {
            test[i] = Integer.parseInt(br.readLine());
            if (top < test[i]) {
                top = test[i];
            }
        }


        for (int i=4; i<=top; i++) {
            dp[i][1] = (dp[i-1][2] + dp[i-1][3])%1000000009;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3])%1000000009;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2])%1000000009;
        }

        for (int i=0; i<T; i++) {
            bw.write((dp[test[i]][1] + dp[test[i]][2] + dp[test[i]][3])%1000000009 + "\n");
        }

        bw.flush();
        bw.close();
    }
}