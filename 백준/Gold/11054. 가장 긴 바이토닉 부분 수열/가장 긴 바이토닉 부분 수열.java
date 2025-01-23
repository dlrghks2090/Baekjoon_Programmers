import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n+1];
        int[] dp1 = new int[n+1];   // 왼쪽부터 가장 긴 증가하는 부분 수열 개수
        int[] dp2 = new int[n+1];   // 오른쪽부터 가장 긴 증가하는 부분 수열 개수

        String[] str = br.readLine().split(" ");

        int sol = 0;

        // 숫자 배열 세팅
        for (int i=0; i<n; i++) {
            arr[i+1] = Integer.parseInt(str[i]);
        }

        dp1[1] = 1;
        for (int i=2; i<=n; i++) {
            dp1[i] = 1;
            for (int j=1; j<i; j++) {
                if (arr[i] > arr[j]) {
                    dp1[i] = Math.max(dp1[i], dp1[j] + 1);
                }
            }
        }

        dp2[n] = 1;
        for (int i=n-1; i>=1; i--) {
            dp2[i] = 1;
            for (int j=n; j>=i; j--) {
                if (arr[i] > arr[j]) {
                    dp2[i] = Math.max(dp2[i], dp2[j] + 1);
                }
            }
        }

        for (int i=1; i<=n; i++) {
            sol = Math.max(sol, dp1[i] + dp2[i]-1);
        }

        bw.write(sol+"");
        bw.flush();
        bw.close();

    }
}