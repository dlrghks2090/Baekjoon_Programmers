class Solution {
    public String solution(String s) {
        String answer = "";
        
        for (int i=0; i<s.length(); i++) {
            if (i-1== -1 || s.charAt(i-1)==' ') {
                if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                    answer += (char)('A' + (s.charAt(i) - 'a'));
                }
                else {
                    answer += s.charAt(i);
                }
            }
            else {
                if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                    answer += (char)('a' + (s.charAt(i) - 'A'));
                }
                else {
                    answer += s.charAt(i);
                }
            }
        }
        return answer;
    }
}