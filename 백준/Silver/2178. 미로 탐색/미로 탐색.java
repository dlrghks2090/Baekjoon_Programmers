import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main{
    public static int[][] map;
    public static int[][] check;
    public static int N;
    public static int M;
    public static int[] m_row = {0,1,0,-1};
    public static int[] m_col = {1,0,-1,0};
    public static int sol = 10000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        map = new int[N+1][M+1];
        check = new int[N+1][M+1];

        // map 세팅
        for (int i = 1; i <= N; i++) {
            String input = br.readLine();
            for (int j = 1; j <= M; j++) {
                map[i][j] = input.charAt(j-1) - '0';
            }
        }

        bfs(1,1);

        bw.write(sol+"");
        bw.flush();
        bw.close();
        br.close();
    }

    public static void bfs(int row, int col) {
        Queue<int[]> que = new LinkedList<>();

        que.add(new int[] {row,col,1});
        check[row][col] = 1;
        while (!que.isEmpty()) {
            int[] arr = que.poll();
            if (arr[0] == N && arr[1] == M) {
                sol = arr[2];
                return;
            }
            for (int i=0; i<4; i++) {
                // map의 범위를 넘기지 않고
                if (0 < arr[0]+m_row[i] && arr[0]+m_row[i] <= N && 0 < arr[1]+m_col[i] && arr[1]+m_col[i] <= M) {
                    // 1인 지점중 아직 거쳐가지 않은 지점일때
                    if (check[arr[0]+m_row[i]][arr[1]+m_col[i]]==0 && map[arr[0]+m_row[i]][arr[1]+m_col[i]]==1) {
                        check[arr[0]+m_row[i]][arr[1]+m_col[i]]=1;
                        que.add(new int[] {arr[0]+m_row[i],arr[1]+m_col[i],arr[2]+1});
                    }
                }
            }
        }
    }

//    public static void dfs(int row, int col, int count) {
//        count++;
//
//        if (row == N && col == M) {
//            if (sol > count) {
//                sol = count;
//            }
//            return;
//        }
//
//        check[row][col] = 1;
//
//        for (int i=0; i<4; i++) {
//            // map의 범위를 넘기지 않고
//            if (0 < row+m_row[i] && row+m_row[i] <= N && 0 < col+m_col[i] && col+m_col[i] <= M) {
//                // 1인 지점중 아직 거쳐가지 않은 지점일때
//                if (check[row+m_row[i]][col+m_col[i]]==0 && map[row+m_row[i]][col+m_col[i]]==1) {
//                    dfs(row+m_row[i],col+m_col[i],count);
//                    // 위 dfs에서 거쳐간 지점을 다시 거쳐갈 수 있도록 0으로 초기화
//                    check[row+m_row[i]][col+m_col[i]] = 0;
//                }
//            }
//        }
//    }
}