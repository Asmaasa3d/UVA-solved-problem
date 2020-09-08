#include <bits/stdc++.h>

using namespace std;

int n,k,a,w;
vector< vector<int> >l;bool vstd[1000074]={0};
vector<int>r;
void dfs(int node){
   vstd[node]=true;
for(int i=0;i<l[node].size();i++){
     int child=l[node][i];
   if(!vstd[child])
    dfs(child);
}
r.push_back(node);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    l=vector< vector<int> >(n+1);
   for(int i=1;i<=k;i++){
     cin>>a;
     for(int j=0;j<a;j++){
        cin>>w;
        l[i].push_back(w);

     }

   }
 for(int i=1;i<=n;i++){
    if(!vstd[i])
        dfs(i);
 }
int p=0;
int rslt[1000074];

for(int i=n-1;i>=0;i--)
{  int stdnt=r[i];
 rslt[stdnt]=p;
 p=stdnt;


}
for(int i=1;i<=n;i++){

    cout<<rslt[i]<<endl;
}



    return 0;
}
