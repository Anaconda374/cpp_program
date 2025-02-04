#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

struct TrieNode{
    std::unordered_map<char, TrieNode*> children;
    bool isEnd;
    
    TrieNode(){
        isEnd = false;
    }       
};

class Trie{
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    void producirTrie(std::vector<std::string>& cadenaVec, 
                    TrieNode* node, std::string corrPalabra) {
    // Check if the current node represents the end of a word
        if (node->isEnd) {
             cadenaVec.push_back(corrPalabra);
        }
    // Traverse all children of the current node
        for (const auto& child : node->children) {
            char nextChar = child.first;
            TrieNode* nextNode = child.second;
        
        // Recursively traverse the child node
            producirTrie(cadenaVec,nextNode, corrPalabra + nextChar);
        }
    }

};

    void producirTrie(std::vector<std::string>& cadenaVec, 
                    TrieNode* node, std::string corrPalabra) {
    // Check if the current node represents the end of a word
        if (node->isEnd) {
             cadenaVec.push_back(corrPalabra);
        }
    // Traverse all children of the current node
        for (const auto& child : node->children) {
            char nextChar = child.first;
            TrieNode* nextNode = child.second;
        
        // Recursively traverse the child node
            producirTrie(cadenaVec,nextNode, corrPalabra + nextChar);
        }
    }


int main()
{
    Trie t = Trie();
    t.insert("kuan");
    t.insert("anacs");
    t.insert("akun");

    std::vector<std::string> cadenaVec;

    producirTrie(cadenaVec, t.root, "");

    for(auto s : cadenaVec){
        std::cout<<s<<std::endl;
    }

}
