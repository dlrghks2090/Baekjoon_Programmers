class Solution
{
    public int solution(int [][]board)
    {
        int answer = 0;
        int num;

        for(int i=0; i<board.length; i++) {
            for(int j=0; j<board[i].length; j++) {
                if (board[i][j] == 1) {
                    if (i-1 >= 0 && j-1 >= 0) {
                        num = Math.min(board[i-1][j], board[i][j-1]);
                        num = Math.min(num,  board[i-1][j-1]);
                        if (num > 0) {
                            board[i][j] = num+1;
                            answer = Math.max(answer, num+1);
                        }
                    }
                    else {
                        if (board[i][j] == 1 && answer == 0) {
                            answer = 1;
                        }
                    }
                }
            }
        }
        
        answer = answer*answer;

        return answer;
    }
}