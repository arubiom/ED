#include <list>
using namespace std;

/**
 * @brief Duplicate into the i position the element in n-i-1 position from a list
 * 
 * @param L The list we want to duplicate
 */
template<class T> void duplicarlista (list<T> &L) {
    list<T> back = L;
    back.reverse();
    typename list<T>::iterator it = L.begin();

    for (it= ++L.begin(); it!= ++L.end(); ++it) {
        L.insert(it,back.front());
        back.pop_front();
    }
}