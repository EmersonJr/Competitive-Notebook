struct Line{
    int a, b;
    Line(){
        a = 0;
        b = -1e18;
    }
    Line(int _a, int _b){
        a = _a;
        b = _b;
    }
    int get(int x){
        return a*x + b;
    }
};
struct Lixao{
    struct Node{
        Line line;
        int l, r;
    
        Node *left_node = NULL;
        Node *right_node = NULL;
    };
    Node *root = new Node;
    Lixao(int _l, int _r, Line _line){ // [l, r] is the interval which a query(x) can be made, basically x ε [l,r]
        root->l = _l;
        root->r = _r;
        root->line = _line;
    }
    Node *add_line(Line new_line, Node *n){
        if(!n){
            Node *a = new Node;
            a->line = new_line;
            return a;
        }
        int l = n->l, r = n->r;
        int mid = (r+l)/2;
        if(new_line.get(mid) > n->line.get(mid)){
            swap(new_line, n->line);
        }
        if(n->line.get(l) >= new_line.get(l) and n->line.get(r) >= new_line.get(r)){ // optimization, but it might get overflow
            return n; // So, allways make sure that -INF < l*a+b < r*a+b < INF
        }
        if(new_line.get(l) > n->line.get(l)){
            n->left_node = add_line(new_line, n->left_node);
            n->left_node->l = l;
            n->left_node->r = mid;
        }
        else{
            n->right_node = add_line(new_line, n->right_node);
            n->right_node->l = mid+1;
            n->right_node->r = r;
        }
        return n;
    }
    void add_line(Line new_line){
        add_line(new_line, root);
    }
    void add_segment(Line new_line, int L, int R, Node *n){
        if(R < n->l or n->r < L){
            return;
        }
        if(L <= n->l and n->r <= R){
            add_line(new_line, n); 
            return;
        }
        int l = n->l, r = n->r;
        int mid = (r+l)/2;
        if(!n->left_node){
            n->left_node = new Node;
            n->left_node->l = l;
            n->left_node->r = mid;
        }
        add_segment(new_line, L, R, n->left_node);
        if(!n->right_node){
            n->right_node = new Node;
            n->right_node->l = mid+1;
            n->right_node->r = r;
        }
        add_segment(new_line, L, R, n->right_node);
        return;
    }
    void add_segment(Line new_line, int L, int R){
        add_segment(new_line, L, R, root);
    }
    int query(int x, Node *n){
        if(!n){
            return -1e18;
        }
        int l = n->l, r = n->r;
        int mid = (r+l)/2;
        
        if(x <= mid){
            return max(n->line.get(x), query(x, n->left_node));
        }
        else{
            return max(n->line.get(x), query(x, n->right_node));
        }
    }
    int query(int x){
        return query(x, root);
    }
};
