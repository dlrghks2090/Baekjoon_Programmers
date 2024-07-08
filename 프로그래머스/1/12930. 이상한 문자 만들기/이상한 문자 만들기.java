class Solution {
    public String solution(String s) {
        String answer = "";
        int idx=0;
        int trans = 'a' - 'A';
        char ch;
        
        for(int i=0; i<s.length(); i++) {
            ch = s.charAt(i);
            if (ch == ' ') {
                idx = 0;
                answer = answer + ' ';
            }
            else{
                if (idx%2 == 0) {
                    if ('a' <= ch)
                        answer = answer + (char)(ch - trans);
                    else
                        answer = answer + ch;
                }
                else {
                    if (ch <= 'Z')
                        answer = answer + (char)(ch + trans);
                    else
                        answer = answer + ch;
                }
                idx++;
            }
        }
        
        
        return answer;
    }
}