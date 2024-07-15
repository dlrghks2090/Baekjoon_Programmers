class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int pre_score = 100000;
        int score;
        int num = 0;
        char ch = ' ';
        char op = '.';
        int flag = 0;
        
        for(int i=0; i<dartResult.length(); i++) {
            if (i!=0 && flag != 0 && '0' <= dartResult.charAt(i) && dartResult.charAt(i) <='9') {
                if (ch == 'S') {
                    
                }
                else if (ch == 'D') {
                    num = num*num;
                }
                else if (ch == 'T') {
                    num = num*num*num;
                }
                
                if (op == '*') {
                    if (pre_score != 100000) {
                        answer += pre_score + num*2;
                    }
                    else {
                        answer += num*2;
                    }
                    pre_score = num*2;
                }
                else if(op == '#') {
                    answer += (-1)*num;
                    pre_score = (-1)*num;
                }
                else {
                    answer += num;
                    pre_score = num;
                }
                op = '.';
                num = 0;
                flag=0;
                System.out.println("answer = " + answer);
                
            }
            
            if ('0' <= dartResult.charAt(i) && dartResult.charAt(i) <='9') {
                num = num*10 + dartResult.charAt(i) - '0';
            }
            else if (dartResult.charAt(i) == 'S' || dartResult.charAt(i) == 'D' || dartResult.charAt(i) == 'T') {
                ch = dartResult.charAt(i);
                flag++;
            }
            else {
                op = dartResult.charAt(i);
                flag++;
            }
            
        }
        
        if (ch == 'S') {
                    
        }
        else if (ch == 'D') {
            num = num*num;
        }
        else if (ch == 'T') {
            num = num*num*num;
        }
                
        if (op == '*') {
            answer += pre_score + num*2;
            pre_score = num*2;
        }
        else if(op == '#') {
            answer += (-1)*num;
            pre_score = (-1)*num;
        }
        else {
            answer += num;
            pre_score = num;
        }
        return answer;
    }
}