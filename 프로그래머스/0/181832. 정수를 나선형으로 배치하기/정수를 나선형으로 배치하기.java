class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        int flag = n-1;
        int flag2 = 0;
        int x = 0;
        int y = 0;
        int num=1;
        
        while (num <= n*n) {
            if(num == n*n) {
                answer[x][y] = n*n;
                break;
            }
        
            for (; y<flag; y++) {
                answer[x][y] = num++;
            }
            //y++;
            for (; x<flag; x++) {
                answer[x][y] = num++;
            }
            //x++;
            for (; flag2<y; y--) {
                answer[x][y] = num++;
            }
            //y--;
            for (; flag2<x; x--) {
                answer[x][y] = num++;
            }
            y++;
            x++;
            flag--;
            flag2++;
            
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    System.out.print(answer[i][j] + " ");
                }
                System.out.println();
            }
            System.out.println("=================");
        }
        return answer;
    }
}