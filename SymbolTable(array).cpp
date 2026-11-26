#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

template <typename Key, typename Value>
class ArrayST {
private:
    Key* keysArr;
    Value* vals;
    int n = 0;
    int capacity;

    void resize(int newCap) {
        Key* newKeys = new Key[newCap];
        Value* newVals = new Value[newCap];
        for (int i = 0; i < n; i++) {
            newKeys[i] = keysArr[i];
            newVals[i] = vals[i];
        }
        delete[] keysArr;
        delete[] vals;
        keysArr = newKeys;
        vals = newVals;
        capacity = newCap;
    }

public:
    explicit ArrayST(int cap = 2) : capacity(cap) {
        keysArr = new Key[capacity];
        vals = new Value[capacity];
    }
    ~ArrayST() {
        delete[] keysArr;
        delete[] vals;
    }

    ArrayST(const ArrayST&) = delete;
    ArrayST& operator=(const ArrayST&) = delete;

    int size() const { return n; }
    bool isEmpty() const { return n == 0; }

    int rank(const Key& key) const {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < keysArr[mid]) hi = mid - 1;
            else if (keysArr[mid] < key) lo = mid + 1;
            else return mid;
        }
        return lo;
    }

    Value* get(const Key& key) {
        if (isEmpty()) return nullptr;
        int i = rank(key);
        if (i < n && keysArr[i] == key) return &vals[i];
        return nullptr;
    }

    bool contains(const Key& key) { return get(key) != nullptr; }

    void put(const Key& key, const Value& val) {
        int i = rank(key);
        if (i < n && keysArr[i] == key) {
            vals[i] = val;
            return;
        }
        if (n == capacity) resize(2 * capacity);

        for (int j = n; j > i; j--) {
            keysArr[j] = keysArr[j - 1];
            vals[j] = vals[j - 1];
        }
        keysArr[i] = key;
        vals[i] = val;
        n++;
    }

    bool remove(const Key& key) {
        if (isEmpty()) return false;
        int i = rank(key);
        if (i == n || !(keysArr[i] == key)) return false;
        // dịch trái để lấp chỗ trống
        for (int j = i; j < n - 1; j++) {
            keysArr[j] = keysArr[j + 1];
            vals[j] = vals[j + 1];
        }
        n--;
        if (n > 0 && n == capacity / 4) resize(capacity / 2);
        return true;
    }


    const Key& min() const {
        if (isEmpty()) throw std::underflow_error("ST rong");
        return keysArr[0];
    }
    const Key& max() const {
        if (isEmpty()) throw std::underflow_error("ST rong");
        return keysArr[n - 1];
    }
    const Key& select(int k) const {   
        if (k < 0 || k >= n) throw std::out_of_range("select: k khong hop le");
        return keysArr[k];
    }

    bool floor(const Key& key, Key& out) const {
        int i = rank(key);
        if (i < n && keysArr[i] == key) { out = keysArr[i]; return true; }
        if (i == 0) return false;
        out = keysArr[i - 1];
        return true;
    }

    bool ceiling(const Key& key, Key& out) const {
        int i = rank(key);
        if (i == n) return false;
        out = keysArr[i];
        return true;
    }

    void deleteMin() {
        if (isEmpty()) throw std::underflow_error("ST rong");
        remove(min());
    }
    void deleteMax() {
        if (isEmpty()) throw std::underflow_error("ST rong");
        remove(max());
    }


    int size(const Key& lo, const Key& hi) const {
        if (hi < lo) return 0;
        int r = rank(hi) - rank(lo);
        if (rank(hi) < n && keysArr[rank(hi)] == hi) r++;   
        return r;
    }

    std::vector<Key> keys() const {
        return std::vector<Key>(keysArr, keysArr + n);
    }


    std::vector<Key> keys(const Key& lo, const Key& hi) const {
        std::vector<Key> result;
        if (hi < lo) return result;
        for (int i = rank(lo); i < n && !(hi < keysArr[i]); i++)
            result.push_back(keysArr[i]);
        return result;
    }
};

int main() {
    ArrayST<std::string, int> st;


    std::string words[] = {"S", "E", "A", "R", "C", "H", "E", "X", "A", "M", "P", "L", "E"};
    for (int i = 0; i < 13; i++) st.put(words[i], i);


    std::cout << "size = " << st.size() << "\n";
    for (const auto& k : st.keys())          
        std::cout << k << " " << *st.get(k) << "\n";

    std::cout << "\nmin = " << st.min() << ", max = " << st.max() << "\n";
    std::cout << "rank(M) = " << st.rank("M") << ", select(6) = " << st.select(6) << "\n";
    std::string f, c;
    if (st.floor("G", f)) std::cout << "floor(G) = " << f << "\n";
    if (st.ceiling("G", c)) std::cout << "ceiling(G) = " << c << "\n";
    std::cout << "size(D, M) = " << st.size("D", "M") << ", keys(D, M) =";
    for (const auto& k : st.keys("D", "M")) std::cout << " " << k;
    std::cout << "\n";

    st.deleteMin();
    st.deleteMax();
    st.remove("E");
    std::cout << "\nSau deleteMin, deleteMax, remove(E): size = " << st.size() << ", keys =";
    for (const auto& k : st.keys()) std::cout << " " << k;
    std::cout << "\n";
    return 0;
}
