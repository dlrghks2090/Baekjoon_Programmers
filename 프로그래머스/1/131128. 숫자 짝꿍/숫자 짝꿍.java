import java.util.*;
import java.io.*;
import java.util.Arrays;

class Solution {
    public String solution(String X, String Y) {
        StringBuffer answer = new StringBuffer();
        String sol_answer = "";
        int idx;
        int[] n = new int[10];  // 0으로 초기화된다.
        int[] sol = new int[10];    // 최종 숫자의 개수
        
        // X의 모든 숫자 체크
        for (int i=0; i<X.length(); i++) {
            n[X.charAt(i) - '0']++;
        }
        
        // 체크된 X의 모든 숫자에 대해 겹치는 Y문자 체크
        for(int i=0; i<Y.length(); i++) {
            if(n[Y.charAt(i)-'0'] != 0) {
                sol[Y.charAt(i)-'0']++;
                n[Y.charAt(i)-'0'] -= 1;
            }
        }
        
        for(int i=9; i>=0; i--) {
            for(int j=sol[i]; j>0; j--) {
                answer.append((char)(i + '0'));
            }
        }
        
        sol_answer = answer.toString();
        
        if(sol_answer.equals("")) {
            sol_answer = "-1";
        }
        else if (answer.charAt(0) == '0') {
             sol_answer = "0";
        }
        
        
        return sol_answer;
    }
}