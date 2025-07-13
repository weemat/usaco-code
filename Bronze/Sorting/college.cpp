#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define all(x) (x).begin(), (x).end()
int main()
{
    int n;
    cin >> n;

    vector<long long> vals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }

    sort(all(vals));

    long long tot = 0;
    long long cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (long long temp = vals[i]; temp != cost) // Only proceed if new value
        {
            if (tot < temp * (n - i))
            {
                tot = temp * (n - i);
                cost = temp;
            }
        }
    }
    cout << tot << " " << cost << endl;
    return 0;
}
