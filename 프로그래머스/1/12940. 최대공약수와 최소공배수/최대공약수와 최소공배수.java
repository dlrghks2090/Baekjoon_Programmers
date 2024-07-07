class Solution {
    public int[] solution(int n, int m) {
        int[] answer = {0,0};
        int max_num=0;  // 최대공약수
        int min_num;    // 최소공배수
        int tmp1, tmp2;
        
        if(n > m) {
            tmp1 = n;
            min_num = m;  
        }
        else {
            tmp1 = m;
            min_num = n;
        }
        while(true) {
            if (tmp1%min_num == 0) {
                break;
            }
            else {
                tmp2 = min_num;
                min_num = tmp1%min_num;
                tmp1 = tmp2;
            }
        }
        answer[0] = min_num;
        
        n = n/min_num;
        m = m/min_num;
        
        answer[1] = n*m*min_num;
        return answer;
    }
}