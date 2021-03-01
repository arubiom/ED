#include <list>
using namespace std;
/**
 * @brief Compares in lexicographuc order two lists
 * 
 * @param L1 The first list
 * @param L2 The second list
 * @return true If the first list is smaller than second
 * @return false If not
 */
bool lexicord (list<int> L1, list<int> L2) {
    int min = L2.size();
    list<int> copia1 = L1, copia2 = L2;

    if (L1.size() < L2.size())
        min = L1.size();

    for (int i = 0; i < min; i++) {
        if (copia1.front() < copia2.front())
            return true;
        if (copia1.front() >= copia2.front())
            return false;
        if (copia1.front() == copia2.front()) {
            copia1.pop_front();
            copia2.pop_front();
        }
    }
    if (!L2.empty())
        return true;
    else
        return false;
    
}         