// Exercice 1 : Implémentation

#include <stack>
#include "node.hpp"

Node* create_node(int value)
{
    Node* node = new Node {value, nullptr, nullptr};
    return node;
}

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
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
    }
    else
    {
        if (right == nullptr) {
            right = create_node(value);
        } 
        else 
        {
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
        left_height = 0;
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
    if (left != nullptr)
    {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right != nullptr)
    {
        right ->display_infix();
    }
}

std::vector<Node const*> Node::prefix() const
{
    std::vector<Node const*> result;
    result.push_back(this);
    if (left != nullptr)
    {
        auto left_prefix = left->prefix();
        result.insert(result.end(), left_prefix.begin(), left_prefix.end());
    }
    if (right != nullptr)
    {
        auto right_prefix = right->prefix();
        result.insert(result.end(), right_prefix.begin(), right_prefix.end());
    }
    return result;
}

// Postfixe version itérative bonus
std::vector<Node const*> Node::postfix() const 
{
    std::vector<Node const*> nodes {};
    std::stack<Node const*> to_process {};
    Node const* previous {nullptr};
    to_process.push(this);

    while (!to_process.empty()) {
        Node const* current { to_process.top() };

        // Si on est en train de descendre dans l'arbre
        if (previous == nullptr || (previous->left == current || previous->right == current)) {
            if (current->left != nullptr) {
                to_process.push(current->left);
            }
            else if (current->right != nullptr) {
                to_process.push(current->right);
            } else {
                nodes.push_back(current);
                to_process.pop();
            }

        // Si l'on remonte dans l'arbre en venant de la gauche
        }else if (current->left == previous) {
            if(current->right != nullptr) {
                to_process.push(current->right);
            } else {
                nodes.push_back(current);
                to_process.pop();
            }

        // Si l'on remonte dans l'arbre en venant de la droite
        } else if (current->right == previous) {
            nodes.push_back(current);
            to_process.pop();
        }

        previous = current;

    }
    return nodes;
}

Node*& most_left(Node*& node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    else
    {
        return most_left(node->left);
    }
}

bool remove(Node*& node, int value)
{
    if (node == nullptr)
    {
        return false;
    }

    if (value < node->value)
    {
        return remove(node->left, value);
    }
    else if (value > node->value)
    {
        return remove(node->right, value);
    }
    else
    {
        if (node->is_leaf())
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr)
        {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node*& most_left_node = most_left(node->right);
            node->value = most_left_node->value;
            remove(node->right, most_left_node->value);
        }
        return true;
    }
}

void delete_tree(Node* node)
{
    if (node != nullptr)
    {
        node->delete_children();
        delete node;
    }
}

// Bonus :
int Node::min() const
{
    if (left == nullptr)
    {
        return value;
    }
    return left->min();
}

int Node::max() const
{
    if (right == nullptr)
    {
        return value;
    }
    return right->max();
}