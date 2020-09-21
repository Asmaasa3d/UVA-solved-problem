// Auther : asmaa saeed date: 2020-06-22
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

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> index;
    int L, H, R;
    v = vector<int>(10000+1, 0);
    ifstream infile;
    infile.open("infile.txt");
    while (cin>> L >> H >> R)
    {
       index.insert(L);
        index.insert(R);
        loop(i, L, R )
        {
            if (H > v[i])
                v[i] = H;
        }
    }

    int current = 0;
   bool nofirst=false;
   set <int> :: iterator itr;
    for (itr = index.begin(); itr != index.end(); ++itr) 
    {
        int i=*itr;
        if(v[i]!=current){
            current=v[i];
            if(nofirst)cout<<" ";
            else nofirst=true;
            cout<<i<<" "<<current;
            
        }
    }
    cout << endl;
    return 0;
}