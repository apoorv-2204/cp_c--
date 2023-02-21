
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

void dbg(string msg, int zvar)
{
    std::cout << " " + msg + " " << zvar << '\n';
}

void dbg_vector(vector<int> arr)
{
    copy(arr.begin(),
         arr.end(),
         ostream_iterator<int>(cout, " "));
}

int BinarySearch(vector<int> &arr, int target, int start = 0, int end = -1)
{
    if (end == -1)
        end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int PivotIndex(vector<int> &arr)
{

    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        // terminating condition
        // ascending order
        if (mid + 1 < arr.size() && mid >= 0 && arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }

        if (arr[start] > arr[mid])
        {
            // co-ordinate line coming baack from y line
            // search left
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
void search_in_rotated_sorted_array()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int target = 5;

    // find pivot index
    int pivot_index = PivotIndex(arr);
    dbg("pivot_index", pivot_index);
    // determine where could be the element
    if (pivot_index == -1)
    {
        // return pivot
        dbg("pivot_index", -1);
    }
    // determine where is the element to the right or left
    // apply binary search
    if (arr[0] < target && target <= arr[pivot_index])
    {
        dbg("to the left", BinarySearch(arr, target, 0, pivot_index));
    }
    else
    {
        // to the right of search space
        dbg("to the right ", BinarySearch(arr, target, pivot_index + 1));
    }
}
void solve()
{
    search_in_rotated_sorted_array();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // /*is Single Test case?*/ cin >> t;
    while (t--)
    {
        cout << "-----------Compile Time----------\n";

        std::time_t result = std::time(nullptr);
        std::cout << std::ctime(&result);
        cout << "-----------------start-----------\n";
        solve();
        cout << "-----------------end-------------\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
