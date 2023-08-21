import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        
        for(int s : scoville) {
            pq.offer(s);
        }
        
        while(pq.peek() < K) {
            int first = pq.poll();
            if(pq.isEmpty()) return -1;
            int second = pq.poll();
            pq.offer(first + second*2);
            answer++;
        }
        
        // if(pq.isEmpty()) return -1;
        return answer;
    }
}