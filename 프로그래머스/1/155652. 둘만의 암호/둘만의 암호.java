class Solution {
    public String solution(String s, String skip, int index) {
        String answer = "";
        int[] check = new int[26];
        int idx;
        int count;
        int num;
        
        // 건너뛸 알파벳 설정
        for (int i=0; i<skip.length(); i++) {
            idx = (int)skip.charAt(i) - (int)'a';
            check[idx] = 1;
            System.out.println(idx);
        }
        // 메인 로직
        for(int i=0; i<s.length(); i++) {
            
            count = 0;

            char ch = (char)((s.charAt(i)-'0') + '0');
            while(count < index) {
                ch = (char)(((ch-'0')+1) + '0');
                
                if (ch <= 'z') {
                    if (check[(int)ch - (int)'a'] != 1){
                        count++;
                    }
                }
                else {
                    ch = 'a';
                    if (check[0] != 1) {
                        count++;
                    }
                }
                
            }
            if (ch <= 'z'){
                //ch = (char)(((ch-'0')+1) + '0');
                answer = answer + ch;
            }
            else
                answer = answer + 'a';
        }
        return answer;
    }
}