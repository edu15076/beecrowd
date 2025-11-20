// https://www.beecrowd.com.br/judge/pt/problems/view/2087

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"

typedef unsigned uint;

template <typename T>
class TrieNode {
public:
    T item;
    bool is_end_point;

    TrieNode() {
        is_end_point = false;
    };

    TrieNode(const T &item) : TrieNode() {
        this->item = T(item);
    }

    TrieNode<T> *create_child(const T &child_item) {
        auto *child = new TrieNode<T>(child_item);
        m_children[child->item] = child;
        return child;
    }

    bool has_child(const T &child_item) {
        return m_children.contains(child_item);
    }

    TrieNode<T> *get_child(const T &child_item) {
        if (not has_child(child_item))
            return nullptr;
        return m_children[child_item];
    }

    TrieNode<T> *get_or_create_child(const T &child_item) {
        if (has_child(child_item))
            return get_child(child_item);
        return create_child(child_item);
    }

    size_t get_number_of_children() {
        return m_children.size();
    }

    TrieNode<T> *erase_child(const T &child_item) {
        auto child = get_child(child_item);
        m_children.erase(child_item);
        return child;
    }

    void delete_child(const T &child_item) {
        auto child = erase_child(child_item);
        delete child;
    }

    ~TrieNode() {
        for (auto& [key, child] : m_children)
            delete child;
    }

private:
    map<T, TrieNode *> m_children;
};

template <typename Container, typename Element>
class Trie {
protected:
    TrieNode<Element> *root;

public:
    Trie() {
        root = new TrieNode<Element>();
    }

    bool add(Container &elements) {
        TrieNode<Element> *node = root;

        for (Element &el : elements) {
            node = node->get_or_create_child(el);
            if (node->is_end_point)
                return false;
        }
        if (node->get_number_of_children())
            return false;
        node->is_end_point = true;
        return true;
    }
};

int main() { _
    uint n;
    while (cin >> n and n) {
        Trie<string, char> trie;
        bool good {true};
        for (uint i {0}; i < n; i++) {
            string s; cin >> s;
            if (good)
                good = trie.add(s);
        }
        cout << "Conjunto " << (good ? "Bom" : "Ruim") << endl;
    }
    
    return 0;
}
