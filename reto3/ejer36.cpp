#include <list>
#include <iostream>
using namespace std;

/**
 * @brief Check if a list is an anagram from anaother
 * 
 * @param L1 The first list
 * @param L2 The second list
 * @return true If they are anagrams
 * @return false If they are not
 */
bool anagrama (list<int> & L1, list<int> & L2) {
    list<int>::iterator it1, it2;
    bool terminar;

    if (L1.size() != L2.size())
        return false;

    for (it1 = L1.begin(); it1 != L1.end(); ++it1) {
        terminar = false;
        it2 = L2.begin();
        while (!terminar) {
            if (*it2 == *it1) {
                L2.erase(it2);
                terminar = true;
            }
            if (!terminar) {
                if (it2 == L2.end())
                    return false;

                ++it2;
            }
        }
    }
    return true;
}