import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        ArrayList<String> list = new ArrayList<>();
        
        for(int i : numbers) {
            list.add(Integer.toString(i));    
        }
        
        Collections.sort(list, new Comparator<>() {
           @Override
            public int compare(String a, String b) {
                return (b+a).compareTo(a+b);
            }
        });
        
        if(list.get(0).equals("0")) return "0";
        else {
            for(String s : list) {
                answer += s;
            }
            return answer;   
        }
    }
}