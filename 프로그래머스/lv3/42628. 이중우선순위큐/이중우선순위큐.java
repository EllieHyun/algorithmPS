import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        answer = new int[2];
        
        for(String oper : operations) {
            String[] strs = oper.split(" ");
            if(strs[0].equals("I")) {
                list.add(Integer.parseInt(strs[1]));
            } else if(strs[0].equals("D") && strs[1].startsWith("-") && !list.isEmpty()) {
                int value = Collections.min(list);
                int index = list.indexOf(value);
                list.remove(index);
            } else if(!list.isEmpty()) {
                // System.out.println("pop max");
                int value = Collections.max(list);
                int index = list.indexOf(value);
                list.remove(index);
            }
        }
        
        // for(int i : list) {
        //     System.out.print(i + " ");
        // }
        
        if(list.isEmpty()) return answer;
        else {
            answer[0] = Collections.max(list);
            answer[1] = Collections.min(list);
        }
        
        return answer;
    }
}