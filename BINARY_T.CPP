#include<stdio.h>
#include<stdlib.h>

struct bin_tree
{
	int key_value;
	struct bin_tree *left;
	struct bin_tree *right;
};
typedef struct 	bin_tree node;

void insert(node ** tree, int value)
{
	node *temp = NULL;
	if(!(*tree))
	{
		temp = (node *) malloc(sizeof(node));
		temp-> left = NULL;
		temp-> right = NULL;
		temp-> 	key_value = value;
		*tree = temp;
		return;
	}

	if(value < (*tree)->key_value)
	{
		insert(&(*tree)->left, value);
	}

	else if(value > (*tree)->key_value)
	{
		insert(&(*tree)->right, value);
	}
}

void postorder(node *tree)
{
	if(tree)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ", tree->key_value);
	}
}

void preorder(node *tree)
{
	if(tree)
	{
		printf("%d ", tree->key_value);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(node *tree)
{
	if(tree)
	{
		inorder(tree->left);
		printf("%d ", tree->key_value);
		inorder(tree->right);
	}
}

void delete_tree(node * tree)
{
	if(tree)
	{
		delete_tree(tree->left);
			delete_tree(tree->right);
		free(tree);
	}
}

node* search(node ** tree, int value)
{
	if(!(*tree))
	{
		return NULL;
	}

	if(value < (*tree)->key_value)
	{
		search(&((*tree)->left), value);
	}
	else if(value > (*tree)->key_value)
	{
		search(&((*tree)->right), value);
	}
	else if(value == (*tree)->key_value)
	{
		return *tree;
	}
}

void main()
{
	node *parent;
	node *search_node;

	parent = NULL;

	insert(&parent, 5);
	insert(&parent, 7);
	insert(&parent, 4);
	insert(&parent, 10);
	insert(&parent, 15);
	insert(&parent, 25);
	insert(&parent, 8);

	printf("Pre-order : \n");
	preorder(parent);
	printf("Inorder : \n");
	inorder(parent);
	printf("Post-order : \n");
	postorder(parent);

	search_node = search(&parent, 15);
	if(search_node)
	{
		printf("Data found  = %d", search_node	->key_value);
	}
	else
		{
		printf("Data not found in binary tree");
	}

	delete_tree(parent);


}
