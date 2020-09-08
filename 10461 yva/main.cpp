#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
#define ll long long
#define sz(v)        ((int)((v).size()))
#define clr(v, d)      memset(v, d, sizeof(v))
#define pb          push_back
#define MP          make_pair
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
int v,e,a,b,all=0,q;
struct vrtx
{
    int no,tm;
};
vrtx arr[600+9];

bool vstd[600+8]={0};
#define v_v vector<vector<vrtx>> 
v_v adjl,invrs;
int BFS(vrtx z,v_v a){
    int cst=0;
    queue<vrtx>q;
    clr(vstd, 0);  
    q.push(z);vstd[z.no]=true;
    while (!q.empty())
    {
        vrtx cur=q.front();q.pop(); //0 cst+=cur.tm;
        loop(i,0,a[cur.no].size()){
            //int n=a[cur.no][i].no;
            vrtx tmp=a[cur.no][i];
            if(!vstd[tmp.no]){
                q.push(tmp);
                cst+=tmp.tm;
                vstd[tmp.no]=true;
            }
        }
        
        
    }
  return cst;  
}
int main(){
    int cs=1;
    while (scanf("%d%d",&v,&e) == 2 )
    {  
         adjl=vector<vector<vrtx>>(600);
        invrs=vector<vector<vrtx>>(600);
        
        if(v==0&&e==0) break;
    loop(i,1,v+1){
        scanf("%d",&arr[i].tm);
        arr[i].no=i;
        all+=arr[i].tm;
    }
    loop(i,0,e){
        scanf("%d%d",&a,&b);
        adjl[a].pb(arr[b]);
        invrs[b].pb(arr[a]);
    }
  scanf("%d",&q);
   printf("Case #%d:\n",cs++);
  loop(i,0,q){
      scanf("%d",&a);
      int mn= BFS(arr[a],adjl);
  int mx=BFS(arr[a],invrs);
  mx=all-mx-arr[a].tm;
  int rslt=mx-mn;
  printf("%d\n",abs(rslt));
  }
cout<<"\n";
adjl.clear();invrs.clear();clr(arr,0);all=0;

        for(int i = 0; i <= v; i++){
            adjl[i].clear();
            invrs[i].clear();
        }
    }
    
    return 0;
}