#include <iostream>

using namespace std;
#define ll long long
ll fn(ll b,ll p,ll m){
  if(p==0) return 1;
  ll s=fn(b,p/2,m);
  s=s%m;
  s=s*s;
  if(p%2==1)
    s=s*(b%m);
    //cout<<s<<"s ";
  return s%m;
}


int main()
{
   ll b,m,p;
   while(cin>>b){
    cin>>p>>m;
   cout<<fn(b,p,m)<<endl;;
   }
    return 0;
}
