#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"




int main(){
  
  // Object creation
  struct Heap *a = malloc(sizeof(struct Heap));
  a->init = &heap_init;
  a->destroy = &heap_destroy;
  
  // An empty heap can be initialized to a max Heap
  a->init(a,4,2);
  assert(a->private_size == 4);
  assert(a->property_flag == 2);
  
  // An empty heap can heapify an array
  float sampleArray[] = {1.00,2.00,3.00};
  a->methods->heapify(a,sampleArray,3);
  assert(a->H[0] == 3.00);
  assert(a->H[1] == 2.00);
  assert(a->H[2] == 1.00);
  assert(a->length == 3);
  
  // Can add an element to the heap
  a->methods->insert(a,4.00);
  assert(a->length == 4);
  assert(a->H[0] == 4.00);
  assert(a->H[1] == 3.00);
  assert(a->H[2] == 1.00);
  assert(a->H[3] == 2.00);


  // Can add an element when the next element would exceed the size of the array
  a->methods->insert(a,5.00);
  assert(a->length == 5);
  assert(a->H[0] == 5.00);
  assert(a->H[1] == 4.00);
  assert(a->H[2] == 1.00);
  assert(a->H[3] == 2.00);
  assert(a->H[4] == 3.00);

  // Can pop max/min element
  int answer = a->methods->pop(a);
  assert(answer == 5);
  assert(a->length == 4);
  assert(a->H[0] == 4.00);
  assert(a->H[1] == 3.00);
  assert(a->H[2] == 1.00);
  assert(a->H[3] == 2.00);

  // Can replace the max/min element with provided element
  a->methods->replace(a,1);
  assert(a->H[0] == 3);
  assert(a->H[1] == 2);
  assert(a->H[2] == 1);
  assert(a->H[3] == 1);

  // Can heapify an array and add to an existing heap
  float anotherArray[] = {7,6,5};
  a->methods->heapify(a,anotherArray,3);
  assert(a->H[0] == 7);
  assert(a->H[1] == 3);
  assert(a->H[2] == 6);
  assert(a->H[3] == 1);
  assert(a->H[4] == 2);
  assert(a->H[5] == 1);
  assert(a->H[6] == 5);

  a->destroy(a);
  free(a);


 struct Heap *b = malloc(sizeof(struct Heap));

 b->init= &heap_init;
 b->destroy = &heap_destroy;

 // Can create empty heap
 b->init(b,0,2);

 // Can insert into a empty heap
 b->methods->insert(b,5);
 assert(b->H[0] == 5);

 b->destroy(b);
 free(b);

  return 0;
}




