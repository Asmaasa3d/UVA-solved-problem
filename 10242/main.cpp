#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x1,x2,x3,x4,y1,y2,y3,y4,x,y,mx1,my1,my2,my3,mx2,mx3;
    while(cin>>x1){
           cin>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if(x1==x2&&y1==y2){
           mx2 =x1;my2=y2;
            mx1 =x3;my1=y3;
             mx3 =x4;my3=y4;
        }
        else if(x1==x3&&y1==y3){
          mx2 =x1;my2=y1;
            mx1 =x2;my1=y2;
             mx3 =x4;my3=y4;
        }
           else if(x1==x4&&y1==y4){
          mx2 =x1;my2=y1;
            mx1 =x2;my1=y2;
             mx3 =x3;my3=y3;
        }
           else if(x2==x3&&y2==y3){
          mx2 =x2;my2=y2;
            mx1 =x1;my1=y1;
             mx3 =x4;my3=y4;
        }
        else if(x2==x4&&y2==y4){
          mx2 =x2;my2=y2;
            mx1 =x1;my1=y1;
             mx3 =x3;my3=y3;
        } else if(x4==x3&&y4==y3){
          mx2 =x4;my2=y4;
            mx1 =x2;my1=y2;
             mx3 =x1;my3=y1;
        }



        x=mx1+mx3-mx2;
        y=my1+my3-my2;

        cout<<fixed << setprecision(3)<<x<<" "<<y<<endl;

    }
    return 0;
}
