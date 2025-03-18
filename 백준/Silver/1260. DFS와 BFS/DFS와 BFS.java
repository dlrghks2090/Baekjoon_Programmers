import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br;
    public static BufferedWriter bw;
    public static ArrayList<Integer>[] list;
    public static int[] check;
    public static List<Integer> sol = new ArrayList<>();

    public static int[] bfs_check;
    public static Queue<Integer> queue = new LinkedList<Integer>();
    public static List<Integer> bfs_sol = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 정점수, 간선수, 시작점 입력
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);
        int V = Integer.parseInt(str[2]);

        check = new int[N+1];     // dfs 지난 정점 체크
        bfs_check = new int[N+1];   // bfs 지난 정점 체크
        list = new ArrayList[N+1];  // 정점 별 간선이 연결된 점 체크를 위한 arrayList 배열

        // 각 정점마다 arraylist 선언
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            String[] str1 = br.readLine().split(" ");
            int a = Integer.parseInt(str1[0]);
            int b = Integer.parseInt(str1[1]);
            list[a].add(b);
            list[b].add(a);
        }

        // 각 정점과 간선으로 연결된 점들을 오름차순으로 정렬
        for (int i = 1; i <= N; i++) {
            Collections.sort(list[i]);
        }
        // 시작점 지나간것으로 체크
        check[V] = 1;
        // dfs 실행(정점수, 시작점, 거쳐간 정점수)
        dfs(V);

        for (int i = 0; i <sol.size(); i++) {
            bw.write(sol.get(i) + " ");
        }
        bw.flush();
        bw.newLine();

        bfs(V);
        for (int i = 0; i < bfs_sol.size(); i++) {
            bw.write(bfs_sol.get(i) + " ");
        }
        bw.flush();


        bw.close();
        br.close();
    }

    // 깊이 우선 탐색 (깊이 먼저 탐색한다음 없으면 돌아와서(backtraking) 다시 탐색)
    public static void dfs(int start) {

        check[start] = 1;
        sol.add(start);

        for (int i = 0; i < list[start].size(); i++) {
            if (check[list[start].get(i)] == 0) {
                dfs(list[start].get(i));
            }
        }
    }

    // 너비 우선 탐색
    public static void bfs(int v) {
        bfs_check[v] = 1;
        queue.offer(v);
        bfs_sol.add(v);

        while (!queue.isEmpty()) {
            int spot = queue.poll();
            for (int i = 0; i < list[spot].size(); i++) {
                if (bfs_check[list[spot].get(i)] == 0) {
                    bfs_check[list[spot].get(i)] = 1;
                    queue.offer(list[spot].get(i));
                    bfs_sol.add(list[spot].get(i));
                }
            }
        }

    }

}