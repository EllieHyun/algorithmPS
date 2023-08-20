import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String[] c : clothes) {
            if(map.get(c[1]) == null) {
                map.put(c[1], 1);
            } else {
                Integer value = map.get(c[1]);
                map.put(c[1], value+1);
            }
        }
        
        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            int value = entry.getValue();
            answer *= (value + 1);
        }
        return answer - 1;
    }
}