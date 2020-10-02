// Auther : asmaa saeed date: 2020-09-28
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

int tc, m, k;
ll p[505];
ll mx = 0;
bool valid(ll pagelimit)
{
    int j = 0;
    loop(i, 0, k)
    {
        ll s = 0;
        while (s + p[j] <= pagelimit && j < m)
        {
            s += p[j];
            j++;
        }
    }
    return (j == m);
}

ll solve()
{
    ll st = 1, en = 1e9;
    while (st < en)
    {
        ll mid = st + (en - st) / 2;
        if (valid(mid))
            en = mid;
        else
        {
            st = mid + 1;
        }
    }
    return st;
}
bool finalbook[505]={0};
void breakbooks(ll pagelmt){
  ll pageForCur=0, curScriber=k-1;
  for(int book=m-1;book>=0;book--){
      if(p[book]+pageForCur>pagelmt
       || curScriber==book+1){
          --curScriber;
          pageForCur=0;
          finalbook[book]=1;

      }
      pageForCur+=p[book];
  }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin >> tc;
    while (tc--)
    {
        cin >> m >> k;

        loop(i, 0, m)
        {
            cin >> p[i];
        }
        ll a = solve();
       
        clr(finalbook,0);
         breakbooks(a);
        
        cout << p[0];
        if (finalbook[0])
            cout << " /";
        
        for (int i = 1; i < m; ++i)
        {
            cout << ' ' << p[i];
            if (finalbook[i])
                cout << " /";
        }
        
        cout << '\n';

       
    }

    return 0;
}