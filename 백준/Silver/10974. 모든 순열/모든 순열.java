import java.io.*;

public class Main {
    public static int[] check;
    public static int[] sol;
    public static BufferedWriter bw;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        check = new int[N+1];
        sol = new int[N+1];

        dfs(N,0);

        bw.close();

    }

    public static void dfs(int n, int count) throws IOException {
        if (count == n) {
            for (int i = 1; i <= n; i++) {
                bw.write(sol[i]+" ");
            }
            bw.write("\n");
            bw.flush();
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (check[i] == 0) {
                check[i] = 1;
                sol[count+1] = i;
                dfs(n, count + 1);
                check[i] = 0;
            }
        }
    }
}