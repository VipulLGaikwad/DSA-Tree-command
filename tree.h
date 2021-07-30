typedef struct node{
	char *name;
	int isdir;
	struct node *next_dir;
	struct node *next_file;
	int level;
}node;


node *create_tree(char *root_name);
node *create_treenor(char *root_name);
void print_tree(node *start);
node *create_node(char *n);
void report(int dir,int file);
void print_treed(struct node *start);
void reportd(int dir);
void help();
node* createtreep(char *dname);
void treepath(const char *name, int level);
void file(char *name, char *fname, char *mode);
void print_treeQ(node *start);
