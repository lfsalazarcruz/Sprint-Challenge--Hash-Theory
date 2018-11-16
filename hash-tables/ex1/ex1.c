#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *answer = malloc(sizeof(Answer));

  for (int i = 0; i < length; i++) {
    printf("looping %d \n", i);
    int hash_retrieve = hash_table_retrieve(ht, weights[i]);

    if(hash_retrieve != -1) {
      answer->index_1 = i;
      printf("Anwser->index_1: %d \n", answer->index_1);
      answer->index_2 = hash_retrieve;
      printf("Anwser->index_2: %d \n", answer->index_2);
      destroy_hash_table(ht);
      return answer;
    }
    else {
      hash_table_insert(ht, limit-weights[i], i);
    }
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};

  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);

  if (answer_4->index_1 != 6)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  if (answer_4->index_2 != 2)
    printf("Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");

  return 0;
}
#endif