import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static int[][] map;
    public static int[][] check;
    public static int[] m_x = {-2,-1,1,2,2,1,-1,-2};
    public static int[] m_y = {1,2,2,1,-1,-2,-2,-1};
    public static int sol;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            int l = Integer.parseInt(br.readLine());
            String[] str = br.readLine().split(" ");
            int start_x = Integer.parseInt(str[0]);
            int start_y = Integer.parseInt(str[1]);
            String[] str2 = br.readLine().split(" ");
            int end_x = Integer.parseInt(str2[0]);
            int end_y = Integer.parseInt(str2[1]);

            map = new int[l][l];
            check = new int[l][l];

            bfs(l,start_x,start_y,end_x,end_y);
            bw.write(sol+"\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

    public static void bfs(int l, int start_x,int start_y,int end_x,int end_y) {
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[]{start_x, start_y, 0});
        check[start_x][start_y] = 1;

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            if (cur[0] == end_x && cur[1] == end_y) {
                sol = cur[2];
                return;
            }

            for (int i=0; i<8; i++) {
                // 이동이 맵 범위 안일때
                if (0 <= cur[0]+m_x[i] && cur[0]+m_x[i] < l && 0 <= cur[1]+m_y[i] && cur[1]+m_y[i] < l) {
                    // 거쳐가지 않은 지점일때
                    if (check[cur[0]+m_x[i]][cur[1]+m_y[i]] == 0) {
                        que.add(new int[] {cur[0]+m_x[i],cur[1]+m_y[i],cur[2]+1});
                        check[cur[0]+m_x[i]][cur[1]+m_y[i]] = 1;
                    }
                }
            }

        }
    }
}