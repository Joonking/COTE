#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;

    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* lastNode = tail->prev;
        removeNode(lastNode);
        return lastNode;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            if (cache.size() == capacity) {
                Node* tail_node = popTail();
                cache.erase(tail_node->key);
                delete tail_node;
            }
            cache[key] = newNode;
            addNode(newNode);
        }
    }
};

vector<int> simulateQueries(int cacheSize, vector<string> queries) {
    vector<int> result;

    if (cacheSize == 0) {
        for (const auto& query : queries) {
            if (query.substr(0, 3) == "GET") {
                result.push_back(-1);
            }
        }
        return result;
    }

    LRUCache lru(cacheSize);

    for (const auto& query : queries) {
        if (query.empty()) continue;

        istringstream iss(query);
        string operation;
        iss >> operation;

        if (operation == "GET") {
            int key;
            if (!(iss >> key)) continue;
            result.push_back(lru.get(key));
        } else if (operation == "PUT") {
            int key, value;
            if (!(iss >> key >> value)) continue;
            lru.put(key, value);
        }
    }

    return result;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string cacheSize_temp;
    getline(input, cacheSize_temp);
    int cacheSize = stoi(cacheSize_temp);

    string queries_count_temp;
    getline(input, queries_count_temp);
    int queries_count = stoi(queries_count_temp);

    vector<string> queries(queries_count);
    for (int i = 0; i < queries_count; i++) {
        getline(input, queries[i]);
    }

    vector<int> result = simulateQueries(cacheSize, queries);

    for (size_t i = 0; i < result.size(); i++) {
        output << result[i];
        if (i != result.size() - 1) {
            output << "\n";
        }
    }

    if (!result.empty()) { // 수정: 마지막 개행 추가
        output << "\n";
    }

    output.close();

    return 0;
}