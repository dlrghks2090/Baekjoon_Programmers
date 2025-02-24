import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int e,s,m;
        int a = 1;
        int b = 1;
        int c = 1;
        int count = 1;
        String[] str = br.readLine().split(" ");

        e = Integer.parseInt(str[0]);
        s = Integer.parseInt(str[1]);
        m = Integer.parseInt(str[2]);

        while(true) {
            if (a == e && b == s && c == m) {
                break;
            }
            ++a;
            ++b;
            ++c;
            if (a > 15) {
                a = 1;
            }
            if (b > 28) {
                b = 1;
            }
            if (c > 19) {
                c = 1;
            }
            count++;
        }

        bw.write(count + "");
        bw.flush();
        bw.close();
    }
}