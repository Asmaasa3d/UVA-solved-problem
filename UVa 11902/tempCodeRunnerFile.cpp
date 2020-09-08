#include <bits/stdc++.h>
using namespace std;
#define loop(i, str, end) for (int i = str; i < end; i++)
#define ll long long
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << " = { " << x << " }\n"
int t, n, tmp;
bool vstd[100 + 3] = {0};
vector<vector<int>> adlst;
bool Dominator[100+2][100+2]={0};
void DFS(int x ,int k)
{   if(k==x) return;
    vstd[x] = true;
    loop(i, 0, adlst[x].size())
    {
        int a = adlst[x][i];
        if (!vstd[a])
            DFS(a,k);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    loop (q,1,t+1)
    {
        cin >> n;
        adlst = vector<vector<int>>(n);
        loop(i, 0, n)
        {
            loop(j, 0, n)
            {
                cin >> tmp;
                if (tmp == 1)
                    adlst[i].pb(j);
            }
        }
        DFS(0,900);
        loop(i, 0, n)
        { 
            if(vstd[i]){
                Dominator[0][i]=true;
            }
        }
        loop(i,0,n){
            memset(vstd,0,sizeof(vstd));
            DFS(0,i);
            loop(j,0,n){
            if(!vstd[j] && Dominator[0][j]){
                Dominator[i][j]=true;
            }
            }
        }
        cout<<"Case "<<q<<":"<<endl;
        cout<<"+";
            loop(z,0,(2*n)-1)cout<<"-";
            cout<<"+\n";
        loop(i,0,n){
            cout<<"|";
            loop(j,0,n){
               if( Dominator[i][j]){
                   cout<<"Y"<<"|";
               }
              else
              {
                  cout<<"N"<<"|";
              }
              
            }
            cout<<endl;
            cout<<"+";
            loop(z,0,(2*n)-1)cout<<"-";
            cout<<"+\n";
        }
    }

    return 0;
}