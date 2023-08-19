import java.util.*;

class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = {};
        answer = new int[queries.length];
        int[][] map = new int[rows+1][columns+1];
        int start = 1;
        for(int i=1; i<=rows; i++) {
            for(int j=1; j<=columns; j++) {
                map[i][j] = start++;
            }
        }
        
        int index = 0;
        for(int[] q : queries) {
            int x1 = q[0];
            int y1 = q[1];
            int x2 = q[2];
            int y2 = q[3];
            int min = 20000;
            
            int temp = map[x1][y2];
            // 행
            for(int i=y2; i>y1; i--) {
                if(min > map[x1][i]) min = map[x1][i];
                map[x1][i] = map[x1][i-1];
            }
            // 왼쪽
            for(int i=x1; i<x2; i++) {
                if(min > map[i][y1]) min = map[i][y1];
                map[i][y1] = map[i+1][y1];
            }
            // 아래
            for(int i=y1; i<y2; i++) {
                if(min > map[x2][i]) min = map[x2][i];
                map[x2][i] = map[x2][i+1];
            }
            // 왼쪽
            for(int i=x2; i>x1; i--) {
                if(min > map[i][y2]) min = map[i][y2];
                map[i][y2] = map[i-1][y2];
            }
            map[x1+1][y2] = temp;
            answer[index++] = min;
        }
        
        return answer;
    }
}