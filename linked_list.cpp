#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int len;
public:
    LinkedList();
    LinkedList(vector<int>);
    ~LinkedList();
    int& operator[](int);
    int length();
    void append(int);
    void print();
    void remove(int);
    int pop(int);
    int pop();

};

LinkedList::LinkedList() : head(nullptr), tail(nullptr), len(0)
{
}

int LinkedList::length() {
    return len;
}



int main(){
    LinkedList list;
    list.length();
    cout << list.length() << endl;
    return 0;
}
