import java.util.HashSet;


class Solution {
    public int solution(int[] nums) {
        int n = nums.length/2;
        int answer = 0;
        HashSet<Integer> set = new HashSet<Integer>();
        
        for(int i = 0; i<nums.length; i++) {
            set.add(nums[i]);
        }
        
        if (set.size() < n) {
            answer = set.size();
        }
        else {
            answer = n;
        }
        
        return answer;
    }
}