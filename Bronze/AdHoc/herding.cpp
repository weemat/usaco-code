#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> nums(3);

    for (int i = 0; i < 3; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    bool hasTwo = false;
    int maxDiff = 0;

    for (int i = 0; i < 2; i++) {
        int diff = nums[i + 1] - nums[i];

        if (diff == 2) {
            hasTwo = true;
        }

        maxDiff = max(maxDiff, diff);
    }

    if (maxDiff == 1) {
        cout << 0 << endl << 0;
    }

    else if (hasTwo) {
        cout << 1 << endl << maxDiff - 1;
    }

    else {
        cout << 2 << endl << maxDiff - 1;
    }
     return 0;

}