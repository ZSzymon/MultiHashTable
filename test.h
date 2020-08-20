#ifndef TEST_H
#define TEST_H
#include "MultiHashTable.h"
#include <iostream>

class Test{
protected:
    MultiHashTable<int,int> *myMap;
    std::map<int,int> *insertedNumbers,*toDelete,*notDeleted;
    void beforeEach(){
        myMap = new MultiHashTable<int,int>();
        insertedNumbers = new std::map<int,int>();
        toDelete = new std::map<int,int>();
        notDeleted = new std::map<int,int>();
        prepareNumbersToInsertAndDelete();
    }
    void afterEach(){
        delete myMap;
        delete insertedNumbers;
        delete toDelete;
        delete notDeleted;
    }
    void insert(){
        for(auto it : *this->insertedNumbers){
            myMap->insert(it.first,it.second);
        }
    }
    void prepareNumbersToInsertAndDelete(){
        int SIZE = 5000;
        int randInt,randInt2,range = 50000;
        for(int i=0; i<SIZE; i++){
            randInt = rand()%range;
            randInt2 = rand()%range;
            insertedNumbers->insert(std::make_pair(randInt,randInt2));
            if(i<SIZE/2 && i > SIZE/5){
                toDelete->insert(std::make_pair(randInt,randInt2));
            }
        }

    }
    void findAllFrom(std::map<int,int> &map,bool shouldExist){
        for(auto it : map){
            auto found = myMap->findKey(it.first);

            if(shouldExist)
                assert(found);
            else
                assert(!found);
        }
    }


public:
    Test(){
        beforeEach();
    }
    void removeFromMap(std::map<int,int> &map){
        for(auto it : map){
            myMap->removeKey(it.first);

        }
    }


    ~Test(){
        afterEach();
    }


};

class InsertTest : public Test{
public:
    InsertTest()
        : Test(){
            insert();
            findAllFrom(*this->insertedNumbers,true);
    }



};
class RemoveTest : public Test{
public:
    RemoveTest()
        : Test(){
            insert();
            removeFromMap(*this->toDelete);
            findAllFrom(*notDeleted,true);
            findAllFrom(*toDelete,false);
    }
};

#endif // TEST_H
