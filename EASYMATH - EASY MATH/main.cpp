#include <bits/stdc++.h>

using namespace std;
int  t,n,m,a,d,cnt1=0,cnte=0,arr[5];

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
int findlcm(int arr[])
{
    // Initialize result
    int ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < 5; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}

int func(int z){
    cnt1=0;
for(int i1=0;i1<2;i1++){
        for(int i2=0;i2<2;i2++){
                for(int i3=0;i3<2;i3++){
                        for(int i4=0;i4<2;i4++){
                            for(int i5=0;i5<2;i5++){
                                int h1=1; int h2=1; int h3=1; int h4=1; int h5=1;cnte=0;
                                if(i1) h1=a ,cnte++;
                                 if(i2) h2=a+d ,cnte++;

                                if(i3) h3=a+(2*d) ,cnte++;

                                if(i4) h4=a+(3*d) ,cnte++;

                                if(i5) h5=a+(4*d) ,cnte++;

                             for(int j=0;j<5;j++){
                                 arr[0]=h1;
                                arr[1]=h2;
                                arr[2]=h3;
                                arr[3]=h4;
                                arr[4]=h5;}



                            if (cnte==0)
                                    continue;

                                int sign=cnte%2==1 ?1:-1;

                              cnt1+=(sign*z)/findlcm(arr);


                            } } } }}


return cnt1;

}


int main()
{

   //int  t,n,m,a,d,cnt1=0,cnte=0;

  cin>>t;
   for(int q=0;q<t;q++){
        int cnt=0;
    cin>>n>>m>>a>>d;

    arr[0]=a;
    arr[1]=a+d;
    arr[2]=a+(2*d);
    arr[3]=a+(3*d);
    arr[4]=a+(4*d);


/*for (int i =n; i<=m; i++)
if ( i%a==0||i%(a+d)==0|| i%(a+(2*d))==0||i%(a+(3*d))==0||i%(a+(4*d))==0)cnt++;//cout <<i<<"\t";
cout<<"is"<<cnt<<endl;*/

 cout<<(m-n)+1-(func(m)-func(n-1))<<endl;

 //cout<<func(n)<<endl;

   }


    return 0;
}
