#include <stdbool.h>
#include <stdio.h>
#define FIRST_POSITION_AFTER_FIVE 3
#define LAST_VALUE_OF_PREALLOCATED_ARRAY 5
#define ARRAY_SIZE 168
#define MAX_PRIME_NUMBERS 1000
#define FIRSTS_OF_PRIME_NUMBERS 2, 3, 5

int allPrimeNumbers[ARRAY_SIZE] = {FIRSTS_OF_PRIME_NUMBERS};
int nextValue = LAST_VALUE_OF_PREALLOCATED_ARRAY;
int position = FIRST_POSITION_AFTER_FIVE;
int soma;

bool isPrime(int value, int position)
{

  while (position >= 0)
  {
    if (allPrimeNumbers[position] != 0)
    {

      if (value % allPrimeNumbers[position] == 0)
      {

        return false;
      }
    }
    position--;
  }

  return true;
}

bool NextNumber()
{

  if (isPrime(nextValue, position - 1))
  {

    allPrimeNumbers[position] = nextValue;
    position++;
  }
}

void printarr(int *arr, int size)
{
  for (int i = 0; i <= size; i++)
  {
    soma += arr[i];
    if (i == 0)
    {
      printf("[%i, ", arr[i]);
    }
    else if (i == size)
    {
      printf("%i]", arr[i]);
    }
    else
    {
      printf("%i, ", arr[i]);
    }
  }
}

int main()
{

  for (nextValue; nextValue < MAX_PRIME_NUMBERS; nextValue = nextValue + 2)
  {

    NextNumber();
  }
  int i = 4000000000;
  printf("%d, ", sizeof(i));
  printarr(allPrimeNumbers, ARRAY_SIZE - 1);
  printf("\n%d\n", soma);
  return 0;
};
