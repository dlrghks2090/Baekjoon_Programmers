class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        
        if (b >= a) {
            answer = (long)(a+b)*(b-a+1)/2;
        }
        else {
            answer = (long)(a+b)*(a-b+1)/2;
        }
        
        return answer;
    }
}
// 3 4 5 -> 12
// 3 -> 3
// 5 4 3 -> 12
// -4 -3 -2 -1 -> -10
// -1 0 1 2 3 4 5 -> 14