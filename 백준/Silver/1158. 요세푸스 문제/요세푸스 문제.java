import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque<Integer> deque = new ArrayDeque<>();
        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str);
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        for (int i=1; i<=N; i++) {
            deque.addLast(i);
        }

        bw.write("<");
        while(!deque.isEmpty()) {

            for (int j=1; j<K; j++) {
                deque.addLast(deque.removeFirst());
            }

            if (deque.size()>1) {
                bw.write(deque.removeFirst() + ", ");
            }
            else {
                bw.write(deque.removeFirst() + ">");
            }
        }

        bw.flush();
        bw.close();
    }
}