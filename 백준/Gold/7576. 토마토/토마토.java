import java.io.*;
import java.sql.SQLOutput;
import java.util.LinkedList;
import java.util.Queue;

public class Main{
    public static int[][] map;
    public static int[][] check;
    public static int N;
    public static int M;
    public static int[] m_row = {0,1,0,-1};
    public static int[] m_col = {1,0,-1,0};

    public static int sol = -1;
    public static Queue<int[]> que = new LinkedList<>();
    public static int total_tomato=0;
    public static int ripe_tomato=0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        map = new int[M+1][N+1];
        check = new int[M+1][N+1];

        // map, queue, 총 토마토개수 세팅
        for (int i = 1; i <= M; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 1; j <= N; j++) {
                map[i][j] = Integer.parseInt(input[j-1]);
                // 안익은 토마토일때
                if (map[i][j] == 0) {
                    total_tomato++;
                }
                // 익은토마토일때
                else if (map[i][j] == 1) {
                    total_tomato++;
                    ripe_tomato++;
                    que.add(new int[]{i, j, 0});
                    check[i][j] = 1;
                }
            }
        }
        
        bfs();

        if (ripe_tomato == total_tomato) {
            bw.write(sol+"");
        }
        else {
            bw.write("-1");
        }
        
        bw.flush();
        bw.close();
        br.close();
    }

    public static void bfs() {

        while (!que.isEmpty()) {
            int[] arr = que.poll();
            sol = arr[2];
            for (int i=0; i<4; i++) {
                // map의 범위를 넘기지 않고
                if (0 < arr[0]+m_row[i] && arr[0]+m_row[i] <= M && 0 < arr[1]+m_col[i] && arr[1]+m_col[i] <= N) {
                    // 익지 않은 토마토 중 아직 거쳐가지 않은 토마토일때
                    if (check[arr[0]+m_row[i]][arr[1]+m_col[i]]==0 && map[arr[0]+m_row[i]][arr[1]+m_col[i]]==0) {
                        check[arr[0]+m_row[i]][arr[1]+m_col[i]]=1;
                        que.add(new int[] {arr[0]+m_row[i],arr[1]+m_col[i],arr[2]+1});
                        ripe_tomato++;
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