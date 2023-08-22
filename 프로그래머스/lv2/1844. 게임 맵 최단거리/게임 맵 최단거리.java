import java.util.*;

class Pos {
    int x;
    int y;
    int dist;
    
    public Pos(int x, int y, int dist) {
        this.x = x;
        this.y = y;
        this.dist = dist;
    }
}

class Solution {
    public int solution(int[][] maps) {
        int answer = 0;
        answer = bfs(0, 0, maps);
        return answer;
    }
    
    public boolean canGo(int x, int y, int row, int col) {
        if(x < 0 || x >= row || y < 0 || y >= col) return false;
        return true;
    }
    
    public int bfs(int x, int y, int[][] maps) {
        int row = maps.length;
        int col = maps[0].length;
        int[] xDir = {-1, 1, 0, 0};
        int[] yDir = {0, 0, -1, 1};
        boolean[][] visited = new boolean[row][col];
        
        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(x, y, 1));
        visited[x][y] = true;
        
        while(!q.isEmpty()) {
            Pos cur = q.poll();
            int curX = cur.x;
            int curY = cur.y;
            int curDist = cur.dist;
            
            if(curX == row-1 && curY == col-1) {
                return curDist;
            }
            
            for(int i=0; i<4; i++) {
                int nextX = curX + xDir[i];
                int nextY = curY + yDir[i];
                if(canGo(nextX, nextY, row, col) && !visited[nextX][nextY] && maps[nextX][nextY] == 1) {
                    visited[nextX][nextY] = true;
                    q.offer(new Pos(nextX, nextY, curDist + 1));
                }
            }
        }
        return -1;
    }
}