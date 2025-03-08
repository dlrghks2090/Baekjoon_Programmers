import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {-1};
        List<Integer> list = new ArrayList<Integer>();
        
        for (int n : arr) {
            if (n%divisor == 0) {
                list.add(n);
            }
        }
        
        if (list.size()!=0) {
            answer = new int[list.size()];
            for(int i=0; i<list.size(); i++) {
                answer[i] = list.get(i);
            }
            Arrays.sort(answer);
        }
        
        return answer;
    }
}