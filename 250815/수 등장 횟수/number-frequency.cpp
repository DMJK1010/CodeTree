#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;

int n, m;
int arr[MAX_N];
int nums[MAX_N];
unordered_map<int, int> numbers;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for(int i=0; i<n; i++){
        if(numbers.find(arr[i]) == numbers.end())
            numbers[arr[i]] = 1;
        else
            numbers[arr[i]]++;
    }

    for(int i=0; i<m; i++){
        int as;
        cin >> as;
        if(numbers.find(as) == numbers.end())
            cout << "0 ";
        else
            cout << numbers[as] << " ";
    }

    

    return 0;
}
