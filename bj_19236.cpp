// 청소년상어
#include <iostream>
#include <queue>

using namespace std;

struct fish {
    int x;   // 물고기가 있는 x 좌표
    int y;   // 물고기가 있는 Y 좌표
    int dir;   // 물고기의 현재 방향
    fish() {
        x = 0;
        y = 0;
        dir = 0;
    };

    fish(int X, int Y, int DIR) : x(X), y(Y), dir(DIR) {}
};

int dirs[9][2] = {{0,  0},
                  {-1, 0},
                  {-1, -1},
                  {0,  -1},
                  {1,  -1},
                  {1,  0},
                  {1,  1},
                  {0,  1},
                  {-1, 1}
};   // 북, 북서, 서, 남서, 남, 남동, 동, 북동(반시계방향)
int maxAns = -1;

bool fishCanGo(int x, int y, int dir, vector<vector<int> > &fishNum) {
    int nextX = x + dirs[dir][0];
    int nextY = y + dirs[dir][1];
    if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4) return false;   // 경계를 벗어나면 이동할 수 없음
    if (fishNum[nextX][nextY] == -1) return false;   // 상어가 존재한다면 이동할 수 없음
    return true;   // 비어있거나 물고기가 있다면 이동할 수 있음
}

int rotateDir(int curDir) {
    if (curDir == 8) curDir = 1;
    else curDir++;
    return curDir;
}

void moveFish(vector<fish> &fishVec, vector<vector<int> > &fishNum) {
    // 물고기 이동
    /**
     * 1. 물고기는 한 칸에 하나만 존재
     * 2. 물고기는 번호 순으로 이동
     * 3. 물고기는 자신의 방향으로 이동
     * 3-1. 만약 다른 물고기가 있다면 자리를 바꿈
     * 4. 이동할 수 없다면(상어가 존재하거나, 공간의 경계를 넘으면) 이동할 수 있을 때까지 45도 반시계 회전
     * 4-1. 만약 이동할 수 있는 칸이 없다면 이동하지 않음
     */
    for (int i = 1; i <= 16; i++) {
        if (fishVec[i].x == -1 && fishVec[i].y == -1) continue;   // 더 이상 존재하지 않는 물고기 번호일 경우는 이동하지 않아도됨
        int curX = fishVec[i].x;
        int curY = fishVec[i].y;
        int curDir = fishVec[i].dir;
        int nextDir = curDir;
        // 물고기가 이동할 수 있을 때까지 45도 반시계로 회전
        if (!fishCanGo(curX, curY, curDir, fishNum)) {
            // 현재 방향에서 이동할 수 없을 경우
            nextDir = rotateDir(curDir);   // 반시계 방향으로 회전
            bool fishCanGoFlag = false;
            while (curDir != nextDir) {
                // 다시 같은 자리로 돌아올 때까지
                if (fishCanGo(curX, curY, nextDir, fishNum)) {
                    fishCanGoFlag = true;
                    break;
                } else {
                    nextDir = rotateDir(nextDir);   // 다시 방향 회전
                }
            }
            if (!fishCanGoFlag) {
                // 45도 회전해도 물고기가 이동할 방향을 찾지 못했을 경우 이동하지 않음
                continue;
            }
        }
        int nextX = curX + dirs[nextDir][0];
        int nextY = curY + dirs[nextDir][1];   // 물고기가 이동할 수 있는 좌표
        if (fishNum[nextX][nextY] == 0) {
            // 물고기가 이동할 곳이 빈 곳인 경우
            fishVec[i].x = nextX;
            fishVec[i].y = nextY;
            fishVec[i].dir = nextDir;
            fishNum[curX][curY] = 0;   // 이전 칸에 물고기 없어짐
            fishNum[nextX][nextY] = i;   // 새로 이동한 칸으로 물고기 이동
        } else {
            // 물고기가 이동할 곳에 다른 물고기가 있는 경우
            int tempFishNum = fishNum[nextX][nextY];   // 바꿀 물고기의 번호
            fishVec[i].x = nextX;
            fishVec[i].y = nextY;
            fishVec[i].dir = nextDir;
            fishNum[nextX][nextY] = i;

            fishVec[tempFishNum].x = curX;
            fishVec[tempFishNum].y = curY;
            fishNum[curX][curY] = tempFishNum;
        }
    }
}

