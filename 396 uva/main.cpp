#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n,m;
int main()
{
    while(true){

        int v[100];
        vector<int>z;

        cin>>n>>m;
        if(n==0&&m==0)
            break;
        int x=max(m,n-m);
        int y=min(m,n-m);

        int q=0;
       for(int i=n;i>x;i--){
            v[q]=i;
         q++;

       }

        for(int i=y;i>1;i--)
            z.push_back(i);

        for(int i=0;i<q;i++){
            for(int a=0;a<z.size();a++){
                  //  cout<<z[a]<<" "<<v[i]<<endl;
                if(v[i]%z[a]==0&&z[a]!=1){
                    v[i]=v[i]/z[a];
                    z[a]=1;
                    break;
                }}}
                ll r=1;
         for(int i=0;i<q;i++){
            r*=v[i];
         }
          for(int i=0;i<z.size();i++){
            r/=z[i];
         }
         cout<<n<<" "<<"things taken "<<m<<" at a time is "<<r<<" exactly."<<endl;
    }

    return 0;
}
