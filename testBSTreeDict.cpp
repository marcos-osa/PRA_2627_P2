#include <iostream>
#include <stdexcept>
#include "BSTreeDict.h"

int main() {
    BSTreeDict<int> d;
    d.insert("pera", 3);
    d.insert("manzana", 1);
    d.insert("uva", 5);
    d.insert("kiwi", 4);

    std::cout << d << std::endl;
    std::cout << "entries(): " << d.entries() << std::endl;
    std::cout << "d[\"uva\"] => " << d["uva"] << std::endl;
    std::cout << "d.remove(\"pera\") => " << d.remove("pera") << std::endl;
    std::cout << d << "(entries " << d.entries() << ")" << std::endl;

    try { d.insert("uva", 0); } catch (std::runtime_error &e) { std::cout << "insert dup => " << e.what() << std::endl; }
    try { d.search("fresa"); } catch (std::runtime_error &e) { std::cout << "search => " << e.what() << std::endl; }
    try { d.remove("fresa"); } catch (std::runtime_error &e) { std::cout << "remove => " << e.what() << std::endl; }
}
