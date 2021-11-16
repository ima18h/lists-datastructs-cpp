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
  int length() const;
  void append(int);
  void print();
  void remove(int);
  int pop(int);
  int pop();
  void insert(int val, int index);
};

// linked list method definitions, implementation ---------------------------------
// constructors, destructors ---------------------------------
LinkedList::LinkedList() : head(nullptr), tail(nullptr), len(0) {
}

// constructor takes a vector and makes a linked lsit from the values
LinkedList::LinkedList(vector<int> &values) {
  // this constructor could probably just use append() instead
  if (values.empty()) {
    len = 0;
    head = nullptr;
    tail = nullptr;
  } else if (values.size() == 1) {
    head = new Node(values[0]);
    len = 1;
    tail = nullptr;
  } else {
    len = int(values.size());
    head = new Node(values[0]);
    head->next = new Node(values[1], head);
    tail = head->next;
    values.erase(values.begin(), values.begin()+2);
    for (int val: values) {
      tail->next = new Node(val, tail);
      tail = tail->next;
    }
  }
}

LinkedList::~LinkedList() {
  if (len == 0) {
  } else if (len == 1) {
    delete[] head;
  } else {
    Node* current = tail;
    for (int i = 0; i < len; ++i) {
      current = current->prev;
      delete tail;
      tail = current;
    }
  }
}

// methods ---------------------------------
int LinkedList::length() const {
  return len;
}
int &LinkedList::operator[](int index) {
  return node_index(index)->data;
}
void LinkedList::append(int intnum) {
  if (head == nullptr) {
    head = new Node(intnum);
  } else if (len == 1) {
    head->next = new Node(intnum, head);
    tail = head->next;
  } else{
    tail->next = new Node(intnum, tail);
    tail = tail->next;
  }
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
  int half = len / 2;
  if (index >= len || index < 0) {
    throw range_error("IndexError: Index out of range");
  } else if (index > half) {
    int jumps = (len - 1) - index;
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
// inserts after given node index
void LinkedList::insert(int val, int index) {
  if (index == len-1)
    append(val);
  else {
    Node *insert_here = node_index(index);
    insert_here->next->prev = new Node(val, insert_here, insert_here->next);
    insert_here->next = insert_here->next->prev;
    len += 1;
  }
}

// main for testing purposes -----------------------------------------------------------
int main() {
  vector<int> v = {88, 2, 3};
  LinkedList list(v);
  list.print();
  cout << "length after instantiation with vector [88,2.3]: " << list.length() << endl;

  list.append(99);
  list.print();
  cout << "new length after append: " << list.length() << endl;

  cout << "list at index 2: " << list[2] << endl;

  list.pop();
  list.print();
  cout << "new length after pop: " << list.length() << endl;

  list.append(69);
  list.append(96);
  list.append(100);
  list.append(111);
  cout << "new length after 4 appends: " << list.length() << endl;
  list.print();

  int index = list.length()/2;
  int popped = list.pop(index);
  list.print();
  cout << "new length after pop at index " << index << ": " << list.length() << ", which returns: " << popped << endl;

  list.remove(index);
  list.print();
  cout << "new length after remove at index " << index << ": " << list.length() << endl;

  list.insert(21, index-1);
  list.print();
  cout << "new length after insert at index " << index-1 << ": " << list.length() << endl;

  return 0;
}
