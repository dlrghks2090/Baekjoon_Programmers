import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n + 1][10];
        int sol=0;

        for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i+1][j] += dp[i][k];
                }
                dp[i+1][j] %= 10007;
            }
        }

        for (int i = 0; i <= 9; i++) {
            sol += dp[n][i];
        }

        sol %= 10007;

        bw.write(sol + "");
        bw.flush();

        bw.close();

    }
}