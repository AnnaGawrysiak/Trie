#include "Trie.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <memory>


Trie::Trie()
{
    root = nullptr;
}

std::shared_ptr<Node> Trie::CreateNewNode(std::shared_ptr<Node> parent, char character)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(character);
    node->set_isLeaf(false);

    return node;
}

bool Trie::hasChildren(const std::shared_ptr<Node> current)
{
    if (!current->get_children().empty())
          return true;

    return false;
}

std::shared_ptr<Node> Trie::go_to_next_node(std::shared_ptr<Node> current_node, char next_letter)
{
    std::shared_ptr<Node> child = nullptr;

    if (!current_node->get_children().empty())
    {
        std::map<char, std::shared_ptr<Node>> current_map = current_node->get_children();
        child = current_map[next_letter];
    }

    return child;
}

void Trie::insert(std::string word)
{
    std::shared_ptr<Node> current = root;
    for (unsigned int i = 0; i < word.length(); i++)
    {
        char character = word[i];
        // check if current node has a child starting with letter c
        // create a new node if the path doesn't exist
        auto search = current->get_children().find(character);
        if (search == current->get_children().end())
        {
            std::shared_ptr<Node> newNode = CreateNewNode(current, character);
            current->set_children(newNode);
        }

        // go to the next node
        current = go_to_next_node(current, word[i]);
    }

        current->set_isLeaf(true);
}

// Iterative function to search a string in a Trie. It returns true
// if the string is found in the Trie; otherwise, it returns false.
bool Trie::search_if_exists(std::string str)
{
    std::shared_ptr<Node> current = root;

    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (hasChildren(current))
            current = go_to_next_node(current, str[i]);
        else
            return false;
    }

// return true if the current node is a leaf and the
// end of the string is reached
    if (current->get_isLeaf() == true)
        return true;

    return false;
}

