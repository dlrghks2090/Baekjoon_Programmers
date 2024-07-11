class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        int tmp;
        
        for(int i=1; i<=number; i++) {
            tmp = 0;
            for(int j=1; j*j<=i; j++) {
                
                if(j*j==i)
                    tmp++;
                else if (i%j == 0) {
                    tmp += 2;
                }
            }
            if (tmp <= limit)
                answer += tmp;
            else
                answer += power;
            //System.out.println(answer);
        }
        return answer;
    }
}