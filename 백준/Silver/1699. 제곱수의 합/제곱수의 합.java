import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n+1];

        double num = n;
        int count = 0;

        dp[1] = 1;

        // 제곱수로 이루어진 수 들 1로 설정
        for (int i=2; i*i<=n; i++) {
            dp[i*i] = 1;
        }

        for(int i=2;i<=n;i++){
            if (dp[i] == 0){
                dp[i] = 1000000;
                for(int j=1;j<=i/2;j++){
                    dp[i] = Math.min(dp[i], dp[j] + dp[i-j]);
                }
            }
        }

        bw.write(dp[n] + "");

        bw.flush();
        bw.close();
    }
}