import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static int[] check;
    public static ArrayList<Integer>[] list;
    public static int sol=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        check = new int[n];
        list = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            list[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            String[] str2 = br.readLine().split(" ");
            int x = Integer.parseInt(str2[0]);
            int y = Integer.parseInt(str2[1]);
            list[x].add(y);
            list[y].add(x);
        }

        for (int i = 0; i < n; i++) {
            init(check);
            check[i] = 1;
            if (sol == 0)
                dfs(i, 1);
            else
                break;
        }

        bw.write(sol+"");
        bw.flush();
        bw.close();
        br.close();
    }

    public static void dfs(int n, int count) {
        if (count == 5) {
            sol = 1;
            return;
        }

        for (int i = 0; i < list[n].size(); i++) {
//            System.out.println("i = " + i);
            if (check[list[n].get(i)] == 0) {
                check[list[n].get(i)] = 1;
                dfs(list[n].get(i), count+1);
                check[list[n].get(i)] = 0;
            }
        }
    }

    public static void init(int[] check){
        Arrays.fill(check, 0);
    }
}