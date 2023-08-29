#include<bits/stdc++.h>
using namespace std;

bool balancedTree(vector<int>& ages) {
    int n = ages.size();
    if(n == 0) return true;
    if(n == 1) return true;
    vector<int> left, right;
    int root = ages[0];
    for(int i = 1; i < n; i++) {
        if(ages[i] < root) left.push_back(ages[i]);
        else right.push_back(ages[i]);
    }
    int l = left.size();
    int r = right.size();
    if(abs(l - r) > 1) return false;
    return balancedTree(left) && balancedTree(right);
}

int main() {
    int n;
    cin >> n;
    vector<int> ages(n);
    for(int i = 0; i < n; i++) {
        cin >> ages[i];
    }
    if(balancedTree(ages)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}