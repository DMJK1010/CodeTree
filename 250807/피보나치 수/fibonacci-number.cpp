#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<long long> D(N+1);

    D[1] = D[2] = 1;

    for(int i=3; i<=N; i++){
        D[i] = D[i-1] + D[i-2];
    }

    cout << D[N] << endl;
    return 0;
}

