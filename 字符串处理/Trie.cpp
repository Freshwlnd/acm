#define per(i, a, b) for(int i=a; i<b; i++)

const int MAXN(2e5+7);  //串总数
const int LEN(32);      //串最长长度
struct trnd{
    int snm, num;    //子树个数/当前节点结尾字符串个数
    int son[26];
    inline void init() { num=snm=son[0]=son[1]=0; }
}Trie[MAXN*LEN];
int cntt;
inline void insrt(int rt, const string& str) {
    int f;
    per(i, 0, str.length()) {
        f = str[i]-'a';
        if(!Trie[rt].son[f]) {
            Trie[rt].son[f] = cntt;
            Trie[cntt++].init();
            Trie[rt].snm++;         //子树个数+1
        }
        rt = Trie[rt].son[f];
    }
    Trie[rt].num++;     //当前节点字符串个数+1
}

int main() {
    
    cntt = 2;       //1为root节点
    Trie[1].init();

    string str;
    while(cin >> str) insrt(1, str);

    return 0;
}
