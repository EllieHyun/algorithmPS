import java.util.*;

class Solution {
    int answer = 0;
    boolean[] visited = {};
    public int solution(int n, int[][] computers) {
        visited = new boolean[computers.length];   // 이미 네트워크에 속해있는지 아닌지 검증
        for(int i=0; i<computers.length; i++) {
            // printVisited(computers.length);
            if(!visited[i]) {
                visited[i] = true;
                dfs(i, computers);
                answer++;
            }
        }
        return answer;
    }
    
    public void dfs(int start, int[][] computers) {
        // System.out.println("start : " + start);
        int[] computer = computers[start];
        // for(int c : computer) {
        //     System.out.print(c + " ");
        // }
        System.out.println();
        for(int i=0; i<computer.length; i++) {
            // System.out.println("i : " + i);
            int isConnected = computer[i];
            // System.out.println("isConnected : " + isConnected);
            if(isConnected == 1 && !visited[i] && i != start) {
                // System.out.println("can go");
                visited[i] = true;
                dfs(i, computers);
            }
        }
        return;
    }
    
    public void printVisited(int length) {
        System.out.println("=====visited=====");
        for(int i=0; i<length; i++) {
            System.out.print(visited[i] + " ");
        }
        System.out.println();
    }
}