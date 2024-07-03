import java.util.Arrays;

class Solution {
    public int solution(int[][] lines) {
        int answer = 0;
        int[] check = new int[201]; // 0으로 초기화된다.
        int min_x,max_y;

        // 첫 번째 숫자 기준 오름차순 정렬
        // 첫 번째 숫자가 같으면 두번째 숫자 기준 오름차순 정렬
        Arrays.sort(lines,(o1,o2) -> {
            if (o1[0] != o2[0])
                return o1[0] - o2[0];
            else
                return o1[1] - o2[1];
        });
        
        min_x = lines[0][0] + 100;
        max_y = lines[0][1] + 100;
        for(int i=0; i<3; i++) {
            for(int j=lines[i][0]; j<lines[i][1]; j++) {
                check[j+100]++;
            }
            if (max_y < lines[i][1] + 100)
                max_y = lines[i][1] + 100;
        }
        
        for(int i=min_x; i<=max_y; i++) {
            if (check[i] > 1) {
                answer++;
            }
        }
        
        return answer;
    }
}