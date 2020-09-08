#include <bits/stdc++.h>

using namespace std;
string s1,s2;


int main()
{
    int n;
    cin>>n;
    while(n--){
        cin>>s1>>s2;
        vector<int>rslt;
       int s=max(s1.size(),s2.size());

       int t=0;
        for(int i=0;i<s;i++){
            int a,b;
            if(i<s1.size())
               a=s1[i]-'0';
            else
                a=0;
           if(i<s2.size())
               b=s2[i]-'0';
            else
                b=0;
                if(t==1)
                    a++;
                if(a+b<10){
            rslt.push_back(a+b);
            t=0;}
        else {
            rslt.push_back((a+b)%10);
            t=1;
        }

        }
        if(t==1)
            rslt.push_back(1);
        bool z=false;
        for(int i=0;i<rslt.size();i++){
             if(rslt[i]>0)
                    z=true;
             if(z)
                cout<<rslt[i];
        }
cout<<endl;
    }
    return 0;
}
