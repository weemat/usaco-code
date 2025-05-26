#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int n, k;
    cin >> k >> n;

    vector<vector<int>> vec(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    // Check every pair
    int count = n*(n-1)/2;
    for (int i = 0; i < n; i++) // Iterate through every number
    {
        int num = vec[0][i];

        for (int j = i+1; j < n; j++) // Iterate through every pair in front
        {
            int pair = vec[0][j];
            for (int l = 1; l < k; l++) // Iterate through every list
            {
                auto it1 = find(vec[l].begin(), vec[l].end(), num);
                auto it2 = find(vec[l].begin(), vec[l].end(), pair);

                if (it1 > it2)
                {
                    count --;
                    break;
                }

            }
        }
    }

    cout << count << endl;
    return 0;

}

