import java.io.*;
import java.util.Arrays;

public class Main{

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int[] sol = new int[7];
    public static int check=0;

    public static void main(String[] args) throws IOException {


        int[] arr = new int[9];
        for (int i=0; i<9; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        solve(arr, 0, 0, 0);

        bw.flush();
        bw.close();
    }

    public static void solve(int[] arr, int idx, int count, int total) throws IOException {
        if (check == 1) {
            return;
        }
        else if (count == 7) {
            if (total == 100) {
                Arrays.sort(sol);
                for (int i = 0; i < 7; i++) {
                    bw.write(sol[i] + "\n");
                }
                check=1;
            }
            return;
        }
        if (count < 7) {
            for (int i = idx; i < arr.length; i++) {
                sol[count] = arr[i];
                solve(arr, i + 1, count + 1, total + arr[i]);
            }
        }
    }
}