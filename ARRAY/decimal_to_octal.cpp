#include <bits/stdc++.h>
using namespace std;

int main() {

    int num;
    cout << "Enter the number: ";
    cin >> num;

    int temp = num;
    vector<int> ans;

    while(temp != 0) {

        int rem = temp % 8;
        ans.push_back(rem);

        temp = temp / 8;
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}