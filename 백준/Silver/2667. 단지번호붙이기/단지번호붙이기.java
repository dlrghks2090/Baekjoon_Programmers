import java.io.*;
import java.util.*;

public class Main {

    public static int[][] map;
    public static int[][] check;
    public static int[] m_row = {0, 1, 0, -1};
    public static int[] m_col = {1, 0, -1, 0};
    public static ArrayList<Integer> sol = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        map = new int[N+2][N+2];
        check = new int[N+2][N+2];

        // map 세팅
        for (int i = 1; i <= N; i++) {
            String str = br.readLine();
            for (int j=1; j<=str.length(); j++) {
                map[i][j] = str.charAt(j-1) - '0';
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] != 0 && check[i][j] == 0) {
                    sol.add(bfs(i, j));
                }
            }
        }

        Collections.sort(sol);


        bw.write(sol.size() + "\n");
        for (int i = 0; i < sol.size(); i++) {
            bw.write(sol.get(i) + "\n");
        }
        bw.flush();
        bw.close();

    }

    public static int bfs(int row, int col) {
        int count = 0;
        Queue<int[]> que = new LinkedList<>();
        check[row][col] = 1;
        que.offer(new int[] {row, col});

        while (!que.isEmpty()) {
            int[] arr = que.poll();
            count++;

            for (int i = 0; i < 4; i++) {
                if (map[arr[0] + m_row[i]][arr[1] + m_col[i]] != 0 && check[arr[0] + m_row[i]][arr[1] + m_col[i]] == 0) {
                    check[arr[0] + m_row[i]][arr[1] + m_col[i]] = 1;
                    que.offer(new int[] {arr[0] + m_row[i], arr[1] + m_col[i]});
                }
            }
        }

        return count;
    }
}