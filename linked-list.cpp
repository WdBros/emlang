#include <string>
#include <iostream>

using std::string;
using std::cout;

struct ListItem {
    ListItem* next;
    string value;

    ListItem(string value, ListItem* next = NULL) : next(next), value(value) { }
};

struct List {
    ListItem* start;

    public:
        ListItem* get_element(int e) {
            ListItem* item = start;
            for (int i = 0; i < e; i++) {
                item = item->next;
            }
            return item;
        }

        void print_list() {
            ListItem* item = start;
            cout << start->value;
            while (item->next) {
                item = item->next;
                cout << " -> " << item->value;
            }
            cout << '\n';
        }

        List(ListItem* start) : start(start) {}
};

int main() {
    ListItem* item3 = new ListItem("three", NULL);
    ListItem* item2 = new ListItem("two", item3);
    ListItem* item1 = new ListItem("one", item2);

    List* list = new List(item1);

    list->print_list();

    delete item3;
    delete item2;
    delete item1;
    delete list;
}