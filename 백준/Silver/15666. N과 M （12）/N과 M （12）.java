import java.io.*;
import java.util.*;

public class Main {
    public static int[] sol = new int[10];
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);
        String[] str2 = br.readLine().split(" ");
        int[] arr;
        int[] check = new int[10001];
        int num;
        List<Integer> list = new ArrayList<>();

        // 중복 되는 숫자 제거하여 배열 구성
        for (int i = 0; i < N; i++) {
            num = Integer.parseInt(str2[i]);
            if (check[num] == 0) {
                list.add(num);
                check[num] = 1;
            }
        }
        // List -> Array
        arr = list.stream()
                .mapToInt(i ->i)
                .toArray();

        // 오름차순 정렬
        Arrays.sort(arr);

        // 재귀
        rec(arr, arr.length, M, 0, 0);

        bw.close();
    }

    public static void rec(int[] arr, int n, int m, int start, int count) throws IOException {
        if(count == m){
            for(int i = 0; i < m; i++){
                bw.write(sol[i]+" ");
            }
            bw.write("\n");
            bw.flush();
            return;
        }

        // 비내림차순을 지키기위해 start부터 시작
        for (int i = start; i < n; i++) {
            sol[count] = arr[i];
            rec(arr, n, m, i, count + 1);
        }
    }
}