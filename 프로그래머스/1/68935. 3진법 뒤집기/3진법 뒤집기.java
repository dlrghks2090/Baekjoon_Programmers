class Solution {
    public int solution(int n) {
        int answer = 0;
        long tmp = 0;
        
        while(n != 0) {
            tmp = tmp*10 + (long)n%3;
            n = n/3;
        }
        System.out.println("3진수 리버스= " + tmp);
        int three=1;
        while(tmp != 0) {
            answer += (int)(tmp%10)*three;
            tmp = tmp/10;
            three *=3;
            
            System.out.println("answer= " + answer);
        }
        
        return answer;
    }
}