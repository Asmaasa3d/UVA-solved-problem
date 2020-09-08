#include <bits/stdc++.h>

using namespace std;
int t, XLL, YLL, XUR ,YUR, XLL2, YLL2, XUR2,YUR2,x2,x1;int z1,y2;
bool ifoverlap( ){
if(XLL>=XUR2 || XLL2>= XUR)
    return false;

if(YLL2>=YUR || YLL>= YUR2)
    return false;

if(XLL<=XUR2&&XLL>=XLL2){
    x1=XLL;
    x2=min(XUR,XUR2);
}
else if(XLL2<=XUR&&XLL2>=XLL){
     x1=XLL2;
    x2=min(XUR2,XUR);
}
if(YLL<=YUR2&& YLL>=YLL2){
    z1=YLL;
    y2=min(YUR,YUR2);
}
else if(YLL2<=YUR && YLL2>=YLL){
     z1=YLL2;
    y2=min(YUR2,YUR);
}

return true;

}


int main()
{
    cin>>t;
    for(int i=0;i<t;i++){
        cin>> XLL>> YLL>> XUR>>YUR>> XLL2>>YLL2>> XUR2>>YUR2;
if(i>0)
    cout<<"\n";
      if(ifoverlap()){
        cout<<min(x1,x2)<<" "<<min(z1,y2)<<" "<<max(x1,x2)<<" "<<max(z1,y2)<<endl;
      }
 else

   cout<<"No Overlap"<<endl;

     }
    return 0;
}
