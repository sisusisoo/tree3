#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
typedef struct TreeNode {
	char data;
	struct TreeNode* left, * right;
} TreeNode;

int top = -1;
TreeNode* stack[SIZE];

//				A	
//		B				C
// 	 D	   E		F

// 스택에 노드 추가
void push(TreeNode* p)
{
	if (top < SIZE - 1) {
		stack[++(top)] = p;
	}
}
// 스택에서 노드 꺼내기
TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}


// 반복적 전위 순회
void preorder_iter(TreeNode* root)
{
	push(root);
	while (top >= 0)
	{
		TreeNode* current = stack[top];
		TreeNode* del = pop();
		printf("%d --> ", del->data);

		TreeNode* temp = current->right;
		if (temp != NULL) {
			push(temp);
		}
		temp = current->left;
		if (temp != NULL) {
			push(temp);
		}

	}
	printf("\n");
}
// 반복적 중위 순회
void inorder_iter(TreeNode* root)
{
	top = -1;
	TreeNode* current = root;


	while (top >= 0 || current != NULL)
	{
		if (current != NULL) {
			push(current);
			current = current->left;
		}
		else {
			current = pop();
			printf(" %d -->", current->data); 
			current = current->right;
		}

	}
	printf("\n");

}
// 반복적 후위 순회
void postorder_iter(TreeNode* root)
{
	top = -1;
	int i = 0;
	TreeNode* node;
	TreeNode* output[SIZE];
	push(root);
	while (top >= 0) {
		node = pop();
		output[i++] = node;
		if (node->left != NULL)
			push(node->left);
		if (node->right != NULL)
			push(node->right);
	
	}

	for (i = i - 1; i >= 0; i--)
		printf("%d --> ", output[i]->data);

	printf("\n");

}
TreeNode n0, n1, n2, n3, n4, n5,n6,n7,n8,n9,n10;

TreeNode n0 = { 1, &n1, &n2 };
TreeNode n1 = { 2,&n3 , &n4 };
TreeNode n2 = { 7, &n5, &n6 };
TreeNode n3 = { 3, &n7,&n8 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 8, NULL,NULL };
TreeNode n6 = { 9, &n9, &n10 };
TreeNode n7 = { 4, NULL, NULL };
TreeNode n8 = { 5, NULL,NULL };
TreeNode n9 = { 10, NULL,NULL };
TreeNode n10 = { 11, NULL,NULL };
TreeNode* root = &n0;

int main()
{
	printf("------------전위 순회------------\n\n");
	preorder_iter(root);

	printf("\n\n------------중위 순회------------n\n");
	inorder_iter(root);

	printf("\n\n------------후위 순회------------n\n");
	postorder_iter(root);

	printf("\n");
	return  0;
}