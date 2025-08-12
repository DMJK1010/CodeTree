#include <bits/stdc++.h>

using namespace std;

int N, M;
int coin[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    vector<int> D(M+1, INT_MAX);
    D[0] = 0;
    
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= coin[j]) {
                if (D[i - coin[j]] == INT_MAX) continue;
                D[i] = min(D[i], D[i - coin[j]] + 1);
            }
        }
    }

	int ans = D[M];

    if (ans == INT_MAX)
        ans = -1;

	cout << ans << endl;

    return 0;
}
