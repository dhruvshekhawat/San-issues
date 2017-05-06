/*Usage: 
clang -fsanitize=memory -O0 undefined-issue.c && ./a.out
clang -fsanitize=memory -O1 undefined-issue.c && ./a.out

-O0 throws a use-of-uninitialized-value error but -O1 does not. We feel this is
because with -O1 flag the code is optimized at compile time and line 23 changes to
if(true) and val==30 condition is never checked. On the other hand, with no optimization, 
val == 30 is checked and sanitizer figures out the use of uninitialized value
*/

#include <stdio.h>
#include <stdbool.h>

bool initialize_value(volatile bool cond, int* val) {
  if (!cond)
    return false;
  *val = 20;
  return true;
}

int main() {
  int val;
  bool initialized = initialize_value(false, &val);
  if (val==30 || !initialized)
    printf("Done\n");
}
