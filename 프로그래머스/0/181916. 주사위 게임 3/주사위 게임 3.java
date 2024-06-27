import java.util.Vector;
import javafx.util.Pair;

class Solution {
    public int solution(int a, int b, int c, int d) {
        int answer = 0;
        int arr[] = new int[4];
        int check[] = new int[4];
        Vector<Pair> v = new Vector<Pair>();
        
        
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
        
        for(int i=0; i<3; i++) {
            int count = 1;
            if (check[i] == 0) {
                for (int j=i+1; j<4; j++) {
                    if (check[j] == 0) {
                        if (arr[i] == arr[j]) {
                            count++;
                            check[j] = 1;
                        }
                    }
                }
                Pair<Integer,Integer> pair = new Pair<>(arr[i],count);
                v.add(pair);
            }
        }
        if (check[3] == 0) {
            Pair<Integer,Integer> pair = new Pair<>(arr[3],1);
            v.add(pair);
        }
        
        if (v.size() == 1) {
            answer = (int)v.get(0).getKey()*1111;
            System.out.println("1개 : " + answer);
        }
        else if (v.size() == 2) {
            int x = (int)v.get(0).getKey();
            int y = (int)v.get(1).getKey();
            
            if ((int)v.get(0).getValue() == 3) {
                answer = x*10+y;
                answer = answer * answer;
            }
            else if ((int)v.get(0).getValue() ==1) {
                answer = y*10+x;
                answer = answer * answer;
            }
            else {
                if (x > y) {
                    answer = (x+y) * (x-y);
                }
                else {
                    answer = (y+x) * (y-x);
                }
            }
        }
        else if(v.size() == 3) {
            System.out.println(v.size() + " 진입");
            if ((int)v.get(0).getValue() == 2) {
                answer = (int)v.get(1).getKey() * (int)v.get(2).getKey();
                System.out.println((int)v.get(1).getKey() + " " + (int)v.get(2).getKey());
            }
            else if ((int)v.get(1).getValue() == 2) {
                answer = (int)v.get(0).getKey() * (int)v.get(2).getKey();
                System.out.println((int)v.get(0).getKey() + " " + (int)v.get(2).getKey());
            }
            else {
                answer = (int)v.get(0).getKey() * (int)v.get(1).getKey();
                System.out.println((int)v.get(0).getKey() + " " + (int)v.get(1).getKey());
            }
            
        }
        else {
            answer = (int)v.get(0).getKey();
            for (int i=1; i<4; i++) {
                int num = (int)v.get(i).getKey();
                if (answer > num) {
                    answer = num;
                }
            }
        }
        
        return answer;
    }
}