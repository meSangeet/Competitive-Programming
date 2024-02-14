#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[2];
    TrieNode() : children{nullptr, nullptr} {}
};

void insert(TrieNode* root, int num) {
    TrieNode* current = root;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!current->children[bit]) {
            current->children[bit] = new TrieNode();
        }
        current = current->children[bit];
    }
}

int findMaxXOR(TrieNode* root, int num) {
    TrieNode* current = root;
    int result = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (current->children[1 - bit]) {
            result |= (1 << i);
            current = current->children[1 - bit];
        } else {
            current = current->children[bit];
        }
    }
    return result;
}

int max_xor_optimized(const vector<int>& A) {
    TrieNode* root = new TrieNode();
    int maxXOR = 0;
    int preXOR = 0;

    for (int num : A) {
        preXOR ^= num;
        insert(root, preXOR);
        maxXOR = max(maxXOR, findMaxXOR(root, preXOR));
    }

    return maxXOR;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int max_xor_value = max_xor_optimized(A);
        cout << max_xor_value << endl;
    }

    return 0;
}