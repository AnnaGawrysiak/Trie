#include "Node.h"

#include <map>
#include <string>
#include <utility>
#include <memory>

Node::Node(char letter_)
  {
        letter = letter_;
        //isLeaf = false;
  }

std::map<char, std::shared_ptr<Node>> Node::get_children() const
  {
        return children;
  }


void Node::set_children(std::shared_ptr<Node> newNode_)
  {
        children.insert({ newNode_->letter, newNode_ });
  }

void Node::set_isLeaf(bool end_of_the_word)
  {
        isLeaf = end_of_the_word;
  }

bool Node::get_isLeaf() const
  {
        return isLeaf;
  }

bool Node::operator== (const Node& rhs)
    {
        return letter == rhs.letter && children == rhs.children && isLeaf == rhs.isLeaf;
    }

