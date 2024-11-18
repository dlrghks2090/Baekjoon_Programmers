import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] str = br.readLine().split(" ");

        String str1 = str[0] + str[1];
        String str2 = str[2] + str[3];

        Long num1 = Long.parseLong(str1);
        Long num2 = Long.parseLong(str2);

        bw.write(num1 + num2 + "");

        bw.flush();
        bw.close();
    }
}