import java.util.*;

class Process implements Comparable<Process> {
    int priority;
    int index;
    
    public Process(int priority, int index) {
        this.priority = priority;
        this.index = index;
    }
    
    @Override
    public int compareTo(Process process) {
        if(this.priority < process.priority) {
            return 1;
        } else {
            return -1;
        }
    }
}

class Solution {
    public int solution(int[] priorities, int location) {        
        int answer = 0;
        PriorityQueue<Process> pq = new PriorityQueue<Process>();
        Queue<Process> q = new LinkedList<Process>();
        for(int i=0; i<priorities.length; i++) {
            Process process = new Process(priorities[i], i);
            pq.offer(process);
            q.offer(process);
        }
    
        
        while(!q.isEmpty()) {
            Process curProcess = q.poll();
            Process maxProcess = pq.peek();
            if(curProcess.priority == maxProcess.priority) {
                pq.poll();
                answer++;
                if(curProcess.index == location) return answer;
            } else {
                q.offer(curProcess);
            }   
        }
        return answer;
    }
}