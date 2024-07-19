import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        char[] ch = s.toCharArray();
        
        Arrays.sort(ch);
        
        for(int i=ch.length-1; i>=0; i--) {
            answer = answer+ch[i];
        }
        
        return answer;
    }
}