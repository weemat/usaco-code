#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;

    string s;
    cin >> s;
    int minLen = n/2 + n % 2;

    for (int len = 1; len <= n/2; len ++) // Iterate through string lengths
    {
        bool isFound = true;
        set<string> substrings;

        for (int i = 0; i <= s.length() - len; i ++) // Starting positions
        {
            string substr = s.substr(i, len); // String
            if (substrings.count(substr)) // Move on to next length if already in string
            {
                isFound = false;
                break;
            }
            substrings.insert(substr);
        }
        if (isFound)
        {
            minLen = min(minLen, len);
            break;
        }
    }
    cout << minLen << endl;
    return 0;
}
