 // Auther : asmaa saeed date: 2020-09-03 
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
 
 int t,n,k,a[10005];
 int toba_palindrome(int i,int j,int s){
   if(s>k)return 10000;
     if(i>=j)return s;
 
     if(a[i]==a[j]){
        return toba_palindrome(i+1,j-1,s);
     }
     else
     {
        return min(toba_palindrome(i+1,j,s+1),toba_palindrome(i,j-1,s+1));
     }
     
 }
 int main () {
      ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>t;
     loop(i,1,t+1){

         cin>>n>>k;
        
        
         loop(j,0,n){
             cin>>a[j];
         }
         
    cout<<"Case "<<i<<": ";
    int ans=toba_palindrome(0,n-1,0);
    if(ans==0)cout<<"Too easy\n";
    else if(ans>k)cout<<"Too difficult\n";
    else cout<<ans<<endl;

     }
     return 0;
 }