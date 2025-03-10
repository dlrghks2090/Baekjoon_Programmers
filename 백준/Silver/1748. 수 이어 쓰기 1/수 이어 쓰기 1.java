import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        int size = str.length();
        int N = Integer.parseInt(str);
        int tmp=1;
        int tmp2=1;
        int sol=0;

        for(int i=1; i<size; i++) {
            tmp2 = tmp;
            tmp *=10;
            sol += (tmp - tmp2)*i;
        }
        sol += (N - tmp + 1)*size;

        bw.write(sol+"");
        bw.flush();
        bw.close();

    }
}