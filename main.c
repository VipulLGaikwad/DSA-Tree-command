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

void print_tree(node *start){
			
		char *s="|    ",*s1="|----";
		int i;
		node *temp=start;
		if(start==NULL)
			return;

	
		temp->level=count;
		if(count > max)
			max=count;
		printf("\n");
		for(i=0;i<(count-1);i++)
			printf("%s",s);
		if(count>0)
			printf("%s",s1);
		//printf("%s",temp->name);
		
		if(temp->isdir == 1){
			printf("\033[0;34m%s", temp->name);
			//printf("%s",temp->name);
			printf("\033[0m");
		}
		else
			printf("%s",temp->name);
		
		if(temp->isdir==1)
		{	
			dir_in_path += 1;
			//printf("\tDIRECTORY");

			count++;
			print_tree(temp->next_dir);
			count--;
		}

		files_in_path += 1;
		print_tree(temp->next_file);
		

}

void print_treed(struct node *start){
	char *s = "|----",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	
		if(temp->isdir ==1) {	
			printf("\n");
			for(i = 0;i < count - 1; i++)
				printf("%s", s1);
			if(count > 0)
				printf("%s", s);
			printf("\033[0;34m%s", temp->name);
			printf("\033[0m");
			dir_in_path += 1;
			count++;
			print_treed(temp->next_dir);
			count--;
		}
		print_treed(temp->next_file);	
}



void print_treei(node *start){
			
		node *temp=start;
		if(start==NULL)
			return;
		printf("%s\n",temp->name);
		
		//Checks if it's a directory
		if(temp->isdir==1)
		{	
			dir_in_path += 1;
			print_treei(temp->next_dir);
		}

		files_in_path += 1;
		print_treei(temp->next_file);
}


void print_treeQ(node *start){
			
		char *s="|    ",*s1="|----";
		int i;
		node *temp=start;
		if(start==NULL)
			return;

	
		temp->level=count;
		if(count > max)
			max=count;
		printf("\n");
		for(i=0;i<(count-1);i++)
			printf("%s",s);
		if(count>0)
			printf("%s",s1);
		
		printf("\"%s\"",temp->name);
		
		//Checks if it's a directory
		if(temp->isdir==1)
		{	
			dir_in_path += 1;
			printf("\tDIRECTORY");

			count++;
			print_treeQ(temp->next_dir);
			count--;
		}

		files_in_path += 1;
		print_treeQ(temp->next_file);
		

}

void printtreed(struct node *start) {
	char *s1 = "|----",*s = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	
		if(temp->isdir ==1) {	
			printf("\n");
			for(i = 0;i < count - 1; i++)
				printf("%s", s);
			if(count > 0)
				printf("%s", s1);
			printf("%s", temp->name);
			count++;
			printtreed(temp->next_dir);
			count--;
		}
		printtreed(temp->next_file);	
}




void report(int dir,int file){
	printf("\n**********SUMMARY**********\n");
	printf("Number of directories in the given path : %d\n",dir);
	printf("Number of Files in the given path : %d\n",file);

}

void reportd(int dir){
	printf("\nNumber of directories in the given path : %d\n",dir);
}





int main(int argc,char *argv[]){
	if(argc == 1){
		node *start=create_node(".");
		start->isdir=1;
		(start->next_dir)=create_treenor(getcwd(0,0));		
		print_tree(start);
		report(dir_in_path-1,files_in_path-dir_in_path);
	}
	else if(argc == 2){
		if((strcmp(argv[1],"-a") != 0) && (strcmp(argv[1],"--help") != 0) &&(strcmp(argv[1],"--noreport") != 0) && (strcmp(argv[1],"-d") != 0) && (strcmp(argv[1],"-i") != 0) && (strcmp(argv[1],"--prune") != 0)  && (strcmp(argv[1],"-Q") != 0)){
			char *filename = argv[1];	
			node *start=create_node(filename);	
			start->isdir=1;
			(start->next_dir)=create_tree(filename);
			print_tree(start);
			report(dir_in_path-1,files_in_path-dir_in_path);
		}
		else if(!(strcmp(argv[1],"-a"))){//also prints the hidden files
			node *start=create_node(".");
			start->isdir=1;
			(start->next_dir)=create_tree(getcwd(0,0));		
			print_tree(start);
			report(dir_in_path-1,files_in_path-dir_in_path);
		}
		else if(!(strcmp(argv[1],"-d"))){
			node *start=create_node(".");
			start->isdir=1;
			(start->next_dir)=create_tree(getcwd(0,0));		
			print_treed(start);
			reportd(dir_in_path-1);
		}
		else if(!(strcmp(argv[1],"-i"))){
			node *start=create_node(".");
			start->isdir=1;
			(start->next_dir)=create_treenor(getcwd(0,0));		
			print_treei(start);
			report(dir_in_path-1,files_in_path-dir_in_path);
		}
		else if(!(strcmp(argv[1],"--noreport"))){
			node *start=create_node(".");
			start->isdir=1;
			(start->next_dir)=create_tree(getcwd(0,0));
			print_tree(start);
		}	
		else if(!(strcmp(argv[1],"--help"))){
			node *start=create_node(".");
			start->isdir=1;
			(start->next_dir)=create_tree(getcwd(0,0));
			help();
		}
		else if(!(strcmp(argv[1],"--prune"))){
			node *start=create_node(".");
			start->isdir=1;
			(start->next_dir)=createtreep(getcwd(0,0));		
			print_tree(start);
			report(dir_in_path-1,files_in_path-dir_in_path);
		
		}
		else if(!(strcmp(argv[1],"-Q"))){//also prints the hidden files
			node *start=create_node(".");
			start->isdir=1;
			(start->next_dir)=create_treenor(getcwd(0,0));		
			print_treeQ(start);
			report(dir_in_path-1,files_in_path-dir_in_path);
		}
	}
	else if(argc == 3){
		if(!(strcmp(argv[1], "-o")))
			file(".", argv[2], "-A");
	}

}













