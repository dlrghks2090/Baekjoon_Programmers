import java.io.*;
import java.util.Stack;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Double> st = new Stack<>();
        int[] arr = new int[26];

        int N = Integer.parseInt(br.readLine());
        String str = br.readLine();

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
                st.push((double)arr[(str.charAt(i)-'0') - ('A' - '0')]);
            }
            else {

                double num2 = st.pop();
                double num1 = st.pop();

                switch (str.charAt(i)) {
                    case '+':
                        st.push((double)num1 + num2);
                        break;
                    case '-':
                        st.push((double)num1- num2);
                        break;
                    case '*' :
                        st.push((double)num1 * num2);
                        break;
                    case '/':
                        st.push((double)num1 / num2);
                        break;
                }
            }
        }
        bw.write(String.format("%.2f", st.pop()));

        bw.flush();
        bw.close();

    }
}