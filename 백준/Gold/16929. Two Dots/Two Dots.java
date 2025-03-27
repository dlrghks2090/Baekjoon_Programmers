import java.io.*;

public class Main {

    public static int N;
    public static int M;
    public static char[][] map;
    public static int[][] check;
    public static int[] m_r = {0,1,0,-1};
    public static int[] m_c = {1,0,-1,0};
    public static String sol = "No";
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        map = new char[N][M];
        check = new int[N][M];

        // map 세팅
        for (int i = 0; i < N; i++) {
            String str2 = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = str2.charAt(j);
            }
        }

        for (int i=0; i < N; i++) {
            for (int j=0; j < M; j++) {
                if (check[i][j] == 0) {
                    dfs(i,j,i, j, 0);
                }
            }
            if (sol.equals("Yes")) {
                break;
            }
        }

        bw.write(sol+"\n");
        bw.flush();
        bw.close();
        br.close();
    }

    public static void dfs(int s_row, int s_col, int row, int col, int count) {

        check[row][col] = 1;
        for (int i=0; i<4; i++) {
            // 이동위치가 map 범위 내
            if (0<=row+m_r[i] && row+m_r[i]<N && 0<=col+m_c[i] && col+m_c[i]<M) {
                // 같은 문자이고
                if (map[row+m_r[i]][col+m_c[i]] == map[row][col]) {
                    if (count>2 && s_row==row+m_r[i] && s_col==col+m_c[i]) {
                        sol = "Yes";
                        return;
                    }
                    // 거쳐가지 않은 지점일때
                    if (check[row+m_r[i]][col+m_c[i]] == 0) {
                        dfs(s_row, s_col, row + m_r[i], col + m_c[i], count + 1);
                        check[row + m_r[i]][col + m_c[i]] = 0;
                    }
                }
            }
        }
    }
}