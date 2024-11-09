import java.io.*;
import java.util.Stack;

class Main {
    public static void main(String[] args) throws IOException {

        Stack<Character> st = new Stack<>();
        Stack<Character> tmp = new Stack<>();
        String str;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        str = br.readLine();
        for (int i=0; i<str.length(); i++) {
            st.push(str.charAt(i));
        }

        int n = Integer.parseInt(br.readLine());

        for (int i=0; i<n; i++) {
            String order = br.readLine();

            if (order.charAt(0) == 'L') {
                if (!st.isEmpty()) {
                    tmp.push(st.pop());
                }
            }
            else if (order.charAt(0) == 'D') {
                if (!tmp.isEmpty()) {
                    st.push(tmp.pop());
                }
            }
            else if (order.charAt(0) == 'B') {
                if (!st.isEmpty()) {
                    st.pop();
                }
            }
            else if (order.charAt(0) == 'P') {
                st.push(order.charAt(2));
            }
        }

        while (!st.isEmpty()) {
            tmp.push(st.pop());
        }
        while (!tmp.isEmpty()) {
            bw.write(tmp.pop());
        }

        bw.flush();
        bw.close();
    }
}