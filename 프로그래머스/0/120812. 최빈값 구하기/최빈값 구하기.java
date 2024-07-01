import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int solution(int[] array) {
        int answer = 0;
        int max_count = 0;
        int count = 0;
        
        Arrays.sort(array);
        
        count = 1;
        answer = array[0];
        for (int i=1; i<array.length; i++) {
            if (array[i-1] == array[i]) {
                count++;
            }
            else {
                if (max_count < count) {
                    max_count = count;
                    answer = array[i-1];
                }
                else if (max_count == count) {
                    answer = -1;
                }
                count = 1;
            }
        }
        if (max_count < count) {
            max_count = count;
            answer = array[array.length-1];
        }
        else if (max_count == count) {
            answer = -1;
        }
        return answer;
    }
}