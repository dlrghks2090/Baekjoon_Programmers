import java.io.*;

public class Main {

    public static int[][] check = new int[502][502];
    public static int[][] arr;
    public static int n,m;
    public static int sol=0;
    public static int[] row = {1,0,-1,0};
    public static int[] col = {0,1,0,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        arr = new int[n+2][m+2];

        // 수가 적혀 있는 배열 생성
        for (int i = 1; i <= n; i++) {
            String[] tmp = br.readLine().split(" ");
            for (int j = 1; j <= m; j++) {
                arr[i][j] = Integer.parseInt(tmp[j-1]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                rec(i,j,0,0);
            }
        }

        // ㅗ ㅜ 모양
        for (int i=1; i<=n-1; i++) {
            for (int j=1; j<=m-2; j++) {
                // ㅜ 모양
                sol = Math.max(sol, arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]);
                // ㅗ 모양
                sol = Math.max(sol, arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2]+arr[i][j+1]);
            }
        }

        // ㅏ ㅓ 모양
        for (int i=1; i<=n-2; i++) {
            for (int j=1; j<=m-1; j++) {
                // ㅏ 모양
                sol = Math.max(sol, arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j+1]);
                // ㅓ 모양
                sol = Math.max(sol, arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1]+arr[i+1][j]);
            }
        }

        bw.write(sol+"");
        bw.flush();
        bw.close();

    }

    public static void rec(int idx1, int idx2, int count, int total){
        if (count == 4) {
            sol = Math.max(sol, total);
            return;
        }

        for (int i=0; i<4; i++){
            if (0 <= idx1+row[i] && idx1+row[i] <= n) {
                if (0 <= idx2+col[i] && idx2+col[i] <= m) {
                    if (check[idx1+row[i]][idx2+col[i]] == 0) {
                        check[idx1 + row[i]][idx2 + col[i]] = 1;
                        rec(idx1 + row[i], idx2 + col[i], count+1, total+arr[idx1 + row[i]][idx2 + col[i]]);
                        check[idx1 + row[i]][idx2 + col[i]] = 0;
                    }
                }
            }
        }
    }
}