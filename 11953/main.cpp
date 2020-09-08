#include <bits/stdc++.h>

using namespace std;
int n;
vector<string>l;
bool vstd[104][104]={0};
void dfs(int i,int j){
  if((i<0) || (i==n) || (j<0) ||(j==n )) return;
  if(vstd[i][j] || l[i][j]=='.')
    return;
    vstd[i][j]=true;
  dfs(i-1,j);
dfs(i+1,j);
dfs(i,j-1);
dfs(i,j+1);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        int cnt=0;
        l.clear();
        for(int j=0;j<n;j++){
            for(int z=0;z<n;z++)
                vstd[j][z]=false;
        }

        for(int j=0;j<n;j++){

           string s;
           cin>>s;
           l.push_back(s);

        }

        for(int z=0;z<n;z++){
            for(int r=0;r<n;r++){
                if(l[z][r]=='x' &&!vstd[z][r]){
                dfs(z,r);
                cnt++;

            }}


        }

        cout<<"Case "<<i<<": "<<cnt<<endl;

    }
    return 0;
}
