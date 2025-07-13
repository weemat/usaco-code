#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define all(x) (x).begin(), (x).end()
int main()
{
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++)
    {
        int first, second;
        cin >> first >> second;
        times[i] = make_pair(first, second);
    }

    sort(all(times));

    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int first = times[i].first;
        int second = times[i].second;

        if (first > tot) tot = first;
        tot += second;
    }
    cout << tot << endl;
    return 0;
}
