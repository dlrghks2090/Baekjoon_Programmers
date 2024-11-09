import java.io.*;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        Queue<Character> queue = new LinkedList<>();
        int[] arr = new int[N+1];
        int num=1;
        int flag=0;

        for (int i=1; i<N+1; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        for (int i=1; i<=N; i++) {
//            System.out.println("==== " + i + "번째 ==== " + arr[i]);
            if (arr[i] == num) {
//                System.out.println("arr == num");
                stack.push(num);
                stack.pop();
                queue.add('+');
                queue.add('-');
//                System.out.println("+" + "  num="+num);
//                System.out.println('-');
                ++num;
            }
            else if (arr[i] > num) {
//                System.out.println("arr > num");
                while (arr[i] >= num) {
                    stack.push(num);
                    queue.add('+');
//                    System.out.println("+" + "  num="+num);
                    ++num;
                }
                stack.pop();
                queue.add('-');
//                System.out.println("-");
            }
            else {
//                System.out.println("arr < num");

                if (arr[i] == stack.peek()) {
                    stack.pop();
                    queue.add('-');
                }
                else {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag==0) {
            while(queue.isEmpty()==false) {
                System.out.println(queue.poll());
            }
        }
        else {
            System.out.println("NO");
        }
    }
}