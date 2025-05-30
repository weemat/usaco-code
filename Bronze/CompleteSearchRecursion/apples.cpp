#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


long long recurse(vector<long long> &apples, int index, long long sum1, long long sum2)
{
    if (index == apples.size())
    {
        return abs(sum1 - sum2);
    }

    return min(recurse(apples, index + 1, sum1 + apples[index], sum2), recurse(apples, index + 1, sum1, sum2 + apples[index]));
}

int main()
{
    int n;
    cin >> n;

    vector<long long> apples;
    for (int i = 0; i < n; i++)
    {
        int apple;
        cin >> apple;
        apples.push_back(apple);
    }

    cout << recurse(apples, 0, 0, 0) << endl;
    return 0;

}
