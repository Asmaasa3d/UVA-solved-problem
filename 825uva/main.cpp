#include<bits/stdc++.h>
using namespace std;
#define loop(i,str,end) for(int i=str;i<end;i++)
#define ll long long
#define sz(v)        ((int)((v).size()))
#define clr(v, d)      memset(v, d, sizeof(v))
#define pb          push_back
#define MP          make_pair
int W,N;
vector<vector<int>>v;
vector<string>a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string input;
    while (t--)
    {

       cin>>W>>N;v=vector<vector<int>>(W);
       cin.ignore();
       loop(i,0,W){
        getline(cin,input);
          a.pb(input); 
       }
    loop(i,0,W) {int sz=a[i].size(); int indx=a[i][0]-48;
        loop(j,1,sz){
            if(a[i][j]!=' '){
                int x=(a[i][j] - 48); 
                v[indx].push_back(x); 
                                     
                   }
        }
    }
    loop(i,0,W){
        loop(j,0,v[i].size())
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    }
    
    return 0;
}