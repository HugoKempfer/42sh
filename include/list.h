/*
** EPITECH PROJECT, 2017
** my_list.h
** File description:
** File which contain all structs for sprite list.
*/

#ifndef	MY_LIST_H
#define	MY_LIST_H

typedef struct lnode_s lnode_t;
typedef struct llist_s llist_t;
typedef void (destroy_func_t)(void *);

struct lnode_s
{
	lnode_t *prev;
	lnode_t *next;
	void *data;
};

struct llist_s
{
	lnode_t *head;
	lnode_t *tail;
	int nb_nodes;
	destroy_func_t *destroyer;
};

lnode_t *list_create_node(void *);
int	list_push_head(void *, llist_t *);
int	list_push_tail(void *, llist_t *);
lnode_t	*list_index(int, lnode_t *);
void	list_pop(lnode_t *, llist_t *);
llist_t	*list_create(destroy_func_t *);
void list_destroy(llist_t *list);
llist_t *list_init(destroy_func_t *destroyer);

#endif	/* MY_LIST_H */
