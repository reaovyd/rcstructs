#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/rll.h"

// #define _DEBUG

bool test_linked_list() {
    ll_t *ll = init_ll();

    destroy_ll(ll);
}

int main(void) {
    printf("%d\n", test_linked_list());
    return 0;
}
