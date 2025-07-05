#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define all(x) (x).begin(), (x).end()

int main ()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(all(v));
    cout << unique(all(v))-v.begin() << endl;
    return 0;

}
