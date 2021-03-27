#pragma once
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <memory>
#include "Node.h"

class Trie
{
private:
    std::shared_ptr<Node> root;
public:
    Trie();

    std::shared_ptr<Node> CreateNewNode(std::shared_ptr<Node> parent, char character);

    bool hasChildren(const std::shared_ptr<Node> current);

    std::shared_ptr<Node> go_to_next_node(std::shared_ptr<Node> current_node, char next_letter);

    void insert(std::string word);

// Iterative function to search a string in a Trie. It returns true
// if the string is found in the Trie; otherwise, it returns false.
    bool search_if_exists(std::string str);

};
