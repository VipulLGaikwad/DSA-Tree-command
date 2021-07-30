#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "tree.h"

node *create_tree(char *root_name){
	DIR *dir = opendir(root_name);

	struct dirent *dr = NULL;

	node *root = NULL, *p = NULL, *q = NULL;
	char *name = (char *)calloc(2000,sizeof(char));
	
	if(dir == NULL){
		printf("Open failed\n");
		return NULL;
	}

	while((dr = readdir(dir)) != NULL){
		
		if(strcmp((dr->d_name),".")!=0 && strcmp((dr->d_name),"..")!=0)
			p = create_node(dr->d_name);
		else{
			p = NULL;
			continue;
		}
		if(q != NULL)
			q->next_file = p;
		else
			root = p;
	
		if((dr->d_type) == DT_DIR){
			p->isdir = 1;
			strcpy(name,root_name);
			(p->next_dir)=create_tree((strcat((strcat(name,"/")),dr->d_name)));
		}
		else{
			p->isdir = 0;
			p->next_dir = NULL;
		}
		q = p;
	}
	closedir(dir);
	return root;	

}

//function to create the normal tree without any hidden file
node *create_treenor(char *root_name){
	DIR *dir = opendir(root_name);

	struct dirent *dr = {NULL};

	node *root = NULL, *p = NULL, *q = NULL;
	char *name = (char *)calloc(2000,sizeof(char));
	
	if(dir == NULL){
		printf("Open failed\n");
		return NULL;
	}

	while((dr = readdir(dir)) != NULL){
		
		if(strcmp((dr->d_name),".")!=0 && strcmp((dr->d_name),"..")!=0 && dr->d_name[0] != '.')
			p = create_node(dr->d_name);
		else{
			p = NULL;
			continue;
		}
		if(q != NULL)
			q->next_file = p;
		else
			root = p;
	
		if((dr->d_type) == DT_DIR){
			p->isdir = 1;
			strcpy(name,root_name);
			(p->next_dir)=create_tree((strcat((strcat(name,"/")),dr->d_name)));
		}
		else{
			p->isdir = 0;
			p->next_dir = NULL;
		}
		q = p;
	}
	closedir(dir);
	return root;	

}
node* createtreep(char *root_name){
	DIR *dir = opendir(root_name);
	char *name = (char *)calloc(2000,sizeof(char));	
	if(dir == NULL) {
		printf("Open failed\n");
		return NULL;
	}
	struct dirent *dr = NULL;
	node *root = NULL,*p = NULL,*q = NULL;
	while((dr = readdir(dir)) != NULL){
		if(strcmp((dr->d_name), ".")!=0 && strcmp((dr->d_name), "..") != 0) {
			p = create_node(dr->d_name);				
		}
		else {
			p = NULL;
			continue;
		}
		if(q != NULL) {
			q->next_file = p;
		}
		else {
			root = p;
		}
		if((dr->d_type) == DT_DIR) {
			p->isdir = 1;
			strcpy(name,root_name);
			(p->next_dir)=createtreep((strcat((strcat(name,"/")),dr->d_name)));
			if(p->next_dir == NULL) {
				free(p);
			}
			else {
				q = p;
			}	
		}
		else {
			
			p->isdir = 0;
			p->next_dir = NULL;
			q = p;	
		}
	}
	closedir(dir);
	return root;
}


