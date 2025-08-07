#include <bits/stdc++.h>

using namespace std;

int N;
int M[1000];
int D[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    D[0] = 1;

    for(int i = 1; i < N; i++){
        D[i] += M[i-1]<M[i]?1:0;
    }

    int len = 0;

    for(int i=0; i<N; i++){
        len += D[i] == 1 ? 1 : 0;
    }

    cout << len << endl;

    return 0;
}
