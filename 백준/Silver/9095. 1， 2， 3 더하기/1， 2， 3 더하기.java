import java.io.*;

public class Main {
    public static int sol=0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for (int i=0; i<T; i++) {
            sol = 0;
            int N = Integer.parseInt(br.readLine());
            rec(N, 0);

            bw.write(sol+"\n");
            bw.flush();
        }

        bw.close();

    }

    public static void rec(int n, int total) {
        if (total == n) {
            sol++;
            return;
        }

        for (int i=1; i<=3; i++) {
            if (total+i <= n) {
                rec(n, total+i);
            }
        }
    }
}