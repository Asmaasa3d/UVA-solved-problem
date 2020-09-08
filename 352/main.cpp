#include <bits/stdc++.h>

using namespace std;
vector<string>adjl;
int n,cnt=0,img=1;
bool visited[30][30]={0};
void dfs(int i,int j){
  if((i<0) || (i==n) || (j<0) ||(j==n )) return;
  if(visited[i][j] || adjl[i][j]!='1')
    return;
visited[i][j]=true;
//cout<<i<<" "<<j<<endl;
dfs(i-1,j);
dfs(i+1,j);
dfs(i,j-1);
dfs(i,j+1);
dfs(i-1,j-1);
dfs(i-1,j+1);
dfs(i+1,j-1);
dfs(i+1,j+1);

}
int main()
{  while(cin>>n){
    adjl.clear();
    cnt=0;

   // cin>>n;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
        visited[j][i]=false;
    }}
        for(int j=0;j<n;j++){
            string s;
            cin>>s;
            adjl.push_back(s);

        }



       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjl[i][j]=='1'&&!visited[i][j])
                {
                    dfs(i,j);
                    cnt++;
                }

            }
       }
       cout<<"Image number "<<img<<" "<<"contains "<<cnt<<" "<<"war eagles."<<endl;
       img++;}
    return 0;
}
