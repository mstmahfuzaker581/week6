#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto ok = [&](long long m) {
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += (m / a[i]);
            if (total >= t)
                return true;
        }
        return false;
    };

    long long l = 0, r = 1e18, mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
