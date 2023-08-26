import java.util.*;

class Solution {
    boolean[] visited = new boolean[10001];   // i번째 경로 방문여부 확인
    // String[] answer = {};
    ArrayList<String> pathList = new ArrayList<>();
    
    public String[] solution(String[][] tickets) {
        // answer = new String[tickets.length + 1];
        dfs("ICN", "ICN", tickets, 0);
        Collections.sort(pathList);
        return pathList.get(0).split(" ");
        // return answer;
    }
    
    public void dfs(String from, String path, String[][] tickets, int count) {
        if(count == tickets.length) {
            pathList.add(path);
            return;
        }
        
        for(int i=0; i<tickets.length; i++) {
            if(!visited[i] && tickets[i][0].equals(from)) {
                visited[i] = true;
                dfs(tickets[i][1], path + " " + tickets[i][1], tickets, count+1);
                visited[i] = false;
            }
        }
    }
}