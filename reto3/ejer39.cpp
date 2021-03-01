#include <list>
#include <vector>
using namespace std;
typedef list<int>::iterator iterador;

void sign_split(list<int> &L,vector< list<int> > &VL) {
    bool signo = true;
    int n = L.size();
    bool oldSigno = true;
    list<int> sublista;

    if (!L.empty()) {
        if (L.front() < 0) {
            oldSigno = false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (L.front() >= 0)
            signo = true;
        if (L.front() < 0)
            signo = false;

        if (signo == oldSigno)
            sublista.push_back(L.front());
        else {
            VL.push_back(sublista);
            sublista.clear();
            sublista.push_back(L.front());
        }
        L.pop_front();
        oldSigno = signo;
    }
    VL.push_back(sublista);
}