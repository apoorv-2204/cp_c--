
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define memf(a) memset(a, false, sizeof(a))
#define mema(a) memset(a, 0x3f, sizeof(a))
#define memn(a) memset(a, 0xc0, sizeof(a))
#define memi(a) memset(a, 0x7f, sizeof(a))
#define memd(a) memset(a, 0x80, sizeof(a))
#define mems(a) memset(a, 0x3f, sizeof(a))
#define memx(a) memset(a, 0x80, sizeof(a))
#define memc(a) memset(a, 0x00, sizeof(a))

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int inf = 1e9;
const ll INF = 1e18;
void dbg(string msg, int zvar);
void dbg_vector(vector<int> arr);
vector<int> get_input_as_vector();

void print_digits_recursion_in_reverse(int n)
{
    if (n == 0)
        return;

    cout << n % 10 << " ";
    print_digits_recursion_in_reverse(n / 10);
}

void print_digits_recursion(int n)
{
    if (n == 0)
        return;
    print_digits_recursion(n / 10);
    cout << n % 10 << " ";
}
void solve()
{
    print_digits_recursion(569);
    cout << endl;
    print_digits_recursion_in_reverse(569);

    // for (auto r : res)
    // {
    //     cout << r << " ";
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    /*is Single Test case?*/ std::cin >> t;
    while (t--)
    {
        cout << "-----------Compile Time----------";
        std::time_t result = std::time(nullptr);
        std::cout << std::ctime(&result);
        cout << "\n-----------------start-----------\n";
        solve();
        cout << "\n-----------------end-------------\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void dbg(string msg, int zvar)
{
    std::cout << "\n " + msg + " " << zvar << '\n';
}

void dbg_vector(vector<int> arr)
{
    copy(arr.begin(),
         arr.end(),
         ostream_iterator<int>(cout, " "));
}
vector<int> get_input_as_vector()
{
    int size = 0;
    std::cin >> size;
    vector<int> input_vec;

    while (size--)
    {
        int temp = 0;
        std::cin >> temp;
        input_vec.push_back(temp);
    }

    return input_vec;
}
