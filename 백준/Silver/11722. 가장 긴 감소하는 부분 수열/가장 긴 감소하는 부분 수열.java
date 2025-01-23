import java.io.*;
import java.util.Stack;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n+1];
        int[][] dp = new int[n+1][2];   // 0번째는 현재 원소까지의 최대 길이, 1번째는 직전 원소 인덱스(0이면 직전원소가 없다.)
        int sol = 0;
        int sol_last_idx=0;

        String[] str = br.readLine().split(" ");

        // 수 배열 세팅
        for (int i = 0; i < n; i++) {
            arr[i+1] = Integer.parseInt(str[i]);
            dp[i+1][0] = 1; // 자기자신은 1이므로 1로 초기화
        }

        dp[1][0] = 1;
        dp[1][1] = 0;
        sol = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j<i; j++) {
                if (arr[i] < arr[j]) {
                    if (dp[i][0] < dp[j][0] + 1) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = j;
                    }
                }
            }
            if (sol < dp[i][0]) {
                sol = dp[i][0];
                sol_last_idx = i;
            }
        }

//        Stack<Integer> st = new Stack<>();
//
//        while(true) {
//            if (sol_last_idx == 0) {
//                break;
//            }
//            st.push(arr[sol_last_idx]);
//            sol_last_idx = dp[sol_last_idx][1];
//        }

//        while (!st.isEmpty()) {
//
//        }

        bw.write(sol + "");
        bw.flush();
        bw.close();

    }
}