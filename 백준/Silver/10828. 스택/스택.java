
import java.io.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {

        int N;
        Stack<String> stack = new Stack<>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        for (int i=0; i<N; i++) {
            String[] str = br.readLine().split(" ");
            if (str[0].equals("push")) {
                stack.push(str[1]);
            }
            else {
                if (str[0].equals("pop")) {
                    if (!stack.isEmpty()) {
                        System.out.println(stack.pop());
                    }
                    else {
                        System.out.println(-1);
                    }
                }
                else if (str[0].equals("size")) {
                    System.out.println(stack.size());
                }
                else if (str[0].equals("empty")) {
                    if (!stack.isEmpty()) {
                        System.out.println(0);
                    }
                    else {
                        System.out.println(1);
                    }
                }
                else if (str[0].equals("top")) {
                    if (!stack.isEmpty()) {
                        System.out.println(stack.peek());
                    }
                    else {
                        System.out.println(-1);
                    }
                }
            }
        }


//        System.out.println("Hello world!  " + N);
    }
}