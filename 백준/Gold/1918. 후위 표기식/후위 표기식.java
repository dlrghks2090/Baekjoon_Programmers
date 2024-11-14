import java.io.*;
import java.util.Stack;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Character> st1 = new Stack<>();
        Stack<Character> st2 = new Stack<>();

        String str = br.readLine();

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
                st1.push(str.charAt(i));
            }
            else {
                if (str.charAt(i) == '(') {
                    st2.push(str.charAt(i));
                } else if (str.charAt(i) == ')') {
                    while (st2.peek() != '(') {
                        st1.push(st2.pop());
                    }
                    st2.pop();
                } else if (str.charAt(i) == '+' || str.charAt(i) == '-') {
                    while (!st2.isEmpty() && st2.peek() != '(') {
                        st1.push(st2.pop());
                    }
                    st2.push(str.charAt(i));
                } else if (str.charAt(i) == '*' || str.charAt(i) == '/') {
                    while (!st2.isEmpty() && (st2.peek() == '*' || st2.peek() == '/')) {
                        st1.push(st2.pop());
                    }
                    st2.push(str.charAt(i));
                }

            }
        }
        while(!st1.isEmpty()) {
            st2.push(st1.pop());
        }

        while(!st2.isEmpty()) {
            bw.write(st2.pop());
        }

        bw.flush();
        bw.close();

    }
}