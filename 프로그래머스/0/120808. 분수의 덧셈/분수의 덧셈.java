// 유클리드 호제법 사용 a%b = r 이면 a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int[] answer = new int[2];
        int num1;
        int num2;
        int tmp;
        int tmp1,tmp2;
        
        // 분자
        num1 = numer1 * denom2 + numer2 * denom1;
        // 분모
        num2 = denom1*denom2;
        
        if (num1 > num2) {
            if (num1 % num2 == 0) {
                answer[0] = num1/num2;
                answer[1] = 1;
            }
            else {
                tmp1 = num2;
                tmp2 = num1%num2;
                while(true) {
                    if (tmp1%tmp2 == 0) {
                        answer[0] = num1/tmp2;
                        answer[1] = num2/tmp2;
                        break;
                    }
                    else {
                        tmp = tmp1;
                        tmp1 = tmp2;
                        tmp2 = tmp%tmp1;
                    }
                }
            }
        }
        else if (num1 < num2) {
            if (num2 % num1 == 0) {
                answer[0] = 1;
                answer[1] = num2/num1;
            }
            else {
                tmp1 = num1;
                tmp2 = num2%num1;
                while(true) {
                    if (tmp1%tmp2 == 0) {
                        answer[0] = num1/tmp2;
                        answer[1] = num2/tmp2;
                        break;
                    }
                    else {
                        tmp = tmp1;
                        tmp1 = tmp2;
                        tmp2 = tmp%tmp1;
                    }
                }
            }
        }
        else {
            answer[0] = 1;
            answer[1] = 1;
        }
        
        return answer;
    }
}