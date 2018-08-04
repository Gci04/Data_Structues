//
//  main.cpp
//  Data_Structues
//
//  Created by Gcinizwe Dlamini on 04/08/2018.
//  Copyright © 2018 Gcinizwe Dlamini. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <limits.h> // for INT_MAX
#include "Array.h"

using namespace std;


int first_non_repeating(int *arr, int n){
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if(i != j && arr[i] == arr[j]){
                break;
            }
        }
        if (j == n) {
            return arr[i];
        }
    }
    return -1;
}
void inser_at_index(int *arr, int n, int idx,int val){
    //insert with repacking
    for (int i = n-1; i > idx; i--) {
        arr[i] = arr[i-1];
    }
    arr[idx] = val;
}
void delete_at_index(int *arr,int &n,int indx){
    int *temp = new int[n-1];
    for (int i = indx; i < n+1; i++) {
        arr[i] = arr[i+1];
    }
    for (int i = 0 ; i < n-1; i++) {
        temp[i] = arr[i];
    }
    n--;
    arr = NULL;
    arr = temp;
}
int second_min(int *arr, int n){
    //solution 1: sort the array in increasing order and pick the 2nd element as second smallest element.
    // solution 2: two elements in one traversal
    assert(n > 2 );
    int first,second;
    first = second = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second && arr[i] != first){
            second = arr[i];
        }
    }
    if (second == INT_MAX) {
        cout<<"Warning : No second minimum element!!"<<'\n';
    }
    return second;
}
void print(int *arr,int n){
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}
int main(int argc, const char * argv[]) {
    srand(time(NULL)); //Generate random numbers
    int n; //size of array
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%20;
    }
    print(arr,n);
    cout<<"After inserting a Value at given index"<<'\n';
    //insert 99 at index 2 (do repacking)
    inser_at_index(arr, n,2,99);
    print(arr, n);
    
    //return element at given index (i.e index 4)
    int temp = arr[4];
    cout <<temp<<'\n';
    
    //delete element at a given index (i.e index 3)
    delete_at_index(arr, n, 3);
    print(arr, n);
    
    int min = second_min(arr, n);
    if (min != INT_MAX) {
        cout<<"Second minimum element : "<<min<<'\n';
    }
    cout<<first_non_repeating(arr, n)<<'\n';
    delete []arr;
    return 0;
}
