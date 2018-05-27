/*
** EPITECH PROJECT, 2017
** markup.h
** File description:
** Our own markup language
*/

#ifndef	    MARKUP_H_
# define    MARKUP_H_

//Macros
# define DATA_RD_SIZE	4096

//ENUMERATIONS
typedef enum mtype
{
	ROOT = 0,
	CHILD = 1
} mtype_t;

typedef enum token_type_e
{
	LABEL = 1,
	VALUE = 2,
	BLOCK_ENTRY = 3,
	BLOCK_END = 4,
	LINE_END = 5,
	ASSIGN = 6,
	DEFAULT = 0
} token_type_t;

//STRUCTURES
typedef struct mroot_s
{
	int nb_nodes;
	struct mnode_s *head;
	struct mnode_s *tail;
} mroot_t;

typedef struct mchild_s
{
	char *value;
} mchild_t;

typedef struct mnode_s
{
	mtype_t type;
	char *label;
	struct mnode_s *next;
	struct mnode_s *prev;
	union {
		struct mchild_s *child;
		struct mroot_s *root;
	} data;
} mnode_t;

typedef struct mtoken_s
{
	char *token;
	token_type_t type;
} mtoken_t;

//Functions prototypes

//Create a new empty node
mnode_t *create_node(char *label, char *value);
//Create and insert a node inside the tree
mnode_t *insert_node_tail(char *label, char *value, mnode_t *root);
mnode_t *insert_node_head(char *label, char *value, mnode_t *root);
//Buffer
char *fill_buffer(char *path);
char *alloc_nstr(char *str, int len);
int get_next_word(char *str, int *cursor);
int get_next_occur(char *str, char c);
mtoken_t *markup_lexer(char *str);
//Get a node from its label
mnode_t *get_node(char *label, mnode_t *root);
char *get_value(char *label, mnode_t *root);
//Strings management functions
int	my_strcmp(const char *s1, const char *s2);
int my_strlen(char *str);
//Memory free
int destroy_tree(mnode_t *root);
int destroy_token_arr(mtoken_t *arr);
int delete_node(mnode_t *node, mnode_t *root);

#endif
