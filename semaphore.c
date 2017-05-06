#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <memory.h>

int main()
{
  sem_t *sem = (sem_t *)malloc(sizeof(sem_t)); 
  sem_init(sem, 0, 0);
  sem_post(sem);
  sem_wait(sem);
  sem_destroy(sem);
  free(sem);
  sem_post(sem);
  return 0;
}
