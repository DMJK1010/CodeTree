#include <bits/stdc++.h>

using namespace std;

int n;
int coin[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

	int dp[1001][4] = { 0 };

    dp[1][1] = coin[1];

    dp[2][0] = coin[2];
	dp[2][2] = coin[2] + dp[1][1];

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (dp[i - 2][j] != 0) {
				dp[i][j] = max(dp[i][j], dp[i - 2][j] + coin[i]);
            }
            if (j && dp[i - 1][j - 1] != 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + coin[i]);
            }
        }
    }

	int max_coins = dp[n][0];
    for (int i = 0; i < 4; i++) {
		max_coins = max(max_coins, dp[n][i]);
    }

	cout << max_coins << endl;

    return 0;
}


/*

1. 1또는 2씩 올라갈 수 있음
2. 각 층에는 동전이 있고 해당 층을 밟으면 동전을 획득함
3. 1계단 올라가는 것은 최대 3번만 하고자 함
4. N층까지 올라가고자 할 때, 동전의 최대 개수를 구하는 프로그램을 작성하시오.
5. 2계단 단위로 올라갈 경우 N층까지 정확히 1계단이 남은 상황에서는 n층으로 올라가지 못함

*/
