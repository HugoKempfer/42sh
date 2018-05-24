/*
** EPITECH PROJECT, 2017
** markup.h
** File description:
** Our own markup language
*/

#ifndef		SRC_MARKUP_H_
# define	SRC_MARKUP_H_

# ifndef	DATA_RD_SIZE
#  define	DATA_RD_SIZE	(4096)
# endif		/* DATA_RD_SIZE */

typedef enum mtype
{
	ROOT = 0,
	CHILD = 1
} mtype_t;

typedef enum token_type_e
{
	DEFAULT,
	LABEL,
	VALUE,
	BLOCK_ENTRY,
	BLOCK_END,
	LINE_END,
	ASSIGN
} token_type_t;

typedef struct mroot_s mroot_t;
typedef struct mchild_s mchild_t;
typedef struct mnode_s mnode_t;
typedef struct mtoken_s mtoken_t;

struct mroot_s
{
	int nb_nodes;
	mnode_t *head;
	mnode_t *tail;
};

struct mchild_s
{
	char *value;
};

struct mnode_s
{
	mtype_t type;
	char *label;
	mnode_t *next;
	mnode_t *prev;
	union {
		mchild_t *child;
		mroot_t *root;
	} data;
};

struct mtoken_s
{
	char *token;
	token_type_t type;
};

//Create a new empty node
mnode_t *create_node(char *label, char *value);

//Create and insert a node inside the tree
mnode_t *insert_node_tail(char *label, char *value, mnode_t *root);
mnode_t *insert_node_head(char *label, char *value, mnode_t *root);

//Buffer
char *fill_buffer(char *path);
char *alloc_str(char *str, int len);
int get_next_word(char *str, int *cursor);
int get_next_occur(char *str, char c);
mtoken_t *markup_lexer(char *str);
mnode_t *parse_file(char*);

//Get a node from its label
mnode_t *get_node(char *label, mnode_t *root);
char *get_value(char *label, mnode_t *root);

//Memory free
int destroy_tree(mnode_t *root);
int destroy_token_arr(mtoken_t *arr);
int delete_node(mnode_t *node, mnode_t *root);

# define	UNABLE_PARSING	"Unable to parse file: File may be corrupted\n"

#endif		/* SRC_MARKUP_H_ */
