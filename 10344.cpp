// Auther : asmaa saeed date: 2020-08-08
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

int arr[5];
bool tst, vstd[6];
void backtrcaking(int index, int sum, bool first)
{
    if (tst)
        return;
    if (index == 5)
    {

        if (sum == 23)
        {
            tst = true;
        }
        return;
    }

    loop(i, 0, 5)
    {
        if (vstd[i])
            continue;
        vstd[i] = 1;
        if (first)
            backtrcaking(index + 1, arr[i], 0);
        else
        {
            backtrcaking(index + 1, sum + arr[i], 0);

            backtrcaking(index + 1, sum - arr[i], 0);

            backtrcaking(index + 1, sum * arr[i], 0);
        }
        vstd[i] = 0;
    }
}

int main()
{

    while (cin >> arr[0])
    {

        cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];
        if (arr[0] == 0)
            break;
        tst = false;
        clr(vstd, 0);
        backtrcaking(0, 0, 1);
        if (tst)
            puts("Possible");
        else
            puts("Impossible");
    }

    return 0;
}