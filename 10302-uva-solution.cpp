// Auther : asmaa saeed date: 2020-07-26 
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (ll v = st; v < en; v++)
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


 ll arr[50001]={0};ll x;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
 loop(i,1,50002){
   arr[i]= pow(i,3);
   
   arr[i]+= arr[i-1];

  
 }

while (cin>>x)
{
 cout<<arr[x]<<endl;
}

  return 0;
}
