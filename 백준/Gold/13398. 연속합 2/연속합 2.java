import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        long[] arr = new long[n+1];
        long[][] dp = new long[n+1][2];
        long sol;

        for (int i = 0; i < n; i++) {
            arr[i+1] = Integer.parseInt(str[i]);
        }

        sol = arr[1];
        dp[1][0] = arr[1];
        if (n > 1) {
            dp[1][1] = 0;
        }
        else {
            dp[1][1] = arr[1];
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = Math.max(dp[i-1][0] + arr[i], arr[i]);   // 1개의 숫자를 빼지 않은경우 최대
            dp[i][1] = Math.max(dp[i-1][1]+arr[i], dp[i-1][0]); // 1개의 숫자를 뺀경우 최대
            sol = Math.max(Math.max(dp[i][0], dp[i][1]), sol);
        }

        bw.write(sol+"");
        bw.flush();
        bw.close();

    }
}