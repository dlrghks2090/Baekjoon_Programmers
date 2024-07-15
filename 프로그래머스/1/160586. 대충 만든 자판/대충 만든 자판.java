class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int[] answer = new int[targets.length];
        int total = 0;
        int tmp = 1000;
        int num;
        
        for(int i=0; i<targets.length; i++) {
            total = 0;
            for (int j=0; j<targets[i].length(); j++) {
                tmp = 1000;
                
                for (int k=0; k<keymap.length; k++) {
                    num = keymap[k].indexOf(targets[i].charAt(j));
                    if (num != -1) {
                        if (tmp > num+1) {
                            tmp = num+1;
                        }
                    }
                }
                if (tmp == 1000) {
                    answer[i] = -1;
                    break;
                }
                else {
                    total += tmp;
                }
                System.out.println(i + " 번째 total= " + total);
            }
            if (tmp != 1000) {
                answer[i] = total;
            }
        }
        return answer;
    }
}