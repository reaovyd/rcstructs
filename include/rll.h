#ifndef __RLL_H__
#define __RLL_H__

typedef struct node_ll_t {
    void *data;
    struct node_ll_t *next;
    struct node_ll_t *prev;
} node_ll_t;

typedef struct ll_t {
    struct node_ll_t *head;
    struct node_ll_t *tail;
    int sz;
} ll_t;

ll_t *init_ll();

void rll_push_front(ll_t *ll, void *data);
void *rll_pop_front(ll_t *ll);

void rll_push_back(ll_t *ll, void *data);
void *rll_pop_back(ll_t *ll);

void *rll_front(ll_t *ll);
void *rll_back(ll_t *ll);

void rll_add(ll_t *ll, void *data, int index);
void *rll_remove(ll_t *ll, int index);

int rll_size(ll_t *ll);

void destroy_ll(ll_t *ll);

#endif /* __RLL_H__ */
