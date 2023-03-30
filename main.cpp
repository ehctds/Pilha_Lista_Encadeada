#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
};

class Stack {
    private:
        Node* top;
        int size;
    public:
        Stack() {
            top = NULL;
            size = 0;
        }

        bool isEmpty() {
            return (top == NULL);
        }

        int getSize() {
            return size;
        }

        void push(int x) {
            Node* newNode = new Node(x);
            newNode->next = top;
            top = newNode;
            size++;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Erro: pilha vazia" << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Erro: pilha vazia" << endl;
                return -1;
            }
            return top->data;
        }
};

int main() {
    Stack s;

    // Testando a inserção de elementos na pilha
    s.push(10);
    s.push(20);
    s.push(30);

    // Testando a leitura do topo da pilha
    cout << "Topo da pilha: " << s.peek() << endl;
    // Resultado esperado: 30

    // Testando o tamanho da pilha
    cout << "Tamanho da pilha: " << s.getSize() << endl;
    // Resultado esperado: 3

    // Testando a remoção de elementos da pilha
    s.pop();
    cout << "Topo da pilha: " << s.peek() << endl;
    // Resultado esperado: 20

    s.pop();
    s.pop();
    s.pop();
    // Testando a remoção de elementos da pilha vazia
    s.pop();
    // Resultado esperado: "Erro: pilha vazia"

    // Testando a verificação de pilha vazia
    cout << "Pilha vazia? " << (s.isEmpty() ? "Sim" : "Nao") << endl;
    // Resultado esperado: Sim

    return 0;
}
