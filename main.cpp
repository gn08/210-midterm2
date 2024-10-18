#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        string name;
        Node* prev;
        Node* next;
        Node(const string& val, Node* p = nullptr, Node* n = nullptr) {
            name = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void insert_after(const string& value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(const string& value)) {
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void push_back(const string& v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(const string& v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

vector<string> load_names(const string& filename){
    vector <string> names;
    string name;
    ifstream filefilename();
    while (getline(file, name)){
        names.push_back(name);
    }
    return names;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    DoublyLinkedList line;
    vector<string> names = load_names("names.txt");

    cout << "Store opens: " << endl;

    for(inr i = 0; i < 5; ++i){
        string name= names[rand() % names.size()];
        line.push_back(name);
        cout << " " << name << "joins the line" << endl;
    }
    line.print();

    for (int time_step = 2; time_step <= 20; ++time_step){
        cout << "Time step #" << time_step << ":" << endl;
        int prob - rand() % 100 +1;
        if (prob <= 40 && !line.is_empty()){
            string served = line.front();
            line.pop_front();
            cout << " " << served << "is served" << endl;
        }

        prob = rand() % 100 + 1;
        if (prob <= 60){
            string name= names[rand() % names.size()];
            line.push_back(name);
            cout << " " << name << "joins the line" << endl;
        }

        prob = rand() % 100 + 1;
        if (){
            string leaving = line.back();
            line.pop_back();
            cout << " " << leaving << "exits rear line" << endl;
        }

        prob = rand() % 100 + 1;
        if (prob <= 10){
            string vip_name = names[rand() % names.size()];
            line.push_front(vip_name);
            cout << " " << vip_name << "(VIP) joins the front of the line" << endl;
        }
        
        line.print();
    }

    return 0;
}