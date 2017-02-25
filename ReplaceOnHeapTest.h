//
// Created by jcespinoza on 2/21/2017.
//

#ifndef AA_CLASSEXERCISES_REPLACEONHEAPTEST_H
#define AA_CLASSEXERCISES_REPLACEONHEAPTEST_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class ReplaceOnHeapTest {
public:
    vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
    {
        int* result = new int[min_heap.size()];
        for (int index = 0; index < min_heap.size(); ++index) {
            int element = min_heap[index];
            if(element != replaced_value){
                result[index] =  element;
            }
        }
        insertOnHeap(result, min_heap.size(), replacement);

        vector<int> resultVector;
        for (int index = 0; index < min_heap.size(); ++index) {
            int element = result[index];
            resultVector.push_back(element);
        }

        return resultVector;
    }

    void insertOnHeap(int* min_heap, int heapSize, int value)
    {
        min_heap[heapSize] = value;
        int actual = heapSize;
        while(actual>0)
        {
            int padre;
            if(actual%2!=0)
            {
                padre = (actual-1)/2;
            }else
            {
                padre = (actual-2)/2;
            }
            if(min_heap[padre]>min_heap[actual])
            {
                break;
            }else
            {
                int aux = min_heap[padre];
                min_heap[padre] = min_heap[actual];
                min_heap[actual] = aux;
                actual = padre;
            }
        }
    }

    bool isMinHeap(vector<int> numbers, int current)
    {
        int left = current*2 + 1;
        int right = current*2 + 2;

        if(current >= numbers.size())
            return true;

        if(left<numbers.size() && numbers[current]>numbers[left])
            return false;

        if(right<numbers.size() && numbers[current]>numbers[right])
            return false;

        return isMinHeap(numbers, left) && isMinHeap(numbers, right);
    }

    bool hasAllValues(vector<int> v1, vector<int> v2)
    {
        for(int i=0; i<v1.size(); i++)
        {
            bool exists = false;
            for(int j=0; j<v2.size(); j++)
            {
                if(v1[i]==v2[j])
                    exists = true;
            }
            if(!exists)
                return false;
        }
        return true;
    }

    void test()
    {
        static const int arr[] = {10, 40, 20, 90, 80, 30, 50, 100};
        vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
        vector<int> vec_changed = vec;
        vec_changed[2] = 200;
        vector<int> res = replace(vec, 20, 200);

        static const int arr2[] = {5, 8, 10, 9, 15};
        vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
        vector<int> vec_changed2 = vec2;
        vec_changed2[4] = 2;
        vector<int> res2 = replace(vec2, 15, 2);

        static const int arr3[] = {25, 50, 75, 80, 100, 200, 150, 600, 540};
        vector<int> vec3 (arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) );
        vector<int> vec_changed3 = vec3;
        vec_changed3[6] = 30;
        vector<int> res3 = replace(vec3, 150, 30);

        if(isMinHeap(res,0) && hasAllValues(vec_changed,res)
           && isMinHeap(res2,0) && hasAllValues(vec_changed2,res2)
           && isMinHeap(res3,0) && hasAllValues(vec_changed3,res3))
        {
            cout<<"Test: Pass"<<endl;
        }else
        {
            cout<<"Test: Fail"<<endl;
        }

    }
};


#endif //AA_CLASSEXERCISES_REPLACEONHEAPTEST_H
