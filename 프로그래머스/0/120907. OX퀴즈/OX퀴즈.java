class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
        String x,y,z;
        String p_m = "";
        
        
        
        for (int i=0; i<quiz.length; i++) {
            int check = 0;
            x = "";
            y = "";
            z = "";
            p_m = "";
            for (int j=0; j<quiz[i].length(); j++) {
                if (quiz[i].charAt(j) == ' ') {
                    check++;
                }
                else {
                    if (check == 0) {
                        x = x+quiz[i].charAt(j);
                    }
                    else if (check == 1) {
                        p_m = p_m + quiz[i].charAt(j);
                    }
                    else if (check == 2) {
                        y = y+quiz[i].charAt(j);
                    }
                    else if (check == 4) {
                        z = z+quiz[i].charAt(j);
                    }
                }
            }
            System.out.println("========" + i + " 번째=======");
            System.out.println(x + p_m + y + " = " + z);
            if (p_m.equals("+")) {
                if (Integer.parseInt(x) + Integer.parseInt(y) == Integer.parseInt(z)) {
                    answer[i] = "O";
                }
                else {
                    answer[i] = "X";
                }
            }
            else {
                if (Integer.parseInt(x) - Integer.parseInt(y) == Integer.parseInt(z)) {
                    answer[i] = "O";
                }
                else {
                    answer[i] = "X";
                }
            }
        }
        return answer;
    }
}