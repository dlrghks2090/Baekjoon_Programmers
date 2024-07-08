import java.util.Arrays;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        
        int[] arr = new int[k+1];
        
        for(int i=0; i<score.length; i++){
            arr[0] = score[i];
            Arrays.sort(arr);
            
            if (i <= k-1) {
                answer[i] = arr[k-i];
            }
            else {
                answer[i] = arr[1];
            }
        }
        
        
        
        return answer;
    }
}