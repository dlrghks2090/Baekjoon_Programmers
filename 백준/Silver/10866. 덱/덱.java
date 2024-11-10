import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque<Integer> deque = new ArrayDeque<>();
        int N = Integer.parseInt(br.readLine());

        for (int i=1; i<=N; i++) {
            String[] input = br.readLine().split(" ");
            switch (input[0]) {
                case "push_front":
                    deque.addFirst(Integer.parseInt(input[1]));
                    break;
                case "push_back":
                    deque.addLast(Integer.parseInt(input[1]));
                    break;
                case "pop_front":
                    if (deque.isEmpty())
                        bw.write("-1\n");
                    else
                        bw.write(deque.removeFirst()+"\n");
                    break;
                case "pop_back":
                    if (deque.isEmpty())
                        bw.write("-1\n");
                    else
                        bw.write(deque.removeLast()+"\n");
                    break;
                case "size":
                    bw.write(deque.size()+"\n");
                    break;
                case "empty":
                    if (deque.isEmpty())
                        bw.write("1\n");
                    else
                        bw.write("0\n");
                    break;
                case "front":
                    if (deque.isEmpty())
                        bw.write("-1\n");
                    else
                        bw.write(deque.peekFirst()+"\n");
                    break;
                case "back":
                    if (deque.isEmpty())
                        bw.write("-1\n");
                    else
                        bw.write(deque.peekLast()+"\n");
                    break;
            }
        }



        bw.flush();
        bw.close();
    }
}