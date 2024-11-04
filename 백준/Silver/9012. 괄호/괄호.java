
import java.io.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {

        int N;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        // N번 진행
        for(int i=0; i<N; i++) {
            Stack<Character> st = new Stack<>();
            String arr = br.readLine();

//            System.out.println(i + " 번째=====");

            // i 번째 괄호문자열
            for (int j=0; j<arr.length(); j++) {

                // '(' 일때
                if (arr.charAt(j) == '(') {
//                    System.out.println(arr.charAt(j) + " push");
                    st.push(arr.charAt(j));
                }
                // ')' 일때
                else if (arr.charAt(j) == ')') {
                    // stack이 비어있으면
                    if (st.isEmpty()) {
                        st.push(arr.charAt(j));
                        break;
                    }
                    // stack 최상단에 '('가 존재하면
                    else {
//                        System.out.println(st.pop() + " pop");
                        st.pop();
                    }
                }
            }

            if (st.isEmpty()) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }
    }
}