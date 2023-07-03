#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node *next) : val(x), prev(nullptr), next(next) {}
    Node(int x, Node *next, Node *prev) : val(x), prev(prev), next(next) {}
};

class MyLinkedList {
private:
    Node *head;
    Node *tail;
    int len;

public:
    MyLinkedList(){
        head = new Node();
        tail = head;
        len = 0;
    }
    
    int get(int index) {
        Node* x = getNode(index);
        return (x) ? x->val : -1;
    }

    Node* getNode(int index) {
        // index out of bounds
        if(index > len-1 || index < 0) return nullptr;

        
        Node* res;
        // go from front
        if(index < len/2){
            res = head;
            for(int i = 0; i < index; i++){
                res = res->next;
            }
            return res;
        }

        // go from back
        res = tail;
        for(int i = len; i > index+1; i--){
            res = res->prev;
        }
        return res;
    }

    int size() {
        return len;
    }

    string toString(){
        string s;
        Node* it = head;
        for(int i = 0; i < len; i++){
            s.append(to_string(it->val) + ", ");
            it = it->next;
        }
        return s.substr(0, s.length()-2);
    }
    
    void addAtHead(int val) {
        // adding first element
        if(len == 0){
            head->val = val;
            len++;
            return;
        }

        head = new Node(val, head);
        head->next->prev = head;
        len++;
    }
    
    void addAtTail(int val) {
        // adding first element
        if(len == 0){
            tail->val = val;
            len++;
            return;
        }

        tail = new Node(val, nullptr, tail);
        tail->prev->next = tail;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        // index out of bounds
        if(index > len || index < 0) return;
        // add to head
        if(index == 0){
            addAtHead(val);
            return;
        }
        // add to tail
        if(index == len){
            addAtTail(val);
            return;
        }

        Node* node = getNode(index);
        Node* x = new Node(val, node, node->prev);
        if(index == 0) head = x;
        else node->prev->next = x;
        node->prev = x;
        len++;
    }
    
    void deleteAtIndex(int index) {
        // index out of bounds
        if(index > len-1 || index < 0) return;

        Node* node = getNode(index);
        // first index
        if(index == 0) head = node->next;
        else node->prev->next = node->next;
        // last index
        if(index == len-1) tail = node->prev;
        else node->next->prev = node->prev;
        
        delete node;
        len--;
    }
};


void test(vector<string> cmd, vector<vector<int>> param){
    MyLinkedList myLinkedList;
    vector<string> out;
    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i] == "MyLinkedList") myLinkedList = MyLinkedList();
        else if(cmd[i] == "addAtHead") myLinkedList.addAtHead(param[i][0]);
        else if(cmd[i] == "addAtTail") myLinkedList.addAtTail(param[i][0]);
        else if(cmd[i] == "addAtIndex") myLinkedList.addAtIndex(param[i][0], param[i][1]);
        else if(cmd[i] == "deleteAtIndex") myLinkedList.deleteAtIndex(param[i][0]);
        else{
            out.push_back(to_string(myLinkedList.get(param[i][0])));
            continue;
        }
        out.push_back("null");
        cout << myLinkedList.toString() << endl;
    }
    cout << "==============================" << endl;
    for(string x : out) cout << x << ", ";
}

int main()
{   
    // vector<string> a = {"MyLinkedList","addAtHead","addAtTail","addAtHead","addAtTail","addAtHead","addAtHead","get","addAtHead","get","get","addAtTail"};
    // vector<vector<int>> b = {{},{7},{7},{9},{8},{6},{0},{5},{0},{2},{5},{4}};
    // null, null, null, null, null, null, null, 8, null, 6, 7, null

    // vector<string> a = {"MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"};
    // vector<vector<int>> b = {{},{2},{1},{2},{7},{3},{2},{5},{5},{5},{6},{4}};
    // null, null, null, null, null, null, null, null, null, 2, null, null

    vector<string> a = {"MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"};
    vector<vector<int>> b = {{},{7},{2},{1},{3,0},{2},{6},{4},{4},{4},{5,0},{6}};
    // null,null,null,null,null,null,null,null,4,null,null,null

    test(a, b);
}