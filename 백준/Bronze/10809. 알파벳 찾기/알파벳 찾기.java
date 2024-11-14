import java.io.*;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] alp = new int[26];
        Arrays.fill(alp, -1);

        String str = br.readLine();

        for (int i=0; i<str.length(); i++) {
            if (alp[str.charAt(i)-'a'] == -1) {
                alp[str.charAt(i)-'a'] = i;
            }
        }

        for (int i=0; i<26; i++) {
            bw.write(alp[i] + " ");
        }


        bw.flush();
        bw.close();
    }
}