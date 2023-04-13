#include <iostream>
#include <vector>

using namespace std;

// Definición de la estructura del nodo
struct Node {
    int data; // Valor del nodo
    vector<Node*> children; // Vector de hijos
    Node(int data) {
        this->data = data;
    }
};

// Función para insertar un nuevo nodo al árbol
void insert(Node* root, int data) {
    Node* newNode = new Node(data); // Creamos un nuevo nodo
    root->children.push_back(newNode); // Lo insertamos como hijo del nodo raíz
}

// Función para eliminar un nodo del árbol
bool remove(Node* root, int data) {
    for (int i = 0; i < root->children.size(); i++) { // Recorremos los hijos del nodo
        Node* current = root->children[i];
        if (current->data == data) { // Si el valor del nodo es el que queremos eliminar
            root->children.erase(root->children.begin() + i); // Lo eliminamos del vector de hijos
            delete current; // Liberamos la memoria del nodo eliminado
            return true;
        }
        if (remove(current, data)) { // Si no encontramos el nodo en este nivel, buscamos en los hijos
            return true;
        }
    }
    return false;
}

// Función para buscar un nodo en el árbol
bool search(Node* root, int data) {
    if (root->data == data) { // Si el valor del nodo es el que estamos buscando
        return true;
    }
    for (Node* child : root->children) { // Si no, buscamos en los hijos
        if (search(child, data)) {
            return true;
        }
    }
    return false;
}

/*
// Función para recorrer el árbol e imprimir sus nodos
void printPreOrden(Node* root, int level = 0) {
    cout << string(level, '-') << " " << root->data << endl; // Imprimimos el valor del nodo con un separador según su nivel en el árbol
    for (Node* child : root->children) { // Recorremos los hijos del nodo
        printPreOrden(child, level + 1); // Imprimimos los hijos recursivamente, aumentando el nivel
    }
}
*/

// Función para recorrer el árbol e imprimir sus nodos en preorden
void printPreOrder(Node* root) {
    cout << root->data << " "; // Imprimimos el valor del nodo antes de recorrer los hijos
    for (Node* child : root->children) { // Recorremos los hijos del nodo
        printPreOrder(child); // Imprimimos los hijos recursivamente
    }
}


// Función para recorrer el árbol e imprimir sus nodos en posorden
void printPosOrder(Node* root)
{
    for (Node* child : root->children) { // Recorremos los hijos del nodo
        printPosOrder(child); // Imprimimos los hijos recursivamente
    }
    cout << root->data << " "; // Imprimimos el valor del nodo después de los hijos
}

// Función para recorrer el árbol e imprimir sus nodos en orden
void printInOrder(Node* root) {
    if (root == nullptr) { // Verificamos si el nodo es nulo
        return;
    }
    if (root->children.size() > 0) { // Si el nodo tiene hijos
        printInOrder(root->children[0]); // Imprimimos el primer hijo
    }
    cout << root->data << " "; // Imprimimos el valor del nodo
    for (int i = 1; i < root->children.size(); i++) { // Recorremos los demás hijos del nodo
        printInOrder(root->children[i]); // Imprimimos los hijos recursivamente
    }
}


int main() {
    // Creamos un árbol con raíz en el nodo 1
    Node *root = new Node(1);

    // Insertamos nodos al árbol
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root->children[0], 5); // Insertamos un nodo como hijo del primer hijo del nodo raíz
    insert(root->children[0], 6);
    insert(root->children[1], 7); // Insertamos un nodo como hijo del segundo hijo del nodo raíz

    // Imprimimos el árbol en preorden
    cout << "Árbol en preorden: ";
    printPreOrder(root);
    cout << "" << endl;

    // Imprimimos el árbol en orden
    cout << "Árbol en orden: ";
    printInOrder(root);
    cout << "" << endl;

    // Imprimimos el árbol en posOrden
    cout << "Árbol en posOrden: ";
    printPosOrder(root);
    cout << "" << endl;

    // Buscamos un nodo en el árbol
    int searchData = 7;
    if (search(root, searchData)) {
        cout << "El nodo " << searchData << " se encuentra en el árbol." << endl;
    } else {
        cout << "El nodo " << searchData << " no se encuentra en el árbol." << endl;
    }

    // Eliminamos un nodo del á
    int removeData = 2;
    if (remove(root, removeData)) {
        cout << "El nodo " << removeData << " ha sido eliminado del árbol." << endl;
    } else {
        cout << "El nodo " << removeData << " no se encuentra en el árbol." << endl;
    }

    /*
    // Imprimimos el árbol actualizado
    cout << "Árbol actualizado:" << endl;
    print(root);
    */

    return 0;
}