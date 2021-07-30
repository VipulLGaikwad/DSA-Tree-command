#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "tree.h"

int count2 = 0; 
int max2 =0;

void tree_file(struct node *start, FILE *fp) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;

	if(temp->name[0] != '.') {
		fprintf(fp, "\n");
		for(i = 0; i < (count2 - 1); i++)
			fprintf(fp, "%s", s1);
		if(count2>0)
			fprintf(fp, "%s",s);
		if(temp->isdir== 1) {
			fprintf(fp,"%s",temp->name);
			
		}
		else {
			fprintf(fp, "%s", temp->name);
			
		}
	}
	if(temp->isdir == 1) {	
		count2++;
	
		tree_file(temp->next_dir, fp);
		count2--;
	}
	
	tree_file(temp->next_file, fp);	
}

void file(char *name, char *fname, char *mode) {
	FILE *fp;
	fp = fopen(fname, "w");
	if(fp == NULL) {
		printf("tree: invalid filename %s", fname);
	}
	struct node *root = create_node(name);
	root->isdir = 1;
	(root->next_dir) = create_tree(name);
	tree_file(root, fp);


}
