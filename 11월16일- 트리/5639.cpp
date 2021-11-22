#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
	int data;
	struct node* left, * right;
}node;

node* bst_insert(node* root, int key) {

	if (root == NULL) {
		 root = (node*)malloc(sizeof(node));
		root->data = key;
		root->left = root->right = NULL;
		return root;
	}
	
	if (root->data >= key) // key값이 더 작다면, 왼쪽 서브트리에 삽입.
		root->left =bst_insert(root->left, key);
	else // key값이 더 크다면, 오른쪽 서브트리에 삽입.
		root->left = bst_insert(root->right, key);

	return root;
}

// l -> r - > v
void post_order(node *root) {

	if (root == NULL)
		return;

	post_order(root->left);
	post_order(root->right);
	cout << root;
}


int main() {

	int n;
	cin >> n;
	
	node* root=NULL;

	
	while (cin>>n) {
		if (n == EOF) break;
		root=bst_insert(root,n);
	}
	post_order(root);

	
}