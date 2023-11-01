#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ItemSet {
public:
   
    ItemSet() {}

    void inserir(const string &s) {
        for (const string &item : items) {
            if (item == s) {
                cout << "Item '" << s << "' ja existe no conjunto." << endl;
                return;
            }
        }

        items.push_back(s);
    }

    void excluir(const string &s) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i] == s) {
                items.erase(items.begin() + i);
                cout << "Item '" << s << "' foi removido do conjunto." << endl;
                return;
            }
        }

        cout << "Item '" << s << "' nao existe no conjunto." << endl;
    }

private:
    vector<string> items;
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("item1");
    conjunto.inserir("item2");
    conjunto.inserir("item3");
    conjunto.inserir("item2");  // Tentando inserir um item que ja existe
    conjunto.excluir("item2");
    conjunto.excluir("item4");  // Tentando excluir um item que nao existe

    return 0;
}
