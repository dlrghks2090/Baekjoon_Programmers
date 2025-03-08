class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        int[] check = new int[10];
        
        for (int idx : numbers) {
            check[idx] = 1;
        }
        
        for (int i=0; i<10; i++) {
            if (check[i] == 0) {
                answer += i;
            }
        }
        
        return answer;
    }
}