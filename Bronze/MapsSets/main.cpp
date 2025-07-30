#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isValid(vector<int>& cows, vector<int>& order, unordered_map<int, int>& map, int ind)
{
    if (cows[ind] != 0) return false; // Check if cow already exists at that position
    int curPos = 1;
    for (int i = 0; i < order.size(); i++) // Iterate through milking order
    {
        int requiredCowPos = map[order[i]];
        if (requiredCowPos > 0) // Cow in hierarchy has permanent spot
        {

        }
    }
    return true;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cows(n + 1); // Store cows here
    vector<int> order(m); // Store the hierarchy
    unordered_map<int, int> map;

    for (int i = 0; i < m; i++)
    {
        cin >> order[i];
    }

    for (int i = 0; i < k; i++)
    {
        int val, pos;
        cin >> val >> pos;
        cows[pos] = val;
        map[val] = pos;
    }

    // Order = 4 5 6
    // Map = 5 : 3, 3 : 1
    int minPos = n;
    // Try inserting first cow at every possible position
    for (int i = 1; i <= n; i++)
    {
        if (isValid(cows, order, map, i))
        {
            minPos = i;
             break;
        }
    }

    cout << minPos << endl;
    return 0;

}
