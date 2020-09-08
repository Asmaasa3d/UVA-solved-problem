#include <bits/stdc++.h>
using namespace std;
#define loop(i, str, end) for (int i = str; i < end; i++)
#define ll long long
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << " = { " << x << " }\n"
vector<pair<ll, ll>> v;
ll mx, my;
enum quadrant
{
    top_right,
    top_left,
    bottom_right,
    bottom_left,
    cross
};
quadrant fnc(ll x, ll y)
{
    if (x == mx || y == my)
        return cross;
    if (x < mx)
    {
        if (y > my)
            return top_right;
        else
            return bottom_right;
    }
    else
    {
        if (y > my)
            return top_left;
        else
            return bottom_left;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        int stan = 0, olie = 0;
        v.clear();
        loop(i, 0, n)
        {
            cin >> x >> y;
            v.pb(MP(x, y));
        }
        int a = n / 2;
        mx = v[a].first, my = v[a].second;
        loop(i, 0, n)
        {
            quadrant ans = fnc(v[i].first, v[i].second);
            if (ans == top_right || ans == bottom_left)
                stan++;
            else if (ans == top_left || ans == bottom_right)
                olie++;
        }
        cout << olie<< " " << stan << endl;
    }

    return 0;
}