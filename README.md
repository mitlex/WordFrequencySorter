This assignment was created as part of the coursework for the following module:
https://www.dundee.ac.uk/module/ac52002

The program is split into two parts.

Part 1 - Printing Words in Alphabetical Order
 
The program first reads in a text file of words and stores each word in a vector of strings. This vector is used to construct a binary search tree (BST) of Treenodes. Each Treenode in the BST contains a unique word from the text file with a counter of the number of times that unique word appeared in the text file (word occurrence frequency). The BST is printed in alphabetical order using in-order traversal.
 
Part 2 - Printing Words in Descending Order of Occurrence Frequency

In order to sort each Treenode in the BST in descending order of word occurrence frequency, a Quicksort algorithm was used. This was accomplished as follows:
 
Whilst constructing the BST, the program generates a count of the number of Treenodes in the BST. This Treenode count is used as an array size to create an array of Treenodes. This array is then populated using in-order traversal of the BST, where each Treenode visited in the tree is placed in the array.

The Quicksort algorithm is then applied to the array of Treenodes, in doing so ordering the Treenodes in descending order of word occurrence frequency. 

Lastly, the array is printed descending from the last index to the first index, showing the words in descending order of their occurrence frequency.

Here is an example:

![image](https://user-images.githubusercontent.com/94235400/162186596-2354fbb3-68ce-461b-b6b0-cb312e395201.png)

![image](https://user-images.githubusercontent.com/94235400/162186632-d7bb39af-b035-46fc-9efe-de1f24575bd9.png)

