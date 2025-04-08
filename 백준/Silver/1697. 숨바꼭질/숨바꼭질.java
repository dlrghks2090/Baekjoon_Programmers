import java.io.*;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {
    private static int sol=0;
    private static int[] check;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int K = Integer.parseInt(str[1]);
        check = new int[100001];

        bfs(N, K, 0);

        bw.write(sol+"");
        bw.flush();
        bw.close();
        br.close();
    }

    public static void bfs(int N, int K, int count) {
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[]{N,0});
        check[N] = 1;

        while(!que.isEmpty()){
            int[] cur = que.poll();

//            System.out.println("N = " + N +"  count= " + cur[1]);
            if (cur[0]+1<=100000 && check[cur[0]+1] == 0){
                if (cur[0]+1 == K) {
                    sol = cur[1]+1;
                    break;
                }
                que.add(new int[]{cur[0]+1, cur[1]+1});
                check[cur[0]+1] = 1;
            }
            if (0<=cur[0]-1 && check[cur[0]-1] == 0){
                if (cur[0]-1 == K) {
                    sol = cur[1]+1;
                    break;
                }
                que.add(new int[]{cur[0]-1,cur[1]+1});
                check[cur[0]-1] = 1;
            }
            if (cur[0]*2<=100000 && check[cur[0]*2] == 0){
                if (cur[0]*2 == K) {
                    sol = cur[1]+1;
                    break;
                }
                que.add(new int[]{cur[0]*2, cur[1]+1});
                check[cur[0]*2] = 1;
            }
        }
    }
}