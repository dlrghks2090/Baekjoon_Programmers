#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    for (int i = 0; i < moves.size(); i++) {

        //cout << "--------------- moves[ = " << i << "]일때 -----------------" << moves[i] << endl;
        
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                if (st.empty()) {
                    st.push(board[j][moves[i] - 1]);
                    board[j][moves[i] - 1] = 0;
                }
                else {
                    if (st.top() == board[j][moves[i] - 1]) {
                        answer += 2;
                        st.pop();
                        board[j][moves[i] - 1] = 0;
                    }
                    else {
                        st.push(board[j][moves[i] - 1]);
                        board[j][moves[i] - 1] = 0;
                    }
                }
                break;
            }
        }
    }

    return answer;
}