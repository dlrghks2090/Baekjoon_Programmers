class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int flag=0;
        
        for(int i=0; i<=t.length()-p.length(); i++) {
            flag=0;
            for(int j=0; j<p.length(); j++) {
                if (t.charAt(i+j) < p.charAt(j)){
                    flag=1;
                    break;
                }
                else if (t.charAt(i+j) > p.charAt(j)) {
                    flag = -1;
                    break;
                }
            }
            if (flag == 1 || flag==0) {
                answer++;
            }
        }
        return answer;
    }
}