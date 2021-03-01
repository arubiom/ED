/**
 * @file ejercicio2.cpp
 * @author Alejandro Rubio Martinez
 * @brief (1.5 puntos) Dada una lista de conjuntos list< set<int> > L, implementar una función
 * @version 0.1
 * @date 2021-01-21
 * 
 * 
 */
#include <set>
#include <list>
using namespace std;

bool proper_subset(list<set<int>> &L) {
    list<set<int>>::iterator it = L.begin();

    for (++it; it != L.end(); ++it) {
        set<int> s = *(--it);
        ++it;
        if (!includeEstricto(s, *it))
            return false;
    }

    return true;
}

bool includeEstricto(set<int> u, set<int> v) {
    set<int>::iterator it;
    if (u.size() == v.size() || u.size() > v.size())
        return false;

    for (it = u.begin(); it != u.end(); ++it)
        if (v.find(*it) == v.end())
            return false;

    return true;
}