import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static String check = "aeiou";
    public static ArrayList<String> answer = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] numbers = br.readLine().split(" ");
        int l = Integer.parseInt(numbers[0]);
        int c = Integer.parseInt(numbers[1]);
        String[] arr = br.readLine().split(" ");
        Arrays.sort(arr);

        rec(arr, l, 0, "");

        for (int i = 0; i < answer.size(); i++) {
            bw.write(answer.get(i)+'\n');
        }

        bw.flush();
        bw.close();
    }

    public static void rec(String[] arr, int l, int idx, String sol) {
        if (sol.length() == l) {
            int mcount=0;
            int jcount=sol.length();
            for (int i=0; i<5; i++) {
                if (sol.indexOf(check.charAt(i)) != -1) {
                    mcount++;
                }
            }
            jcount = jcount - mcount;
            if (mcount >= 1 && jcount >= 2) {
                answer.add(sol);
            }
            return;
        }

        for (int i=idx; i<arr.length; i++) {
            rec(arr, l, i+1, sol+arr[i]);
        }
    }
}