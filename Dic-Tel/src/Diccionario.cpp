/**
 * @file Diccionario.cpp
 * @author Alejandro Rubio Martinez
 * @brief Implementation from Diccionario.h
 * 
 */
#include "../inc/Diccionario.h"

template<class T,class U>
Dictionary<T,U>::Dictionary() {
    clear();
}

template<class T, class U>
Dictionary<T,U>::Dictionary(const Dictionary & D) {
    *this = D;
}

template<class T, class U>
Dictionary<T,U>::~Dictionary() {}

template<class T, class U>
Dictionary<T,U> & Dictionary<T,U>::operator=(const Dictionary<T,U> &D) {
    if (this!=&D){
        clear();
        copy(D);
    }
    return *this;
}

template<class T, class U>
bool Dictionary<T,U>::searchKey(const T &p, Iterator &it_out) {
    if (dict.size()>0){
				    
        typename Dictionary::Iterator it;
        
        for (it=this->begin(); it!=this->end() ;++it){
            if (((*it).key==p)) {
                it_out=it;
                return true;
            }
            else if ((*it.get()).key>p){
                it_out=it;
                return false;
            }	   
        }
    }
    it_out=dict.end();
    return false;    
}

template<class T, class U>
void Dictionary<T,U>::insert(const T& key,const list<U> &info) {
    typename Dictionary::Iterator it;
		     
    if (!searchKey(key,it)){
        data<T,U> p;
        p.key = key;
        p.info=info;
    
        dict.push_back(p);
    }
}

template<class T, class U>
void Dictionary<T,U>::addMeaning(const U & s ,const T &p) {
    Dictionary::Iterator it;
    data<T,U> aux;

    if (searchKey(p,it)) {
        (*it).info.push_back(s);
    }
    else {
        aux.key = p;
        aux.info.push_back(s);
        dict.push_back(aux);
    }
}

template<class T, class U>
list<U>  Dictionary<T,U>::getInfo(const T & p) {
    typename Dictionary::Iterator it;
			   
    if (!searchKey(p,it)){
        return list<U>();
    }
    else{
        return (*it).info;
    }
}

template<class T, class U>
void Dictionary<T,U>::copy(const Dictionary<T,U>& D) {
    dict.assign(D.dict.begin(),D.dict.end());
}

template<class T, class U>
void Dictionary<T,U>::clear() {
    this->dict.erase(dict.begin(),dict.end());
}

template<class T,class U>
int Dictionary<T,U>::size()const {
    return dict.size();
}

template<class T, class U>
typename Dictionary<T,U>::Iterator Dictionary<T,U>::begin(){
    typename Dictionary<T,U>::Iterator iter(dict.begin());
    return iter;
}

template<class T, class U>
typename Dictionary<T,U>::Iterator Dictionary<T,U>::end(){
    typename Dictionary<T,U>::Iterator iter(dict.end());
    return iter;
}

template<class T, class U>
typename Dictionary<T,U>::Const_Iterator Dictionary<T,U>::cbegin()const{
    typename Dictionary<T,U>::Const_Iterator iter(dict.cbegin());
    return iter;
}

template<class T, class U>
typename Dictionary<T,U>::Const_Iterator Dictionary<T,U>::cend()const {
    typename Dictionary<T,U>::Const_Iterator iter(dict.cend());
    return iter;
}

template<class T, class U>
bool Dictionary<T,U>::empty() const {
    if (dict.empty())
        return true;
    else
        return false;
}

template<class T, class U>
void Dictionary<T,U>::erase(Iterator & it) {
    dict.erase(it.get());
}

template<class T, class U>
Dictionary<T,U>::Iterator::Iterator() {}

template<class T,class U>
Dictionary<T,U>::Iterator::Iterator(typename list<data<T,U>>::iterator iter) {
    it = iter;
}

template<class T, class U>
typename list<data<T,U>>::iterator Dictionary<T,U>::Iterator::get() const {
    return it;
}

template<class T,class U>
typename list<data<T,U>>::iterator& Dictionary<T,U>::Iterator::operator++() {
    return ++it;
}

template<class T,class U>
typename Dictionary<T,U>::Iterator& Dictionary<T,U>::Iterator::operator--() {
    return --it;
}

template<class T,class U>
typename Dictionary<T,U>::Iterator Dictionary<T,U>::Iterator::operator=(typename Dictionary<T,U>::Iterator iter){
    if (this->it!=iter.get()){
        it = iter.get();
    }
    return *this;
}

template<class T, class U>
bool Dictionary<T,U>::Iterator::operator!=(const typename Dictionary<T,U>::Iterator & iter) {
    return it!=iter.get();
}

template<class T, class U>
bool Dictionary<T,U>::Iterator::operator==(const typename Dictionary<T,U>::Iterator & iter) {
    return it==iter.get();
}

template<class T,class U>
data<T,U> & Dictionary<T,U>::Iterator::operator*(){
    return *it;
}

template<class T, class U>
ostream& operator<<(ostream& os, const Dictionary<T,U>& D) {
    typename Dictionary<T,U>::Const_Iterator it;
    typename list<U>::const_iterator it2;

    for (it = D.cbegin(); it != D.cend(); ++it) {
        os << (*it).key << endl;

        for (it2 = (*it).info.begin(); it2 != (*it).info.end(); ++it2)
            os << "\t-" << *it2 << endl;
    }

    return os;
}

template<class T,class U>
Dictionary<T,U>::Const_Iterator::Const_Iterator() {}

template<class T, class U>
Dictionary<T,U>::Const_Iterator::Const_Iterator(typename list<data<T,U>>::const_iterator iter) {
    it = iter;
}

template<class T,class U>
typename list<data<T,U>>::const_iterator Dictionary<T,U>::Const_Iterator::getConst() const {
    return it;
}

template<class T,class U>
typename list<data<T,U>>::const_iterator& Dictionary<T,U>::Const_Iterator::operator++() {
    return ++it;
}

template<class T,class U>
typename Dictionary<T,U>::Const_Iterator& Dictionary<T,U>::Const_Iterator::operator--() {
    return --it;
}

template<class T,class U>
typename Dictionary<T,U>::Const_Iterator Dictionary<T,U>::Const_Iterator::operator=(typename Dictionary<T,U>::Const_Iterator iter){ 
    if (this->it!=iter.getConst()){
        it = iter.getConst();
    }
    return *this;
}

template<class T,class U>
bool Dictionary<T,U>::Const_Iterator::operator!=(const typename Dictionary<T,U>::Const_Iterator & iter) {
    return it!=iter.getConst();
}

template<class T,class U>
const data<T,U> & Dictionary<T,U>::Const_Iterator::operator*() {
    return *it;
}

template<class T, class U>
Dictionary<T,U> operator+(const Dictionary<T,U> & D1, const Dictionary<T,U> & D2) {
    typename Dictionary<T,U>::Const_Iterator it;
    Dictionary<T,U> D;

    for (it = D1.cbegin(); it != D1.cend(); ++it) {
        D.insert((*it).key, (*it).info);
    }
    for (it = D2.cbegin(); it != D2.cend(); ++it) {
        D.insert((*it).key, (*it).info);
    }

    return D;
}