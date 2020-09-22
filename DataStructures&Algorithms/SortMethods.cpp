//
// Created by Alexander P on 20/09/10.
//

#include "SortMethods.h"
#include "vector"

using namespace std;

template<typename E>
void QuickSort(vector<E> &elements, int first, int last) {
    int i = first, j = last, posPiv = (int) (first + last) / 2;
    E pivot, aux;

    do {
        while (elements.at(i) < pivot)i++;
        while (elements.at(j) > pivot)j--;

        if (i <= j) {
            aux = elements.at(i);
            elements.at(i) = elements.at(j);
            elements.at(j) = aux;
            i++, j--;
        }
    } while (i <= j);

    if (first < j) QuickSort(elements, first, j);
    if (i < last) QuickSort(elements, i, last);
}

template<typename E>
void mergeSort(vector<E> &array, int low, int high) {
    if (high <= low) return;

    int mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, mid, high);
}

template<typename E>
static void merge(vector<E> &array, int low, int mid, int high) {
    // Creating temporary subarrays
    auto *leftArray = new vector<E>(mid - low + 1);
    auto *rightArray = new vector<E>(high - mid);

    // Copying our subarrays into temporaries
    for (int i = 0; i < leftArray->size(); i++)
        leftArray->at(i) = array.at(low + 1);
    for (int i = 0; i < rightArray->size(); i++)
        rightArray->at(i) = array.at(mid + i + 1);

    // Iterators containing current index of temp subarrays
    int leftIndex = 0;
    int rightIndex = 0;

    // Copying from leftArray and rightArray back into array
    for (int i = low; i < high + 1; i++) {
        // If there are still uncopied elements in R and L, copy minimum of the two
        if (leftIndex < leftArray->size() && rightIndex < rightArray->size()) {
            if (leftArray->at(leftIndex) < rightArray->at(rightIndex)) {
                array.at(i) = leftArray->at(leftIndex);
                leftIndex++;
            } else {
                array.at(i) = rightArray->at(rightIndex);
                rightIndex++;
            }
        } else if (leftIndex < leftArray->size()) {
            // If all elements have been copied from rightArray, copy rest of leftArray
            array.at(i) = leftArray->at(leftIndex);
            leftIndex++;
        } else if (rightIndex < rightArray->size()) {
            // If all elements have been copied from leftArray, copy rest of rightArray
            array.at(i) = rightArray->at(rightIndex);
            rightIndex++;
        }
    }
}

template<typename E>
void BubbleSort(vector<E> &elements) {
    bool flag;
    E *aux;

    for (int i = 0; i < elements.size() - 1; ++i) {
        flag = false;
        for (int j = 0; j < elements.size() - 1; ++j)
            if (elements.at(j) > elements.at(j + 1)) {
                flag = true;
                aux = elements.at(j);
                elements.at(j) = elements.at(j + 1);
                elements.at(j + 1) = aux;
            }
    }
}

template<typename E>
void ShellSort(vector<E> &elements) {
    int k, aux, j, jump = int(elements.size()) / 2;;

    while (jump > 0) {
        for (int i = jump; i < int(elements.size()); i++) {
            j = i - jump;
            while (j >= 0) {
                k = j + jump;
                if (elements[j] < elements[k])
                    j = -1;
                else {
                    aux = elements[j];
                    elements[j] = elements[k];
                    elements[k] = aux;
                    j -= jump;
                }
            }
        }
        jump /= 2;
    }
}

template<typename E>
static void HeapSort(vector<E> &elements) {
    int n = elements.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(elements, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        E *temp = elements[0];
        elements[0] = elements[i];
        elements[i] = *temp;

        // call max heapify on the reduced heap
        heapify(elements, i, 0);
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template<typename E>
static void heapify(vector<E> &elements, int n, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && elements[l] > elements[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && elements[r] > elements[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        E *swap = elements[i];
        elements[i] = elements[largest];
        elements[largest] = *swap;

        // Recursively heapify the affected sub-tree
        heapify(elements, n, largest);
    }
}
