// Auther : asmaa saeed date: 2020-08-27
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

int m, n, k, arr[10003],mem[10004][105];
bool tst = false;
int solve(int index, int mod)
{
    if (index == n)
    {
        if (mod== 0)
            return 1;
      return 0;
    }
    int &ret=mem[index][mod];
    if(ret!=-1)return ret;
   
    ret=solve(index + 1,((( mod+arr[index])%k)+k)%k);
    
    ret |=solve(index + 1,((( mod-arr[index])%k)+k)%k);

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    while (m--)
    {
        cin >> n >> k;
        tst=false;
        loop(i,0,n){
            loop(j,0,k)
            mem[i][j]=-1;
        }
        loop(i, 0, n) cin >> arr[i];
        
        if(solve(1,(arr[0]+k)%k))cout<<"Divisible\n";
        else cout<<"Not divisible\n";
    }

    return 0;
}