import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] dp = new int[n];
        int sol=0;

        String[] str = br.readLine().split(" ");

        // 숫자 배열 세팅
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }

        dp[0] = arr[0];

        sol = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + arr[i]);
                }
                sol = Math.max(sol, dp[i]);
            }
        }

        bw.write(sol+"");
        bw.flush();
        bw.close();
    }
}