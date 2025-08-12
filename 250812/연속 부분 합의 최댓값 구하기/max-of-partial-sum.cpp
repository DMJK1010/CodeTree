#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> D(N+1, INT_MIN);

	D[0] = arr[0];
    int max_sum = D[0];

    for (int i = 1; i <= N; i++) {
        D[i] = max(arr[i], D[i - 1] + arr[i]);
    }


    int max_d = D[0];

    for (int i = 1; i < N; i++)
        max_d = max(D[i - 1], D[i]);

	cout << max_d << endl;
    return 0;
}
