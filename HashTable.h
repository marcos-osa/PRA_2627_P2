#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h"

template <typename V>
class HashTable : public Dict<V> {

    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;

        // h(key) = (suma de los ASCII de los caracteres) mod max
        int h(std::string key) {
            int sum = 0;
            for (int i = 0; i < (int)key.size(); i++) {
                sum += int(key.at(i));
            }
            return sum % max;
        }

    public:
        HashTable(int size) : n(0), max(size) {
            table = new ListLinked<TableEntry<V>>[max];
        }

        ~HashTable() override {
            delete[] table;
        }

        int capacity() {
            return max;
        }

        void insert(std::string key, V value) override {
            ListLinked<TableEntry<V>> &bucket = table[h(key)];
            if (bucket.search(TableEntry<V>(key)) != -1) {
                throw std::runtime_error("Key '" + key + "' already exists!");
            }
            bucket.prepend(TableEntry<V>(key, value));
            n++;
        }

        V search(std::string key) override {
            ListLinked<TableEntry<V>> &bucket = table[h(key)];
            int pos = bucket.search(TableEntry<V>(key));
            if (pos == -1) {
                throw std::runtime_error("Key '" + key + "' not found!");
            }
            return bucket.get(pos).value;
        }

        V remove(std::string key) override {
            ListLinked<TableEntry<V>> &bucket = table[h(key)];
            int pos = bucket.search(TableEntry<V>(key));
            if (pos == -1) {
                throw std::runtime_error("Key '" + key + "' not found!");
            }
            n--;
            return bucket.remove(pos).value;
        }

        int entries() override {
            return n;
        }

        V operator[](std::string key) {
            return search(key);
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]\n";
            for (int i = 0; i < th.max; i++) {
                out << "== Cubeta " << i << " ==\n\n" << th.table[i] << "\n\n";
            }
            return out;
        }
};

#endif
