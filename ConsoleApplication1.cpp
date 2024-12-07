#include<iostream>
#include<string>
using namespace std;

struct Tree {
	string data;
	Tree* left;
	Tree* right;

	Tree(string value) {
		data = value;
		left = right = NULL;
	}
};

//Kiem tra ham rong?
bool isEmpty(Tree* goc) {
	return goc == NULL;
}

//Ham khoi tao
void initTree(Tree*& goc, string gia_tri) {
	if (isEmpty(goc)) {
		goc = new Tree(gia_tri);
	}
	else {
		return;
	}
}

//Ham nhap phan tu (bo sung) vao cay
void Add_tree(Tree*& node, string gia_tri) {
	if (isEmpty(node)) {
		node = new Tree(gia_tri);	
		return;
	} else {
		if (node->left == NULL) {
			node->left = new Tree(gia_tri);
		}
		else if (node->right == NULL) {
			node->right = new Tree(gia_tri);
		}
		else {
			cout << "Error!";
			return;
		}
	}
	return;
}

//In ra tien to
void tien_to(Tree* n) {
	if (n == NULL)
		return;
	cout << n->data << " ";
	tien_to(n->left);
	tien_to(n->right);
}

//In ra trung to
void trung_to(Tree* n) {
	if (n == NULL)
		return;
	trung_to(n->left);
	cout << n->data << " ";
	trung_to(n->right);
}

//In ra hau to
void hau_to(Tree* n) {
	if (n == NULL)
		return;
	hau_to(n->left);
	hau_to(n->right);
	cout << n->data << " ";
}

int main() {
	Tree* Nguyet = NULL;

	initTree(Nguyet, "+");

	Add_tree(Nguyet->left, "-");
	Add_tree(Nguyet->right, "*");
	Add_tree(Nguyet->left->left, "*");
	Add_tree(Nguyet->left->right, "/");
	Add_tree(Nguyet->right->left, "-");
	Add_tree(Nguyet->right->right, "^");
	Add_tree(Nguyet->left->left->left, "a");
	Add_tree(Nguyet->left->left->right, "5");
	Add_tree(Nguyet->left->right->left, "*");
	Add_tree(Nguyet->left->right->right, "d");
	Add_tree(Nguyet->right->left->left, "h");
	Add_tree(Nguyet->right->left->right, "f");
	Add_tree(Nguyet->right->right->left, "e");
	Add_tree(Nguyet->right->right->right, "/");
	Add_tree(Nguyet->left->right->left->left, "b");
	Add_tree(Nguyet->left->right->left->right, "^");
	Add_tree(Nguyet->right->right->right->left, "1");
	Add_tree(Nguyet->right->right->right->right, "2");
	Add_tree(Nguyet->left->right->left->right->left, "c");
	Add_tree(Nguyet->left->right->left->right->right, "6");

	//In tien to
	cout << "Cay in ra tien to: ";
	tien_to(Nguyet);
	cout << endl;

	//In trung to
	cout << "Cay in ra trung to: ";
	trung_to(Nguyet);
	cout << endl;

	//In hau to
	cout << "Cay in ra hau to: ";
	hau_to(Nguyet);
	cout << endl;

	return 0;
}