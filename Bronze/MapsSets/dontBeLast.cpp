#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n;
    cin >> n;
    unordered_map<string, int> map;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int val;
        cin >> val;
        map[s] += val;
    }

    vector<pair<string, int>> vec(map.begin(), map.end());

    sort(vec.begin(), vec.end(), [](const pair<string, int>& p1, const pair<string, int>& p2)
    {
        return p1.second < p2.second;
    });

    int min;
    if (map.size() < 7)
    {
        min = 0;
    }

    else min = vec[0].second;

    bool isFound = false;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i].second > min)
        {
            if (vec[i + 1].second != vec[i].second)
                cout << vec[i].first << endl;
            else cout << "Tie" << endl;
            isFound = true;
            break;
        }
    }
    if (!isFound)
    {
        if (vec[vec.size() - 1].second > min)
        {
            cout << vec[vec.size() - 1].first << endl;
        }
        else cout << "Tie" << endl;
    }
    return 0;


}
