#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include "tree.h"

int count = 0; 
int max =0;
int dir_in_path = 0;
int files_in_path = 0;

void tree_file(struct node *start, FILE *fp) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;

	if(temp->name[0] != '.') {
		fprintf(fp, "\n");
		for(i = 0; i < (count - 1); i++)
			fprintf(fp, "%s", s1);
		if(count>0)
			fprintf(fp, "%s",s);
		if(temp->isdir== 1) {
			fprintf(fp,"%s",temp->name);
			
		}
		else {
			fprintf(fp, "%s", temp->name);
			
		}
	}
	if(temp->isdir == 1) {	
		count++;
		tree_file(temp->next_dir, fp);
		count--;
	}
	tree_file(temp->next_file, fp);	
}

void initfile(char *name, char *fname, char *mode) {
	FILE *fp;
	fp = fopen(fname, "w");
	if(fp == NULL) {
		printf("tree: invalid filename %s", fname);
	}
	struct node *root = create_node(name);
	root->isdir = 1;
	(root->next_dir) = create_tree(name);
	/*if(!(strcmp(mode, "-a")))
		tree_filea(root, fp);
	else if(!(strcmp(mode, "-d")))
		tree_filed(root, fp);
	else if(!(strcmp(mode, "-f")))
		tree_filef(root, 0, fp);
	else if(!(strcmp(mode, "-i"))) 
		printtreeleveli(root);
	else*/
		tree_file(root, fp);
//	if(nore == 0)
//		fprintf(fp, "\n%d directories, %d files\n", direc, file);
}


int main(int argc,char *argv[]){
	if(!(strcmp(argv[1], "-o")))
				initfile(".", argv[2], "-A");
}













