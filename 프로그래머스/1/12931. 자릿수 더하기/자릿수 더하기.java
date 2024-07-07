import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        int tmp = n;
        
        while(tmp != 0) {
            answer += tmp%10;
            tmp = tmp/10;
        }

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");

        return answer;
    }
}