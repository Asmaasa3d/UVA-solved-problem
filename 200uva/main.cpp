#include <bits/stdc++.h>

using namespace std;
vector<int> topsort;
vector<bool> visited;
string t;vector<vector<int> >arr;vector<string>s;
int farr[1000]={0};
vector<bool>res;
void dfs(int node)
{
	visited[node] = true;

	for(int i=0;i<arr[node].size();i++)
	{
		int child = arr[node][i];
		if (!visited[child])	// To avoid cyclic behavior
			dfs(child);
	}

	topsort.push_back(node);	// DAG // Other way Indegree / Outdegree
}



int main()
{


    t="asnaa";
    while(t!="#"){
        cin>>t;

       // cout<<t.size()<<endl;
        int z=t[0];
        if(t!="#"){
             s.push_back(t);
          farr[z-65]++;
       //   cout<<farr[z-65];
          }
        }

       for(int i=0;i<s.size();i++){
         t=s[i];
         cout<<t<<endl;
         int z=t[0];
       arr[i].push_back(t[0]);
       res[z-65]=true;
           cout<<t<<endl;
      /*   if(farr[z-65]>1){
                cout<<"E"<<endl;
                for(int j=1;j<t.size();j++){
                    int x=t[j];
                    if(!res[x-65]){
                        arr[i].push_back(t[j]);
                        res[x-65]=true;}
                }
         }*/
        }
       /* dfs(0);
         for(int i=0;i<arr.size();i++){
                 for(int j=0;j<topsort.size();j++)
                 cout<<arr[i][j];
     cout<<" "<<endl;

         }

      for(int i=0;i<topsort.size();i++)
        cout<<topsort[i];*/

    return 0;
}
