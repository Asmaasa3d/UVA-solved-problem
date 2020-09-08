// Auther : asmaa saeed date: 2020-07-28
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

string eq, Xs;

vi poly, x;
ostream &operator<<(ostream &oov, const vector<int> &a)
{
  loop(i, 0, a.size())
  {
    oov << a[i] << " ";
  }
  return oov;
}
ll calc(ll x)
{

  ll n = poly.size(), rslt = 0;
  
  
  loop(i, 0, n)
  {
    ll q = pow(x, n - i-1);
    q = q * poly[i];
    rslt += q;
  }
  return rslt;
}
int main()
{

  while (getline(cin, eq))
  {
    getline(cin, Xs);
    stringstream s(eq), t(Xs);
poly.clear();
    int a;
    int cnt = 0;
    while (s >> a)
    {
      poly.pb(a);
    }
    bool frst = true;
    while (t >> a)
    {
      
      if (!frst)
      {
        cout << " ";
  
      }
      else 
      frst=false;

      ll z=calc(a);
      cout << z;
    }
  
  cout << endl;}
  return 0;
}