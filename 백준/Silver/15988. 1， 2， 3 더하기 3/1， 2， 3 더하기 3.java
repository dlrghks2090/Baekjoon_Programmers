import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        long[] dp = new long[1000001];
        int max_idx=3;

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 0; i < T; i++) {
            int n = Integer.parseInt(br.readLine());

            if (n > max_idx) {
                for (int j = max_idx+1; j <= n; j++) {
                    dp[j] = (dp[j-1] + dp[j-2] + dp[j-3])%1000000009;
                }
                max_idx = n;
            }

            bw.write(dp[n] + "\n");
            bw.flush();
        }

        bw.close();
    }
}