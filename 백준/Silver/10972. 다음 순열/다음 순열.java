import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] arr = new int[N];
        int flag = 0;
        int tmp;

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }

        // 뒷 부분에서 내림차순 부분 수열 탐색
        for (int i = N-1; i > 0; i--) {
            // 부분수열을 탐색해냈을때
            if (arr[i] > arr[i-1]) {
                // 부분수열 이전 원소중
                for (int j = N-1; j >= i; j--) {

                    if (arr[j] > arr[i-1]) {
                        tmp = arr[j];
                        arr[j] = arr[i-1];
                        arr[i-1] = tmp;
                        Arrays.sort(arr, i, N); // i ~ N-1까지 오름차순 정렬
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                break;
        }

        if (flag == 0) {
            bw.write("-1\n");
        }
        else {
            for (int i = 0; i < N; i++) {
                bw.write(arr[i] + " ");
            }
        }

        bw.flush();
        bw.close();
    }
}