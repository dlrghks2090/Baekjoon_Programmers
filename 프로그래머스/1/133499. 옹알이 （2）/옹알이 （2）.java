class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        String[] str = {"aya", "ye", "woo", "ma" };
        String[] strstr = {"ayaaya", "yeye", "woowoo", "mama"};
        
        for(int i=0; i<babbling.length; i++) {
            // 연속된 발음가능 문자열이 오면 " " 공백으로 치환
            babbling[i] = babbling[i].replaceAll("ayaaya|yeye|woowoo|mama", " ");
            // 정상적인 발음가능 문자열이 오면 "" 문자열제거
            babbling[i] = babbling[i].replaceAll("aya|ye|woo|ma", "");
            
            System.out.println(i +"번째 " + babbling[i]);
            
            if(babbling[i].equals("")) {
                answer++;
            }
        }
        return answer;
    }
}