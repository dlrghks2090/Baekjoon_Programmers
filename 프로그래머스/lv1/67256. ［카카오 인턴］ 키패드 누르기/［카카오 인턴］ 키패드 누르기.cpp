#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;


    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.push_back('L');
            left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer.push_back('R');
            right = numbers[i];
        }
        else {
            int tmp1 = 0;
            int tmp2 = 0;
            int l_c = 0;
            int r_c = 0;
            tmp1 = left;
            tmp2 = right;
            int num = 0;

            if (numbers[i] == 0) {
                num = 11;
            }
            else {
                num = numbers[i];
            }


            if (left + 1 > num) {
                while (tmp1 > num) {
                    tmp1 -= 3;
                    l_c++;
                }
            }
            else {
                while (tmp1 + 1 < num) {
                    tmp1 += 3;
                    l_c++;
                }
            }

            if (right -1 > num) {
                while (tmp2 - 1 > num) {
                    tmp2 -= 3;
                    r_c++;
                }
            }
            else {
                while (tmp2 < num) {
                    tmp2 += 3;
                    r_c++;
                }
            }

            if (tmp1 != num)
                l_c++;
            if (tmp2 != num)
                r_c++;

            if (l_c > r_c) {
                right = num;
                answer.push_back('R');
            }
            else if (l_c < r_c) {
                left = num;
                answer.push_back('L');
            }
            else {
                if (hand.compare("right") == 0) {
                    right = num;
                    answer.push_back('R');
                }
                else {
                    left = num;
                    answer.push_back('L');
                }
            }


        }

        //cout << answer << endl;
        //cout << "left: "<< left << "   " << "right : " << right << endl;
    }

    return answer;
}
