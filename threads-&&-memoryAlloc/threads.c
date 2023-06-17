#include <threads.h>
#include <stdio.h>
#include <unistd.h> 
#include <time.h>
#define TIME_TO_WAIT_1 6
#define TIME_TO_WAIT_2 3


int function_2(void* arg) {
  int* idThread = (int*)arg;
  sleep(TIME_TO_WAIT_2);
  printf("Waiting for %d seconds in thread %d...\n", TIME_TO_WAIT_2, *idThread);
  return 0;
}

int function_1(void* arg) {
  int* idThread = (int*)arg;

  sleep(TIME_TO_WAIT_1);
  printf("Waiting for %d seconds in thread %d...\n", TIME_TO_WAIT_1, *idThread);
  return 0;
}


int main(int argc, char const* argv[]) {
  time_t start;
  time(&start);

  thrd_t thread1, thread2;
  thrd_create(&thread1, function_1, (void*)&thread1);

  thrd_create(&thread2, function_2, (void*)&thread2);
  thrd_join(thread1, NULL);
  thrd_join(thread2, NULL);


  time_t end;
  time(&end);
  time_t final = (end - start);

  printf("The program was executed in: %d seconds\n", (int)final);


  return 0;
}
