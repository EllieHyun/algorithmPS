// dfs & bfs
// 아이템 줍기
#include <string>
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
        //cout << "find! curX : " << curX << ", curY : " << curY << ", count : " << count << "\n";
        if(result > count) result = count;
        return;
    }

    visited[curX][curY] = true;

    for(int i=0; i<4; i++) {
        int nextX = curX + xDir[i];
        int nextY = curY + yDir[i];
        //cout << "nextX : " << nextX << ", nextY : " << nextY << "\n";
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

//    for(int i=1; i<=20; i++) {
//        for(int j=1; j<=20; j++) {
//            cout << board[i][j] << " ";
//        }
//        cout << "\n";
//    }

    visited[characterX*2][characterY*2] = true;

    move(characterX*2, characterY*2, itemX*2, itemY*2, 0);

    cout << "result : " << result/2 << "\n";

    return result;
}

int main() {
//    case 1
//    vector<vector<int>> rectangle = {
//            {1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}
//    };
//    int characterX = 1;
//    int characterY = 3;
//    int itemX = 7;
//    int itemY = 8;
//
//    case2
//    vector<vector<int>> rectangle = {
//            {1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}
//    };
//    int characterX = 9;
//    int characterY = 7;
//    int itemX = 6;
//    int itemY = 1;

//    case3
//    vector<vector<int>> rectangle = {
//            {1, 1, 5, 7}
//    };
//    int characterX = 1;
//    int characterY = 1;
//    int itemX = 4;
//    int itemY = 7;

//    case4
    vector<vector<int>> rectangle = {
            {2, 1, 7, 5}, {6, 4, 10, 10}
    };
    int characterX = 3;
    int characterY = 1;
    int itemX = 7;
    int itemY = 10;

    solution(rectangle, characterX, characterY, itemX, itemY);
}