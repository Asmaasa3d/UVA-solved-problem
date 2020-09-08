#include <iostream>

using namespace std;

int main()
{
   int D, M, Y,C,N,calendar[13],cnt=0,res=0,lday[5];
   calendar[1]=31;calendar[2]=28;calendar[3]=31;
   calendar[4]=30;calendar[5]=31;calendar[6]=30;
   calendar[7]=31;calendar[8]=31;calendar[9]=30;
   calendar[10]=31;calendar[11]=30;
   calendar[12]=31;




   while(true){
      cnt=0;
       res=0;
    cin>>N;
    if(N==0)
        break;
     cin>> lday[0]>>lday[1]>>lday[2]>>lday[3];

    for (int i=1;i<N;i++){

      cin>> D>>M>>Y>>C;

       if(lday[2]%4==0&&lday[2]%100!=0){
        calendar[2]=29;

        }
       else
         calendar[2]=28;


   // cout<<calendar[2]<<endl;
    if (Y==lday[2]){
        if(M==lday[1]){
           if(D-lday[0]==1){
            cnt++;
            res+=C-lday[3];

           }}
          else if(M-lday[1]==1){
            if(D==1){
                if(lday[0]==calendar[lday[1]]){
                 cnt++;
            res+=C-lday[3];

                }}}}
    else {
        if(Y-lday[2]==1){
            if(M==1){
                if(lday[1]==12){
                    if(lday[0]==31&&D==1)
                    {
                        cnt++;
                        res+=C-lday[3];
                    }}}}}

                    lday[0]=D;lday[1]=M;lday[2]=Y;lday[3]=C;
                    }


cout<<cnt<<" "<<res<<endl;

   }

    return 0;
}
