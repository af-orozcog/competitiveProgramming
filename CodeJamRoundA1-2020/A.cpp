#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int child;
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;
    pNode->child = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

bool insert(struct TrieNode *root, string &key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'A';
        if (!pCrawl->children[index] && pCrawl->child == 0){
            pCrawl->children[index] = getNode();
            pCrawl->child = 1;
        }
        else if(!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
    return 1;
}

string search(struct TrieNode *root)
{
    struct TrieNode *pCrawl = root;
    string ans = "";
    while(1){
        int index = -1;
        for(int i = 0; i < 26 && index == -1;++i){
            if(pCrawl->children[i] != NULL)
                index = i;
        }
        if(index == -1)break;
        ans += 'A'+index;
        pCrawl = pCrawl->children[index];
    }
    return ans;
}



int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        cin >> n;
        struct TrieNode *root1 = getNode();
        struct TrieNode *root2 = getNode();
        bool posi = 1;
        while(n--){
            string re;
            cin >> re;
            string pre = "";
            int i = 0;
            for(; i < re.size() && re[i] != '*';++i)
                pre += re[i];
            if(pre.size() != 0){
                cout << "entra???" << "\n";
                posi = posi & insert(root1,pre);
            }
            ++i;
            string pos = "";
            for(; i < re.size();++i)
                pos += re[i];
            cout << "pos is "<< pos << "\n";
            if(pos.size()){
                reverse(pos.begin(),pos.end());
                posi = posi & insert(root2,pos);
            }
            cout << "posi is " << posi << "\n";
        }
        printf("Case #%d: ",cas++);
        if(!posi){puts("*");continue;}
        string pre = search(root1);
        string pos = search(root2);
        reverse(pos.begin(),pos.end());
        cout << pre+pos << "\n";
    }
    return 0;
}
