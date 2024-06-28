// 100*100 일때
/*  풀이1
    1.전체를 돌며 폭탄 체크시 주변 위험지역 2로 표시
    2.다시 전체를 돌며 0인 부분만 카운트한다.   */

/*  풀이2
    1.전체를 돌며 0인부분 카운트(체크시 -1처리) + 폭탄 체크시 주변 위험지역 2로 표시 (이미 0으로체크한부분들 카운트에서 빼준다.)
*/

class Solution {
    public int solution(int[][] board) {
        int answer = 0;
        int row = board.length;
        int col = board[0].length;
        
        System.out.println(row + " " + col);
        
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = -1;
                    answer++;
                }
                else if(board[i][j] == 1) {
                    for(int p=-1; p<=1; p++) {
                        if (i+p < 0) {
                            continue;
                        }
                        else if(i+p >= row) {
                            break;
                        }
                        for (int q=-1; q<=1;q++) {
                            if (j+q < 0) {
                                continue;
                            }
                            else if(j+q >= col) {
                                break;
                            }
                            else {
                                if (board[i+p][j+q] == -1) {
                                    board[i+p][j+q] = 2;
                                    answer--;
                                }
                                else if(board[i+p][j+q] == 0) {
                                    board[i+p][j+q] = 2;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
        return answer;
    }
}