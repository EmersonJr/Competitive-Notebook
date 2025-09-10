// Suffix Automata
// estrutura que compacta todas as substrings de uma string
// todo caminho no automato eh uma substring, e toda substring tem um caminho associado a ela
// o link de um no eh o maior sufixo dela que possui um conjunto de ocorrencias maior do que o proprio no (ou o lnk eh a raiz)
// cada no representa varias substrings, as de tamanho len[lnk[no]]+1 ate as de len[no] com mesmo sufixo

struct SuffixAutomata {
    int n, id = 1, last = 1;
    vector<array<int, 26>> to;
    vector<int> len, lnk, occ, fpos;

    SuffixAutomata(string &s, char a='a'): n(s.size()), to(2*n+2, {0}), len(2*n+2), lnk(2*n+2), occ(2*n+2, 0), fpos(2*n+2) {
        len[1] = lnk[1] = 0;
        for (char c : s) push(c-a);

        vector<int> states(id); 
        iota(all(states), 1);
        sort(all(states), [&](int a, int b) {return len[a] > len[b];});
        for (int st : states)
            occ[lnk[st]] += occ[st];
    }

    void push(int c) {
        int curr = ++id;
        int prev = last;
        last = curr;

        len[curr] = len[prev]+1;
        fpos[curr] = len[curr]-1;
        occ[curr] = 1;

        for (; prev && !to[prev][c] ; prev = lnk[prev]) to[prev][c] = curr;

        int q = to[prev][c];
        if (!prev)
            lnk[curr] = 1;
        else if (len[prev] + 1 == len[q])
            lnk[curr] = q;
        else {
            int clone = ++id;

            lnk[clone] = lnk[q];
            to[clone] = to[q];
            fpos[clone] = fpos[q];
            len[clone] = len[prev]+1;

            lnk[q] = lnk[curr] = clone;
            for (; to[prev][c] == q ; prev = lnk[prev]) to[prev][c] = clone;
        }
    }
};