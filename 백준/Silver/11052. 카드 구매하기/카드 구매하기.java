import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] arr = new int[n+1];
        int[] dp = new int[n+1];

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(str[i-1]);
        }

        dp[1] = arr[1];
//        bw.write(dp[1] + " ");

        for (int i = 2; i <= n; i++) {
            dp[i] = arr[i];
            for (int j = 1; j <= i/2; j++) {
                if (dp[i] < dp[j] + dp[i-j]) {
                    dp[i] = dp[j] + dp[i-j];
                }
            }
//            bw.write(dp[i] + " ");
        }

//        bw.write("\n");
        bw.write(dp[n]+"");

        bw.flush();
        bw.close();
    }
}