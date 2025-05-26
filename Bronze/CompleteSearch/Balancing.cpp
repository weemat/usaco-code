#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;
    cin >> n >> b;

    vector<pair<int, int> > coords(n);

    // Take in coordinates
    for (int i = 0; i < n; i++)
    {
        cin >> coords[i].first >> coords[i].second;
    }

    int minM = n;
    // Check every possible arrangement of lines
    for (int i = 0; i < n; i++)
    {
        int a = coords[i].first + 1;
        for (int j = 0; j < n; j++)
        {
            int b = coords[j].second + 1;
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            for (int k = 0; k < n; k++)
            {
                int x = coords[k].first;
                int y = coords[k].second;

                if (x > a && y > b) q1++;
                else if (x < a && y > b) q2++;
                else if (x < a && y < b) q3++;
                else q4++;
            }
            int maxM = max({q1, q2, q3, q4, q4});
            minM = min(minM, maxM);
        }
    }
    cout << minM << endl;
    return 0;

}
