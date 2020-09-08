#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
#define loop(v,strt,end) for (ll v=strt;v<end;v++)
int main(){
    int n;
    while (cin>>n)
    {
       if(n==-1)
            break;
       ll m=0,f=0,rslt=0;
        for(int i=0;i<n;i++)
        {    f=m; 
             m=rslt+1; 
           rslt=m+f;
         
           //cout<<m<<" "<<f<<" "<<rslt<<endl;
        }
        cout<<m<<" "<<rslt+1<<endl;

    }
    
    return 0;
}