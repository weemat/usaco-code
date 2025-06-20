#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
int countWays = 0;
vector<bool> col, diag1, diag2;


void solve(int y)
{
    if (y == N)
    {
        countWays++;
        return;
    }

    for (int x = 0; x < N; x++)
    {
        if (col[x] || diag1[x+y]||diag2[y-x+N-1]) continue;
        col[x] = diag1[x+y] = diag2[y-x+N-1] = true;
        solve(y+1);
        col[x] = diag1[x+y] = diag2[y-x+N-1] = false;
    }
}

int main()
{
    cin >> N;
    col.resize(N);
    diag1.resize(2*N-1);
    diag2.resize(2*N-1);

    solve(0);
    cout << countWays << endl;
    return 0;
}




