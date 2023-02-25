
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
        // dont be too specific in conditons
        // if (mid + 1 < arr.size() && mid >= 0 && arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        // {
        //     return mid;
        // }

        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
            return mid;

        if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
            return mid - 1;

        if (arr[start] >= arr[mid])
        {
            // co-ordinate line coming baack from y line
            // search left
            end = mid - 1;
        }
        else
        {
            start = mid;
        }
    }
    return start;
}
int search_in_sorted_rotated_array(vector<int> &arr, int target)
{

    int pivot_index = PivotIndex(arr);

    if (target >= arr[0] && target <= arr[pivot_index])
    {
        return BinarySearch(arr, target, 0, pivot_index);
    }
    else if (pivot_index + 1 < arr.size() && target >= arr[pivot_index + 1] && target <= arr[arr.size() - 1])
    {
        // to the right of search space
        return BinarySearch(arr, target, pivot_index + 1);
    }
    return -1;
}

int lower_bound(vector<int> &arr, int target, int start = 0, int end = -1)
{
    int last_index = -1;
    if (end == -1)
        end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            last_index = mid;
            // shift to left for first occurence
            end = mid - 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
    }
    return last_index;
}

int upper_bound(vector<int> &arr, int target, int start = 0, int end = -1)
{
    int last_index = -1;
    if (end == -1)
        end = arr.size() - 1;

    while (start <= end)
    {
        // integer overflow
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            // shift to right for last occurence
            last_index = mid;
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
    }

    return last_index;
}

int search_insert_position(vector<int> &arr, int target, int start = 0, int end = -1)
{
    if (end == -1)
        end = arr.size() - 1;
    int position_to_insert_at = -1;
    int found = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            found = 1;
            position_to_insert_at = mid;
            break;
        }

        if (target < arr[mid])
            end = mid - 1;
        else
        {
            start = mid + 1;
        }
        position_to_insert_at = mid;
    }
    if (found == 1)
    {
        // dbg("start", start);
        // dbg("end", end);
        return position_to_insert_at;
    }
    else
    {
        // dbg("else start", start);
        // dbg("else end", end);
        return start;
    }
}

int squareRoot(ll int x)
{
    // https://leetcode.com/problems/sqrtx/
    int start = 0, end = x;
    while (start <= end)
    {
        ll int mid = start + (end - start) / 2;

        if (mid * mid == x)
            return mid;

        if (mid * mid > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start - 1;
}

bool matrix_binary_search(vector<vector<int>> &matrix, int target, int start = 0, int end = -1)
{
    // row
    int m = matrix.size();
    // col
    int n = matrix[0].size();
    // https://leetcode.com/problems/search-a-2d-matrix/
    if (end == -1)
        end = m * n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int col_index = mid % n;
        int row_index = mid / n;

        if (matrix[row_index][col_index] == target)
        {
            return true;
        }

        if (target < matrix[row_index][col_index])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}
