#include <fstream>

using namespace std;

ifstream cin("rucsac.in");
ofstream cout("rucsac.out");

int w[5001], p[5001];
int dp[2][10001];

int main() {
    int n, gmax;
    cin >> n >> gmax;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> p[i];
    }

    int l = 0;
    for (int i = 1; i <= n; ++i, l = 1 - l) {
        for (int g = 0; g <= gmax; ++g) {
            dp[1 - l][g] = dp[l][g];

            if (w[i] <= g) dp[1 - l][g] = max(dp[1 - l][g], dp[l][g - w[i]] + p[i]);
        }
    }

    cout << dp[l][gmax];

    return 0;
}