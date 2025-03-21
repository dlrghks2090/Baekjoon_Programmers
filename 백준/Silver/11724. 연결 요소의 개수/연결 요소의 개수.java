import java.io.*;
import java.util.*;

public class Main {
    public static ArrayList<Integer>[] link_list;
    public static int[] check;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int sol=0;

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        link_list = new ArrayList[N + 1];   // 1 ~ N 까지의 수에 대한 연결점을 체크하기 위해 N+1까지 동적할당
        check = new int[N + 1];

        // 1 ~ N 까지 arrayList 선언
        for (int i = 1; i <= N; i++) {
            link_list[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            String[] str = br.readLine().split(" ");
            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            link_list[a].add(b);
            link_list[b].add(a);
        }

        for (int i = 1; i <= N; i++) {
            if (check[i] == 0) {
                sol++;
                dfs(i);
            }
        }

        bw.write(sol + "\n");
        bw.flush();
        bw.close();

    }

    public static void dfs(int start) {

        check[start] = 1;   // 해당 지점에 왔을때 거쳐간 것으로 체크한다.
        for (int i = 0; i < link_list[start].size(); i++) {
            if (check[link_list[start].get(i)] == 0) {
                dfs(link_list[start].get(i));
            }
        }
    }
}