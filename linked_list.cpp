#include <iostream>
#include <vector>
using namespace std;

// node, structure ---------------------------------------------------------------
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;

  explicit Node(int i);
  Node(int i, Node *);
  Node(int i, Node *, Node *);
};

// node method definitions ---------------------------------------------------------------
Node::Node(const int i) : data(i), next(nullptr), prev(nullptr) {
}

Node::Node(int i, Node *p) : data(i), prev(p), next(nullptr) {
}

Node::Node(int i, Node *p, Node *n) : data(i), prev(p), next(n) {
}

// --------------------------- linkedlist class ---------------------------------
class LinkedList {
 private:
  Node *head;
  Node *tail;
  int len;
 public:
  LinkedList();
  explicit LinkedList(vector<int> &);
  ~LinkedList();
  int &operator[](int);
  int length();
  void append(int);
  void print();
  void remove(int);
  int pop(int);
  int pop();

};

// linked list method definitions, implementation ---------------------------------
LinkedList::LinkedList() : head(nullptr), tail(nullptr), len(0) {
}

LinkedList::LinkedList(vector<int> &values) {
  if (values.empty()) {
  } else if (values.size() == 1) {
    head = new Node(values[0]);
  } else {
    head = new Node(values[0]);
    tail = new Node(values[1], head);
    values.erase(values.begin(), values.begin()+1);
    for (int i: values)
      tail = new Node(values[i], tail);
  }
}

int LinkedList::length() {
  return len;
}

// main for testing purposes -----------------------------------------------------------
int main() {
  LinkedList list;
  list.length();
  cout << list.length() << endl;
  return 0;
}
