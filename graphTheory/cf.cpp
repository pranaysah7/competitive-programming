#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;
typedef long double ld;
const ld r = 1e+9;

using namespace std;

ld check(ld c, ld m, ld p, ld v, ld len)
{
    ld ans = (p / r) * len;
    if (c > 0)
    {
        if (c > v)
        {
            if (m > 0)
                ans += (c / r) * check(c - v, m + v / 2, p + v / 2, v, len + 1);
            else
                ans += (c / r) * check(c - v, 0, p + v, v, len + 1);
        }
        else
        {
            if (m > 0)
                ans += (c / r) * check(0, m + c / 2, p + c / 2, v, len + 1);
            else
                ans += (c / r) * check(0, 0, p + c, v, len + 1);
        }
    }
    if (m > 0)
    {
        if (m > v)
        {
            if (c > 0)
                ans += (m / r) * check(c + v / 2, m - v, p + v / 2, v, len + 1);
            else
                ans += (m / r) * check(0, m - v, p + v, v, len + 1);
        }
        else
        {
            if (c > 0)
                ans += (m / r) * check(c + m / 2, 0, p + m / 2, v, len + 1);
            else
                ans += (m / r) * check(0, 0, p + m, v, len + 1);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
// #endif

    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        ld c, m, p, v;
        cin >> c >> m >> p >> v;
        c = c * r;
        m = m * r;
        p = p * r;
        v = v * r;
        ld ans = 0;
        ans = check(c, m, p, v, 1);
        cout << setprecision(12) << ans << "\n";
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}