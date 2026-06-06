#include <iostream>
#include <algorithm>
using namespace std;

int* getFSMax(int dp[][1000], int row, int c) {
    static int res[2];

    int fmax = max(dp[row][0], dp[row][1]);
    int smax = min(dp[row][0], dp[row][1]);

    for (int col = 2; col < c; col++) {
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

    int grid[R][1000];
    int dp[R + 1][1000];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];

            if (i == 0) {
                dp[i][j] = grid[i][j];
            }
        }
    }

    for (int row = 1; row < R; row++) {
        int* fsmax = getFSMax(dp, row - 1, C);

        for (int col = 0; col < C; col++) {
            dp[row][col] =
                grid[row][col] +
                (dp[row - 1][col] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }

    cout << getFSMax(dp, R - 1, C)[0];

    return 0;
}