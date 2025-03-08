class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        int big,small;
        
        if (wallet[0] > wallet[1]) {
            big = wallet[0];
            small = wallet[1];
        }
        else {
            big = wallet[1];
            small = wallet[0];
        }
        
        while(true) {
            if (bill[0] > bill[1]) {
                if (big >= bill[0]) {
                    if (small >= bill[1]) {
                        break;
                    }
                    else {
                        bill[0] = bill[0]/2;
                        answer++;
                    }
                }
                else {
                    bill[0] = bill[0]/2;
                    answer++;
                }
            }
            else {
                if (big >= bill[1]) {
                    if (small >= bill[0]) {
                        break;
                    }
                    else {
                        bill[1] = bill[1]/2;
                        answer++;
                    }
                }
                else {
                    bill[1] = bill[1]/2;
                    answer++;
                }
            }
        }
        
        return answer;
    }
}