#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "tree.h"

node *create_node(char *n){
	node *temp = (node*)malloc(sizeof(node));
	temp->name = n;
	temp->next_dir = NULL;
	temp->next_file = NULL;
	return temp;	
}

void help(){
	printf("-a   Prints all files and directories including the hidden files.\n");
	printf("-d  List directories only\n");
	printf("-i  Makes tree not print the indentation line\n");
	printf("-o  Outputs the tree in the file\n");
	printf("-Q  Prints the output in double quotes\n");
	printf("--help  Provides us help\n");
	printf("--prune  Doesn't print the empty directories\n");
	printf("--noreport omits printing the files and directories at the end\n");
	
}


