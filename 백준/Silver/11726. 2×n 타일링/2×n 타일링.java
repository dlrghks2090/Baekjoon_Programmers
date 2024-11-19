import java.io.*;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[1001];

        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 3;
        arr[4] = 5;
        arr[5] = 8;
        // arr[n] = arr[n-1]+arr[n-2];

        for (int i = 6; i <= n; i++) {
            arr[i] = (arr[i-1] + arr[i - 2])%10007;
        }

        bw.write(arr[n] + "");

        bw.flush();
        bw.close();
    }
}