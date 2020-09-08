#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n,t,c,cnt;
vector<long long>v;
bool tst(ll z){
 cnt=c-1;
 for(ll i=0;i<v.size();i++){
       // cout<<"I"<<i<<" "<<cnt<<endl;
        for(ll j=i+1;j<v.size();j++){
    if(v[j]-v[i]>=z){
        cnt--;i=j-1;break;}


 }
 if(cnt==0)
        return true;
}
if(cnt>0)
    return false;
return true;

}
void bs(){
ll lo=0,hi=v[n-1]-v[0],mid;
while(lo<hi-1){
    mid=lo+(hi-lo)/2;
    //cout<<mid<<" "<<tst(mid)<<endl;
    if(tst(mid))lo=mid;
    else hi=mid-1;

}
if(tst(hi))
    cout<<hi<<endl;
else
    cout<<lo<<endl;
}
int main()
{ cin>>t;
while(t--){
    cin>>n>>c;
    v.clear();
    v=vector<long long>(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    bs();
   }
    return 0;
}
