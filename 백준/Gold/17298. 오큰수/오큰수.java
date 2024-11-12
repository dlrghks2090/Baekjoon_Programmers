import java.io.*;
import java.util.Stack;

class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Integer> st1 = new Stack<>();
        Stack<Integer> st2 = new Stack<>();
        Stack<Integer> st3 = new Stack<>();
        int flag = 0;

        int N = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");

        // stack1에 원소 모두 저장
        for (int i=0; i<N; i++) {
            st1.push(Integer.parseInt(str[i]));
        }

        st2.push(st1.pop());
        st3.push(-1);

        for(int i=1; i<N; i++) {
            if (st1.peek() < st2.peek()) {
                st3.push(st2.peek());
                st2.push(st1.pop());
            }
            else {
                while(!st2.isEmpty()) {
                    if (st1.peek() < st2.peek()) {
                        st3.push(st2.peek());
                        st2.push(st1.pop());
                        flag = 1;
                        break;
                    }
                    else {
                        st2.pop();
                    }
                }
                if (flag == 0) {
                    st3.push(-1);
                    st2.push(st1.pop());
                }
                flag=0;
            }
        }

        while (!st3.isEmpty()) {
            bw.write(st3.pop() + " ");
        }

        bw.flush();
        bw.close();
    }
}