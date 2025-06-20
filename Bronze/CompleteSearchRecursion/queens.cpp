#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int N = 8;
vector<string> board(N);
int countWays = 0;
bool col[N], diag1[2*N-1], diag2[2*N-1];

void solve(int y)
{
    if (y == N)
    {
        countWays++;
        return;
    }

    for (int x = 0; x < N; x++)
    {
        if (board[y][x] == '*') continue;
        if (col[x] || diag1[x+y]||diag2[y-x+N-1]) continue;
        col[x] = diag1[x+y] = diag2[y-x+N-1] = true;
        solve(y+1);
        col[x] = diag1[x+y] = diag2[y-x+N-1] = false;
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    solve(0);
    cout << countWays << endl;
    return 0;
}




