学习笔记

第7周学习笔记：

1. Trie 前缀树 

1) 每条路径是一个单词；
2) 查询效率比哈希更高；
3) 模板：

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node -> next[c-'a'] == NULL)
                node -> next[c-'a'] = new Trie();
            node = node -> next[c-'a'];
        }
        node -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node -> next[c-'a'];
            if (node == NULL)
                return false;
        }
        return node -> isEnd;
    }

2. 并查集

1) 适用于组团和配对问题
2) 基本操作有make_set、find_set和union_sets
3) 模板：

    int parent[];

    void make_set(int n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find_set(int i) {
        if (i == parent[i])
            return i;
        return parent[i] = find_set(parent[i]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }


