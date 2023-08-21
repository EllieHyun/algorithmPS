import java.util.*;

class Solution {
    
    boolean solution(String s) {
        boolean answer = true;
        
        Queue<Character> queue = new LinkedList<>();
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(c == '(') {
                queue.offer(c);
            } else {
                if(queue.isEmpty()) return false;
                else queue.poll();
            }
        }
        
        if(!queue.isEmpty()) return false;
        return true;
    }
}