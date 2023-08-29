#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& money, int bill, int index, vector<int>& subset, vector<vector<int>>& result) {
 if (bill == 0) {
 result.push_back(subset);
 return;
 }
 for (int i = index; i < money.size(); i++) {
 if (bill - money[i] < 0) {
 break;
 }
 subset.push_back(money[i]);
 backtrack(money, bill - money[i], i + 1, subset, result);
 subset.pop_back();
 }
}

int main() {
 int n, bill;
 cin >> n;
 vector<int> money(n);
 for (int i = 0; i < n; i++) {
 cin >> money[i];
 }
 sort(money.begin(), money.end());
 cin >> bill;
 vector<vector<int>> subsets;
 vector<int> subset;
 backtrack(money, bill, 0, subset, subsets);
 for (auto subset : subsets) {
 for (auto money : subset) {
 cout << money << " ";
 }
 cout << "\n";
 }
 int total_contribution = 0;
 for (auto subset : subsets) {
 int max_money = subset.back();
 total_contribution += max_money;
 cout << max_money << " ";
 }
 cout << "\n" << total_contribution << "\n";
 return 0;
}