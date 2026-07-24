class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* dummy;
    int size;

public:
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* curr = dummy->next;
        for (int i = 0; i < index; i++)
            curr = curr->next;

        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            index = 0;

        if (index > size)
            return;

        Node* prev = dummy;
        for (int i = 0; i < index; i++)
            prev = prev->next;

        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        Node* prev = dummy;
        for (int i = 0; i < index; i++)
            prev = prev->next;

        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;

        size--;
    }
};
