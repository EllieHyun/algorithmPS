#include <vector>
#include <iostream>
#define MAX 102
using namespace std;

int xDir[4] = {-1, 0, 1, 0};   // 북, 동, 남, 서
int yDir[4] = {0, 1, 0, -1};   // 북, 동, 남, 서

vector<vector<int>> board(MAX, vector<int>(MAX, 0));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
int result = 1000000;

void move(int curX, int curY, int itemX, int itemY, int count) {
    if(curX == itemX && curY == itemY) {
        if(result > count) result = count;
        return;
    }

    visited[curX][curY] = true;

    for(int i=0; i<4; i++) {
        int nextX = curX + xDir[i];
        int nextY = curY + yDir[i];
        if(board[nextX][nextY] == 1 && !visited[nextX][nextY]) {
            move(nextX, nextY, itemX, itemY, count+1);
        }

    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    for(auto r : rectangle) {
        int firstX = 2 * r[0];
        int firstY = 2 * r[1];
        int secondX = 2 * r[2];
        int secondY = 2 * r[3];
        for(int i=firstX; i<=secondX; i++) {
            for(int j=firstY; j<=secondY; j++) {
                // 사각형 전체 채우기
                if(!visited[i][j]) board[i][j] = 1;
            }
        }
        for(int i=firstX+1; i<=secondX-1; i++) {
            for(int j=firstY+1; j<=secondY-1; j++) {
                // 사각형 내부 비우기
                board[i][j] = 0;
                visited[i][j] = true;
            }
        }

    }

    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            visited[i][j] = false;
        }
    }

    visited[characterX*2][characterY*2] = true;

    move(characterX*2, characterY*2, itemX*2, itemY*2, 0);

    return result/2;
}