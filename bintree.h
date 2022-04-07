#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
using namespace std;

template <class Type>
class Bintree
{
private:
	class Treenode
	{
	public:
		Type Element;
		int Counter;
		Treenode* Left;
		Treenode* Right;

		//adaptation of Stack Node class constructors from lecture notes
		//all new tree nodes are given a Counter value of 1
		Treenode() : Counter(1), Left(nullptr), Right(nullptr) {}
		Treenode(Type data, Treenode* pnodeleft = nullptr, Treenode* pnoderight = nullptr) : Element(data), Counter(1), Left(pnodeleft), Right(pnoderight) {}
	};
	Treenode* Root;
	int Treenode_count; //number of nodes in tree
public:
	// Constructor functions
	Bintree();
	Bintree(vector<Type> items);
	bool Bin_search_tree_insert(Treenode*& node, const Type item);

	// Part 1 - Printing functions
	void Print_in_order(Treenode*& node, ostream& out_stream) const;

	//overload << to allow Binary Tree objects to be output with cout
	template <class Type>
	friend ostream& operator<<(ostream& out_stream, Bintree<Type>& out_binary_tree)
	{
		Treenode* temp = out_binary_tree.Root;

		out_binary_tree.Print_in_order(temp, out_stream);
		cout << endl;
		return out_stream;
	}

	//Part 2 - Quicksort functions
	void Populate_array(Treenode*& node, Treenode nodes[], int& array_index);
	void Swap(Treenode& a, Treenode& b);
	void Split(const int first, const int last, int& split_index, Treenode arr[]);
	void Quicksort(const int first, const int last, Treenode arr[]);

	// This function acts almost like a control function
	// for the process of generating an array of Treenodes,
	// populating it, sorting it, then printing it
	// in descending order of Treenode Counter value
	template <class Type>
	void Quick_sort_binary_search_tree(Bintree<Type> bst)
	{
		//generate array of Treenodes
		const int array_size = Treenode_count;
		Treenode* arr = new Treenode[array_size];

		//populate array of Treenodes
		Treenode* temp = bst.Root;
		int array_index = 0;
		Populate_array(temp, arr, array_index);

		//sort array
		Quicksort(0, array_size - 1, arr);

		//print array
		for (int i = array_size - 1; i >= 0; i--)
		{
			cout << arr[i].Element << " " << arr[i].Counter << endl;
		}
	}
};

#endif

