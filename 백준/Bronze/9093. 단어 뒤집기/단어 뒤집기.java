
import java.io.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        int N;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            StringBuffer str = new StringBuffer(br.readLine());
            String[] reverseStr = str.reverse().toString().split(" ");
            for (int j = reverseStr.length-1; j >= 0; j--) {
                System.out.print(reverseStr[j] + " ");
            }
            System.out.println();
        }
    }
}