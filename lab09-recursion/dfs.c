// Compile with: clang -Wall dfs.c -o dfs
// Run with: ./dfs
//
// This is a great lab to practice debugging.
// First compile with debugging symbols
// Compile with: clang -Wall -g dfs.c -o dfs
// Run with: gdb ./dfs --tui
//   Then type 'start'
//   Then type 'next' or 'n' and enter
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
  struct TreeNode* left;
  struct TreeNode* right;
  char data;
} TreeNode_t;

// Depth-First Tree Traversal
// Make sure to print out each node you visit, and only print it out once!
// **Hint** Think recursively
void dfs(TreeNode_t* start){
    // TODO: Hmm, how can I look through both branches of the node?
    // TODO: Hmm, when do I stop?
    //

	//Base case for the recursive function. This provides the termination condition. 
	if (start == NULL){
		return;
	}

	//This block of code first prints the root node. It then makes a recursive call to the print function
	//and prints out the left sub-tree first, followed by the right sub-tree. 
	printf("%s\n", &start->data);
	dfs(start->left);
	dfs(start->right);

}
// TODO: Write a helper function to free all the nodes
// // Think carefully of the order that nodes should be freed.
// // Use valgrind to make sure that you were successful!


//Function to recursively delete the tree. The input parameter is a pointer to the root node. 
void delete_tree(TreeNode_t* start){

	//Base case for the recursive function. This provides the termination condition. 
        if (start == NULL){
                return;
        }

	// This block of code first deletes the right sub-tree, followed by the left sub-tree, and finally deletes
	// the root node itself and then frees it from memory. 
        delete_tree(start->right);
        delete_tree(start->left);
        printf("Deleting node %s.\n", &start->data);
	free(start);

}


int main(){

  // Manually create a tree for this lab
  TreeNode_t* start = malloc(sizeof(TreeNode_t));
  TreeNode_t* a= malloc(sizeof(TreeNode_t));
  TreeNode_t* b= malloc(sizeof(TreeNode_t));
  TreeNode_t* c= malloc(sizeof(TreeNode_t));
  TreeNode_t* d= malloc(sizeof(TreeNode_t));
  TreeNode_t* e= malloc(sizeof(TreeNode_t));
  TreeNode_t* f= malloc(sizeof(TreeNode_t));
  TreeNode_t* g= malloc(sizeof(TreeNode_t));
  TreeNode_t* h= malloc(sizeof(TreeNode_t));

  // The root of our tree  
  // The root also has two 'branches' a and b.
  start->data = 's';
  start->left = a;
  start->right = b;
  
  a->data = 'a';
  a->left = c;
  a->right = d;
  
  b->data = 'b';
  b->left = e;
  b->right = f;
  
  c->data = 'c';
  c->left = g;
  c->right = h;

  // All of the 'leaves' in our tree
  d->data = 'd';
  d->left = NULL;
  d->right = NULL;   
  
  e->data = 'e';
  e->left = NULL;
  e->right = NULL;

  f->data = 'f';
  f->left = NULL;
  f->right = NULL;
  
  g->data='g';
  g->left = NULL;
  g->right = NULL;

  h->data = 'h';
  h->left = NULL;
  h->right = NULL;
  
  // Perform the dfs
  dfs(start);
 
  delete_tree(start);

return 0; 
  // Perform the dfs at a different spot
}

