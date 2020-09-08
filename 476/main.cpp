#include <bits/stdc++.h>

using namespace std;
char r ;float x1,x2,yy1,yy2;
struct rect{
    float rx1;float rx2;float ry1;float ry2;
};

int main()

{ vector<rect>l;
 rect c;
    while(true){
 cin>>r;
 if(r=='*')
    break;
 cin>>x1>>yy1>>x2>>yy2;
 c.rx1=x1;c.rx2=x2;c.ry1=yy1;c.ry2=yy2;
l.push_back(c);

}
for(int i=1;;i++){
        bool tst=false;
    cin>>x1>>yy1;
    if(x1==9999.9f && yy1==9999.9f)
         break;
    for(int j=0;j<l.size();j++){
        if(x1>l[j].rx1 &&x1<l[j].rx2 ){
            if(yy1<l[j].ry1 &&yy1>l[j].ry2 ){tst=true;
                cout<<"Point "<<i<<" is contained in figure "<<j+1<<endl;}
        }
    }

if(!tst)
     cout<<"Point "<<i<<" is not contained in any figure"<<endl;

}

    return 0;
}
