// DFS
#include <iostream>
#define MAX 21
using namespace std;

int map[MAX][MAX] = { 0, };
int dice[4][3] = { {0, 2, 0}, {4, 1, 3}, {0, 5, 0}, {0, 6, 0} };   // 초기 주사위의 전개도
int n, m, k, sameCnt = 0, score = 0, dir = 0;
int xDir[4] = { 0, 1, 0, -1 };   // 동남서북
int yDir[4] = { 1, 0, -1, 0 };   // 동남서북
int visited[MAX][MAX] = { false, };

void roll(int dir) {
	if (dir == 0) {
		// 동쪽
		swap(dice[1][2], dice[3][1]);
		int temp1 = dice[1][0];
		int temp2 = dice[1][1];
		int temp3 = dice[1][2];
		dice[1][0] = temp3;
		dice[1][1] = temp1;
		dice[1][2] = temp2;
	}
	else if (dir == 1) {
		// 남쪽
		int temp1 = dice[0][1];
		int temp2 = dice[1][1];
		int temp3 = dice[2][1];
		int temp4 = dice[3][1];
		dice[0][1] = temp4;
		dice[1][1] = temp1;
		dice[2][1] = temp2;
		dice[3][1] = temp3;
	}
	else if (dir == 2) {
		// 서쪽
		swap(dice[1][0], dice[3][1]);
		int temp1 = dice[1][0];
		int temp2 = dice[1][1];
		int temp3 = dice[1][2];
		dice[1][0] = temp2;
		dice[1][1] = temp3;
		dice[1][2] = temp1;
	}
	else if(dir == 3) {
		// 북쪽
		int temp1 = dice[0][1];
		int temp2 = dice[1][1];
		int temp3 = dice[2][1];
		int temp4 = dice[3][1];
		dice[0][1] = temp2;
		dice[1][1] = temp3;
		dice[2][1] = temp4;
		dice[3][1] = temp1;
	}
}

void dfs(int curX, int curY, int num) {
	if (curX < 1 || curX > n || curY < 1 || curY > m) return;
	if (map[curX][curY] != num) 
		return;
	else {
		visited[curX][curY] = true;
		sameCnt++;
		for (int i = 0; i < 4; i++) {
			int newX = curX + xDir[i];
			int newY = curY + yDir[i];
			if (newX >= 1 && newX <= n && newY >= 1 && newY <= m && !visited[newX][newY]) {
				dfs(newX, newY, num);
			}
		}
	}
}

void changeDir(int watch) {
	if (watch == 0) {
		if (dir == 3) dir = 0;
		else dir++;
	}
	else {
		if (dir == 0) dir = 3;
		else dir--;
	}
}

bool canMove(int curX, int curY, int dir) {
	int newX = curX + xDir[dir];
	int newY = curY + yDir[dir];
	if (newX >= 1 && newX <= n && newY >= 1 && newY <= m) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];   // 지도 수 입력받기

	int curX = 1, curY = 1;
	dir = 0;   // 초기방향 동쪽

	for (int i = 0; i < k; i++) {
		if (!canMove(curX, curY, dir)) {
			// 갈 수 없는 칸일 경우 방향 바꾸기
			if (dir == 0) dir = 2;
			else if (dir == 2) dir = 0;
			else if (dir == 1) dir = 3;
			else if (dir == 3) dir = 1;
		}
		roll(dir);   // 주사위 회전
		curX += xDir[dir];   // 지도에서 이동(x좌표)
		curY += yDir[dir];   // 지도에서 이동(y좌표)
		sameCnt = 0;
		dfs(curX, curY, map[curX][curY]);
		score += sameCnt * map[curX][curY];
		if (dice[3][1] > map[curX][curY]) {
			changeDir(0);   // 시계방향 회전
		}
		else if (dice[3][1] < map[curX][curY]) {
			changeDir(1);   // 반식계방향 회전
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				visited[i][j] = false;
	}

	cout << score;

	return 0;
	
}