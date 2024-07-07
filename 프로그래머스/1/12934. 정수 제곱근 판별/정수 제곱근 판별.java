class Solution {
    public long solution(long n) {
        long answer = 0;
        int tmp = (int)Math.sqrt(n);
        
        if ((long)tmp*tmp == n) {
            answer = (long)(tmp+1)*(tmp+1);
        }
        else
            answer = -1;
        
        
        return answer;
    }
}