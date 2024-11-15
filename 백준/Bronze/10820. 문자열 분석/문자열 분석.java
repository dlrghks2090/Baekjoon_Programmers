import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str;

        while((str = br.readLine()) != null) {  // 입력 만큼 작동하게 하기 위한 장치
            int[] arr = new int[4];
//            bw.write(str + " 입력 완료!. \n");
            for(int i=0; i<str.length(); i++) {
                if (str.charAt(i) >='a' && str.charAt(i) <='z') {
                    arr[0]++;
                }
                else if (str.charAt(i) >='A' && str.charAt(i) <='Z') {
                    arr[1]++;
                }
                else if (str.charAt(i) >='0' && str.charAt(i) <='9') {
                    arr[2]++;
                }
                else if (str.charAt(i) == ' ') {
                    arr[3]++;
                }
            }
//            System.out.println(arr[0] + " " + arr[1] + " " + arr[2] + " " + arr[3]);
            bw.write(arr[0] + " " + arr[1] + " " + arr[2] + " " + arr[3] + '\n');
            bw.flush();

        }

        bw.close();
    }
}