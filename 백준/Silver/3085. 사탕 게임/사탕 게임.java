import java.io.*;

public class Main{

    public static int sol=0;
    public static char[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] strs = new String[n];
        arr = new char[n][n];

        char tmp;

        // 배열 세팅
        for (int i = 0; i < n; i++) {
            strs[i] = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = strs[i].charAt(j);
            }
        }

        // 오른쪽 문자와 교환 후 체크
        for (int i=0; i<n; i++) {
            for (int j=0; j<n-1; j++) {
                tmp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = tmp;
                search();
                arr[i][j+1] = arr[i][j];
                arr[i][j] = tmp;
            }
        }

        // 아래쪽 문자와 교환 후 체크
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n; j++) {
                tmp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = tmp;
                search();
                arr[i+1][j] = arr[i][j];
                arr[i][j] = tmp;
            }
        }

        bw.write(sol+"");
        bw.flush();
        bw.close();
    }

    public static void search() {

        // 오른쪽 최대 길이
        for (int i=0; i<arr.length; i++) {
            int count=1;
            for (int j=0; j<arr.length-1; j++) {
                if (arr[i][j]==arr[i][j+1]) {
                    count++;
                }
                else {
                    sol = Math.max(sol, count);
                    count = 1;
                }
            }
            sol = Math.max(sol, count);
        }

        // 아랫쪽 최대 길이
        for (int i=0; i<arr.length; i++) {
            int count=1;
            for (int j=0; j<arr.length-1; j++) {
                if (arr[j][i]==arr[j+1][i]) {
                    count++;
                }
                else {
                    sol = Math.max(sol, count);
                    count = 1;
                }
            }
            sol = Math.max(sol, count);
        }
    }
}