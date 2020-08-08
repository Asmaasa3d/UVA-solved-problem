// Auther : asmaa saeed date: 2020-08-08
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << " = { " << x << " }\n"
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t, n, k;
vector<vi> adl;
bool blk[101] = {0};
vi ans, tmpAns;
template <typename TT >
ostream &operator<<(ostream &oov,const vector<TT> &a)
{
    loop(i, 0, a.size())
        {  oov << a[i]; if(i!= a.size()-1)oov<< " ";}
    return oov;
}
bool canbeblack(int node)
{
    loop(i, 0, adl[node].size())
    {
        int a = adl[node][i];
        if (blk[a])
            return false;
    }
    return true;
}
void solve(int cur)
{
    if (cur == (n+1))
    { 
        //cout<<tmpAns;
        //cout<<endl;
        if (tmpAns.size() > ans.size())
            ans = tmpAns;
        return;
    }
    
    if (canbeblack(cur))
    {
        blk[cur] = 1;
        tmpAns.pb(cur);

        solve(cur + 1);

        blk[cur] = 0;
        tmpAns.pop_back();
    }
    solve(cur + 1);
}
void clearing()
{
    ans.clear();
    adl.clear();
    clr(blk, 0);
    ans.clear();
    tmpAns.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    
    loop(i, 0, t)
    {
        adl = vector<vi>(101);
        cin >> n >> k;
        int a, b;
        loop(j, 0, k)
        {
            cin >> a >> b;
            adl[a].pb(b);
            adl[b].pb(a);
        }
        solve(1);
        cout << ans.size() << endl;
        cout << ans;
        cout << endl;
        clearing();
    }

    return 0;
}
