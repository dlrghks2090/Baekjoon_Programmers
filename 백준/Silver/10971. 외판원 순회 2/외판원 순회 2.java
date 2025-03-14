import java.io.*;
import java.util.Arrays;

public class Main {
    public static int[] check;  // 지나간 도시 체크
    public static int sol = 100000000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][N];
        check = new int[N];

        // 도시 사이의 이동비용 배열 세팅
        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(str[j]);
            }
        }

        check[0] = 1;
        dfs(arr, 0, 1, 0);

        bw.write(sol+"");
        bw.flush();
        bw.close();

    }

    public static void dfs(int[][] arr, int spot, int count, int total) {
        // 마지막 도시에 도착했을때가 탈출조건
        if (count == arr.length && arr[spot][0] != 0) {
            // 마지막 도시에서 첫번째 도시로 이동할때 비용 추가
            total += arr[spot][0];
            // 최소 비용 체크
            if (sol > total) {
                sol = total;
            }
            return;
        }

        for (int i = 0; i < arr.length; i++) {
            if (check[i] == 0 && arr[spot][i] != 0) {
                check[i] = 1;
//                System.out.println("node= " + i + "  count= " + (count+1) + " total= " + (total+arr[spot][i]));
                dfs(arr, i, count + 1, total+arr[spot][i]);
//                System.out.println("                   이전으로  count= " + count);
                check[i] = 0;
            }
        }
    }
}