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
        // data.~ArrayList(); //want to use method itslf instead. possible?
        // ~ArrayList();
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
};


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


int main() {
	//  test_arrayList_primes();
    ArrayList primes({2, 3, 5, 7, 11});
    primes.print();
}

