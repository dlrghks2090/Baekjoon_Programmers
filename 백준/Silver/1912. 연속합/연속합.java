import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] arr = new int[n+1];
        int[] dp = new int[n+1];
        int sol=0;

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(str[i-1]);
        }

        sol = arr[1];
        for (int i=1; i<=n; i++) {
            if (dp[i-1] + arr[i] > arr[i]) {
                dp[i] = dp[i-1] + arr[i];
            }
            else {
                dp[i] = arr[i];
            }
            if (sol < dp[i]) {
                sol = dp[i];
            }
        }

        bw.write(sol+"");

        bw.flush();
        bw.close();

    }
}