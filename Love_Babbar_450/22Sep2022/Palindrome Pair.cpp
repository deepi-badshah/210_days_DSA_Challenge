// CPP DSA Love Babbar 450 CN Lec 16
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
    
    //Search Word in Tries
            bool searchWord(TrieNode *root, string word){

        if (word.length() == 0) {
          return root->isTerminal; 
        }
        int index = word[0] -'a';
        //TrieNode *child;
        if (root->children[index] != NULL) {
                //cout<<word<<" ";
            return searchWord(root->children[index],word.substr(1));
        }

            return false;

    }

    bool search(string word) {
        // Write your code here
        return searchWord(root, word);
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
  			for(int i=0;i<words.size();i++){
            string m=words[i];
            int k=0;
            for(int j=0;j<m.size();j++){

               add(m.substr(k,m.size()));
               add(m.substr(0,k));

                k++;
            }
        }
        

        
    	for(int i=0;i<words.size();i++){
            string s=words[i];
            reverse(s.begin(),s.end());
            if(search(s)){
                return true;
            }

        }
        return false;

    }
};
