// Auther : asmaa saeed date: 2020-09-10 
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

int n,arr[20];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream f;
    f.open("x.txt");
    int k=1;
    while (cin>>n)
    { 
        int cnt[20]={0},a=0;ll ans=0;ll prfx[20];
        loop (i,0,n+1)prfx[i]=1;
        loop(i,1,n+1){cin>>arr[i];
        if(arr[i]==0){a++;cnt[i]=a;}
        else cnt[i]=a;
       if(prfx[i-1]==0)prfx[i]=arr[i];
       else
        prfx[i]=arr[i]*prfx[i-1];
        }
    loop(i,1,n+1){
        loop(j,i,n+1){
            if((cnt[j]-cnt[i-1])==0){
                int q;
                if(prfx[i-1]==0) q=1;
                else q=prfx[i-1];
                if((prfx[j]/q)>ans)ans=prfx[j]/q;
            }
        }
    }

        
        cout<<"Case #"<<k<<": The maximum product is "<<ans<<".\n";
        cout<<endl;
        k++;

    }
    
    return 0;
}