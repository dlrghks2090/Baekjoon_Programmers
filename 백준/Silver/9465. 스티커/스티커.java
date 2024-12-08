import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        // 테스트 케이스 t번 실행
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            String[] str1 = br.readLine().split(" ");
            String[] str2 = br.readLine().split(" ");
            int[][] arr = new int[3][n+2];
            int[][] dp = new int[3][n+2];
            int[] dp2 = new int[n+2];
            int sol = 0;

            for (int j = 1; j <= n; j++) {
                arr[0][j] = Integer.parseInt(str1[j-1]);
                arr[1][j] = Integer.parseInt(str2[j-1]);
            }

            dp[0][1] = arr[0][1];
            dp[1][1] = arr[1][1];
            sol = Math.max(dp[0][1],dp[1][1]);
//            bw.write("dp[0]["+ 1 + "] = " + dp[0][1] + "\n");
//            bw.write("dp[1]["+ 1 + "] = " + dp[1][1] + "\n");
//            bw.write("sol= " + sol + "\n\n");

            for (int j = 2; j <= n; j++) {
                dp[0][j] = Math.max(arr[0][j]+dp[1][j-1], arr[0][j]+dp[1][j-2]);
                dp[1][j] = Math.max(arr[1][j]+dp[0][j-1], arr[1][j]+dp[0][j-2]);
                dp2[j] = Math.max(dp[0][j], dp[1][j]);
                sol = Math.max(sol,dp2[j]);

//                bw.write("dp[0]["+ j + "] = " + dp[0][j] + "\n");
//                bw.write("dp[1]["+ j + "] = " + dp[1][j] + "\n");
//                bw.write("sol= " + sol + "\n\n");
            }
            bw.write(sol + "\n");
            bw.flush();
        }
        bw.close();

    }
}