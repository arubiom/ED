#include <vector>
using namespace std;

void tartaglia (int nivel, vector <unsigned int> &v) {
    int coef;
    
    for (int i = 0; i < nivel; i++) {
        coef = 1;
        for (int j = 0; j<i+1; j++) {
            v.push_back(coef);
            coef*=(i*1.0-j*1.0)/(j*1.0+1.0);
        }
    }
}