#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int value) : val(value), next(nullptr) {}
    Node(int value, Node *next) : val(value), next(next) {}
};


struct Bucket
{
    Node *head;
    Node *tail;
    int size;

    Bucket() : head(nullptr), tail(head), size(0) {}

    bool add(int val){
        if(find(val)) return false;

        if(size == 0){
            head = new Node(val);
            tail = head;
            size++;
            return true;
        }

        tail->next = new Node(val);
        tail = tail->next;
        size++;
        return true;
    }

    bool remove(int val){
        if(!head) return false;

        if(head->val == val){
            Node *del = head;
            head = head->next;
            delete del;
            size--;
            return true;
        }

        Node *it = head;

        while(it && it->next){
            if(it->next->val == val){
                Node *del = it->next;
                if(del == tail) tail = it;
                it->next = it->next->next;
                delete del;
                size--;
                return true;
            }
            else it = it->next;
        }

        return false;
    }

    Node* find(int val){
        Node *it = head;

        while(it){
            if(it->val == val) return it;
            it = it->next;
        }
        
        return nullptr;
    }
};



class RandomizedSet {
private:
    int hashFunctionSize;
    vector<Bucket> buckets;
public:
    RandomizedSet() {
        hashFunctionSize = 8;
        buckets = *(new vector<Bucket>(hashFunctionSize));
    }
    
    bool insert(int val) {
        return buckets[abs(val%hashFunctionSize)].add(val);
    }
    
    bool remove(int val) {
        return buckets[abs(val%hashFunctionSize)].remove(val);
    }
    
    int getRandom() {
        int r = rand() % hashFunctionSize;
        bool left = rand() % 2 == 1;

        // find non empty bucket
        while(!buckets[r].head) {
            r = r - left + !left;
            if(r == -1) r = hashFunctionSize-1;
            else if(r == hashFunctionSize) r = 0;
        }

        return (left) ? buckets[r].head->val : buckets[r].tail->val;
    }
};


void test(vector<string> cmd, vector<int> par){
    RandomizedSet set;
    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i] == "insert") set.insert(par[i]);
        else if(cmd[i] == "remove") set.remove(par[i]);
        else if(cmd[i] == "getRandom") cout << set.getRandom() << ", ";
        else if(cmd[i] == "RandomizedSet") set = *(new RandomizedSet());
    }
    cout << endl;
}


int main()
{
    vector<string> a = {"RandomizedSet","insert","getRandom","getRandom","getRandom","insert","insert","insert","insert","insert","getRandom","getRandom","insert","getRandom","insert","insert","getRandom","getRandom","getRandom","getRandom","remove","insert","getRandom","getRandom","insert","remove","remove","insert","getRandom","getRandom","insert","insert","getRandom","remove","remove","insert","remove","getRandom","getRandom","remove","getRandom","insert","insert","getRandom","remove","remove","remove","getRandom","insert","insert","insert","insert","getRandom","insert","getRandom","remove","insert","insert","insert","getRandom","getRandom","insert","getRandom","insert","insert","getRandom","getRandom","remove","getRandom","remove","insert","getRandom","insert","insert","insert","getRandom","insert","insert","getRandom","insert","getRandom","insert","getRandom","getRandom","getRandom","insert","getRandom","getRandom","insert","insert","insert","getRandom","remove","insert","insert","getRandom","insert","insert","insert","insert"};
    vector<int> b = {{},{-7},{},{},{},{6},{7},{10},{3},{8},{},{},{-8},{},{6},{-8},{},{},{},{},{2},{2},{},{},{5},{-5},{-8},{-8},{},{},{-4},{10},{},{7},{-1},{8},{-6},{},{},{9},{},{7},{0},{},{-10},{-4},{-3},{},{-4},{-5},{8},{-2},{},{-9},{},{7},{-2},{7},{4},{},{},{-6},{},{-8},{2},{},{},{9},{},{-1},{3},{},{0},{-3},{-1},{},{-8},{-10},{},{3},{},{4},{},{},{},{-10},{},{},{0},{-2},{5},{},{-2},{5},{10},{},{9},{0},{7},{-2}};
    test(a, b);

    return 0;
}