#pragma once
#include <map>
#include <string>
#include <utility>
#include <memory>

class Node
{
private:
    char letter;
    bool isLeaf;
    // each node stores a map to its child nodes
    std::map<char, std::shared_ptr<Node>> children;

public:
    Node(char letter_);
    std::map<char, std::shared_ptr<Node>> get_children() const;
    void set_children(std::shared_ptr<Node> newNode_);
    void set_isLeaf(bool end_of_the_word);
    bool get_isLeaf() const;
    bool operator== (const Node& rhs);
    
};