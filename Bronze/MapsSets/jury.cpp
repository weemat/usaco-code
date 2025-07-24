#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> prefixSum(k + 1);
    prefixSum[0] = 0;
    vector<int> values(n);
    for (int i = 1; i <= k; i++)
    {
        cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    unordered_set<int> intSet;
    for (int i = 1; i <= k; i++)
    {
        intSet.insert(values[0] - prefixSum[i]);
    }

    // Traverse each remembered value to get a set of possible starting points
    for (int a = 1; a < n; a ++)
    {
        int val = values[a];
        unordered_set<int> locSet;
        unordered_set<int> newSet;
        for (int i = 1; i <= k; i++)
        {
            locSet.insert(val - prefixSum[i]);
        }

        if (locSet.size() > intSet.size()) swap(locSet, intSet);

        for (const int& elem : locSet)
        {
            if (intSet.find(elem) != intSet.end())
            {
                newSet.insert(elem);
            }
        }

        swap(intSet, newSet);

    }

    cout << intSet.size() << endl;
    return 0;


}
