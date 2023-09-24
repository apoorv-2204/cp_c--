
bool isArraySorted(vector<int> &arr, int &index, int &last_index)
{
    if (index == last_index)
        return true;

    // for recurrent element we dont return false
    if (!(arr[index] <= arr[index + 1]))
        return false;

    return isArraySorted(arr, ++index, last_index);
}

int binarySearch(vector<int> &arr, int &start, int &end, int &last_index, int &target)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;

    if (target > arr[mid])
    {
        start = mid + 1;
    }
    else
    {
        end = mid = 1;
    }
    return binarySearch(arr, start, end, last_index, target);
}
void solveMaze()

    void solve()
{
    int main[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    int i, j = 0, row = 3, col = 3;
    vector<vector<bool>> isVisitedArray(row, vector<bool>(col, false));
    isVisitedArray[0][0] = true;
    vector<string> path;
    string output = "";
}