class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int tmp = 0;
        int len = nums.length;
        int count = 0;

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        
        for(int i=0; i<len-2; i++) {
            for (int j=i+1; j<len-1; j++) {
                for (int k=j+1; k<len; k++) {
                    tmp = nums[i]+nums[j]+nums[k];
                    
                    for(int p=1; p*p<=tmp; p++) {
                        if (tmp%p == 0) {
                            count++;
                        }
                    }
                    if (count == 1) {
                        answer++;
                    }
                    count = 0;
                }
            }
        }
        

        return answer;
    }
}