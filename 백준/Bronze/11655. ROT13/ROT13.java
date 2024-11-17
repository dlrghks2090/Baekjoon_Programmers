import java.io.*;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        String sol = "";

        for(int i=0; i<str.length(); i++){
            if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z'){
                if (str.charAt(i) + 13 > 'z') {
                    sol += (char)('a' + (str.charAt(i) + 13 - 'z' -1 - '0') + '0');
                }
                else {
                    sol += (char)(str.charAt(i) + 13);
                }
            }
            else if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z'){
                if (str.charAt(i) + 13 > 'Z') {
                    sol += (char)('A' + (str.charAt(i) + 13 - 'Z' -1 - '0') + '0');
                }
                else {
                    sol += (char)(str.charAt(i) + 13);
                }
            }
            else {
                sol += str.charAt(i);
            }
        }

        bw.write(sol);

        bw.flush();
        bw.close();
    }
}