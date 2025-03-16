import java.io.*;

public class Main {
    public static int[] check;
    public static int[] sol = new int[6];
    public static BufferedWriter bw;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true) {
            String[] str = br.readLine().split(" ");
            int k = Integer.parseInt(str[0]);
            // 입력값이 0이면 종료
            if (k == 0) {
                break;
            }
            int[] arr = new int[k];
            // 수 배열 세팅
            for (int i = 0; i < k; i++) {
                arr[i] = Integer.parseInt(str[i + 1]);
            }

            check = new int[k];
            dfs(arr, 0, 0);
            bw.newLine();
        }

        bw.close();
    }

    public static void dfs(int[] arr, int start, int count) throws IOException {
        if (count == 6) {
            for (int i = 0; i < 6; i++) {
                bw.write(sol[i]+" ");
            }
            bw.newLine();
            bw.flush();
            return;
        }

        for (int i = start; i < arr.length; i++) {
            if (check[i] == 0) {
                check[i] = 1;
                sol[count] = arr[i];
                dfs(arr, i+1, count + 1);
                check[i] = 0;
            }
        }
    }
}