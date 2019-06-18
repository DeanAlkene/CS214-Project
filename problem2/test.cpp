#include <bits/stdc++.h>
using namespace std;

main()
{
    unordered_multimap<int, int> um;
    um.insert(pair<int, int>(1, 2));

    um.insert(pair<int, int>(1, 3));

    um.insert(pair<int, int>(1, 2));
    cout << um.size() << endl;
}