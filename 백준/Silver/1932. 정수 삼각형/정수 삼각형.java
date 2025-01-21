import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int[][] arr = new int[n+1][n+2];
        int[][] dp = new int[n+1][n+2];

        int sol=0;

        // arr 채우기
        for (int i = 1; i <= n; i++) {
            String[] str = (br.readLine()).split(" ");
            for (int j = 1; j <= i; j++) {
                arr[i][j] = Integer.parseInt(str[j-1]);
            }
        }

        if (n == 1) {
            sol = arr[1][1];
        }
        else {
            for (int i = 1; i <= n; i++) {
                dp[n][i] = arr[n][i];
            }

            for (int i = n-1; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                    dp[i][j] = Math.max(arr[i][j] + dp[i+1][j], arr[i][j] + dp[i+1][j+1]);
                }
            }
            sol = dp[1][1];
        }

        bw.write(sol+"\n");
        bw.flush();
        bw.close();

    }
}