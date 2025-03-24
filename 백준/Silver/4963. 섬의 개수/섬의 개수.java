import java.io.*;
import java.util.*;

public class Main {

    public static int[][] map;
    public static int[][] check;
    public static int[] m_row = {0, 1, 0, -1, -1, 1, 1, -1};
    public static int[] m_col = {1, 0, -1, 0, 1, 1, -1, -1};
    public static ArrayList<Integer> sol = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            int count = 0;
            String[] input = br.readLine().split(" ");
            int w = Integer.parseInt(input[0]); // 너비
            int h = Integer.parseInt(input[1]); // 높이

            if (w == 0 && h == 0) {
                break;
            }
            map = new int[h + 2][w + 2];
            check = new int[h + 2][w + 2];

            // map 세팅
            for (int i = 1; i <= h; i++) {
                String[] str = br.readLine().split(" ");
                for (int j = 1; j <= str.length; j++) {
                    map[i][j] = Integer.parseInt(str[j - 1]);
                }
            }

            // 섬 개수 구하기
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    if (map[i][j] != 0 && check[i][j] == 0) {
                        bfs(i, j);
                        count++;
                    }
                }
            }
            sol.add(count);
        }

        for (int i = 0; i < sol.size(); i++) {
            bw.write(sol.get(i) + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }

    public static void bfs(int row, int col) {
        Queue<int[]> que = new LinkedList<>();
        check[row][col] = 1;
        que.offer(new int[] {row, col});

        while (!que.isEmpty()) {
            int[] arr = que.poll();

            for (int i = 0; i < 8; i++) {
                if (map[arr[0] + m_row[i]][arr[1] + m_col[i]] != 0 && check[arr[0] + m_row[i]][arr[1] + m_col[i]] == 0) {
                    check[arr[0] + m_row[i]][arr[1] + m_col[i]] = 1;
                    que.offer(new int[] {arr[0] + m_row[i], arr[1] + m_col[i]});
                }
            }
        }

    }
}