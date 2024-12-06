import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n+1][3];
        int[][] dp = new int[n+1][3];
        int sol;

        for (int i = 1; i <= n; i++) {
            String str = br.readLine();
            String[] tmp = str.split(" ");
            arr[i][0] = Integer.parseInt(tmp[0]);
            arr[i][1] = Integer.parseInt(tmp[1]);
            arr[i][2] = Integer.parseInt(tmp[2]);
        }

        dp[1][0] = arr[1][0];
        dp[1][1] = arr[1][1];
        dp[1][2] = arr[1][2];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
            dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
            dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
        }

        sol = Math.min(dp[n][0], dp[n][1]);
        sol = Math.min(dp[n][2], sol);

        bw.write(sol + "");

        bw.flush();
        bw.close();
    }
}