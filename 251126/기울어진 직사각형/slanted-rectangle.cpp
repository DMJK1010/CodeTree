#include <iostream>
#include <algorithm> // max 함수 사용
#include <vector>

using namespace std;

int N;
int grid[21][21];

// (r, c)에서 시작해서 왼쪽 아래 길이 d1, 오른쪽 아래 길이 d2인 직사각형의 합 반환
int getRectSum(int r, int c, int d1, int d2) {
    int sum = 0;
    int x = r;
    int y = c;

    // 1. 왼쪽 아래로 이동 (↙️) : 길이 d1만큼
    for (int i = 0; i < d1; i++) {
        x++; // 아래로
        y--; // 왼쪽으로
        sum += grid[x][y];
    }

    // 2. 오른쪽 아래로 이동 (↘️) : 길이 d2만큼
    for (int i = 0; i < d2; i++) {
        x++; // 아래로
        y++; // 오른쪽으로
        sum += grid[x][y];
    }

    // 3. 오른쪽 위로 이동 (↗️) : 길이 d1만큼
    for (int i = 0; i < d1; i++) {
        x--; // 위로
        y++; // 오른쪽으로
        sum += grid[x][y];
    }

    // 4. 왼쪽 위로 이동 (↖️) : 길이 d2만큼
    for (int i = 0; i < d2; i++) {
        x--; // 위로
        y--; // 왼쪽으로
        sum += grid[x][y];
    }

    // 주의: 위 로직은 시작점 (r, c)를 마지막 4번 과정 끝에 더하게 됩니다.
    // 한 바퀴를 핑 돌아서 제자리로 오면서 더하므로 중복 없이 깔끔하게 더해집니다.
    
    return sum;
}

int main() {
    // 1. 입력 받기
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    int max_sum = -1e9;

    // 2. 모든 점을 기준점(상단 꼭짓점)으로 시도
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            
            // 3. 가능한 모든 길이 d1, d2 시도
            // d1: 왼쪽 아래 길이, d2: 오른쪽 아래 길이
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    
                    // 4. 범위 체크
                    // 기준점(r,c)에서:
                    // 아래쪽 끝 점의 행: r + d1 + d2 가 N을 넘으면 안 됨
                    // 왼쪽 끝 점의 열: c - d1 이 1보다 작으면 안 됨
                    // 오른쪽 끝 점의 열: c + d2 가 N을 넘으면 안 됨
                    if (r + d1 + d2 > N) continue;
                    if (c - d1 < 1) continue;
                    if (c + d2 > N) continue;

                    // 5. 유효한 직사각형이면 합 계산 후 최댓값 갱신
                    int current_sum = getRectSum(r, c, d1, d2);
                    if (current_sum > max_sum) {
                        max_sum = current_sum;
                    }
                }
            }
        }
    }

    // 6. 결과 출력
    cout << max_sum << endl;

    return 0;
}