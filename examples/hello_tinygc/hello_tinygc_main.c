#include <nuttx/config.h>
#include <stdio.h>
#include <setjmp.h>
#include <assert.h>

#include <gc.h>

int main(int argc, FAR char *argv[])
{
  int i;

  GC_init();
  printf("Hello, tinygc World!!\n");
  for (i = 0; i < 100; ++i)
   {
     int **p = (int **) GC_malloc(sizeof(int *));
     int *q = (int *) GC_malloc_atomic(sizeof(int));
     DEBUGASSERT(*p == 0);
     // *p = (int *) GC_realloc(q, 2 * sizeof(int));
     if (i % 10 == 0)
       printf("Heap size = %d\n", GC_get_heap_size());
   }
  return 0;
}
