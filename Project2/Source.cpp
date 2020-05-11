//Mariah Diaz
//CIS 3501
//Fall 2019
//Prof. John P. Baugh
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

//The function checks if input is a binary tree. It uses the vector that 
//the tree values are put in, and the root of the tree. The output 
//is either true or false 
bool IsaBST(vector<int> values, int root)
{
	bool left = true, right = true;

	//leaf node
	if (values[root] == -1)
		return true;

	//check left node
	if (values[root] < values[root * 2 + 1] && values[root * 2 + 1] != -1)
		left = false;
	//check right node
	if (values[root] > values[root * 2 + 2] && values[root * 2 + 2] != -1)
		right = false;

	if (left == false || right == false)
	{
		return false;
	}

	return IsaBST(values, root * 2 + 1) && IsaBST(values, root * 2 + 2);
}

//The function is for preorder traversal. Its input is the vector of values
//from the file and the root of the tree. The function puts the values in the
//tree in the preorder traversal for output
void preOrder(vector<int> values, int root)
{
	if (values[root] == -1)
		return;
	cout << values[root] << " ";
	preOrder(values, root * 2 + 1);
	preOrder(values, root * 2 + 2);
}

//The function is for in order traversal. The input is the vector of values
//from the file and the root of the tree. The function puts the values in the
//tree in the in order traversal for output
void inOrder(vector<int> values, int root)
{
	if (values[root] == -1)
		return;
	inOrder(values, root * 2 + 1);
	cout << values[root] << " ";
	inOrder(values, root * 2 + 2);
}

//The function is for post order traversal. The input is the vector of values
//from the file and the root of the tree. The function puts the values in the
//tree in the post order traversal for output
void postOrder(vector<int> values, int root)
{
	if (values[root] == -1)
		return;
	postOrder(values, root * 2 + 1);
	postOrder(values, root * 2 + 2);
	cout << values[root] << " ";
}

int main()
{
	vector<int> treeValues; //the vector that stores the values from the file to load into the BST

	ifstream file("tree.txt");

	while (!file.eof()) //while you are not at the end of the file, the values will be loaded to the vector
	{
		int tempInt;
		file >> tempInt;
		treeValues.push_back(tempInt);
	}

	if (IsaBST(treeValues, 0)) //If the function that checks for a BST returns true,
		//then output "yes" and the preorder, inorder, and postorder traversals
	{
		cout << "Yes." << endl;
		preOrder(treeValues, 0);
		cout << endl;
		inOrder(treeValues, 0);
		cout << endl;
		postOrder(treeValues, 0);
	}
	else //if the function that checks for a BST returns false, then output "no"
		cout << "No" << endl;
	cout << endl;

	system("pause");
}