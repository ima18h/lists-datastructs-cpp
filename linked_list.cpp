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

Node::Node(int i, Node *n) : data(i), next(n), prev(nullptr) {
}

Node::Node(int i, Node *n, Node *p) : data(i), next(n), prev(p) {
}

// --------------------------- linkedlist class ---------------------------------
class LinkedList {
 private:
  Node *head;
  Node *tail;
  int len;
 public:
  LinkedList();
  explicit LinkedList(const vector<int> &);
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

LinkedList::LinkedList(const vector<int> &values) {
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
