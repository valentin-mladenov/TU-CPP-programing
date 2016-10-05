//
// Created by hudson on 4.10.2016 г..
//

#ifndef QUICKSORT3OFDECK_QUICKSORT_H
#define QUICKSORT3OFDECK_QUICKSORT_H

struct dl_node *partition(struct dl_node *l, struct dl_node *h);
void _quickSort(struct dl_node *l, struct dl_node *h);
void quickSort(struct double_list *doubleList);

#endif //QUICKSORT3OFDECK_QUICKSORT_H
