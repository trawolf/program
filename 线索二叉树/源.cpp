#include<iostream>
using namespace std;

template<class T>
struct BiThrNode {
	T data;
	BiThrNode* L_child, * R_child;
	int L_tag, R_tag;
};

template<class T>
BiThrNode<T>* CreatBiTree(BiThrNode<T>* BiTree, int k) {
	BiThrNode<T>* p, * t;
	T tmp;
	cout << "Input key: " << endl;
	cin >> tmp;
	cout << tmp << endl;
	if (tmp != '0') {
		p = new BiThrNode<T>;
		p->data = tmp;
		p->L_child = nullptr;
		p->R_child = nullptr;
		p->L_tag = 0;
		p->R_tag = 0;
		if (k == 0) t = p;
		if (k == 1) BiTree->L_child = p;
		if (k == 2) BiTree->R_child = p;

		CreatBiTree(p, 1);
		CreatBiTree(p, 2);
	}
	return BiTree;
}

template<class T>
void Inorder_Raverse(BiThrNode<T>* root) {
	if (root != nullptr) {
		Inorder_Raverse(root->L_child);
		cout << root->data << " ";
		Inorder_Raverse(root->R_child);
	}
}

template <class T>
void Inorder_Thread(BiThrNode< T> *BiTree,BiThrNode< T> **t) {
	if (BiTree != nullptr) {
		Inorder_Thread(BiTree->L_child, t);
		if (BiTree->L_child == nullptr) {
			BiTree->L_child = t;
			BiTree->L_tag = 1;
		}
		if ((*t != nullptr) && ((*t)->R_child == nullptr)) {
			(*t)->R_child = BiTree;
			(*t)->R_tag = 1;
		}
		Inorder_Thread(BiTree->R_child, t);
	}
}

template<class T>
void Intorder_Traverse(BiThrNode< T>* BiTree) {
	BiThrNode<T>* t;
	if (BiTree == nullptr) return;
	t = BiTree;
	while (t->L_tag == 0) t = t->L_child;
	cout << t->data << " ";
	while (t->R_child != nullptr) {
		if (t->R_tag == 1)
			t = t->R_child;
		else {
			t = t->R_child;
			while ((t->L_tag == 0) && (t->L_child != nullptr))
				t = t->L_child;
		}
		cout << t->data << " ";
	}
}

int main()
{
	typedef BiThrNode<char> BiTree_char;
	BiTree_char* root = new BiTree_char;
	root = CreatBiTree(root, 0);
	Inorder_Raverse(root);
	cout << endl;
	return 0;
}