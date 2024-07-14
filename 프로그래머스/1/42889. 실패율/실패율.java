import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = {};
        int tmp=0;
        int count = 0;
        int len = stages.length;
        int last = 0;
        
        Map<Integer,Double> map = new HashMap<>();
        
        Arrays.sort(stages);
        
        // for(int i=0; i<len; i++) {
        //     System.out.print(stages[i] + " ");
        // }
        
        for(int i=1; i<=N; i++) {
            
            count = 0;
            for (int j=tmp; j<stages.length; j++) {
                if (i == stages[j]) {
                    count++;
                }
                else {
                    System.out.println("key:" + i + " 값: " + (double)count/len + " len: " + len);
                    map.put((Integer)i,(double)count/len);
                    tmp = j;
                    len = len-count;
                    last = i+1;
                    count = 0;
                    break;
                }
            }
            if (count !=0 && count == len) {
                last = i;
                break;
            }
            
            // if(len !=0 && len == count) {
            //     map.put((Integer)i,(double)count/len);
            //     last = N-i;
            //     break;
            // }
        }
        for (int i=last; i<=N; i++) {
            if (len != 0) {
                map.put((Integer)i,(double)count/len);
                System.out.println("key:" + i + " 값: "+ (double)count/len + "   for문 끝난 후 0추가");
                System.out.println("idx: " + i +  " len: " + len);
                len = len - count;
                
            }
            else {
                map.put((Integer)i,(double)0);
                System.out.println("key:" + i + " 값: "+ 0 + "   for문 끝난 후 0추가");
            }
        }
        
        List<Integer> keySet = new ArrayList<>(map.keySet());
        
        // 람다를 이용한 내림차순 정렬
        //keySet.sort((o1,o2) -> map.get(o2).compareTo(map.get(o1)));
        
        keySet.sort(new Comparator<Integer>() {
            
            @Override
            public int compare(Integer o1, Integer o2) {
                if (map.get(o2).compareTo(map.get(o1)) == 0) {
                    return o1.compareTo(o2);
                }
                else {
                    return map.get(o2).compareTo(map.get(o1));
                }
                
            }
        });
        
        answer = new int[N];
        int k=0;
        for(Integer key : keySet) {
            System.out.println(key + "  값: " + map.get(key));
            answer[k] = (int) key;
            k++;
        }
        
        return answer;
    }
}