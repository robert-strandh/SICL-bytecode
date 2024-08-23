#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <stdint.h>

typedef uint64_t object;

typedef struct rack *rack;

struct header
{
  object class;
  rack rack;
};

struct rack
{
  int stamp;
  object slot_definitions;
};

extern object make_standard_object(void);

extern rack make_rack(size_t size);

extern object class_of(object obj);

extern void set_class_of(object obj, object class);

extern rack rack_of(object obj);

extern void set_rack_of(object obj, rack r);

extern size_t header_size;

extern size_t rack_size;

#endif
