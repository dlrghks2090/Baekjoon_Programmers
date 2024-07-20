class Solution {
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        int[] arr1 = {0,1,0,-1};
        int[] arr2 = {1,0,-1,0};
        
        for(int i=0; i<4; i++) {
            if(h+arr1[i] >=0 && h+arr1[i] < board.length && w+arr2[i] >=0 && w+arr2[i] < board[0].length) {
                if(board[h+arr1[i]][w+arr2[i]].equals(board[h][w])) {
                    answer++;
                }
            }
        }
        return answer;
    }
}