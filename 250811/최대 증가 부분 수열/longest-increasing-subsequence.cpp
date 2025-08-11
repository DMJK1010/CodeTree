#include <bits/stdc++.h>

using namespace std;

int N;
int M[1000];
int D[1000] = { INT_MIN, };

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    // Please write your code here.
    D[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if( M[j] < M[i] && D[j] + 1 > D[i]) {
                D[i] = D[j] + 1;
			}
        }
    }

	int ans = 0;

    for (int i = 0; i < N; i++) {
        ans = max(ans, D[i]);
	}
	cout << ans << endl;


    return 0;
}