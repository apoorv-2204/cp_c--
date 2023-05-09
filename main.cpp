
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

// void dbg(string msg, int zvar);
// void dbg_vector(vector<int> arr);
// vector<int> get_input_as_vector();
// bool isArraySorted(vector<int> &arr, int &index, int &last_index)
// {
//     if (index == last_index)
//         return true;

//     // for recurrent element we dont return false
//     if (!(arr[index] <= arr[index + 1]))
//         return false;

//     return isArraySorted(arr, ++index, last_index);
// }

// int binarySearch(vector<int> &arr, int &start, int &end, int &last_index, int &target)
// {
//     if (start > end)
//         return -1;

//     int mid = start + (end - start) / 2;

//     if (arr[mid] == target)
//         return mid;

//     if (target > arr[mid])
//     {
//         start = mid + 1;
//     }
//     else
//     {
//         end = mid = 1;
//     }
//     return binarySearch(arr, start, end, last_index, target);
// }
// void solveMaze()

//     void solve()
// {
//     int main[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
//     int i, j = 0, row = 3, col = 3;
//     vector<vector<bool>> isVisitedArray(row, vector<bool>(col, false));
//     isVisitedArray[0][0] = true;
//     vector<string> path;
//     string output = "";
// }

class Node
{
public:
    Node *next;
    int data;
    Node *prev;

    Node()
    {
        this->next = nullptr;
        this->data = 0;
    }

    Node(int data)
    {
        this->next = nullptr;
        this->data = data;
    }

    Node(Node &other)
    {
        // ->is applied to poitner type
        this->next = other.next;
        this->data = other.data;
    }
};

class SLL
{
    Node *head;
    Node *tail;

public:
    SLL(int data)
    {
        head = tail = new Node(data);
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

void solve()
{
    // dynamic allocating memory
    SLL *temp = new SLL(10);
    temp->insertAtHead(20);
    temp->insertAtHead(30);
    temp->insertAtHead(40);

    temp->insertAtTail(100);
    temp->insertAtTail(200);
    temp->insertAtTail(300);
    temp->insertAtTail(400);

    temp->print();
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
