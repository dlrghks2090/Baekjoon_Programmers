import java.util.Arrays;
class Solution {
    public long solution(long n) {
        long answer = 0;
        long tmp = n;
        int size = 0;
        int[] arr;
        
        while(tmp != 0) {
            tmp = tmp/10;
            size++;
        }
        arr = new int[size];
        System.out.println(size);
        tmp = n;
        
        for(int i=0; i<size; i++) {
            arr[i] = (int)(tmp%10);
            tmp = tmp/10;
            System.out.print(arr[i] + " ");
        }
        
        // collection.reverseOrder() 를 사용해서 내림차순정렬을 하려 했으나
        // int 자료형을 지원하지 않는다는것을 배웠다.
        Arrays.sort(arr);
        
        for(int i=size-1; i>=0; i--) {
            answer = answer*10 + (long)arr[i];
        }
        
        return answer;
    }
}