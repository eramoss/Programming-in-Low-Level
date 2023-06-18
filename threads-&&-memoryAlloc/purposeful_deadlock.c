#include <threads.h>
#include <unistd.h>
#include <stdio.h>

/**
 * WARNING!!!
 * This code is not thread safe for purposes
 * It is intended to be used only for testing and studies purposes
 * The codes never run, because function 1 needs to end function 2 and also function 2 needs to end function 1
 *
 * This problem is called by DEAD_LOCK
*/

mtx_t lock;
int function_1();
int function_2();

int function_2(void* arg) {
  mtx_lock(&lock);
  sleep(5);
  function_1(NULL);

  printf("function_2 done\n");
  mtx_unlock(&lock);
  return 0;
}

int function_1(void* arg) {
  mtx_lock(&lock);
  sleep(3);
  function_2(NULL);

  printf("function_1 done\n");
  mtx_unlock(&lock);
  return 0;
}

int main(int argc, char const* argv[]) {
  int err;
  thrd_t thread1, thread2;

  if (mtx_init(&lock, 1) != 0) {
    printf("Mutex initialization failed.\n");
    return 1;
  }


  thrd_create(&thread1, function_1, (void*)&thread1);
  thrd_create(&thread2, function_2, (void*)&thread2);

  thrd_join(thread1, NULL);
  thrd_join(thread2, NULL);

  return 0;
}
