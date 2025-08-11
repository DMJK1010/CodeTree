#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

int dp[MAX_NUM + 1];
int n;
int a[MAX_NUM + 1];

void Initialize() {
    for(int i = 0; i <= n; i++)
        dp[i] = INT_MIN;
    
    dp[0] = 0;
    a[0] = 0;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    Initialize();

    for(int i = 1; i <= n; i++){

        for(int j = 0; j < i; j++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    int answer = 0;
    for(int i = 0; i <= n ; i++)
        answer = max(answer, dp[i]);

    cout << answer;
}
