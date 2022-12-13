// collaborated with Leandra McPhie and Sumayyah Husain

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "process.h"
#include "util.h"

#define DEBUG 0 // enable verbose output, change to 1

/**
 * Signature for an function pointer that can compare
 * You need to cast the input into its actual
 * type and then compare them according to your
 * custom logic
 */
typedef int (*Comparer)(const void *a, const void *b);

/**
 * compares 2 processes
 * You can assume:
 * - Process ids will be unique
 * - No 2 processes will have same arrival time
 */

int my_comparer(const void *this, const void *that) {
  Process *process_1 = (Process *)this;
  Process *process_2 = (Process *)that;

  if (process_1 -> priority < process_2 -> priority) {
    return 1;
  } else if (process_1 -> priority > process_2 -> priority) {
    return -1;
  } else {
    if (process_1 -> arrival_time > process_2 -> arrival_time) {
      return 1;
    } else if (process_1 -> arrival_time < process_2 -> arrival_time) {
      return -1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
    fflush(stdout);
    return 1;
  }

  /*******************/
  /* Parse the input */
  /*******************/
  FILE *input_file = fopen(argv[1], "r");
  if (!input_file) {
    fprintf(stderr, "Error: Invalid filepath\n");
    fflush(stdout);
    return 1;
  }

  Process *processes = parse_file(input_file);

  /*******************/
  /* sort the input  */
  /*******************/
  Comparer process_comparer = &my_comparer;

#if DEBUG
  for (int i = 0; i < P_SIZE; i++) {
    printf("%d (%d, %d) ", processes[i] -> pid, processes[i] -> priority,
           processes[i] -> arrival_time);
  }
  printf("\n");
#endif

  qsort(processes, P_SIZE, sizeof(Process), process_comparer);

  /**************************/
  /* print the sorted data  */
  /**************************/

  for (int i = 0; i < P_SIZE; i++) {
    printf("%d (%d, %d)\n", processes[i].pid, processes[i].priority,
           processes[i].arrival_time);
  }
  fflush(stdout);
  fflush(stderr);

  /************/
  /* clean up */
  /************/
  free(processes);
  fclose(input_file);
  return 0;
}
