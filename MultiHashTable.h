#ifndef MULTIHASHTABLE_H
#define MULTIHASHTABLE_H

#include <bits/stdc++.h>

template<class K,class V>
class MultiHashTable{

    size_t DEFAULT_SIZE = 100;
    struct Base_Element{
        K key;
        std::list<V> values;
        Base_Element(K key, V value):key(key){
            values.push_back(value);
        }

        ~Base_Element(){
          values.clear();
        }
        std::list<V> *getValues(){
            return &values;
        }
    };

    void setDefaultSizeOfArr(size_t newSize);
    size_t hashFunc(K key);
    std::vector<std::list<Base_Element*>*> arr;

public:
    MultiHashTable(){
        setDefaultSizeOfArr(DEFAULT_SIZE);
    }
    std::list<V> *findKey(K key);
    void insert(K key, V value);
    bool removeKey(K key);
    void removeValue(K key, V valueToDelete);
    ~MultiHashTable();



};
template<class K, class V>
void MultiHashTable<K,V>::setDefaultSizeOfArr(size_t newSize){
    arr.resize(newSize);
}

template<class K, class V>
size_t MultiHashTable<K,V>::hashFunc(K key){
    return std::hash<K>{}(key)%DEFAULT_SIZE;
}

template<class K, class V>
std::list<V> *MultiHashTable<K,V>::findKey(K key){
    size_t i = hashFunc(key);
    auto list = arr[i];
    if(!list)
        return nullptr;
    for(auto it = list->begin(); it != list->end(); ++it ){
        if((*it)->key == key)
            return (*it)->getValues();
    }
    return nullptr;
}

template<class K, class V>
void MultiHashTable<K,V>::insert(K key, V value){
    size_t i = hashFunc(key);
    bool inserted = false;
    auto listt = arr[i];
    //jezeli kubek nie istnieje (to wsk na liste)
    if(!listt){
        arr[i] = new std::list<Base_Element*>();
        listt = arr[i];
    }
    //znajdz klucz
    for(auto it = listt->begin(); it != listt->end(); ++it ){
        if((*it)->key == key){
            (*it)->values.push_back(value);
            inserted = true;
            break;
        }
    }
    //nie ma klucza, wrzuc element
    if(!inserted)
        listt->push_back(new Base_Element(key,value));

}

template<class K, class V>
bool MultiHashTable<K,V>::removeKey(K key){
    size_t i = hashFunc(key);

    auto bucket = arr[i];
    if(!bucket)
        return true;
    for(auto el : *bucket){
        if(el->key == key){
            bucket->remove(el);
            if(bucket->size() == 0){
                delete arr[i];
                arr[i] = nullptr;
            }
            return true;
        }

    }
    return false;

}

template<class K, class V>
void MultiHashTable<K,V>::removeValue(K key, V valueToDelete){
    size_t i = hashFunc(key);
    auto bucket = arr[i];
    if(!bucket)
        return;
    for(auto el: *bucket){
        if(el->key == key){
            el->values.remove(valueToDelete);
            if(el->values.size()== 0){
                bucket->remove(el);
                if(bucket->size()== 0){
                    delete arr[i];
                    arr[i] = nullptr;
                }
                break;
            }
        }
    }
}

template<class K, class V>
MultiHashTable<K,V>::~MultiHashTable(){
    size_t size = arr.size();
    //list<Element*> *bucket;
    for(size_t i=0; i<size;i++){
        if(arr[i]){
            //auto it = begin(*arr[i]);
            for(auto it = begin(*arr[i]); it != end(*arr[i]); ++it){
                delete *it;
                *it = nullptr;
            }
            arr[i]->clear();

            delete arr[i];
            arr[i] = nullptr;
        }
    }
    arr.clear();
}

#endif // MULTIHASHTABLE_H

