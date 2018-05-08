#ifndef ARRAYDATABASE_H
#define ARRAYDATABASE_H
#include<iostream>
#include<chrono>
#include<random>
#include<ctime>
#include<QMessageBox>
#include<vector>
#include<utility>
#include<string>
#include"listnode.h"


typedef std::vector<ListNode> database;

class arrayDatabase: public ListNode{

public:
    database list;
    int list_size;

public:

    arrayDatabase();

    void createDatabase(int rooms);

    int bell_curve_generator();

    void changePrice();

    void print_database();

    void insertionSort();

    void selectionSort();

    void mergeSort(int l, int r);

    void randomizedQuickSort(int low, int high);

    void bubbleSort();    

    void deleteValue(int room_price);
    
    void addItem();
};

#endif // ARRAYDATABASE_H
