// Auther : asmaa saeed date: 2020-10-02
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define pb push_back
#define MP make_pair
#define P(x) cout << #x << " = { " << x << " }\n"
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m, mtrx[505][505],q,a,b;
int upper_bound(int i, int x)
{
	int st = 0, en = m-1;
	if(mtrx[i][m-1]<x)return -1;
	while (st < en)
	{
		int mid = st + (en - st) / 2;
		if (mtrx[i][mid] >= x)
			en = mid;
		else
			st = mid + 1;
	}
	return st;
}
int lower_bound(int i, int x)
{
	int st = 0, en = m-1;
	if(mtrx[i][0]>x)return -1;
	while (st < en)
	{
		int mid = st + (en - st+1) / 2;
		if (mtrx[i][mid] <= x)
			st = mid;
		else
			en = mid - 1;
	}
	return st;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	while (cin >> n >> m )
	{
		if(n==0 && m==0)break;
		loop(i, 0, n)
		{
			loop(j, 0, m)
			{
				cin >> mtrx[i][j];
			}
		}
		cin >> q;
		loop(i, 0, q)
		{
			cin>>a>>b;
			int r[505],c[505];
			loop(i, 0, n)
			{
				r[i] =upper_bound(i, a);
			}
			loop(i,0,n){
				c[i]=lower_bound(i,b);
			}
			//loop(i,0,n)cout<<mtrx[i][r[i]]<<" "<<mtrx[i][c[i]]<<endl;
			int maxSize=0;
			loop(i,0,n){
				if(r[i]==-1)continue;
				loop(j,i,n){
					if(c[j]==-1)continue;
					int s=min((j-i+1),(c[j]-r[i]+1));
					maxSize=max(maxSize,s);

				}
			}
			cout<<maxSize<<"\n";
		}
		cout<<"-\n";
	}
	return 0;
}