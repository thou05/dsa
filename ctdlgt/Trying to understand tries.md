Created: 202409250528
Tags: 

The term “trie” comes from the word _re_**_trie_**_val_, and is usually pronounced “try”, to distinguish it from other “tree” structures.

Deffinition: A trie is a tree-like data structure whose nodes store the letters of an alphabet. By structuring the nodes in a particular way, words and strings can be retrieved from the structure by traversing down a branch path of the tree.

According to Donald Knuth’s research in [The Art of Computer Programming](https://books.google.com.vn/books?id=e3wLBAAAQBAJ&pg=PA494&lpg=PA494&dq=Ren%C3%A9+de+la+Briandais+trie&ots=10VsH1KzxH&sig=xcvhPt3ECyr60gHDs27BJK-HDdk&hl=en&sa=X&redir_esc=y#v=onepage&q=Ren%C3%A9%20de%20la%20Briandais%20trie&f=false):
> Trie memory for computer searching was first recommended by René de la Briandais. He pointed out that we can save memory space at the expense of running time if we use a linked list for each node vector, since most of the entries in the vectors tend to be empty.

The original idea behind using tries as a computing structure was that they could be a nice compromise between running time and memory

![[Pasted image 20240925100853.png]]

Each trie has an empty root node, with links (or references) to other nodes - one for each possible alphabetic value

Important: The size of a trie is directly correlated to the size of all the possible values that the trie could reoresent. 
Ex: 
- English aplhabet has 26 letters -> 26 child nodes 
- Cambodian alphabet: 74 characters -> 74 child nodes

#### The root node
 Where do the letters of different words live if the root node doesn’t house them all? =>  lies in the root node’s references to its children.

#### What's in a single node of a trie ?
Contains two things:
- A value, which might be `null`
- An array of references to child nodes, all of which also might be `null`

![[Pasted image 20240925102917.png]]

Each node in a trie, including the root node itself, has only these two aspects to it.
Ex: A tries representing the Eng language consists of :
- A single root node,  whose value is an empty string: `" "`
- An array that contains 26 references point to `null` at first. The character "A" would live at the array index of 0.

#### Giving trie traversal a try
 “Peter Piper picked a peck of pickled peppers”.
 ![[Pasted image 20240925104549.png]]
-  an empty root node - typical for a trie structure.
-  six different words: Peter, piper, picked, peck, pickled, and peppers
- follow the links from one node to another until we reached a `NULL` node -> insert a value into the node

What if we wanted to add the word pecked to this list?
1. Check the word `pecked` doesnt already exits 
2.  If we’ve traversed down the branch where this word ought to live and the words doesn’t exist yet -> insert a value into the node’s reference where the word should go


#### Understanding array pointers in a trie structure

![[Pasted image 20240925105828.png]]

- Insert the word "pie", give value 5 : `{ "pie": 5 }`
- Since this trie doesn’t have anything in just yet, the reference at `p` in our root node will be `null` => create a new node for `p` =>  the root node now has an array with 25 empty slots, and 1 slot (at index 15) that contains a reference to a node, holding the value for p
- i, e do the same thing

#### Searching through a trie
![[Pasted image 20240925133006.png]]
###### search hit
- since able to find a value for the key
- If search key "pie" and are able to find it, we can look to see => if it has a value and return it
###### search miss
-  since we could not find a value for the key.
- If search for the key "pi" and find the node at the last letter "i", we can look to see => if it has a NULL value, mean "pi" is not currently a key

#### Deleting from a trie:
![[Pasted image 20240925134140.png]]
- first, find the node for that key => set its value to null 
- second, check the node's references, if null => remove it . If there are pointers for other nodes that _do_ have values, we don’t want to delete the node that we’ve just set to `null`

#### Trying our hand at tries
###### Hash tables vs. tries
Hash tables -> array + linled lists
Tries -> arrays + pointers
Both tries and hash tables are reminscient of one another because they both use arrays under the hood.
Diffetence: 
- Trie doesnt need a **hash function** because every key can be represented in order (alphabetically), every path to an element will be unique. 
	The side effect:  
	- no collisions to deal with 
	- thus a relying on the index of an array is enough, and a hashing function is unnecessary.
-  a trie takes up a lot of memory/space with empty/null pointers

###### How tries changes as they grow
As a trie grows in singe, less work must be done to add a value since the "intermediate nodes" we’ve already initialized nodes, values, references. , or the branches of the trie have already been built up

Each time we add a word's letter, we need to look at 26 references, since there are only 26 letters in the alphabet. This number never changes in the context of out trie, so it is a constant value. 

###### Big O Notation 
The worst-case runtime for creating a trie is O(mn):
- m: the length of the longest key
- n: total number of keys
The time of searching, inserting, deleting from a trie depends on the length of the word (a) and the total number of words: O(a.n)

#### where are tries used?
- rarely used exclusively
- used in combination with another structure, or in the context of an algorithm.

- coolest example of how tries can be leveraged for their form and function is for autocomplete features, like the one used in search engines like Google.
- used for matching algorithms and implementing things like spellcheckers
- used for imlementing versions of [radix sort](https://medium.com/basecs/getting-to-the-root-of-sorting-with-radix-sort-f8e9240d4224)



-----
## References
1. https://medium.com/basecs/trying-to-understand-tries-3ec6bede0014
2.  [Digit-based sorting and data structures](https://www.cs.cmu.edu/~avrim/451f11/recitations/rec0921.pdf), Professor Avrim Blum
2. [Lecture Notes on Tries](https://www.cs.cmu.edu/~fp/courses/15122-f10/lectures/18-tries.pdf), Professor Frank Pfenning
3. [Algorithms: Tries](http://algs4.cs.princeton.edu/lectures/52Tries.pdf), Robert Sedgewick and Kevin Wayne
4. [Tries](https://brilliant.org/wiki/tries/), Brilliant Learning
5. [Tries](http://ellard.org/dan/www/libsq/cb_1998/c06.pdf), Daniel Ellard
6. [Tries](https://www.youtube.com/watch?v=TRg9DQFu0kU), Harvard CS50
