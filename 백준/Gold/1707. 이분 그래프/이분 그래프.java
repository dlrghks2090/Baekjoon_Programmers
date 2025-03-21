import java.io.*;
import java.util.*;

public class Main {

    public static String sol;
    public static ArrayList<Integer>[] list;
    public static int[] check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K; i++) {
            String[] input = br.readLine().split(" ");
            int V = Integer.parseInt(input[0]);
            int E = Integer.parseInt(input[1]);
            list = new ArrayList[V+1];
            check = new int[V+1];
            sol = "YES";

            for (int j = 1; j <= V; j++) {
                list[j] = new ArrayList<>();
            }

            for (int j = 0; j < E; j++) {
                String[] str = br.readLine().split(" ");
                int a = Integer.parseInt(str[0]);
                int b = Integer.parseInt(str[1]);
                list[a].add(b);
                list[b].add(a);
            }

            for(int j=1; j<=V; j++) {
                if (check[j] == 0) {
                    dfs(j, 1);
                }
            }

            bw.write(sol + "\n");

        }

        bw.flush();
        bw.close();

    }

    public static void dfs(int n, int color) {
        check[n] = color;

        // 인접한 정점이 있을때
        if (!list[n].isEmpty()) {
            for (int i =0; i<list[n].size(); i++) {
                // 인접한 정점과 현재 정점이 같은 위치
                if (check[list[n].get(i)] == color) {
                    sol = "NO";
                    return;
                }
                // 인접한 정점과 현재 정점이 다른 위치
                else if (check[list[n].get(i)] == 0) {
                    if (color == 1)
                        dfs(list[n].get(i),2);
                    else
                        dfs(list[n].get(i),1);
                }
            }


        }
        // 인접한 정점이 없을때
        else {
            return;
        }
    }

}