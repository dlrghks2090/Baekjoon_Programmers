import java.io.*;
import java.util.Arrays;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N+1];
        int[] dp = new int[N+1];
        int sol = 1;
        int sol_idx = 0;

        // 자기 자신이 최소이기때문에 1로 초기화
        Arrays.fill(dp, 1);

        int[] pre_idx = new int[N+1];
        Stack<Integer> stack = new Stack<>();

        String[] str = br.readLine().split(" ");
        // 숫자로 변환하여 배열 설정
        for (int i=1; i<=N; i++) {
            arr[i] = Integer.parseInt(str[i-1]);
        }

        dp[1] = 1;
        sol_idx = 1;
        pre_idx[1] = 0; // 1번째 원소의 이전 원소를 0번째로 가리키도록 하여 종료 포인트 지정
        // 배열의 2번째 요소부터 마지막까지 체크
        for (int i=2; i<=N; i++) {
            for (int j = 1; j < i; j++) {
                if (arr[i] > arr[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        pre_idx[i] = j;
                    }
                    // 현재 i원소까지의 최대 수열길이와 j번째수열길이 +1 이 같을때
                    else if (dp[i] == dp[j] + 1) {
                        // 저장된 최대 수열의 i번째 직전 원소값 보다 j번째 원소값이 더 작다면 갱신
                        if (arr[j] < arr[pre_idx[i]]) {
                            pre_idx[i] = j;
                        }
                    }
                }
            }
            // 현재 최대 수열 길이보다 i번째까지의 최대길이수열이 더 길다면 갱신
            if (sol < dp[i]) {
                sol = dp[i];
                sol_idx = i;
            }
        }

        // 가장 긴 증가하는 부분 수열 길이 출력
        bw.write(sol + "\n");

        int k = sol_idx;
        while (k != 0) {
            stack.push(arr[k]);
            k = pre_idx[k];
        }

        while (!stack.isEmpty()) {
            bw.write(stack.pop() + " ");
        }

        bw.flush();
        bw.close();

    }
}