#include <bits/stdc++.h>

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

    // https://leetcode.com/problems/palindromic-substrings
    int countSubstrings(string s)
    {
        int left_pointer = 0, right_pointer = 0;
        int counter = 0;
        int len = s.size();
        // loop through string
        // traverse until window reach to end
        // set pointer to start and end
        // is it palindrome
        for (int i = 0; i < len; i++)
        {
            left_pointer = i;
            right_pointer = left_pointer;

            while (left_pointer >= 0 && right_pointer < len && s[left_pointer] == s[right_pointer])
            {
                counter++;
                left_pointer--;
                right_pointer++;
            }
            left_pointer = i;
            right_pointer = left_pointer + 1;
            while (left_pointer >= 0 && right_pointer < len && s[left_pointer] == s[right_pointer])
            {
                counter++;
                left_pointer--;
                right_pointer++;
            }
        }
        return counter;
    }

    // https://leetcode.com/problems/valid-anagram
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    // https://leetcode.com/problems/valid-anagram
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        int counts[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int count : counts)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }

    // https : // leetcode.com/problems/reverse-only-letters
    bool
    isEnglishLetter(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    string reverseOnlyLetters(string s)
    {
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            if (!isEnglishLetter(s[left]))
            {
                left++;
            }
            else if (!isEnglishLetter(s[right]))
            {
                right--;
            }
            else
            {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
    // https : // leetcode.com/problems/reverse-vowels-of-a-string/
    string
    reverseVowels(string s)
    {
        int left = 0, len = s.size() - 1;
        int right = len;
        while (left < right)
        {
            bool lV = isVowel(s[left]);
            bool rV = isVowel(s[right]);
            if (lV && rV)
            {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
            else if (!lV)
            {
                left++;
            }
            else if (!rV)
            {
                right--;
            }
        }
        return s;
    }

    bool isVowel(char ch)
    {
        ch = tolower(ch);
        // Convert to lowercase for case-insensitive comparison
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    // https://leetcode.com/problems/reverse-string
    void reverseString(vector<char> &s)
    {
        int left = 0, len = s.size() - 1;
        int right = len;

        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    // https : // leetcode.com/problems/isomorphic-strings
    bool
    isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int len = s.size() - 1;
        std::map<char, char> language_S_to_T;
        std::map<char, char> language_T_to_S;

        for (int i = 0; i <= len; i++)
        {
            // Two strings s and t are isomorphic if the characters in s can be replaced to get t
            char ch_s = s[i];
            char ch_t = t[i];
            if (language_S_to_T.find(ch_s) == language_S_to_T.end() &&
                language_T_to_S[ch_t] == 0)
            {
                // if mapping dont exist create a mappning
                language_S_to_T[ch_s] = ch_t;
                language_T_to_S[ch_t] = ch_s;
            }
            else
            {
                // mapping already done
                // check for conflict
                if (language_S_to_T[ch_s] != ch_t)
                    return false;
                if (language_T_to_S[ch_t] != ch_s)
                    return false;
            }
        }
        return true;
    }
    bool isIsomorphic2(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int len = s.size();
        char language_S_to_T[256] = {0};
        char language_T_to_S[256] = {0};

        for (int i = 0; i < len; i++)
        {
            char ch_s = s[i];
            char ch_t = t[i];

            if (language_S_to_T[ch_s] == 0 && language_T_to_S[ch_t] == 0)
            {
                language_S_to_T[ch_s] = ch_t;
                language_T_to_S[ch_t] = ch_s;
            }
            else
            {
                if (language_S_to_T[ch_s] != ch_t)
                    return false;
                if (language_T_to_S[ch_t] != ch_s)
                    return false;
            }
        }

        return true;
    }
    bool isIsomorphic3(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int len = s.size();
        unordered_map<char, char> s_to_t_map;
        unordered_map<char, char> t_to_s_map;

        for (int i = 0; i < len; i++)
        {
            char ch_s = s[i];
            char ch_t = t[i];

            if (s_to_t_map.count(ch_s) == 0 && t_to_s_map.count(ch_t) == 0)
            {
                s_to_t_map[ch_s] = ch_t;
                t_to_s_map[ch_t] = ch_s;
            }
            else if (s_to_t_map[ch_s] != ch_t || t_to_s_map[ch_t] != ch_s)
            {
                return false;
            }
        }
        return true;
    }

    bool isIsomorphic4(string s, string t)
    {

        int n = s.size();
        int s_to_t[256] = {0}; // array to keep track of mappings from s to t
        int t_to_s[256] = {0}; // array to keep track of mappings from t to s

        for (int i = 0; i < n; i++)
        {
            if (s_to_t[s[i]] == 0 && t_to_s[t[i]] == 0)
            {
                // if mappings don't exist, create new ones
                s_to_t[s[i]] = t[i];
                t_to_s[t[i]] = s[i];
            }
            else if (s_to_t[s[i]] != t[i] || t_to_s[t[i]] != s[i])
            {
                // if mappings exist but are different, return false
                return false;
            }
        }

        return true;
    }
};