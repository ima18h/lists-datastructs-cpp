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
  Node* node_index(int);
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
    // does this for empty vector work?
    LinkedList();
  } else if (values.size() == 1) {
    head = new Node(values[0]);
    len = 1;
  } else {
    len = int(values.size());
    head = new Node(values[0]);
    tail = new Node(values[1], head);
    values.erase(values.begin(), values.begin()+1);
    for (int i: values)
      tail = new Node(values[i], tail);
  }
}

LinkedList::~LinkedList() {
  if (head == nullptr) {
  } else if (len == 1) {
    delete[] head;
  } else {
    Node* current;
    current = head;
    while (current->next != nullptr) {
      current = current->next;
      delete[] head;
    }
  }
}

int LinkedList::length() {
  return len;
}
int &LinkedList::operator[](int index) {
  return node_index(index)->data;
}
void LinkedList::append(int intnum) {
  if (head == nullptr) {
    head = new Node(intnum);
    return;
  }

  tail->next = new Node(intnum, tail);
  tail = tail->next;
  len += 1;
}
void LinkedList::print() {
  Node* current = head;
  cout << "[";
  while (current->next != nullptr) {
    cout << current->data;
    cout << ", ";
    current = current->next;
  }
  cout << current->data << "]" << endl;
}
void LinkedList::remove(int i) {
  Node* redacted = node_index(i);
  redacted->prev->next = redacted->next;
  redacted->next->prev = redacted->prev;
  delete redacted;
  len -= 1;
}
Node* LinkedList::node_index(int index) {
  int half = int(len - 1 / 2);
  if (index >= len || index < 0) {
    throw range_error("IndexError: Index out of range");
  } else if (index > half) {
    int jumps = len - index;
    Node *current = tail;
    for (int i = 0; i < jumps; ++i) {
      current = current->prev;
    }
    return current;
  } else {
    Node *current = head;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }
    return current;
  }
}
int LinkedList::pop(int i) {
  // TODO: needs some if checks for edge cases
  Node* redacted = node_index(i);
  auto val = redacted->data;
  redacted->prev->next = redacted->next;
  redacted->next->prev = redacted->prev;
  delete redacted;
  len -= 1;
  return val;
}
int LinkedList::pop() {
  auto val = tail->data;
  Node* temp = tail->prev;
  tail->prev->next = nullptr;
  delete tail;
  tail = temp;
  len -= 1;
  return val;
}

// main for testing purposes -----------------------------------------------------------
int main() {
  LinkedList list;
  list.length();
  cout << list.length() << endl;

  for (int i = 0; i < 1; ++i) {
    cout << i << "\n";
  }
  return 0;
}
