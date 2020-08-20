#include <bits/stdc++.h>

#include "test.h"
//template<class K,class V>
//class MultiHashTable{

//    int DEFAULT_SIZE = 100;
//    struct Base_Element{
//        K key;
//        std::list<V> values;
//        Base_Element(K key, V value):key(key){
//            values.push_back(value);
//        }

//        ~Base_Element(){
//          values.clear();
//        }
//        std::list<V> *getValues(){
//            return &values;
//        }
//    };

//    void setDefaultSizeOfArr(size_t newSize){
//        arr.resize(newSize);
//    }


//    size_t hashFunc(K key){
//        return std::hash<K>{}(key)%DEFAULT_SIZE;
//    }

//    std::vector<std::list<Base_Element*>*> arr;

//public:
//    MultiHashTable(){
//        setDefaultSizeOfArr(DEFAULT_SIZE);

//    }
//    std::list<V> *findKey(K key){
//        size_t i = hashFunc(key);
//        auto list = arr[i];
//        if(!list)
//            return nullptr;
//        for(auto it = list->begin(); it != list->end(); ++it ){
//           if((*it)->key == key)
//               return (*it)->getValues();
//        }
//        return nullptr;
//    }

//    void insert(K key, V value){
//        size_t i = hashFunc(key);
//        bool inserted = false;
//        auto listt = arr[i];
//        //jezeli kubek nie istnieje (to wsk na liste)
//        if(!listt){
//            arr[i] = new std::list<Base_Element*>();
//            listt = arr[i];
//        }
//        //znajdz klucz
//        for(auto it = listt->begin(); it != listt->end(); ++it ){
//           if((*it)->key == key){
//                (*it)->values.push_back(value);
//                inserted = true;
//                break;
//            }
//        }
//        //nie ma klucza, wrzuc element
//        if(!inserted)
//            listt->push_back(new Base_Element(key,value));

//    }
//    bool removeKey(K key){
//        size_t i = hashFunc(key);

//        auto bucket = arr[i];
//        if(!bucket)
//            return true;
//        for(auto el : *bucket){
//            if(el->key == key){
//                bucket->remove(el);
//                if(bucket->size() == 0){
//                    delete arr[i];
//                    arr[i] = nullptr;
//                }
//                return true;
//            }

//        }
//        return false;

//    }
//    void removeValue(K key, V valueToDelete){
//        size_t i = hashFunc(key);
//        auto bucket = arr[i];
//        if(!bucket)
//            return;
//        for(auto el: *bucket){
//            if(el->key == key){
//                el->values.remove(valueToDelete);
//                if(el->values.size()== 0){
//                    bucket->remove(el);
//                    if(bucket->size()== 0){
//                        delete arr[i];
//                        arr[i] = nullptr;
//                    }
//                    break;
//                }
//            }
//        }
//    }


//    ~MultiHashTable(){
//        size_t size = arr.size();
//        //list<Element*> *bucket;
//        for(size_t i=0; i<size;i++){
//            if(arr[i]){
//                //auto it = begin(*arr[i]);
//                for(auto it = begin(*arr[i]); it != end(*arr[i]); ++it){
//                    delete *it;
//                    *it = nullptr;
//                }
//                arr[i]->clear();

//                delete arr[i];
//                arr[i] = nullptr;
//            }
//        }
//        arr.clear();
//    }



//};

//class Test{
//protected:
//    MultiHashTable<int,int> *myMap;
//    std::map<int,int> *insertedNumbers,*toDelete,*notDeleted;
//    void beforeEach(){
//        myMap = new MultiHashTable<int,int>();
//        insertedNumbers = new std::map<int,int>();
//        toDelete = new std::map<int,int>();
//        notDeleted = new std::map<int,int>();
//        prepareNumbersToInsertAndDelete();
//    }
//    void afterEach(){
//        delete myMap;
//        delete insertedNumbers;
//        delete toDelete;
//        delete notDeleted;
//    }
//    void insert(){
//        for(auto it : *this->insertedNumbers){
//            myMap->insert(it.first,it.second);
//        }
//    }
//    void prepareNumbersToInsertAndDelete(){
//        int SIZE = 5000;
//        int randInt,randInt2,range = 50000;
//        for(int i=0; i<SIZE; i++){
//            randInt = rand()%range;
//            randInt2 = rand()%range;
//            insertedNumbers->insert(std::make_pair(randInt,randInt2));
//            if(i<SIZE/2 && i > SIZE/5){
//                toDelete->insert(std::make_pair(randInt,randInt2));
//            }
//        }

//    }
//    void findAllFrom(std::map<int,int> &map,bool shouldExist){
//        for(auto it : map){
//            auto found = myMap->findKey(it.first);

//            if(shouldExist)
//                assert(found);
//            else
//                assert(!found);
//        }
//    }


//public:
//    Test(){
//        beforeEach();
//    }
//    void removeFromMap(std::map<int,int> &map){
//        for(auto it : map){
//            myMap->removeKey(it.first);

//        }
//    }


//    ~Test(){
//        afterEach();
//    }


//};

//class InsertTest : public Test{
//public:
//    InsertTest()
//        : Test(){
//            insert();
//            findAllFrom(*this->insertedNumbers,true);
//    }



//};
//class RemoveTest : public Test{
//public:
//    RemoveTest()
//        : Test(){
//            insert();
//            removeFromMap(*this->toDelete);
//            findAllFrom(*notDeleted,true);
//            findAllFrom(*toDelete,false);
//    }
//};

int main()
{
    std::ios_base::sync_with_stdio(false);
    InsertTest insertTest;
    RemoveTest removeTest;


    return 0;
}
