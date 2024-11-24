import java.io.*;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long[][] dp = new long[101][10];
        long sol=0;

        for (int i = 1; i < 10; i++){
            dp[1][i] = 1;
        }

        int N = Integer.parseInt(br.readLine());

        for (int i = 2; i<=N; i++) {
            dp[i][0] = dp[i-1][1]%1000000000;
            for (int j = 1; j<=8; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
            }
            dp[i][9] = dp[i-1][8]%1000000000;
        }

        for (int i = 0; i<=9; i++) {
            sol = sol + dp[N][i];
        }

        bw.write(sol%1000000000+"");

        bw.flush();
        bw.close();
    }
}