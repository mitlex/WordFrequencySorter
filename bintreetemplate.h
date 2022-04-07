#ifndef BINTREETEMPLATE_H
#define BINTREETEMPLATE_H
#include "bintree.h"

// Default Constructor
template<class Type>
Bintree<Type>::Bintree() : Root(nullptr), Treenode_count(0) {}

// Constructor where vector passed as argument
// Creates a binary search tree
template<class Type>
Bintree<Type>::Bintree(vector<Type> items)
{
	// create tree root with first vector item, default Counter = 1
	Root = new Treenode(items[0]);
	Treenode_count = 1;

	// for all remaining items in vector
	for (int i = 1; i < items.size(); i++)
	{
		Bin_search_tree_insert(Root, items[i]);
	}
}

// general logic credit - https://stackoverflow.com/questions/8183985/recursive-insertion-of-bst
// searches for item in tree, if found: increment Counter
// otherwise inserts a new tree node representing the item at the correct position, with Counter = 1
template<class Type>
bool Bintree<Type>::Bin_search_tree_insert(Treenode*& node, const Type item)
{
	if (node == nullptr) //empty slot found
	{
		//create new node (Counter 1 by default - see Treenode constructor)
		Treenode* new_node;
		new_node = new Treenode(item);

		//point left or right pointer of parent node at new node
		//left or right depends on if we recursively called node->Left or node->Right
		node = new_node;

		Treenode_count++;

		return true;
	}
	else if (item == node->Element)
	{
		node->Counter++;
		return true; // item found, Counter incremented
	}
	else if (item < node->Element)
	{
		return Bin_search_tree_insert(node->Left, item);
	}
	else
	{
		return Bin_search_tree_insert(node->Right, item);
	}
}

// general logic taken from lecture notes
// prints entire tree using in-order traversal
// If type is string, words printed in alphabetical order
template<class Type>
void Bintree<Type>::Print_in_order(Treenode*& node, ostream& out_stream) const
{
	if (node != nullptr)
	{
		Print_in_order(node->Left, out_stream); // Traverse left subtree
		out_stream << node->Element << " " << node->Counter << endl; // Output root
		Print_in_order(node->Right, out_stream); // Traverse right subtree
	}
}

// general logic taken from lecture notes
// takes empty array and populates it using in-order traversal of tree
template<class Type>
void Bintree<Type>::Populate_array(Treenode*& node, Treenode nodes[], int& array_index)
{
	if (node != nullptr)
	{
		Populate_array(node->Left, nodes, array_index); // Traverse left subtree
		nodes[array_index] = *node;
		array_index++;
		Populate_array(node->Right, nodes, array_index); // Traverse right subtree
	}
}

// general logic taken from lecture notes
// swaps two Treenodes in the array
template<class Type>
void Bintree<Type>::Swap(Treenode& a, Treenode& b)
{
	Treenode temp = a;
	a = b;
	b = temp;
}

// general logic taken from lecture notes
// performs splitting operation on array
template<class Type>
void Bintree<Type>::Split(const int first, const int last, int& split_index, Treenode arr[])
{
	int left, right; // Markers for searching from left and right
	int pivot; // Pivot element

	pivot = arr[first].Counter;
	left = first;
	right = last;

	while (left < right) // While markers have not met
	{
		// Search from the right for treenode with counter <= pivot
		while (arr[right].Counter > pivot)
			right = right - 1;
		// Search from the left for treenode with counter > pivot
		while ((left < right) && (arr[left].Counter <= pivot))
			left = left + 1;
		// If markers have not met, interchange elements
		if (left < right)
			Swap(arr[left], arr[right]);
	};

	// Searches complete; now place pivot in correct place
	split_index = right;
	Swap(arr[first], arr[split_index]);
}

// general logic taken from lecture notes
// Sorts portion of array between arr[first] and arr[last]
template<class Type>
void Bintree<Type>::Quicksort(const int first, const int last, Treenode arr[])
{
	{
		int split_index; // Final position of pivot
		if (first < last) // Array has at least two elements
		{
			Split(first, last, split_index, arr); // Split into two subarrays
			Quicksort(first, split_index - 1, arr); // Sort left subarray
			Quicksort(split_index + 1, last, arr); // Sort right subarray
		}
		// else array has 0 or 1 elements and needs no sorting
	}
}

#endif
