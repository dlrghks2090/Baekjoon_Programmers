import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] alp = new int[26];
        String str = br.readLine();

        for (int i=0; i<str.length(); i++) {
            alp[str.charAt(i)-'a']++;
        }

        for (int i=0; i<26; i++) {
            bw.write(alp[i] + " ");
        }


        bw.flush();
        bw.close();
    }
}