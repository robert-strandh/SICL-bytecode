#include "object.h"

size_t header_size = sizeof(struct header);

#define CONS_TAG            0x001
#define IMMEDIATE_TAG       0x011
#define STANDARD_OBJECT_TAG 0x101
#define RACK_TAG            0x111

object
make_object(void)
{
  return ((object) malloc(header_size)) + STANDARD_OBJECT_TAG;
}

size_t rack_size = sizeof(struct rack);

rack
make_rack(size_t size)
{
  return (rack) malloc(rack_size + size);
}

object
class_of(object obj)
{
  return ((struct header *) (obj - STANDARD_OBJECT_TAG)) -> class;
}

rack
rack_of(object obj)
{
  return ((struct header *) (obj - STANDARD_OBJECT_TAG)) -> rack;
}

void
set_class_of(object obj, object class)
{
   ((struct header *) (obj - STANDARD_OBJECT_TAG)) -> class = class;
}

void
set_rack_of(object obj, rack r)
{
   ((struct header *) (obj - STANDARD_OBJECT_TAG)) -> rack = r;
}
