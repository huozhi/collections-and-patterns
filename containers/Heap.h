/*
+-----------------------------------------------------------------------+
| C++ Code Heap                                                         |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


template <class Type = int>
class Heap {
private:
    vector<Type> __data;
    int          __size;

public:
    Heap(int *data, int size):
        __size(size) {
        __data.clear();
        __data.reserve(__size);
        for (int i = 0; i < size; i++)
            __data.push_back(data[i]);
    }

    Heap(vector<Type> __v):
        __size(__v.size()) {
        __data.clear();
        __data.assign(__v.begin(), __v.end());
    }


    void adjust(int holeIndex, Type adjustValue) {
        int topIndex = holeIndex;
        int secondChild = 2 * holeIndex + 2;
        while (secondChild < __size) {
            // if right child is smaller than left child
            if (__data[secondChild] < __data[secondChild - 1])
                --secondChild; // move to left part
            __data[holeIndex] = __data[secondChild]; // prelocate
            holeIndex = secondChild; // prelocate down index
            secondChild = 2 * secondChild + 2; // then find next right child first
        }
        // if there is no right child, only has left child
        if (secondChild == __size) {
            // prelocate to left child
            __data[holeIndex] = __data[secondChild - 1];
            holeIndex = secondChild - 1;
        }
        __data[holeIndex] = adjustValue;
    }

    void make_heap() {
        if (__size < 2) return;

        int parent = (__size - 2) / 2;
        while (true) {
            adjust(parent, __data[parent]);
            if (parent == 0) return;
            parent--;
        }
    }

    void push_element(Type e) {
        __data.push_back(e);
        int holeIndex = __size - 1;
        int parent = (__size - 1) / 2;
        while (holeIndex > 0 && !__comp(__data[parent], e)) {
            __data[holeIndex] = __data[parent];
            holeIndex = parent;
            parent = (holeIndex - 1) / 2;
        }
        __data[holeIndex] = e;
        ++__size;
    }

    void pop_element() {
        Type temp = __data[__size - 1];
        __data[__size - 1] = __data[0];
        adjust(0, temp);
        --__size;

    }

    void sort() {
        while (__size > 0) {
            pop_element();
            --__size;
        }
    }

    vector<Type> data() {
        return __data;
    }
};
