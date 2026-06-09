#include <iostream>
#include <algorithm>
using namespace std;

int* getFSMax(int dp[][1000], int col, int rows) {
    static int res[2];

    int fmax = max(dp[0][col], dp[1][col]);
    int smax = min(dp[0][col], dp[1][col]);

    for (int row = 2; row < rows; row++) {
        if (dp[row][col] > fmax) {
            smax = fmax;
            fmax = dp[row][col];
        }
        else if (dp[row][col] > smax) {
            smax = dp[row][col];
        }
    }

    res[0] = fmax;
    res[1] = smax;

    return res;
}

int main() {
    int R, C;
    cin >> R >> C;

    int grid[1000][1000];
    int dp[1000][1000];

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];

            if (col == 0) {
                dp[row][col] = grid[row][col];
            }
        }
    }

    for (int col = 1; col < C; col++) {
        int* fsmax = getFSMax(dp, col - 1, R);

        for (int row = 0; row < R; row++) {
            dp[row][col] =
                grid[row][col] +
                (dp[row][col - 1] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }

    cout << getFSMax(dp, C - 1, R)[0];

    return 0;
}