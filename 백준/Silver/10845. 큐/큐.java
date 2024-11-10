import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;


class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque<Integer> deque = new ArrayDeque<>();
        int N = Integer.parseInt(br.readLine());

        for(int i=0; i<N; i++) {
            String[] input = br.readLine().split(" ");
            if (input[0].equals("push")) {
                deque.addLast(Integer.parseInt(input[1]));
            }
            else if (input[0].equals("pop")) {
                if(!deque.isEmpty()) {
                    bw.write( deque.removeFirst()+"\n");
                }
                else {
                    bw.write("-1\n");
                }
            }
            else if (input[0].equals("size")) {
                bw.write(deque.size()+"\n");
            }
            else if (input[0].equals("empty")) {
                if (deque.isEmpty()) {
                    bw.write(1+"\n");
                }
                else {
                    bw.write(0+"\n");
                }
            }
            else if (input[0].equals("front")) {
                if(!deque.isEmpty()) {
                    bw.write(deque.peekFirst()+"\n");
                }
                else {
                    bw.write("-1\n");
                }
            }
            else if (input[0].equals("back")) {
                if(!deque.isEmpty()) {
                    bw.write(deque.peekLast()+"\n");
                }
                else {
                    bw.write("-1\n");
                }
            }
        }

        bw.flush();
        bw.close();
    }
}