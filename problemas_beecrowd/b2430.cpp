// https://www.beecrowd.com.br/judge/pt/problems/view/2430

#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(x) cout << #x << " = " << x << endl
#define endl "\n"
#define INF 1'000'000

typedef unsigned uint;

template <typename T>
class TrieNode {
public:
    T item;
    uint leafs;
    uint size_below;
    uint value;
    bool visited;

    TrieNode() {
        leafs = depth = size_below = value = 0;
        visited = false;
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

    vector<TrieNode<T> *> children() {
        vector<TrieNode<T> *> c;
        for (const auto &[key, child] : m_children)
            c.push_back(child);
        return c;
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

    void add(Container &elements) {
        TrieNode<Element> *node = root;
        vector<TrieNode<Element> *> nodes {root};

        for (Element &el : elements) {
            node->leafs++;
            node = node->get_or_create_child(el);
            nodes.push_back(node);
        }

        vector<uint> sizes(nodes.size(), 0);

        for (int i = nodes.size() - 2; i >= 0; i--) {
            sizes[i] = sizes[i + 1] + nodes[i + 1]->item.size() + (i != nodes.size() - 2);
            nodes[i]->size_below += sizes[i];
        }
    }

    uint calculate_min_node() {
        stack<TrieNode<Element> *> stack;

        TrieNode<Element> *node_before;
        for (TrieNode<Element> *child : root->children()) {
            child->value = root->size_below - child->leafs * (child->item.size() + (child->get_number_of_children() != 0))
                    + (root->leafs - child->leafs) * 3;
            stack.push(child);
        }

        uint min_node_value {root->size_below};

        while (not stack.empty()) {
            auto node = stack.top();
            stack.pop();

            min_node_value = min(min_node_value, node->value);

            for (TrieNode<Element> *child : node->children()) {
                if (child->visited or not child->get_number_of_children())
                    continue;
                stack.push(child);
                child->visited = true;
                child->value = node->value + (root->leafs - child->leafs) * 3 - (child->item.size() + 1) * child->leafs;
            }
        }

        return min_node_value;
    }
};

vector<string> split(const string& s, const string& pattern) {
    vector<string> splited;
    for (uint i {0}; i < s.length(); ) {
        uint nextPos = s.find(pattern, i);
        splited.push_back(s.substr(i, nextPos - i));
        if (nextPos == UINT32_MAX)
            break;
        i = nextPos + pattern.length();
    }

    return splited;
}

int main() { _
    Trie<vector<string>, string> trie;
    uint n; cin >> n;

    while (n--) {
        string path; cin >> path;
        vector<string> dir = split(path, "/");
        trie.add(dir);
    }

    cout << trie.calculate_min_node() << endl;
    
    return 0;
}
