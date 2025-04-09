struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };
    bool is_leaf() const;
    int height () const;
    void delete_children();
    void display_infix() const;
};

Node* create_node(int value);

void Node::insert(int value);