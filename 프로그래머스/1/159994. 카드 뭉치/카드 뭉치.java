class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "";
        int idx1=0;
        int idx1_max = cards1.length;
        int idx2=0;
        int idx2_max = cards2.length;
        int flag = 0;
        
        for(int i=0; i<goal.length;i++) {
            if(idx1<idx1_max && cards1[idx1].equals(goal[i])) {
                idx1++;
            }
            else if(idx2<idx2_max && cards2[idx2].equals(goal[i])) {
                idx2++;
            }
            else{
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            answer = "Yes";
        }
        else {
            answer = "No";
        }
        
        return answer;
    }
}