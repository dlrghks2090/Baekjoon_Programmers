import java.io.*;

/*
    ~~~|
    ~~=
    ~~ㅁ
    와 같이 마지막의 모양이 총 3가지만 올 수 있다.
    => dp[n] = dp[n-1] + 2*dp[n-2]
 */

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = new int[1001];  // 0으로 초기화

        int n = Integer.parseInt(br.readLine());

        arr[1] = 1;
        arr[2] = 3;

        for (int i = 3; i <= n; i++) {
            arr[i] = (arr[i - 1] + 2*arr[i - 2]) % 10007;
        }

        bw.write(arr[n] + "");

        bw.flush();
        bw.close();
    }
}