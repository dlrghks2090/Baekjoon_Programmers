import java.io.*;

public class Main{

    // 최대 공약수 구하는 함수 -> 유클리드 호제법 사용.
    public static int gcd(int a, int b){
        int tmp;
        while(b != 0) {
            tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
    }

    public static int lcm(int a, int b){
        return a*b/gcd(a, b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int M,N,x,y;
        int T = Integer.parseInt(br.readLine());

        for (int i=0; i<T; i++){
            String[] str = br.readLine().split(" ");
            int a,b;
            int check=0;
            int tmp;
            M = Integer.parseInt(str[0]);
            N = Integer.parseInt(str[1]);
            x = Integer.parseInt(str[2]);
            y = Integer.parseInt(str[3]);

            tmp = lcm(M,N);

            // 카잉 달력의 마지막 날까지 반복
            for (int j=x; j<=tmp; j+=M){
                b = (j%N == 0)?N:j%N;
                if (b == y) {
                    bw.write(j+"\n");
                    check=1;
                    break;
                }
            }

            if (check==0){
                bw.write("-1\n");
            }

        }
        bw.close();
    }
}