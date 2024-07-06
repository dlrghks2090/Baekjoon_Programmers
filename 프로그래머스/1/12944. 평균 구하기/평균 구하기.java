class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        int total=0;
        
        for (int i=0; i<arr.length; i++) {
            total += arr[i];
        }
        
        answer = (double)total/arr.length;
        return answer;
    }
}