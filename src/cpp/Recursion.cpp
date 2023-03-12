#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        // 0,1,1,2,3,5, https://leetcode.com/problems/fibonacci-number/submissions/913358203/
        // for first term return 1
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }

    bool isPowerOfFour(int n) // https://leetcode.com/problems/power-of-four/submissions/913363419/
    {
        if (n == 0)
            return false;
        if (n == 1 || n == 4 || n == 16 || n == 256)
            return true;
        else if (n % 4 != 0)
        {
            return false;
        }

        return isPowerOfFour(n / 4);
    }

    bool isPowerOfTwo(int n) // https://leetcode.com/problems/power-of-two
    {
        if (n == 0)
            return false;
        if (n == 1 || n == 2 || n == 4 || n == 8)
            return true;
        else if (n % 2 != 0)
            return false;

        return isPowerOfTwo(n / 2);
    }
    // https://leetcode.com/problems/power-of-three/

    bool isPowerOfThree(int n)
    {
        if (n == 0)
            return false;
        if (n == 1 || n == 3 || n == 9 || n == 27)
            return true;
        else if (n % 3 != 0)
            return false;

        return isPowerOfThree(n / 3);
    }

    double myPow(double x, int n) // https://leetcode.com/problems/powx-n/
    {
        if (n == 0)
            return 1;
        if (n < 0)
        {
            n = abs(n);
            x = 1 / x;
        }
        if (n % 2 == 0)
        {
            return myPow(x * x, n / 2);
        }
        else
        {
            return x * myPow(x, n - 1);
        }
    }

    // https : // leetcode.com/problems/climbing-stairs/description/
    int
    climbStairs(int n)
    {
        // it takes n steps to reach the top means
        // there are n stairs

        //    climb in one step to reach first staircase
        if (n == 1)
            return 1;
        //  to climb 2 staircases there are two ways to do so
        if (n == 2)
            return 2;

        // 2steps and then 1 step
        // 1steps and the 2steps
        // 1steps and 1 step and 1step
        if (n == 3)
            return 3;

        // RR
        //  nb of ways to reach n th stair case is by
        // nb of ways to reach n-1th staircase and +
        // nb of ways tp reach n-2th stair case
        // by obervation

        return climbStairs(n - 1) + climbStairs(n - 2);
        ;
    }

    void printArrayRecursively(vector<int> &v, int index)
    {
        if (index == v.size())
            return;

        printArrayRecursively(v, index + 1);
        cout << v[index] << " " << endl;
    }

    int array_max_recusion(vector<int> &s, int index, int &max_val)
    {
        // avoid pre post in recursion
        // index reached last and calls one more itself for exit
        if (index == s.size())
            return max_val;

        if (s[index] > max_val)
        {
            max_val = s[index];
        }
        return array_max_recusion(s, index + 1, max_val);
    }

    void array_min_recusion_by_reference(vector<int> &s, int index, int &min_val)
    {
        // index reached last and calls one more itself for exit
        if (index == s.size())
            return;

        min_val = min(s[index], min_val);

        array_min_recusion_by_reference(s, index + 1, min_val);
    }

    bool key_in_string(string &str, int &index, char &target)
    {
        // traversed all string , but key not found return false
        // we can use null also
        if (index == str.size())
            return false;

        if (str[index] == target)
            return true;

        return key_in_string(str, ++index, target);
    }

    void return_key_indices(string &str, int &index, char &target, vector<int> &res)
    {
        // traversed all string , but key not found return false
        // we can use null also
        if (index == str.size())
            return;

        if (str[index] == target)
            res.push_back(index);

        return return_key_indices(str, ++index, target, res);
    }
    void count_occurences(string &str, int &index, char &target, int &count)
    {
        // traversed all string , but key not found return false
        // we can use null also
        if (index == str.size())
            return;

        if (str[index] == target)
            count++;

        return count_occurences(str, ++index, target, count);
    }

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
};