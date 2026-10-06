#include <iostream>
#include <stdexcept>
#include "BSTree.h"

int main() {
    BSTree<int> t;
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 35};
    for (int v : vals) t.insert(v);

    std::cout << "inorder: " << t << "(size " << t.size() << ")" << std::endl;
    std::cout << "t.search(40) => " << t.search(40) << "; t[60] => " << t[60] << std::endl;

    t.remove(20);  // hoja
    t.remove(40);  // un hijo (35)
    t.remove(50);  // dos hijos (raíz)
    std::cout << "tras remove 20, 40, 50: " << t << "(size " << t.size() << ")" << std::endl;

    try { t.insert(70); } catch (std::runtime_error &e) { std::cout << "insert dup => " << e.what() << std::endl; }
    try { t.search(1); } catch (std::runtime_error &e) { std::cout << "search => " << e.what() << std::endl; }
    try { t.remove(1); } catch (std::runtime_error &e) { std::cout << "remove => " << e.what() << std::endl; }
}
