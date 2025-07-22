#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{
    map<long long, long long> a;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int code;
        long long next;
        cin >> code >> next;
        if (code == 0)
        {
            int third;
            cin >> third;
            a[next] = third;
        }
        else
        {
            cout << a[next] << endl;
        }
    }
    return 0;
}
