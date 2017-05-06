#include <stdlib.h>
/*Note: There is nothing wrong with the below code. Address sanitizer reports an error: attempting 
free on address which was not malloc()-ed. This means it does not have the
ability to intercept aligned_alloc calls which is a relatively new C11 feature. Somebody using it 
in their code would get a false positive.
*/

int main(void)
{
  void * p = aligned_alloc(128, 1024);
  free(p);
}
