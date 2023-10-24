#include <fstream>
#include <unordered_map>

using namespace std;

ifstream cin("hashuri.in");
ofstream cout("hashuri.out");

int main() {
    int n;
    cin >> n;

    unordered_map<int, bool> m;
    for (int i = 0; i < n; ++i) {
        int p, x;
        cin >> p >> x;

        if (p == 1) m[x] = true;
        else if (p == 2) m[x] = false;
        else {
            cout << m[x] << '\n';
        }
    }
    return 0;
}
