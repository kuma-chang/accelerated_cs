#ifndef purchase_h
#define purchase_h

#include "ordered_list.h"
#include "queue.h"
#include "stack.h"

const int SIZE = 500;

int feature_list(char *product_info);
bool again();
void ol_display(Ordered_list &ol);
void add_feature_to_wanted_list(Ordered_list &wanted_features);
void remove_feature_from_the_wanted_list(Ordered_list &wanted_features);

void get_car_node(car_node *node_to_add);
void add_new_car(Queue &car_list);

void compare(Ordered_list &wanted_features, Queue &car_list, Stack &reject_list);
void push_to_reject(Queue &car_list, Stack &reject_list);


#endif
