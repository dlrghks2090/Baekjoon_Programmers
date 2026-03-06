class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        int score[] = {0, 0, 0, 0};
        int num[] = {0,3,2,1,0,-1,-2,-3};
        String[] arr = {"RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA"};
        String[] arr2 = {"RT","FC","MJ","AN"};
        
        for (int i=0; i<survey.length; i++) {
            for (int j=0; j<arr.length; j++) {
                if (arr[j].equals(survey[i])) {
                    if (j < 2) {
                        if (j%2 == 0) {
                            score[0] += num[choices[i]];
                        } else {
                            score[0] -= num[choices[i]];
                        }
                    } else if(j < 4) {
                        if (j%2 == 0) {
                            score[1] += num[choices[i]];
                        } else {
                            score[1] -= num[choices[i]];
                        }
                    } else if(j < 6) {
                        if (j%2 == 0) {
                            score[2] += num[choices[i]];
                        } else {
                            score[2] -= num[choices[i]];
                        }
                    }
                    else {
                        if (j%2 == 0) {
                            score[3] += num[choices[i]];
                        } else {
                            score[3] -= num[choices[i]];
                        }
                    }
                }
            }
            
        }
        
        for (int i=0; i<score.length; i++) {
            System.out.println("score " + i + " = " + score[i]);
            if (score[i] < 0){
                answer += arr2[i].charAt(1);
            }
            else if (score[i] > 0){
                answer += arr2[i].charAt(0);
            }
            else {
                if ((arr2[i].charAt(0)) < arr2[i].charAt(1)) {
                    answer += arr2[i].charAt(0);
                } else {
                    answer += arr2[i].charAt(1);
                }
            }
        }
        
        return answer;
    }
}