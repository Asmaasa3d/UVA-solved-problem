#include <bits/stdc++.h>
using namespace std;
int n,m,e,b;
vector<vector<char>>lst;
bool vst[20][20]={0};
vector<pair<int ,int>>d;
void dfs(int i,int j){
    if((i<0) || (i==n) || (j<0) ||(j==m ))return;
    if(vst[i][j]){//cout<<"vst";
            return;}
  if(lst[i][j]!='I'&&lst[i][j]!='O'
                    &&lst[i][j]!='E' &&lst[i][j]!='H'
                    &&lst[i][j]!='V'&&lst[i][j]!='A' && lst[i][j]!='#' && lst[i][j]!='@'){
                   //cout<<"ls";
    return;}

vst[i][j]=true;
//cout<<i<<" "<<j<<endl;
d.push_back(make_pair(i,j));

dfs(i+1,j);
dfs(i,j-1);
dfs(i,j+1);
}
int main()
{  int t;cin>>t;
for(int i=0;i<t;i++){
    cin>>n>>m;

   lst = vector< vector<char> >(n);
   lst.clear();
   d.clear();
   for(int w=0;w<n;w++){
    for(int a=0;a<m;a++)
        vst[w][a]=false;
   }

   //cout<<t<<" "<<n<<" "<<m;
   for(int x=0;x<n;x++){
        for(int j=0;j<m;j++){
           char s;
           cin>>s;
            lst[x].push_back(s);
           // cout<<lst[x][j]<<" ";
            if(s=='#')
                 e=j;
            if(s=='@')
                 b=j;

        }}
   // cout<<e<<" "<<b;
      dfs(0,e);
      //cout<<d.size();
      vector<string>rslt;string s;

      for(int k=1;k<d.size();k++){
          // cout<<"k="<<k<<" "<<d[k-1].first<<endl;
            if(d[k].first ==d[k-1].first){
                if(d[k].second>d[k-1].second){
                        s="left";
                    rslt.push_back(s);
                    }
                else{

                      s="right";
                    rslt.push_back(s);
                }


            }
            else{
                s="forth";
                rslt.push_back(s);
            }
    //  cout<<d[k].first<<" "<<d[k].second<<endl;

        }

        for(int k=rslt.size() -1;k>=0;k--){
            if(k==0)
            cout<<rslt[k];
            else
            cout<<rslt[k]<<" ";}
            cout<<endl;

}

    return 0;
}
