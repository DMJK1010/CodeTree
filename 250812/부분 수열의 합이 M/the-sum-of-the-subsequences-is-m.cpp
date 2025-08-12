#include <bits/stdc++.h>

using namespace std;

int n, m;
int coins[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> D(m+1, -1);

    D[0] = 0;

    for(auto coin: coins){
        for(int i=m; i>=1; i--){
            if(i >= coin && D[i-coin] != -1){
                if(D[i] == -1 || D[i] > D[i-coin] + 1){
                    D[i] = D[i-coin] + 1;
                }
            }
        }
    }

    cout << D[m] << endl;



    return 0;
}
