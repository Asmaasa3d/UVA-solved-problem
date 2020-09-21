// Auther : asmaa saeed date: 2020-06-27
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

string s;
int t;
bool vstd[35][85] = {0};
void DFS(vector<string> &v, int i, int j, int sz)
{
    if (i < 0 || i >= v.size()-1 || j < 0 || j >= sz || vstd[i][j] || (v[i][j] != ' ' && v[i][j] != '*'))
        return;
    v[i][j] = '#';
    vstd[i][j] = true;

    DFS(v, i + 1, j, sz);
    DFS(v, i - 1, j, sz);
    DFS(v, i, j + 1, sz);
    DFS(v, i, j - 1, sz);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fstream infile;
    infile.open("infile.txt");
    ofstream q;
    q.open("q.txt");
    cin >> t;
   cin.ignore(256, '\n');
    loop(i, 0, t)
    {
        vector<string> v;
        int sz = 0;
        memset(vstd, 0, sizeof vstd);
        while (true)
        {
            getline(cin, s);
            v.pb(s);
            //cout<<s<<" "<<s.size()<<endl;
            if (s[0] == '_')
                break;
            if (s.size() > sz)
                sz = s.size();
        }
        int a, b;
        loop(i, 0, v.size())
        {
            loop(j, 0, sz)
            { 
                if (v[i][j] == '*')
                {
                    a = i;
                    b = j;
                    break;
                }
            }
        }

        DFS(v, a, b, sz);
        loop(i, 0, v.size())
        {
            q<< v[i];
        
            q << endl;
        }
    }

    return 0;
}