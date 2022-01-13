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

// --------------------------- CircLinkedList class ---------------------------------
// TODO: wanted to make a doubly linked list with both tail and head
// has a node pointer to the head of the list. The list should start empty, with the head pointer pointing to a nullptr.
// If the list only has one element, it should point at itself. If the list has two or more elements, the last element should point back at the first.
class CircLinkedList {
 private:
  Node *head;
  // tail for circular list is other side of circle. if even number, it should be closer to "back"
  // don't have time to implement this right now though
  Node *tail;
  int len;
  Node* node_index(int);

 public:
  CircLinkedList();
  explicit CircLinkedList(vector<int> &);
  explicit CircLinkedList(int);
  ~CircLinkedList();
  int &operator[](int);
  int length() const;
  void append(int);
  void print();
  void remove(int);
  int pop(int);
  int pop();
  void insert(int, int);
  vector<int> josephus_sequence(int);
};

// linked list method definitions, implementation ---------------------------------
// constructors, destructors ---------------------------------
CircLinkedList::CircLinkedList() : head(nullptr), tail(nullptr), len(0) {
}

// TODO: solve Josephus Problem
CircLinkedList::CircLinkedList(int n) {
    // not implemented. init with 1 to n
}

// constructor takes a vector and makes a linked lsit from the values
CircLinkedList::CircLinkedList(vector<int> &values) {
  // this constructor could probably just use append() instead
  if (values.empty()) {
    len = 0;
    head = nullptr;
    tail = nullptr;
  } else if (values.size() == 1) {
    head = new Node(values[0], head, head);
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
    head->prev = tail;
    tail->next = head;
    // TODO: optimize setting tail. can do for loop, set tail, then new for loop
    tail = this->node_index(len / 2);
  }
}

CircLinkedList::~CircLinkedList() {
  if (len == 0) {
  } else if (len == 1) {
    delete head;
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
int CircLinkedList::length() const {
  return len;
}
int &CircLinkedList::operator[](int index) {
  return node_index(index)->data;
}
void CircLinkedList::append(int intnum) {
  if (head == nullptr) {
    head = new Node(intnum, head, head);
  } else if (len == 1) {
    head->next = new Node(intnum, head, head);
    tail = head->next;
    head->prev = tail;
  } else{
    Node *pre = head->prev;
    head->prev = new Node(intnum, pre, head);
    pre->next = head->prev;
    // TODO: optimize setting tail.
    tail = this->node_index(len / 2);
  }
  len += 1;
}
void CircLinkedList::print() {
  Node* current = head;
  cout << "[";
  for (int i = 0; i < len-1; ++i) {
    cout << current->data;
    cout << ", ";
    current = current->next;
  }
  cout << current->data << "]" << endl;
}
void CircLinkedList::remove(int i) {
  Node* redacted = node_index(i);
  redacted->prev->next = redacted->next;
  redacted->next->prev = redacted->prev;
  delete redacted;
  len -= 1;
}
Node* CircLinkedList::node_index(int index) {
  // TODO: implement for circular
  int half = len / 4;
  if (len == 0) {
    throw range_error("IndexError: list is empty");
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
int CircLinkedList::pop(int i) {
  // TODO: needs some if checks for edge cases
  Node* redacted = node_index(i);
  auto val = redacted->data;
  redacted->prev->next = redacted->next;
  redacted->next->prev = redacted->prev;
  delete redacted;
  len -= 1;
  return val;
}
int CircLinkedList::pop() {
  // not working
  auto val = head->prev->data;
  Node* temp = head->prev->prev;
  head->prev->prev->next = head;
  delete head->prev;
  tail = temp;
  len -= 1;
  return val;
}
// inserts after given node index
// TODO: change it so insert is before the index element (already have append)
void CircLinkedList::insert(int val, int index) {
  if (index == len-1)
    append(val);
  else {
    Node *insert_here = node_index(index);
    insert_here->next->prev = new Node(val, insert_here, insert_here->next);
    insert_here->next = insert_here->next->prev;
    len += 1;
  }
}

/*
  * This method should start at the head,
  * and iterate through the linked list,
  * removing every k’th element,
  * and adding them to a vector, until the linked list is empty.
  */
vector<int> CircLinkedList::josephus_sequence(int k) {
    //TODO
    return {};
}

int last_man_standing(int n, int k) {
    /*
     * This function should use the CircLinkedList class to solve the
     * original Josephus’ problem stated by Ball and Coxeter.
     */
}

// main for testing purposes -----------------------------------------------------------
int main() {
  vector<int> v = {88, 2, 3};
  CircLinkedList list(v);
  list.print();
  cout << "length after instantiation with vector [88,2.3]: " << list.length() << endl;

  list.append(99);
  list.print();
  cout << "new length after append: " << list.length() << endl;

  cout << "list at index 3: " << list[3] << endl;

  //list.pop();
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
