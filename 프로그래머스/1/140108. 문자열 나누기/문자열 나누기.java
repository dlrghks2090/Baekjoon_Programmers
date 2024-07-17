class Solution {
    public int solution(String s) {
        int answer = 0;
        char ch=s.charAt(0);
        int flag1=1;
        int flag2=0;
        
        for(int i=1; i<s.length(); i++) {
            if (ch==s.charAt(i)) {
                flag1 += 1;
            }
            else {
                flag2 += 1;
            }
            
            if (flag1 == flag2) {
                answer++;
                if (i+1 < s.length()) {
                    ch = s.charAt(i+1);
                }
                flag1=0;
                flag2=0;
            }
        }
        if (flag1 !=0) {
            answer++;
        }
        
        return answer;
    }
}