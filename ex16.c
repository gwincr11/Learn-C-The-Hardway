#include <stdio.h>   // Standard io
#include <assert.h> // Import assert function
#include <stdlib.h> // Library for standard var types and methods we use malloc and free
#include <string.h> // work with strings and arrays

// Define the person structure. Similar to a class.
struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

// function to create person struct and allocate memory
struct  Person *Person_create(char *name, int age, int height, int weight) {
  // setup the memory blocks. Use the size of person to allocate the correct amount.
  struct Person *who = malloc(sizeof(struct Person));
  // make sure memory was setup
  assert(who != NULL);

  // set attributes, duplicate the name string to make sure it is not a pointer.
  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
};

// Destroy the person by deallocating memory
void Person_destroy(struct Person *who) {
  // make sure we have a struct
  assert(who != NULL);
  // delete the duplicated string name
  free(who->name);
  // delete the person struct
  free(who);
}

void Person_print(struct Person *who) {
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n",who->age );
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n",who->weight );
}


int main(int argc, char *argv[]) {

  struct Person *joe = Person_create("Joe Alex", 32, 64, 140) ;

  struct  Person *frank = Person_create("Frank Blank", 20, 72, 180);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", frank);
  Person_print(frank);
  // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);


  return 0;
}