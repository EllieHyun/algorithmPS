// 톱니바퀴
#include <iostream>
using namespace std;

int leftPointer[5] = {0,};
int rightPointer[5] = {0,};
int gear[5][9] = {0,};
bool rotateCheck[5] = {false,};
int rotateDirection[5] = {0,};   // 각 기어의 회전방향이 저장된 배열
int answer = 0;

void movePointer(int curGear, int rotateDir) {
    if (rotateDir == 0) {
        return;
    } else if (rotateDir == 1) {
        // 시계방향으로 회전
        if (leftPointer[curGear] == 1) leftPointer[curGear] = 8;
        else leftPointer[curGear]--;
        if (rightPointer[curGear] == 1) rightPointer[curGear] = 8;
        else rightPointer[curGear]--;
    } else if (rotateDir == -1) {
        // 반시계방향으로 회전
        if (leftPointer[curGear] == 8) leftPointer[curGear] = 1;
        else leftPointer[curGear]++;
        if (rightPointer[curGear] == 8) rightPointer[curGear] = 1;
        else rightPointer[curGear]++;
    }
}

int checkBothSide(int curGear) {
    bool rightSideIsDiff, leftSideIsDiff;
    if (curGear == 1) {
        // 오른쪽만 확인하면됨
        if (rotateCheck[curGear + 1]) return 0;   // 양쪽이 모두 같은 극이거나 이미 돌아간 톱니바퀴라 돌아갈 필요가 없음
        else {
            rightSideIsDiff = (gear[curGear][rightPointer[curGear]] != gear[curGear + 1][leftPointer[curGear + 1]]);
            if (rightSideIsDiff) return 2;   // 오른쪽이 다른 극일 경우
            else return 0;   // 오른쪽이 같은 극일 경우
        }
    } else if (curGear == 4) {
        // 왼쪽만 확인하면됨
        if (rotateCheck[curGear - 1]) return 0;
        else {
            leftSideIsDiff = (gear[curGear][leftPointer[curGear]] != gear[curGear - 1][rightPointer[curGear - 1]]);
            if (leftSideIsDiff) return 1;   // 왼쪽만 다른 극일 경우
            else return 0;   // 왼쪽이 같은 극일 경우
        }
    } else {
        if (rotateCheck[curGear - 1]) leftSideIsDiff = false;
        else leftSideIsDiff = (gear[curGear][leftPointer[curGear]] != gear[curGear - 1][rightPointer[curGear - 1]]);

        if (rotateCheck[curGear + 1]) rightSideIsDiff = false;
        else rightSideIsDiff = (gear[curGear][rightPointer[curGear]] != gear[curGear + 1][leftPointer[curGear + 1]]);

        if (!leftSideIsDiff && !rightSideIsDiff) return 0;   // 양쪽 모두 같은 극일 경우
        else if (leftSideIsDiff && !rightSideIsDiff) return 1;    // 왼쪽만 다른 극일 경우
        else if (rightSideIsDiff && !leftSideIsDiff) return 2;   // 오른쪽만 다른 극일 경우
        else return 3;   // 양쪽 모두 다른 극일 경우
    }
}

void rotate(int curGear, int rotateDir) {
    // dir - 0 : 왼쪽, dir - 1 : 오른쪽
    // 왼쪽 방향
    int bothSide = checkBothSide(curGear);   // 왼쪽과 오른쪽 검사
    rotateDirection[curGear] = rotateDir;
    rotateCheck[curGear] = true;   // 한 턴에서 한번 돈 톱니바퀴는 다시 돌 수 없음
    if (bothSide == 0) {
        // 두 방향 다 회전 안해도됨
        return;
    } else if (bothSide == 1) {
        // 왼쪽만 다른 극일 경우 왼쪽만 회전
        rotateDirection[curGear - 1] = -rotateDir;
        rotateCheck[curGear - 1] = true;
        rotate(curGear - 1, -rotateDir);
    } else if (bothSide == 2) {
        rotateDirection[curGear + 1] = -rotateDir;
        rotateCheck[curGear + 1] = true;
        rotate(curGear + 1, -rotateDir);
        // 오른쪽만 다른 극일 경우 오른쪽만 회전
    } else {
        // 두쪽 다 다른 극일 경우 두쪽 다 회전
        rotateDirection[curGear - 1] = -rotateDir;
        rotateCheck[curGear - 1] = true;
        rotate(curGear - 1, -rotateDir);

        rotateDirection[curGear + 1] = -rotateDir;
        rotateCheck[curGear + 1] = true;
        rotate(curGear + 1, -rotateDir);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, num;
    char str[9];

    for (int i = 1; i <= 4; i++) {
        cin >> str;
        for (int j = 1; j <= 8; j++) gear[i][j] = str[j - 1] - '0';   // 톱니바퀴의 상태 저장
        leftPointer[i] = 7;
        rightPointer[i] = 3;
    }

    cin >> k;
    int gearNum, rotateDir;
    for (int i = 0; i < k; i++) {
        cin >> gearNum >> rotateDir;
        for (int j = 1; j <= 4; j++) {
            rotateDirection[j] = 0;   // 어느방향으로도 회전하지 않음
            rotateCheck[j] = false;
        }
        rotate(gearNum, rotateDir);   // 현재 톱니바퀴부터 회전 시작
        for (int j = 1; j <= 4; j++) movePointer(j, rotateDirection[j]);   // 모든 톱니바퀴 한번에 회전
    }

    int temp = 1;
    for (int i = 1; i <= 4; i++) {
        int curRight = rightPointer[i];
        if (curRight == 1) curRight = 7;
        else if (curRight == 2) curRight = 8;
        else curRight -= 2;
        if (gear[i][curRight] == 1) answer += temp;
        temp *= 2;
    }

    cout << answer;

    return 0;
}
