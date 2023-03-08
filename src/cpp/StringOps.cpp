#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    // https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
    {
        int i = 0;
        int size = s.length() - 1;
        string s2 = "";
        while (i <= size)
        {

            if (s2.length() > 0 && s2[s2.length() - 1] == s[i])
            {
                s2.pop_back();
            }
            else
            {
                s2.push_back(s[i]);
            }
            i++;
        }
        return s2;
    }
    int getLength(char name[])
    {
        int length = 0;
        int i = 0;

        while (name[i] != '\0')
        {
            length++;
            i++;
        }
        return length;
    }

    void reverseCharArray(char name[])
    {
        int i = 0;
        int n = getLength(name);
        int j = n - 1;

        while (i <= j)
        {
            swap(name[i], name[j]);
            i++;
            j--;
        }
    }

    void replaceSpaces(char sentence[])
    {

        int i = 0;
        int n = strlen(sentence);

        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == ' ')
            {
                sentence[i] = '@';
            }
        }
    }

    bool checkPalindrome(char word[])
    {
        int i = 0;
        int n = strlen(word);
        int j = n - 1;

        while (i <= j)
        {
            if (word[i] != word[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    void convertIntoUpperCase(char arr[])
    {
        int n = getLength(arr);

        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] - 'a' + 'A';
        }
    }

    bool compareString(string a, string b)
    {
        if (a.length() != b.length())
            return false;

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }

        return true;
    }

    // https: // leetcode.com/problems/remove-all-occurrences-of-a-substring/
    string removeOccurrences(string s, string part)
    {
        int pos = s.find(part);
        while (pos != string::npos)
        {
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }

    // int findInString(string &s, string &part)
    // {
    //     for (int i = 0; i < s.length() - part.length(); i++)
    //     {
    //         int j = 0;

    //         if (part[0] == s[i])
    //         {
    //             for (j = 0; j < part.length(); j++)
    //             {
    //                 if (part[j] == s[i + j])
    //                 {
    //                     continue;
    //                 }
    //                 else
    //                 {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return -1;
    // }

    bool validPalindrome(string s)
    {
        // {https://leetcode.com/problems/valid-palindrome-ii/description/

        int start = 0,
            end = s.length() - 1;

        while (start <= end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                // then check excluding i is palindrome or
                // excluding j is palindrome
                return isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1);
            }
        }

        return true;
    }

    bool isPalindrome(string s, int i = 0, int j = -1)
    {
        if (j == -1)
            j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // https: // leetcode.com/problems/minimum-time-difference/
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> time;
        for (int i = 0; i < timePoints.size(); i++)
        {
            int hours = std::stoi(timePoints[i].substr(0, 2));
            int mins = std::stoi(timePoints[i].substr(3, 5));
            time.push_back(hours * 60 + mins);
        }

        // step 2 sort
        sort(time.begin(), time.end());
        // mint start from 0 and goes to 1440 and repeat
        //  find min_diff;
        int min_diff = findCyclicMinDiff(time[0], time[1], 0, 1440);
        for (int i = 1; i < time.size() - 1; i++)
        {
            min_diff = min(min_diff, findCyclicMinDiff(time[i], time[i + 1], 0, 1440));
        }
        min_diff = min(min_diff, findCyclicMinDiff(time[0], time[time.size() - 1], 0, 1440));

        return min_diff;
    }

    int findCyclicMinDiff(int a, int b, int cycleStart, int cycleEnd)
    {
        int mid = (cycleStart + cycleEnd) / 2;
        if ((a <= mid && b <= mid) || (a >= mid && b >= mid))
        {
            return abs(a - b);
        }
        else if (a > mid)
        {
            // a closer to end
            return min(abs(a - b), abs(cycleEnd - a) + abs(cycleStart - b));
        }
        else
        {
            // b closer to end
            return min(abs(a - b), abs(cycleEnd - b) + abs(cycleStart - a));
        }
    }   
};