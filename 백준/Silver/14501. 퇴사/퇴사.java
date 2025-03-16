import java.io.*;

public class Main {
    public static BufferedWriter bw;
    public static int sol=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] t = new int[N+1];
        int[] p = new int[N+1];

        // index 1부터 배열 세팅
        for (int i = 1; i <= N; i++) {
            String[] s = br.readLine().split(" ");
            t[i] = Integer.parseInt(s[0]);
            p[i] = Integer.parseInt(s[1]);
        }
        dfs(t,p,N,1,0);

        bw.write(sol+"");
        bw.flush();
        bw.close();
    }

    public static void dfs(int[] t, int[] p, int n, int start, int total) {
        if (sol < total) {
            sol = total;
//            System.out.println("        sol= " + sol + "      ");
        }

        for (int i = start; i < t.length; i++) {
            if (i+t[i]-1 <= n) {
//                System.out.println("i= " + i + " t= " + t[i] + " p= " + p[i] + " total= " + total);
                dfs(t, p, n, i + t[i], total + p[i]);
            }
        }
    }

}