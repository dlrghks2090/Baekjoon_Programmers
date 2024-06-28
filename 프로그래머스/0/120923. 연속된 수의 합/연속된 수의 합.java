class Solution {
    public int[] solution(int num, int total) {
        int[] answer = new int[num];
        int n;
        int m_n;
        
        n = total/num;
        
        if (num%2 == 1) {
            m_n = num/2;
        }
        else {
            m_n = num/2-1;
        }
        
        n = n - m_n;
        
        for (int i=0; i<num; i++) {
            answer[i] = n+i;
        }
        return answer;
    }
}