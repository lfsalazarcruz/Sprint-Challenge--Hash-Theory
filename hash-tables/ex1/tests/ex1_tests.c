#include "../ex1.h"
#include "../../utils/utils.h"
#include "../../utils/minunit.h"

char *test_ex1()
{
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  printf("-1\n");
  mu_assert(answer_1 == NULL, "Your function did not return the expected answer for input {9}");
  printf("passed +1\n\n");

  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  printf("-2 \n");
  mu_assert(answer_2->index_1 == 1, "Your function did not return the expected answer for input {4, 4}");
  mu_assert(answer_2->index_2 == 0, "Your function did not return the expected answer for input {4, 4}");
  printf("passed +2 \n\n");

  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  printf("-3 \n");
  mu_assert(answer_3->index_1 == 3, "Your function did not return the expected answer for input {4, 6, 10, 15, 16}");
  mu_assert(answer_3->index_2 == 1, "Your function did not return the expected answer for input {4, 6, 10, 15, 16}");
  printf("passed +3 \n\n");


  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  printf("-4 \n");
  mu_assert(answer_4->index_1 == 6, "Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  mu_assert(answer_4->index_2 == 2, "Your function did not return the expected answer for input {12, 6, 7, 14, 19, 3, 0, 25, 40}");
  printf("passed +4 \n\n");

  return NULL;
}

char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_ex1);

  return NULL;
}

RUN_TESTS(all_tests);