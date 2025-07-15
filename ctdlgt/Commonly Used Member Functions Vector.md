Created: 202409220531
Tags: 

Member function
```
constructor
destructor
operator
```

Modifiers:
```
assign(int size, int value); // It assigns new value to the vector elements by replacing old ones

push_back();
pop_back(); //pop or remove elements from a vector from the back.
insert(position, value); 
erase(position); 
erase(start-position, end-position); 

emplace(position, element); //extends the container by inserting new element at position

emplace_back(); //insert a new element into the vector container, the new element is added to the end of the vector

emplace_back(value); 
swap(vector); 
clear();
```


Iterators:
```C++ 
begin() 
end() 

rbegin() //Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() //Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

cbegin() //Returns a constant iterator pointing to the first element in the vector.
```

Capacity:
```
size(); 
max_size(); 
capacity();   //return size of allocated storage
resize(n); 
resize(int n, int value); 
empty(); 

shrink_to_fit(); //Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.

reserve(n);  //request a change in capacity
```

Element access
```
at(position); 
data() 
front() 
back() 
[]
```


-----
## References
1. [[Vector]]
2. [[DSA]]
3. https://www.geeksforgeeks.org/vector-in-cpp-stl/
