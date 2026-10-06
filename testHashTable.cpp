#include <iostream>
#include <stdexcept>
#include "HashTable.h"

int main() {
    HashTable<int> ht(5);
    ht.insert("a", 1);
    ht.insert("b", 2);
    ht.insert("c", 3);
    ht.insert("ab", 12);   // "ab" y "ba" colisionan (misma suma ASCII)
    ht.insert("ba", 21);

    std::cout << ht << std::endl;
    std::cout << "entries(): " << ht.entries() << "; capacity(): " << ht.capacity() << std::endl;
    std::cout << "ht[\"ab\"] => " << ht["ab"] << "; ht.search(\"c\") => " << ht.search("c") << std::endl;
    std::cout << "ht.remove(\"ba\") => " << ht.remove("ba") << std::endl;
    std::cout << "entries(): " << ht.entries() << std::endl;

    try { ht.insert("a", 99); } catch (std::runtime_error &e) { std::cout << "insert dup => runtime_error: " << e.what() << std::endl; }
    try { ht.search("zzz"); } catch (std::runtime_error &e) { std::cout << "search => runtime_error: " << e.what() << std::endl; }
    try { ht.remove("zzz"); } catch (std::runtime_error &e) { std::cout << "remove => runtime_error: " << e.what() << std::endl; }
}
