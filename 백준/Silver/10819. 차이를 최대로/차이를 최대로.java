import java.io.*;

public class Main{
    public static int[] check;
    public static int[] sol;
    public static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] arr  = new int[N];
        check = new int[N];
        sol = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }

        rec(arr,N,0);

        bw.write(answer+"");
        bw.flush();
        bw.close();

    }

    public static void rec(int[] arr, int n, int count) {
        if (n == count) {
            int tmp = 0;
            for (int i = 1; i < sol.length; i++) {
                if (sol[i] - sol[i - 1] < 0) {
                    tmp += sol[i-1] - sol[i];
                }
                else {
                    tmp += sol[i] - sol[i-1];
                }
            }
//            System.out.println("수 배열 완성! total= " + tmp);
            if (tmp > answer) {
                answer = tmp;
            }
            return;
        }

        for (int i = 0; i < arr.length; i++) {
            if (check[i] == 0) {
                check[i] = 1;
                sol[count] = arr[i];
                rec(arr, n, count + 1);
                check[i] = 0;
            }
        }
    }
}