class Solution {
    public int[] solution(int n) {
        
        int[][] arr = new int[n+1][n+1];
        int flag = 0;
        int tmp = n;
        int idx1=1;
        int idx2=1;
        int count=0;
        int size = (1+n)*n/2;
        int[] answer = new int[size];
        
        for(int i=1; i<=size; i++) {
            if (flag == 0) {
                arr[idx1][idx2] = i;
                idx1++;
                ++count;
                if (count == tmp-1) {
                    flag = 1;
                    count=0;
                }
            }
            else if(flag == 1) {
                arr[idx1][idx2] = i;
                idx2++;
                ++count;
                if (count == tmp-1) {
                    flag = 2;
                    count = 0;
                }
            }
            else {
                arr[idx1][idx2] = i;
                idx1--;
                idx2--;
                ++count;
                if (count == tmp-1) {
                    flag = 0;
                    idx1 += 2;
                    idx2 += 1;
                    count=0;
                    tmp -= 3;
                }
            }
        }
        
        int idx=0;
        for(int i=1; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                //System.out.print(arr[i][j] + " ");
                answer[idx]=arr[i][j];
                idx++;
            }
            //System.out.println();
        }
        
        
        return answer;
    }
}