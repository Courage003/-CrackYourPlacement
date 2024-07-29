class Trie {  
public:

    struct trieNode{
        bool endWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode= new trieNode();
        newNode->endWord=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }

    trieNode* root;
    Trie() {
        root= getNode();

       
    }
    
    void insert(string word) {
        trieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(node->children[idx]==NULL){
                node->children[idx]=new trieNode();
            }
            node=node->children[idx];
        }
        node->endWord=true;
       
    }
    
    bool search(string word) {
       trieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(node->children[idx]==NULL){
                return false;
            }
            node=node->children[idx];
        }
        if(node!=NULL && node->endWord==true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* node=root;
        int i=0;
        for(i=0;i<prefix.size();i++){
            char c=prefix[i];
            int idx=c-'a';
            if(node->children[idx]==NULL){
                return false;
            }
            node=node->children[idx];
        }
        if(i==prefix.size()){
            return true;
        }
        return false;
       

      
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
