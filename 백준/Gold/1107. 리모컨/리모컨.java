import java.io.*;

public class Main {

    public static int n;
    public static int m;
    public static int[] arr;
    public static int sol=0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        arr = new int[10-m];

        // 최종 목표 채널의 자릿수를 사용하기 위한 변수
        String tmp = Integer.toString(n);
        // 고장난 버튼을 체크하기 위한 배열
        int[] check = new int[10];
        // 현재 채널
        int now = 100;

        // 작동되는 버튼을 모은 배열 arr을 만들기 위한 변수
        int count = 0;

        int over_num=0;
        int count2=0;

        // 1. +, -로만으로 센 값
        if (n > 100) {
            sol = n-100;
        }
        else {
            sol = 100 - n;
        }



        // 2. 고장난 버튼이 없을 경우
        if (m == 0) {
            sol = Math.min(sol, tmp.length());
        }
        // 3. 고장난 버튼이 있을 경우
        else{
            String[] str = br.readLine().split(" ");


            for (int i = 0; i < str.length; i++) {
                check[Integer.parseInt(str[i])] = 1;
            }

            for (int i = 0; i < 10; i++) {
                if (check[i] == 0) {
                    arr[count++] = i;
                }
            }
            func(tmp.length(), 0, 0);
        }



        bw.write(sol+"");

        bw.flush();
        bw.close();
    }

    // 작동되는 버튼으로만 만들 수 있는 숫자 생성 후 +,-키로 목표 채널인 n 까지의 수 구하는 재귀함수     ->    브루트포스보다 빅오적으로 더 줄일 수 있다고 판단함.
    public static void func(int size, int count, int total) {
        if (count >= size-1 && count <= size + 1 && count !=0) {
            int count2 = count;
//            System.out.println("size= "+size + "   total= "+total + "  count= "+ count);
            if (n > total) {
                count2 += n-total;
            }
            else{
                count2 += total-n;
            }

            if (sol > count2) {
                sol = count2;
//                System.out.println("sol= "+sol);
            }
        }
        else if (count > size+1) {
            return ;
        }

        for (int i=0; i<arr.length; i++) {
            func(size, count+1, total*10 + arr[i]);
        }
    }
}