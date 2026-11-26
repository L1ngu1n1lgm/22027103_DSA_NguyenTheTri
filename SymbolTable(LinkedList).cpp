#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <typename Key, typename Value>
class LinkedListST {
private:
    struct Node {
        Key key;
        Value val;
        Node* next;
        Node(const Key& k, const Value& v, Node* n) : key(k), val(v), next(n) {}
    };

    Node* head = nullptr;
    int n = 0;

public:
    LinkedListST() = default;
    ~LinkedListST() { clear(); }

    LinkedListST(const LinkedListST&) = delete;
    LinkedListST& operator=(const LinkedListST&) = delete;

    int size() const { return n; }
    bool isEmpty() const { return n == 0; }


    Value* get(const Key& key) {
        for (Node* x = head; x != nullptr; x = x->next)
            if (x->key == key) return &x->val;
        return nullptr;
    }

    bool contains(const Key& key) { return get(key) != nullptr; }


    void put(const Key& key, const Value& val) {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key) {
                x->val = val;
                return;
            }
        }
        head = new Node(key, val, head);
        n++;
    }


    bool remove(const Key& key) {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur != nullptr && !(cur->key == key)) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) return false;   

        if (prev == nullptr) head = cur->next;  
        else prev->next = cur->next;
        delete cur;
        n--;
        return true;
    }

    std::vector<Key> keys() const {
        std::vector<Key> result;
        for (Node* x = head; x != nullptr; x = x->next)
            result.push_back(x->key);
        return result;
    }

    void clear() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        n = 0;
    }
};

int main() {
    LinkedListST<std::string, int> st;

    std::string words[] = {"S", "E", "A", "R", "C", "H", "E", "X", "A", "M", "P", "L", "E"};
    for (const auto& w : words) {
        int* v = st.get(w);
        st.put(w, v ? *v + 1 : 1);
    }

    std::cout << "size = " << st.size() << "\n";
    for (const auto& k : st.keys())
        std::cout << k << " -> " << *st.get(k) << "\n";

    st.remove("E");
    st.remove("S");
    std::cout << "\nSau khi xoa E, S: size = " << st.size() << "\n";
    std::cout << "contains(E)? " << (st.contains("E") ? "yes" : "no") << "\n";
    std::cout << "contains(A)? " << (st.contains("A") ? "yes" : "no") << "\n";
    return 0;
}
