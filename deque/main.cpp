#include <fstream>
#include <deque>

using namespace std;

ifstream cin("deque.in");
ofstream cout("deque.out");

int v[5000001];
deque<int> d;

int main() {
    int n, k;
    cin >> n >> k;

    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];

        while (!d.empty() && v[d.back()] >= v[i]) {
            d.pop_back();
        }

        if (!d.empty() && d.front() == i - k) {
            d.pop_front();
        }

        d.push_back(i);
        if (i >= k) {
            s += v[d.front()];
        }
    }

    cout << s;
    return 0;
}