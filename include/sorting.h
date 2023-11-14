#ifndef ED_TP2_SORTING_H
#define ED_TP2_SORTING_H


class Sorting {
public:
    static void bubbleSort(int arr[], int n);
    static void selectionSort(int arr[], int n);
    static void insertionSort(int arr[], int n);
    static void quickSort(int arr[], int low, int high);
    static void mergeSort(int array[], int const begin, int const end);
    static void heapSort(int arr[], int N);

private:
    static int partition(int arr[], int low, int high);
    static void merge(int array[], int const left, int const mid, int const right);
    static void heapify(int arr[], int N, int i);



};


#endif //ED_TP2_SORTING_H
