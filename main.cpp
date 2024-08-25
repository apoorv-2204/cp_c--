
// #include <bits/stdc++.h>

#include "src/cpp/imports.hpp"

int main()
{
    Utils::dbg("Hello -- start", 87);

    Tree::tree_main();

    Utils::dbg("Hello -- end", 87);
    return 0;
}

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("error.txt", "w", stderr);
//     freopen("output.txt", "w", stdout);
// #endif

//     int t = 1;
//     /*is Single Test case?*/ std::cin >> t;
//     while (t--)
//     {
//         cout << "-----------Compile Time----------";
//         std::time_t result = std::time(nullptr);
//         std::cout << std::ctime(&result);
//         cout << "\n-----------------start-----------\n";
//         solve();
//         cout << "\n-----------------end-------------\n";
//     }

//     cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
//     return 0;
// }
