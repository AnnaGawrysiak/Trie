#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <memory>
#include "Trie.h"

int main()
{
    Trie sample;

    sample.insert("hello");
    std::cout << sample.search_if_exists("hello") << " "; 

    sample.insert("helloworld");
    std::cout << sample.search_if_exists("helloworld") << " ";  

    std::cout << sample.search_if_exists("helll") << " ";       

    sample.insert("alabaster");

    sample.insert("alabama");

    //sample.delete("hello");
    std::cout << sample.search_if_exists("hello") << " ";     

    return 0;
}

