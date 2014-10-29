#ifndef _ex22_h
#define _ex22_h

// Make the size in ex22.c available to other .c files
extern int THE_SIZE;

// gets and sets an internal static variable in ex22.c
int get_age();
void set_age(int age);

//updates a static var thats inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif
