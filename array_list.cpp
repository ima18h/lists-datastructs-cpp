#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class ArrayList {
    private:
        int capacity; 
        int *data;
        int growth_factor;

    public:
        int size; //initial size 0
        
    //constructor
    ArrayList() {
    size = 0;
    capacity = 1;
    growth_factor = 2; //double when full 
    data = new int[capacity];
    }

    //overloading
    
    ArrayList(vector<int> init) {
    size = 0;
    capacity = 1;
    growth_factor = 2; //double when full 
    data = new int[capacity];

    for (int e: init) {
        append(e);
    }


    
    }
    


    //destructor
    ~ArrayList() {
    delete[] data;
    }


    int lenght(){
         // return nb. of elements in the object;
         return size; 

    }

 
    
    

    // c) 

    void append(int n){
        if (size < capacity) {
        data[size] = n;
        size += 1;
        }
        else {
            //call the below method 
            resize(); 
            //then do the desired task
            data[size] = n;
            size += 1;
      }
    }

    void resize(){
        // All0cate new array with new_capacity = 2 * capacity
        capacity *= growth_factor;
        
        //create a new data structure with the double capacity of the existing one
        int *data_new = new int[capacity]; 
        
        // filling the new array with the old one, i.e. copying the existing one
        for (int i=0; i<size; i++) {
        data_new[i] = data[i]; 
    }
        //delete the existing one and reassign the data-pointer
        delete[] data;
        data = data_new;
    }

    //d - pretty printing 
    //Add a public method void print() that prints out the contents of the list in order on a single line.
    void print(){
        cout << "[";
        for (int i=0; i<size-1; i++) {
		cout << data[i] <<" "; 
        
    }
    cout << data[size-1] << "]" << endl;
    
    }

    //support method which throws  
    void check_index(int index){
        if ((index >= size) || (index < 0)) {
            throw out_of_range("Index " + to_string(index) + " is out of range to array list with size "
                               + to_string(size));

        }
    }


    //overwrite the 'int &operator', so that we can use bracketing to set/get later
    int &operator[](int index) {
        check_index(index);
        return data[index];
    }


    //not correct results yet
    void insert(int val, int index) {
        if (0 <= index < size) { //checking if legal argument
            size += 1;
            for (int i = index; i<size+1; i++) {
                data[i] = data[i+1];
            }
            data[index] = val;
        } 
        else {
        throw range_error("Capacity full");
        }
    }

    
    void remove(int index) {
        //shift to left from end to index
        for(int i=index;i<size-1;++i){
                data[i]=data[i+1];
        }

        //delete in the end
        size -= 1;

    }

    //mthod that deletes a given element as well as returning it
    int pop(int index) {
        int to_return = data[index]; //a temp variable
        remove(index);
        return to_return; //return the temp (which point to the element at given index)
    }

    int pop(){
        //method that deletes the last element aas well as returning it
        int d = data[size-1];
        remove(size-1);
        return d;
    }


    // 1i) Help method for shrink
    //just for testing for the programmer, hence I violate the private variable agreement
    int allocated(){
         // return capacity of the object;
         int allocated = capacity;
         return allocated; 

    }
    void shrink_to_fit() {
        //do something if capacity can be reduced without being less than size (capazity being 2^n)
        while (capacity/2 >= size)
        // if (capacity/2 >= size) 
        {
            capacity /= 2; 
        }
    }


    //added functionality for automatic shrinking 1j)
    //comment out the following method if you are running test_shrink_to_fit(); in 'main', 
    //i.e. if you do not want automatic shrink
        
    void automatic_shrinking(){
        double ratio = 0.25;
        if (size < ratio*capacity) {
            shrink_to_fit();
        }
    }
};
//class end



bool is_prime(int n) {
    if (n == 1) {
        return false;
    }
    
    for (int d=2; d<n; d++) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

//1e test function 
void test_arrayList_primes() {
    ArrayList primes;

    int n = 100; //choose an arbitrary large number we are sure than contains min. of 10 primes
    int i = 0;
    int j = 0; //tolerance, max nb. of primes
    while (j < 10) {
    
       bool p = is_prime(i);

        if (p) {
            primes.append(i);
            j++;
         }
    i++;
    }
    primes.print();
}

//1i test function
void test_shrink_to_fit(){
    ArrayList example({8,7,6,5,4,3,2,1});
    
    for (int i = 0; i<1200; i++) {
        example.append(i);
    }

    // example.print();

    cout << "---size is:" << example.lenght() << endl;
    cout << "---capacity is:" << example.allocated() << endl;
    
    cout << "---DELETING elements" << endl;
    
    for (int i = 20; i<800; i++) {
        example.remove(i);
    }
    // example.print();

    cout << "---size is:" << example.lenght() << endl;
    cout << "---capacity is:" << example.allocated() << endl;
    
    example.shrink_to_fit();

    cout << "-SHRINKING" << endl;

    cout << "---size is:" << example.lenght() << endl;
    cout << "---capacity is:" << example.allocated() << endl;


} 

//function for testing automatic shrinking. just for remove() method, but the same implementation in pop*2
void test_automatic_shrinking(){
    ArrayList example({8,7,6,5,4,3});
    example.print();
    cout << "---adding elements:" << endl;
    for (int i = 0; i<1200; i++) {
        example.append(i);
    }
    cout << "---size is:" << example.lenght() << endl;
    cout << "---capacity is:" << example.allocated() << endl;
    cout << "---removing elements:" << endl;
     for (int i = 20; i<800; i++) {
        example.remove(i);
    }
    
    cout << "---size is:" << example.lenght() << endl;
    cout << "---capacity is:" << example.allocated() << endl;
} 

int main() {
	//calling test_ array_list 1e)
    //  test_arrayList_primes();
    
    
    //tests for insert, remove and pop(s)
    // ArrayList primes({2, 3, 5, 7, 11});
    // primes.print();
    // ArrayList example({8,7,6,5,4,3});
    // example.print();
    // // example.insert(0,2);
    // cout << example.pop() << endl;
    // example.print();
    // example.remove(2); //test remove
    // cout << example.pop(2) << endl; //test pop(int)
    // cout << example.pop() << endl;//test pop()
    // example.print();
    
    

    //calling 1i
    // test_shrink_to_fit();

    //testing automatic shrink (1j)
    // test_automatic_shrinking();
}

