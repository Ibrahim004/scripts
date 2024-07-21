#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class resizable_array {
    private:
        T* array;
        int capacity = 0;
        int size = 0;
        const int default_initial_capacity = 100;

    public:
        resizable_array(){
            capacity = default_initial_capacity;
            array = new T[capacity];
        }
        resizable_array(int n){
            if(n <= 0){
                throw out_of_range{"initial size of array must be positive value!"};
            }
            array = new T[n];
            capacity = n;
        }
        ~resizable_array(){
            delete[](array);
        }
        T& operator[](int i){
            if(i < 0 || i > size-1){
                throw out_of_range{"index out of bound!"};
            }
            return array[i];
        }
        void push_back(T value){
            if(size < capacity){
                array[size++] = value;
            }
            else {
                capacity *= 2;
                T* newArray = new T[capacity];
                for(int i = 0; i < size; ++i){
                    newArray[i] = array[i];
                }
                delete[](array);
                array = newArray;
                array[size++] = value;
            }
        }
        T* begin(){
            return &array[0];
        }
        T* end(){
            return &array[size];
        }

};

template <typename T>
void printArray(resizable_array<T>& arr){
    for(auto& x: arr){
        cout << x << " ";
    }
    cout << endl;
}
int main(){
    resizable_array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    printArray(arr);
}