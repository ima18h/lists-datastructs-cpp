# Inroduction
This project is made to learn about basic data structures and their time complexity. 2 different lists are
created and compared, ArrayLists and LinkedLists.


## ArrayList - Big O
- Indexing into a list and getting element i: In an ArrayList, you simply just access the element/index desired. 
Thus, we have Big O(1). Constant time. 


- Insert in the front: 
Depends on the length, n, of the list. This is because we have to shift (n-1) elements to
the right, as well as adding an element in the front. This yields that we get Big O(n). Linear time.  

- Insert at the back (aka append): 
O(1), since we are just adding one element. An exception is if size == capacity before we append, then
we need to resize, which amounts to O(n), because we have to copy the whole list. 


- Inserting into the middle: 
This depends on the number of elements in the list. O(n). 


- Removing an element yields the same result as inserting. 


- Removing an element from the front: 
deleting one element, and shifting the rest one to the right. O(n). 


- Removing an element from the back (pop()): 
Analogous to inserting (append(int)). O(1). 


- Removing an element from the middle: 
O(n), same as inserting in the middle, only elements are moved to the "left" (towards the front). 


- Printing. 
Depends on method. For printing just one number, is the same as accessing an element, O(1). 
But printing the whole list (or a subset of it), is O(1) * O(n) = O(n). 


## LinkedList - Big O
Relative performance will be worse for small lists compared to big ones because of overhead. 
- Get element i by index:  
Our linked list contains nodes that are, well, linked together. 
As the list gets bigger it will go towards O(n / 2) = O(n) for the worst case. 


- Insert at front:  
Independent of list size, just insert and link. 
Independent of n means constant, i.e. O(1). 


- Insert at back (aka append):  
Same as "Insert at front" because tail pointer. O(1). 


- Insert into middle of list:  
Same as indexing worst case. O(n / 2) = O(n). 


- Removing, approximately the same as indexing. O(n). 


- Remove element from front:  
O(1). Same as inserting. 


- Remove element from back:  
Analogous to appending, i.e. O(1). 


- Removing in the middle
Same as the indexing worst case, O(n). 


- Print  
I think it's O(n) because accessing the elements becomes O(1) when we already have the pointer.


## Josephus Problem: 
Given a group of _n_ men arranged in a circle under the edict that every _k_’th man
will be executed going around the circle until only one remains,
find the position L(n, k), in which you should stand, in order to be the last survivor (Ball and Coxeter 1987). 
Example, if n=67 and k=7, man number 61 will be the last man standing. 
