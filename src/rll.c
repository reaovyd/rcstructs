#include <stdio.h>
#include <stdlib.h>
#include "../include/rll.h" // change back to < > later

static node_ll_t *init_node_ll_t(void *data) {
    node_ll_t *new_node = malloc(sizeof(node_ll_t));
    
    if(new_node == NULL)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

ll_t *init_ll() {
    ll_t *new_ll = malloc(sizeof(ll_t));
    if(new_ll == NULL)
        return NULL;
    new_ll->head = NULL;
    new_ll->tail = NULL;
    new_ll->sz   = 0;

    return new_ll;
}

void rll_push_front(ll_t *ll, void *data) {
    if(ll == NULL) {
        return;
    }
    node_ll_t *new_node = init_node_ll_t(data);
    if(new_node == NULL) {
        return;
    }
    if(ll->head == NULL) {
        ll->head = new_node;
        ll->tail = new_node;
        ++ll->sz;
        return;
    }
    ll->head->prev = new_node;
    new_node->next = ll->head;
    ll->head       = new_node;
    ++ll->sz;
}

void *rll_pop_front(ll_t *ll) {
    if(ll == NULL || ll->head == NULL)
        return NULL;
    void *data = ll->head->data;
    node_ll_t *tmpptr = ll->head;
    ll->head = ll->head->next;
    if(ll->head == NULL) {
        ll->tail = NULL;
    } else {
        ll->head->prev = NULL;
    }
    --ll->sz;
    free(tmpptr);
    return data;
}

void rll_push_back(ll_t *ll, void *data) {
    if(ll == NULL)
        return;
    if(ll->head == NULL) {
        rll_push_front(ll, data);
        return;
    }
    node_ll_t *new_node = init_node_ll_t(data);
    new_node->prev = ll->tail;
    ll->tail->next = new_node;
    ll->tail       = new_node;
    ++ll->sz;
}

void *rll_pop_back(ll_t *ll) {
    if(ll == NULL || ll->head == NULL)
        return NULL;
    if(ll->tail == ll->head) {
        return rll_pop_front(ll);
    }
    void *data = ll->tail->data;

    node_ll_t *nptr = ll->tail;
    ll->tail = ll->tail->prev;
    ll->tail->next = NULL;
    free(nptr);
    --ll->sz;

    return data; 
}
void *rll_front(ll_t *ll) {
    if(ll == NULL || ll->head == NULL)
        return NULL;

    return ll->head->data;
}
void *rll_back(ll_t *ll) {
    if(ll == NULL || ll->head == NULL)
        return NULL;

    return ll->tail->data;
}

// add after
void rll_add(ll_t *ll, void *data, int index) {
    if(ll == NULL || index <= -1 || index > ll->sz)
        return;
    if(ll->head == NULL || index == 0) {
        rll_push_front(ll, data);
        return;
    }
    node_ll_t *crs = ll->head;
    node_ll_t *prev_crs_ptr = NULL;
    int i = 0;

    while(i < index) {
        prev_crs_ptr = crs;
        crs = crs->next;
        ++i;
    }

    node_ll_t *new_node = init_node_ll_t(data);
    new_node->next = crs;
    new_node->prev = prev_crs_ptr;
    prev_crs_ptr->next = new_node;
    ++ll->sz;
}

void *rll_remove(ll_t *ll, int index) {
    if(ll == NULL || index <= -1 || index >= ll->sz || ll->head == NULL)
        return NULL;
    if(index == 0) {
        return rll_pop_front(ll);
    }
    if(index == ll->sz - 1) {
        return rll_pop_back(ll);
    }
    int i = 0;
    node_ll_t *crs = ll->head;

    while(i != index) {
        crs = crs->next;
    }
    void *data = crs->data;
    node_ll_t *crs_prev = crs->prev;
    crs_prev->next = crs->next;
    if(crs->next != NULL) {
        crs->next->prev = crs_prev;
    }
    free(crs);
    --ll->sz;
    return data;
}

int rll_size(ll_t *ll) {
    if(ll == NULL) {
        return 0;
    }

    return ll->sz;
}

void destroy_ll(ll_t *ll) {
    if(ll == NULL)
        return;
    node_ll_t *curr = ll->head;
    node_ll_t *next = ll->head;

    while(curr != NULL) {
        next = next->next;
        free(curr);
        curr = next;
    }

    free(ll);
}
