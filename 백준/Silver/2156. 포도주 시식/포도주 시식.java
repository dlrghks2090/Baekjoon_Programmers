import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n+1];
        int[][] dp = new int[n+1][4];
        int sol=0;
        int tmp=0;

        // 포도주 양을 넣은 배열 생성
        for (int i=1; i<=n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        dp[1][0] = 0;
        dp[1][1] = arr[1];
        dp[1][2] = 0;
        dp[1][3] = Math.max(dp[1][0],dp[1][1]);
        sol = dp[1][3];
        for (int i=2; i<=n; i++) {
            dp[i][0] = dp[i-1][3];
            dp[i][1] = dp[i-1][0] + arr[i];
            dp[i][2] = dp[i-1][1] + arr[i];
            tmp = Math.max(dp[i][0],dp[i][1]);
            tmp = Math.max(tmp,dp[i][2]);
            dp[i][3] = tmp;
            sol = Math.max(sol,tmp);
        }

        bw.write(sol+"");
        bw.flush();
        bw.close();
    }
}