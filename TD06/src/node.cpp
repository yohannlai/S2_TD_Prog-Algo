#include "node.hpp"

Node* create_node(int value)
{
    Node* node = new Node {value, nullptr, nullptr};
    return node;
}

bool Node::is_leaf() const
{
    return left == nullptr && right == nullptr;
}

void Node::insert(int value)
{
    if (value < this->value) {
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else if (value > this->value) {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

int Node::height() const
{
    if (is_leaf())
    {
        return true;
    }
    int left_height;
    if (left != nullptr)
    {
        left_height = left->height();
    }
    else
    {
        left_height = ;
    }

    int right_height;
    if (right != nullptr)
    {
        right_height = right->height();
    }
    else
    {
        right_height = 0;
    }
    return std::max(left_height, right_height) + 1;
}

void Node::delete_children()
{
    if (left != nullptr)
    {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right != nullptr)
    {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix()
{
    
}