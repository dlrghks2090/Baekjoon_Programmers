class Solution {
    public int solution(int[] common) {
        int answer = 0;
        int num=0;
        
        
        if (common[0] != 0 && common[1]%common[0] == 0) {
            num = common[1]/common[0];
            if (num == common[2]/common[1]) {
                answer = num*common[common.length-1];
            }
            else {
                num = common[1] - common[0];
                answer = common[common.length-1] + num;
            }
        }
        else {
            num = common[1] - common[0];
            answer = common[common.length-1] + num;
        }
        return answer;
    }
}