//link: https://leetcode.com/problems/implement-trie-prefix-tree/

/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

/*
Result:
Runtime: 148 ms, faster than 34.19% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 43.8 MB, less than 56.67% of C++ online submissions for Implement Trie (Prefix Tree).
*/

class TrieNode{
    public:
        string word;
        TrieNode* next[26];
    public:
        TrieNode():word(""){
            memset(next, NULL, sizeof(TrieNode*) * 26);  
        }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *t = root;
        for(int i = 0; i < word.length(); i ++){
            if(t -> next[word[i] - 'a'] == NULL){
                t -> next[word[i] - 'a'] = new TrieNode();
            }
            t = t -> next[word[i] - 'a'];
        }
        if(t -> word == ""){
            t -> word = word;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *t = root;
        for(int i = 0; i < word.length(); i ++){
            if(t -> next[word[i] - 'a'] == NULL){
                return false;
            }
            t = t -> next[word[i] - 'a'];
        }
        return t -> word != "";
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *t = root;
        for(int i = 0; i < prefix.length(); i ++){
            if(t -> next[prefix[i] - 'a'] == NULL){
                return false;
            }
            t = t -> next[prefix[i] - 'a'];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */