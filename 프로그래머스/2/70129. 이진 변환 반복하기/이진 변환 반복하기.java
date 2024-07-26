class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];
        String tmp = s;
        String tmp2 = "";
        int trans = 0;
        int zero = 0;
        int n;
        
        while (!tmp.equals("1")) {
            // 0제거
            for (int i=0; i<tmp.length(); i++) {
                if (tmp.charAt(i) == '1') {
                    tmp2 += '1';
                }
                else {
                    zero++;
                }
            }
            // 변환 +1
            trans++;
            
            tmp = "";
            // 0뺀 이진수의 길이 저장
            n=tmp2.length();
            
            // n을 2진법으로 표현해 tmp에 할당
            while (true) {
                if (n/2 != 0) {
                    tmp += Integer.toString(n%2);
                    n = n/2;
                }
                else {
                    if (n%2 == 1){
                        tmp += Integer.toString(n%2); 
                    }
                    break;
                }
            }
            StringBuffer sb = new StringBuffer(tmp);
            tmp = "" + sb.reverse().toString();
            
            tmp2 = "";
            System.out.println(tmp);
        }
        
        answer[0] = trans;
        answer[1] = zero;
        
        //System.out.println(tmp);
        
        return answer;
    }
}