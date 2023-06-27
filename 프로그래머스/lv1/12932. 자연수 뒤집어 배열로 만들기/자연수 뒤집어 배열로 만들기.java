import java.util.ArrayList;

class Solution {
    public ArrayList<Long> solution(long n) {
        ArrayList<Long> answer = new ArrayList<Long>();
        while(n != 0) {
            
            answer.add((Long)n%10);
            n = n/10;
            
        }
        
        return answer;
    }
}