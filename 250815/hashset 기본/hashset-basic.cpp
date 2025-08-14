#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
string command[100000];
int x[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
    }

    unordered_set<int> s;

    for(int i=0; i<n; i++){
        if(command[i] == "add")
            s.insert(x[i]);
        else if(command[i] == "remove")
            s.erase(x[i]);
        else if(command[i] == "find"){
            if(s.find(x[i]) == s.end())
                cout << "false" << endl;
            else
                cout << "true" << endl;
        }
    }

    return 0;
}
