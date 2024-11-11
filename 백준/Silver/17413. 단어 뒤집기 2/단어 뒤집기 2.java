import java.io.*;
import java.util.Stack;

class Main {
    public static void main(String[] args) throws IOException {
        // 입력 세팅
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 출력 세팅
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Character> st1 = new Stack<>();
        Stack<Character> st2 = new Stack<>();
        int count=0;

        String str = br.readLine();

        for (int i=0; i<str.length(); i++) {
            if(str.charAt(i)=='<'){

                if (!st1.isEmpty()) {
                    while(!st1.isEmpty()) {
                        bw.write(st1.pop());
                    }
                }

                st1.push(str.charAt(i));
                while(str.charAt(i+(++count)) != '>') {
                    st1.push(str.charAt(i+count));
                }
                st2.push(str.charAt(i+count));
                while (!st1.isEmpty()) {
                    st2.push(st1.pop());
                }
                while(!st2.isEmpty()) {
                    bw.write(st2.pop());
                }
                i = i+count;
                count=0;
            }
            else if(str.charAt(i)==' '){
                if(!st1.isEmpty()){
                    while(!st1.isEmpty()){
                        bw.write(st1.pop());
                    }
                }
                bw.write(' ');
            }
            else {
                st1.push(str.charAt(i));
            }
        }
        if(!st1.isEmpty()){
            while(!st1.isEmpty()){
                bw.write(st1.pop());
            }
        }

        bw.flush();
        bw.close();

    }
}