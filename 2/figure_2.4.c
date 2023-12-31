#include <stddef.h>
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++)
    printf(" %.2x", start[i]);
  printf("\n");
}

void show_int(int x) {
  printf("show_int. sizeof(int): %lu\n", sizeof(int));
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
  printf("show_int. sizeof(float): %lu\n", sizeof(float));
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
  printf("show_int. sizeof(void *): %lu\n", sizeof(void *));
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float) ival;
  int *pval = &ival;
  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

int main(void) {
  int i = 12345;

  test_show_bytes(i);

  return 0;
}
