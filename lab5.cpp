#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Estructura para representar los elementos del heap
struct Element {
    int value;     // Valor actual del elemento
    int listIndex; // Índice de la lista
    int elementIndex; // Índice dentro de la lista

    // Sobrecarga del operador para el min-heap
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

// Función para fusionar k listas ordenadas
vector<int> mergeKSortedLists(const vector<vector<int>>& lists) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result;

    // Insertar el primer elemento de cada lista en el heap
    for (int i = 0; i < lists.size(); ++i) {
        if (!lists[i].empty()) {
            minHeap.push({lists[i][0], i, 0});
        }
    }

    // Procesar el heap
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();

        result.push_back(current.value);

        // Si hay más elementos en la misma lista, añadir el siguiente al heap
        if (current.elementIndex + 1 < lists[current.listIndex].size()) {
            minHeap.push({
                lists[current.listIndex][current.elementIndex + 1],
                current.listIndex,
                current.elementIndex + 1
            });
        }
    }

    return result;
}

// Ejemplo de uso
int main() {
    vector<vector<int>> lists = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<int> result = mergeKSortedLists(lists);

    // Imprimir el resultado
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
