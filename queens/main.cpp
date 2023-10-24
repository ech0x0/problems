#include <iostream>

using namespace std;

int queen[14];
bool col[14], firstDiagonal[28], secondDiagonal[28];
int n, ans;

void backtrack(int l) {
    if (l == n) {
        if (ans < 1) {
            for (int i = 0; i < n; ++i) {
                cout << queen[i] + 1 << ' ';
            }
            cout << '\n';
        }
        ++ans;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (!col[i] && !firstDiagonal[i - l + n - 1] && !secondDiagonal[l + i]) {
                queen[l] = i;

                col[i] = firstDiagonal[i - l + n - 1] = secondDiagonal[l + i] = true;

                backtrack(l + 1);

                col[i] = firstDiagonal[i - l + n - 1] = secondDiagonal[l + i] = false;
            }
        }
    }
}

int main() {
    cin >> n;

    backtrack(0);

    cout << ans;
    return 0;
}