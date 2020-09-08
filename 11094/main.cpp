#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
#define ll long long
#define sz(v)        ((int)((v).size()))
#define clr(v, d)      memset(v, d, sizeof(v))
#define pb          push_back
#define MP          make_pair
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
int m,n,x,y;
vector<string>v;
bool vstd[23][23]={0};int cnt=0;bool tst=true;
int DFS(int i,int j,char c){
    
    if(i>=n || j>=m ||i<0 ||j<0|| vstd[i][j] || v[i][j]!=c)
        return 0;
if(i==x && j==y){
    tst=false;
    cnt=0;  
}
vstd[i][j]=1;
if(tst)
{cnt++;}
DFS(i+1,j,c);
DFS(i-1,j,c);
DFS(i,j+1,c);
DFS(i,j-1,c);
if(j==m-1)
    DFS(i,0,c);
if(j==0)
    DFS(i,m-1,c);
return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m)
   {v.clear();clr(vstd,0);
    string s;
    loop(i,0,n){
        cin>>s;
        v.pb(s);
    }
   
    cin>>x>>y;
    char a=v[x][y];
    int ans=0;
   loop(i,0,n){
        loop(j,0,m){
            if(!vstd[i][j] && v[i][j]==a){
                cnt=0;tst=true;
                int z=DFS(i,j,a);
                if(z>ans) ans=z;
            }

        }
    }
  cout<<ans<<endl;  
}
    return 0;
}