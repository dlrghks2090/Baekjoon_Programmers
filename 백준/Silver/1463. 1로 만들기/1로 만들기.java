import java.io.*;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[1000001];

        arr[1] = 0;
        arr[2] = 1;
        arr[3] = 1;

        for (int i = 4; i <= n; i++) {
            arr[i] = arr[i-1]+1;
            if (i%2 == 0) {
                arr[i] = Math.min(arr[i], arr[i/2]+1);
            }
            if (i%3 == 0) {
                arr[i] = Math.min(arr[i], arr[i/3]+1);
            }
        }

        bw.write(arr[n] + "");

        bw.flush();
        bw.close();
    }
}