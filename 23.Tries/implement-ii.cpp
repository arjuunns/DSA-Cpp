#include <bits/stdc++.h> 
class Node{
    Node* links[26];
    int ends_with;
    int count_prefix;
    public : 
    Node(){
        for(int i = 0;i<26;i++) links[i] = nullptr;
        ends_with = 0;
        count_prefix = 0;
    }
    void increment_cp(){
        count_prefix++;
    }
    void decrement_cp(){
        count_prefix--;
    }
    void increment_ew(){
        ends_with++;
    }
    void decrement_ew(){
        ends_with--;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    int getEW(){
        return ends_with;
    }
    int getCP(){
        return count_prefix;
    }
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    // bool isEnd(bool flag) return flag;
};
class Trie{
    Node *root;
    public:

    Trie(){
        root  = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            } 
            node = node->getNode(ch);
            node->increment_cp();
        }
        node->increment_ew();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++){
            char ch = word[i];
            if(!node->containsKey(ch)) return 0;
            node = node->getNode(ch);
        }
        return node->getEW();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++){
            char ch = word[i];
            if(!node->containsKey(ch)) return 0;
            node = node->getNode(ch);
        }
        return node->getCP();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++){
            char ch = word[i];
            node = node->getNode(ch);
            node->decrement_cp();
        }
        node->decrement_ew();
    }
};
