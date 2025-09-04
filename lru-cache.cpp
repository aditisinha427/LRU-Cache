#include <bits/stdc++.h>
using namespace std;

// Doubly linked list
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

// LRU Cache class
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; 
    Node* tail; 

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtFront(Node* node) {
        Node* first = head->next;
        head->next = node;
        node->prev = head;
        node->next = first;
        first->prev = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];
        removeNode(node);
        insertAtFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            insertAtFront(node);
            return;
        }

        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            removeNode(lru);
            delete lru;
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        insertAtFront(node);
    }
};

// CLI driver code
int main() {
    int capacity;
    cout << "Enter cache capacity: ";
    cin >> capacity;

    LRUCache lru(capacity);

    string command;
    cout << "Enter commands (PUT key value / GET key / EXIT):\n";

    while (true) {
        cin >> command;
        if (command == "PUT") {
            int key, value;
            cin >> key >> value;
            lru.put(key, value);
            cout << "Inserted (" << key << ", " << value << ")\n";
        } 
        else if (command == "GET") {
            int key;
            cin >> key;
            int result = lru.get(key);
            if (result == -1) cout << "Key not found\n";
            else cout << "Value: " << result << "\n";
        } 
        else if (command == "EXIT") {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}
