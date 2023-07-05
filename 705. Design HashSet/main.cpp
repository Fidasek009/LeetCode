#include <iostream>
#include <vector>

using namespace std;

struct Bucket
{
    vector<int> keys;
    Bucket() : keys() {}
};


class MyHashSet {
private:
    Bucket buckets[4096];
public:
    int hashFunctionSize;

    MyHashSet() {
        hashFunctionSize = 4096;
    }
    
    void add(int key) {
        if(contains(key)) return;

        buckets[key%hashFunctionSize].keys.push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        vector<int> *bucket = &buckets[key%hashFunctionSize].keys;

        for(int i = 0; i < bucket->size(); i++){
            if(bucket->at(i) == key) bucket->erase(bucket->begin()+i);
        }
    }
    
    bool contains(int key) {
        vector<int> *bucket = &buckets[key%hashFunctionSize].keys;
        for(int i = 0; i < bucket->size(); i++){
            if(bucket->at(i) == key) return true;
        }

        return false;
    }
};

int main()
{
    return 0;
}