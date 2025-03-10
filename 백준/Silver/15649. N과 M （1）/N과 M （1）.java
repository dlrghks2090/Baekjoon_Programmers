import java.io.*;

public class Main {
    public static int[] sol = new int[10];
    public static int[] check = new int[10];
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);

        rec(N,M,0);

        bw.close();
    }

    public static void rec(int n, int m, int count) throws IOException {
        if (count == m) {
            for (int i=0; i<m; i++) {
                bw.write(sol[i] + " ");
            }
            bw.write("\n");
            bw.flush();
            return;
        }

        for (int i=1; i<=n; i++) {

            if (check[i] == 0) {
                check[i] = 1;
                sol[count] = i;
                rec(n, m, count + 1);
                sol[count] = 0;
                check[i] = 0;
            }
        }
    }

}