#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string &key)
{
    struct TrieNode *pCrawl = root;
    pCrawl->isEndOfWord = 0;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        pCrawl->isEndOfWord = 0;
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
        pCrawl->isEndOfWord = 0;
    }

    pCrawl->isEndOfWord = true;
}
pair<bool,bool> dfs(struct TrieNode *root, int pa){
    if(pa && root->isEndOfWord) return {0,1};
    if(!pa && root->isEndOfWord) return {1,0};
    bool ans1 = (pa == 0? 1:0),ans2 = (pa == 0?1:0);
    for(int i = 0;i < ALPHABET_SIZE;++i){
        if(root->children[i] == NULL) continue;
        pair<bool,bool> va = dfs(root->children[i],(pa+1)&1);
        if(pa == 0){ans1 = ans1 & va.first; ans2 = ans2 & va.second;}
        else {ans1 = ans1 | va.first; ans2 = ans2 | va.second;}
    }
    return {ans1,ans2};
}


int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    struct TrieNode *root = getNode();
    for (int i = 0; i < n; i++){
        string temp; cin >> temp;
        insert(root, temp);
    }
    pair<int,int> posi = dfs(root,1);
    //cout << posi.first << " " << posi.second << endl;
    if(posi.second && posi.first) puts("First");
    else if(!posi.first) puts("Second");
    else if(!posi.second){
        if(m&1) puts("First");
        else puts("Second");
    }
    return 0;
}
