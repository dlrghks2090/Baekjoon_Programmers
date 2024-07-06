class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int tmp=x;
        int num = 0;
        while(true) {
            if (tmp/10 == 0) {
                num += tmp;
                break;
            }
            else {
                num += tmp%10;
                tmp = tmp/10;
            }
        }
        if (x % num == 0)
            answer = true;
        else
            answer = false;
        return answer;
    }
}