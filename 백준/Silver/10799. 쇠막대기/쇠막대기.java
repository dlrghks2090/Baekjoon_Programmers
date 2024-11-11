import java.io.*;
import java.util.Stack;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        Stack<Character> st = new Stack<>();
        int count = 0;
        int sol = 0;

        for (int i=0; i<str.length(); i++){
            if (str.charAt(i)=='('){
                if(str.charAt(i+1)==')'){
                    sol += st.size();
                    i += 1;
                }
                else {
                    st.push(str.charAt(i));
                }
            }
            else {
                sol += 1;
                st.pop();
            }
        }

        bw.write(sol+"");

        bw.flush();
        bw.close();
    }
}