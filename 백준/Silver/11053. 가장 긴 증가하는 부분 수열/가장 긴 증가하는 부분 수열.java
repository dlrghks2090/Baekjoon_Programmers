import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] dp = new int[N+1];
        String[] str = br.readLine().split(" ");
        int[] arr = new int[N+1];
        int sol=0;

        // 정수화
        for(int i = 1; i <= N; i++){
            arr[i] = Integer.parseInt(str[i-1]);
        }

        dp[1] = 1;
        sol = 1;

        for(int i = 2; i <= N; i++){
            for(int j = i-1; j >= 0; j--){
                if (arr[i] > arr[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (dp[i] > sol) {
                sol = dp[i];
            }
        }

        bw.write(sol+"");

        bw.flush();
        bw.close();
    }
}
// 1
// 10
// 100 101
// 1000 1001 1010
// 10000 10001 10010 10100 10101