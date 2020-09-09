// Auther : asmaa saeed date: 2020-09-09 
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x  <<" = { "<< x<<" }\n"
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int l,n,c[55],dp[55][55];
int solve(int ss,int se,int cs,int ce){
 if(ss==se|| cs>ce)return 0;

 int &ret=dp[cs][ce];
 if(ret!=-1)return ret;
 int best=10000000;
 loop(i,cs,ce+1){
     int cur=c[i];
     best=min(best,solve(ss,cur,cs,i-1)+solve(cur+1,se,i+1,ce)+se-ss+1);
 }
 return ret=best;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   while ( cin>>l)
   {
       if(l==0)break;
       cin>>n;
       loop(i,0,n)cin>>c[i];
       clr(dp,-1);
       cout<<"The minimum cutting is "<<solve(1,l,0,n-1)<<".\n";
   }
   

    return 0;
}