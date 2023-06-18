#include <threads.h>
#include <unistd.h>
#include <stdio.h>

mtx_t lock;
int j;

int function_1(void* arg) {
  mtx_lock(&lock); // lock to prevent concurrent thread access same memory of function
  int i = 0;

  j++;

  while (i < 5) {
    printf("%d", j);
    sleep(1);

    i++;
  }

  printf("...Done\n");

  //mtx_unlock(&lock);
  /*
    mtx_unlock(&lock);
    unlock the function to other thread access and make process
    if doesn't unlock the function, the 2 thread will be blocked
    and the process will be blocked in this function
  */
  return 0;
}

int main(int argc, char const* argv[]) {
  int err;
  thrd_t thread1, thread2;

  if (mtx_init(&lock, 1) != 0) {
    printf("Mutex initialization failed.\n");
    return 1;
  }

  j = 0;

  thrd_create(&thread1, function_1, (void*)&thread1);
  thrd_create(&thread2, function_1, (void*)&thread1);

  thrd_join(thread1, NULL);
  thrd_join(thread2, NULL);

  return 0;
}
