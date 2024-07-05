// (String).replace("찾을 문자열","바꿀 문자열") 을 사용해 찾은 문자열을 공백으로 치환하여 해결했다.
// (Stirng).isBlank()를 사용해 공백으로만 이루어져있는지를 체크하여 최종 답을 구할 수 있었다.
class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        String tmp = "";
        String[] arr = {"aya","ye","woo","ma"};
        
        for (String i : babbling) {
            for (String j : arr) {
                tmp = i.replace(j," ");
                i = tmp;
            }
            if (i.isBlank())
                answer++;
        }
        
        return answer;
    }
}