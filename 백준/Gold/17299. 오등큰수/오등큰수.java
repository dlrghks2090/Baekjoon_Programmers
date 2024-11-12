import java.io.*;
import java.util.Stack;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Integer> st1 = new Stack<>();
        Stack<Integer> st2 = new Stack<>();
        Stack<Integer> st3 = new Stack<>();
        int[] arr = new int[1000001];   // 0으로 초기화된다.
        int flag=0;

        int N = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");

        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(str[i]);
            arr[num] += 1;  // 숫자 개수 체크
            st1.push(num);  // stack1에 주어진 수들 저장
        }

        st3.push(-1);
        st2.push(st1.pop());

        for (int i = 1; i < N; i++) {
            if (arr[st1.peek()] < arr[st2.peek()]) {
                st3.push(st2.peek());   // 오등큰수
                st2.push(st1.pop());
            }
            else {
                while (!st2.isEmpty()) {
                    if (arr[st1.peek()] < arr[st2.peek()]) {
                        st3.push(st2.peek());   // 오등큰수
                        st2.push(st1.pop());
                        flag=1;
                        break;
                    }
                    else {
                        st2.pop();
                    }
                }
                if (flag==0) {
                    st3.push(-1);
                    st2.push(st1.pop());
                }
                flag=0;
            }
        }

        while (!st3.isEmpty()) {
            bw.write(st3.pop()+ " ");
        }

        bw.flush();
        bw.close();
    }
}