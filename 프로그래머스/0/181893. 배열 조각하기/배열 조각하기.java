class Solution {
    public int[] solution(int[] arr, int[] query) {
        int[] answer = {};
        int flag_left = 0;
        int flag_right = 0;
        
        for (int i=0; i<query.length; i++) {
            if (i % 2 == 0) {
                flag_right = flag_left+query[i];
            }
            else {
                flag_left = flag_left+query[i];
            }
        }
        
        answer = new int[flag_right - flag_left + 1];
        
        for (int i=0; i<answer.length; i++) {
            answer[i] = arr[flag_left+i];
        }
        
        
        return answer;
    }
}