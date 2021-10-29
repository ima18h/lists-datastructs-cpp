# H21_project2_erlingpv_imadha
Project 2 for erlingpv (erlingpv@mail.uio.no) and imadha (imadha@mail.uio.no)



Part 1: Used VSC to build/compile into executable. In our understanding, we managed to complete the problem correctly. 
At least, it compiles and run, as well as providing promising and expected functionality/results. 
Perhaps code style could be better. Made test functions for the shrink-methods and 1e) which we call from the 'main' block. 
Besides that, we had some simple tests in main-block (just for us, since not asked for besides the aforementioned ones.) Furthermore,
we created a method 'int allocated()' which in some way return a private variable. To our understanding, this is not a prefered programming style, 
but we only used it for OUR testing purposes, hence we thought it was OK. A final remark is that we interpreted the
pop() method to delete the last element as well as returning it (as the word "delete" is not mentioned for this spesific method
we were not sure originally). 




Part 3a) - Big O  

--ARRAYList--
Get element i by index: In an ArrayList, this is just operation - you simply just access the element/index desired.
Thus we hav Big O(1)

Insert at front: 
-Depend proportionally on the elenght n of the list, when n is the lenght of the list aftr inseritng
. This is because we have to shift the originally ellements (n-1) of them to the right, as well as adding an element
in the front. This yields that we get Big O(n) (linear)

Insert at back (aka append): 
-Big-oh is Big O(1) since we are just adding _one_ element. An execption is if size == capacity before we append, then
we need to rezize, which amount to Big O(n), as this is copying thw whole list. 

Insert into middle of list
-This depends on the number of elements, since when you insert at index i, it depends on how big the size of
n-i is. Hence, the number of operations needed depends linearly on n, hence Big O(n). 

Removing yields the same number of operations as inserting

Remove element from front:
-deleting pne element, and shifting the rest (i.e. n-1 elements) one to the elements. this yields Big O(n)

Remove element from back
Analogously to the inserting:
deleting element nb. n: one element is deleted and nothing else, i.e. Big O(1)

Remove the last element of the list:
Big O(n), same argument as for the inserting. 

Print
Depending on the loop: for printing just one number yields the same as accessing an element, namely Big O(1). 
But printing the list itself (or arbitrary size of it) yields Big O(1) * Big O(n) = Big O(n)


--LinkedList--
Get element i by index: 
This is different from the ArrayList: As we here are facing a list were evertyhing is 'chained together', we 
now must traverse the whole list to accescc our desired element/index. Thus Big O(n)

Insert at front: 
-Independent of the size of the list, since we just add an element that point to the previous head. 
Independent of n means constant, i.e. Big O(1).

Insert at back (aka append): 
-By utilizing the tail-pointer, we have a neat way of reaching the end. Hence, this also scales as Big O(1)

Insert into middle of list
-Same argument as for arraylist, Big O(n)

Removing yields the same number of operations as inserting
Remove element from front:
-Big O(1). Same argument as for inserting

Remove element from back:
-Analogously to the inserting, i.e. Big O(1)

Removing in the middle
-Same argument as for arraylist, Big O(n)

Print
for an n-sized list, printing it yields 'numeber of iterations' * 'cost of acceccing the elemnts' = 
Big O(n) * Big O(n) = Big O(n^2)  




part 4: If n=67 and k=7, the best location in the circle would be 61, as this would make you be the last man standing.
(derived by calculator). 





Unfortuneately, we did not had enough time to finish this time. We hope to get a second attempt, and will finish the project then. 
We got 


