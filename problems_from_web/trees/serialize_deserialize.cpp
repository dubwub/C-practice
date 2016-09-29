#include <vector>
#include <iostream>
#include <cstddef>

using namespace std;

template<class T> class LinkedListNode;
template<class T> class BinaryTreeNode;

template<class T> class LinkedListNode {
public:
	LinkedListNode<T>(T value_) : value(value_) {}
	LinkedListNode<T>* left;
	LinkedListNode<T>* right;
	T value;

	vector<T> getVector() {
		LinkedListNode<T>* tmp = left;
		vector<T> output;
		while (tmp->left) tmp = tmp->left;
		while (tmp->right) {
			output.push_back(tmp->value);
			tmp = tmp->right;
		}
		return output;
	}

	void printList() {
		LinkedListNode<T>* tmp = this;
		cout << value << ", ";
		while (tmp->right) {
			cout << tmp->value << ", ";
			tmp = tmp->right;
		}
		cout << endl;
	}

	void deleteList() {
		if (right) right->deleteList();
		delete this;
	}

private:
	BinaryTreeNode<T>* serializeFromVector(vector<T>& list, int start, int end) {
		if (start == end) {
			return new BinaryTreeNode<T>(list[start]);
		}
		int rootIndex = (start + end)/2;
		BinaryTreeNode<T>* root = new BinaryTreeNode<T>(list[rootIndex]);
		root->left = serializeFromVector(list, start, rootIndex - 1);
		root->right = serializeFromVector(list, rootIndex + 1, end);
	}

public:
	BinaryTreeNode<T>* serialize() {
		vector<T> list = getVector();
		return serializeFromVector(list, 0, list.size() - 1);
	}
};

template<class T> class BinaryTreeNode {
public:
	BinaryTreeNode<T>(T value_) : value(value_) {}
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	T value;

	LinkedListNode<T>* deserialize() {
		LinkedListNode<T>* leftList = NULL;
		LinkedListNode<T>* rightList = NULL;
		LinkedListNode<T>* tmp = NULL;
		LinkedListNode<T>* thisNode = new LinkedListNode<T>(value);
		if (left) leftList = left->deserialize();
		if (right) rightList = right->deserialize();
		if (leftList) {
			tmp = leftList;
			while (tmp->right) tmp = tmp->right;
			tmp->right = thisNode;
			thisNode->left = tmp;
		}
		thisNode->right = rightList;
		return leftList;
	}

	void printTree() {
		cout << "Value: " << value << ",";
		if (left) cout << "left: " << left->value;
		if (right) cout << ", right: " << right->value;
		cout << endl;
		if (left) left->printTree();
		if (right) right->printTree();
	}

	void deleteTree() {
		if (left) left->deleteTree();
		if (right) right->deleteTree();
		delete this;
	}
};

int main() {
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
	root->left = new BinaryTreeNode<int>(3);
	root->right = new BinaryTreeNode<int>(8);
	root->printTree();
	LinkedListNode<int>* serializedRoot = root->deserialize();
	cout << serializedRoot->value << endl;
	serializedRoot->printList();
	serializedRoot->deleteList();
	root->deleteTree();
}