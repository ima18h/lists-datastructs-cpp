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
    int length();
};

LinkedList::LinkedList() : head(nullptr), tail(nullptr), len(1)
{
}

int LinkedList::length() {
    return len;
}



int main(){

    return 0;
}
