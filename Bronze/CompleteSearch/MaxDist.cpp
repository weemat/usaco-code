#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// Problem: https://codeforces.com/gym/102951/problem/A

int distanceSquared(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    return dx*dx + dy*dy;
}

int main()
{
    int N;
    cin >> N;

    vector<int> xCoords;
    vector<int> yCoords;

    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        xCoords.push_back(x);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> y;
        yCoords.push_back(y);
    }

    long long maxDistSq = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            long long distSq = distanceSquared(xCoords[i], yCoords[i], xCoords[j], yCoords[j]);
            if (distSq > maxDistSq)
            {
                maxDistSq = distSq;
            }
        }
    }
    cout << maxDistSq << endl;
    return 0;

}