void dfs(int curSum, int curSharkX, int curSharkY, int curDir, vector<fish> &fishVec, vector<vector<int> > &fishNum) {
    // 상어가 물고기를 먹고, 방향을 가진다
    int curFish = fishNum[curSharkX][curSharkY];   // 현재 상어가 있는 칸의 물고기 번호
    fishNum[curSharkX][curSharkY] = -1;   // 상어가 해당 칸으로 이동
    curSum += curFish;   // 물고기 번호 더함
    curDir = fishVec[curFish].dir;   // 물고기의 방향대로 상어의 방향 변경
    fishVec[curFish].x = -1;
    fishVec[curFish].y = -1;   // 더 이상 필요없는 물고기 번호


    // 물고기가 이동한다
    moveFish(fishVec, fishNum);

    fishNum[curSharkX][curSharkY] = 0;   // 해당 칸의 물고기를 먹고 난 후 해당 칸은 비게됨
    // 상어가 이동하는 모든 경우의 수
    int nextX = curSharkY;
    int nextY = curSharkY;
    bool canSharkGo = false;   // 해당 경우에서 상어가 이동할 수 있는지 확인
    for (int i = 0; i < 4; i++) {
        // 4*4이므로 최대 4번 이동 가능
        // 하나라도 갈 수 있는 곳이 있다면 이동 가능
        nextX += dirs[curDir][0];   // 상어가 다음으로 이동할 x 좌표
        nextY += dirs[curDir][1];   // 상어가 다음으로 이동할 y 좌표
        if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4) continue;   // 격자를 벗어나는 곳은 이동 불가
        if (fishNum[nextX][nextY] == 0) continue;   // 물고기가 없을 경우
        else {
            // 격자를 벗어나지 않고, 물고기가 존재하는 칸이 하나라도 존재함 = 이동할 수 있는 곳이 존재한다는 것
//            int temp = fishNum[nextX][nextY];
            vector<fish> fishVecTemp = fishVec;
            vector<vector<int> > fishNumTemp = fishNum;
            dfs(curSum, nextX, nextY, curDir, fishVec, fishNum);   // 해당 칸으로 이동
            fishVec = fishVecTemp;
            fishNum = fishNumTemp;
//            fishNum[nextX][nextX] = temp;   // 상어가 다시 올라옴
            canSharkGo = true;   // 한군데라도 상어가 갈 수 있는 것
        }
    }

    // 해당 상황에서 상어가 더 이상 갈 수 있는 칸이 없을 경우에는 함수를 종료하고 최댓값 확인
    // 상어가 이동할 수 없을 떄 = 상어가 현재 방향으로 이동했을 떄 물고기가 한 칸도 없는 경우
    if (!canSharkGo) {
        if (curSum > maxAns) maxAns = curSum;
        return;
    }
}

int main() {
    // 상어가 먹을 수 있는 물고기 번호의 합의 최댓값
    // 상어가´ 어디로 이동하느냐에 따라 달라짐
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num, dir;
    int sharkDir;
    priority_queue<fish> pq;   // 초기 물고기
    vector<vector<int> > fishNum(4, vector<int>(4, 0));   // 각 좌표에 몇번 물고기가 있는지 확인
    vector<fish> fishVec(17);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> num >> dir;   // 물고기의 번호와 방향
            if (i == 0 && j == 0) sharkDir = dir;
            fishVec[num].x = i;
            fishVec[num].y = j;
            fishVec[num].dir = dir;
            fishNum[i][j] = num;   // 각 칸에 어떤 물고기가 존재하는지 확인
        }
    }

    dfs(0, 0, 0, sharkDir, fishVec, fishNum);

    cout << "maxAns : " << maxAns << "\n";

    return 0;
}