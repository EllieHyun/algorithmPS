// 컨베이어 벨트 위의 로봇
#include <iostream>
#include <deque>

using namespace std;

struct box {
    int durability;
    bool robot;

    box(int DURABILITY, bool ROBOT) : durability(DURABILITY), robot(ROBOT) {}
};

deque<box> belt;
int n, k, ans = 0;

void rotate() {
    box temp = belt.back();
    belt.pop_back();
    belt.push_front(temp);
    if (belt[n - 1].robot) belt[n - 1].robot = false;   // 회전하다가 내리는 곳에 가면 즉시 로봇이 내림
}

void move() {
    // 여기서 내리는 위치에 있는 로봇 없애야함
    if (belt[2 * n - 1].robot && !belt[0].robot && belt[0].durability > 0) {
        // 2n번쨰 벨트에 로봇이 있고 1번쨰 벨트에 로봇이 없을 경우
        belt[2 * n - 1].robot = false;
        belt[0].robot = true;
        belt[0].durability--;
    }
    for (int i = 2 * n - 1; i >= 2; i--) {
        if (!belt[i].robot && belt[i].durability > 0 && belt[i - 1].robot) {
            // 이동하려는 칸에 로봇이 없고 그 칸의 내구도가 1 이상이며 이전 칸에 로봇이 있으면 로봇이 이동해올 수 있음
            belt[i - 1].robot = false;
            belt[i].robot = true;
            belt[i].durability--;
            if (i == n - 1) belt[i].robot = false;   // 이동하는 곳이 내리는 곳이라면 즉시 내림
        }
    }
}

void upRobot() {
    if (belt[0].durability != 0 && !belt[0].robot) {
        // 올리는 칸의 내구도가 0이 아니고 그 자리에 로봇이 없다면
        belt[0].robot = true;   // 그 자리에 로봇을 올리고
        belt[0].durability--;   // 내구도 1 감소
    }
}

int cntDurability() {
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) if (belt[i].durability == 0) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int durability;

    cin >> n >> k;

    for (int i = 0; i < 2 * n; i++) {
        cin >> durability;
        belt.push_back(box(durability, false));
    }

    while (true) {
        ans++;
        rotate();   // 회전
        move();
        upRobot();
        int cnt = cntDurability();
        if (cnt >= k) break;
    }

    cout << ans;

    return 0;

}