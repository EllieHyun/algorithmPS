import java.util.*;

class Task {
    int days;
    int number;
    
    public Task(int days) {
        this.days = days;
        this.number = 1;
    }
}

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        Queue<Integer> queue = new LinkedList<>();
        int max = 0;
        int index = 0;
        
        for(int i=0; i<progresses.length; i++) {
            int progress = 100 - progresses[i];
            int speed = speeds[i];
            int rest = progress % speed;
            int days;
            if(rest == 0) {
                days = progress / speed;
            } else {
                days = (progress / speed) + 1;
            }
            // System.out.println("days : " + days);
            if(max < days) {
                max = days;
                index++;
            }
            queue.offer(days);
        }
        
        // System.out.println("index : " + index);
        
        // while()
        answer = new int[index];
        max = 0;
        index = -1;
        int cnt = 1;
        while(!queue.isEmpty()) {
            int value = queue.poll();
            if(value > max) {
                // 현재 최대 작업일수보다 작은 작업 일수면 같이 진행될 작업에 포함됨
                max = value;
                // index++;
                answer[++index] = 1;
            } else {
                // 더 큰 작업 일수를 만나면 개별 작업으로 들어감
                answer[index]++;
            }
        }
        
        return answer;
    }
}