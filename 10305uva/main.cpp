#include <bits/stdc++.h>

using namespace std;
int n,m,i,j;
vector< vector<int> >adlst;
vector<int>out;
vector<bool>visited;
void dfs(int node){
    visited[node]=true;
  for(int in=0;in<adlst[node].size();in++){
        int child=adlst[node][in];
    if(!visited[child])
        dfs(child);

  }
out.push_back(node);


}
int main()
{
    while(true){

   cin>>n>>m;
   adlst = vector< vector<int> >(n);
	visited = vector<bool>(n,0);
	adlst.clear();
	visited.clear();
	out.clear();
   if(n+m==0)
        break;

   for(int in=0;in<m;in++){
       // cout<<in;
    cin>>i>>j;
    //cout<<i<<" "<<j;

  adlst[i-1].push_back(j-1);
   }
  /* for(int i=0;i<n;i++){
        cout<<i<<endl;
    for(int j=0;j<adlst[i].size();j++){
        cout<<adlst[i][j]<<" ";}
    cout<<" "<<endl;


  }*/


  for(int in=0;in<n;in++){
  if(!visited[in])
    dfs(in);
  }

 for(int in=n-1;in>=0;in--)
    cout<<out[in]+1<<" ";
    cout<<endl;

}
    return 0;
}
