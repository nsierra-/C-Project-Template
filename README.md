# Obj-parser
Simple parser of Wavefront Obj file written in ANSI C.

# About

Work in progress (hence ```main.c```).

Currently supported :
  - v
  - vt
  - vn
  - f

  See ```obj.h```for top-level functions documentation.
  
# Use Case

```c

#include "obj.h"

int				main(void)
{
	t_obj_data	*obj_data;
	obj_data = obj_parse("test.test");
	obj_print_data(obj_data);
	obj_delete_data(&obj_data);
	return EXIT_SUCCESS;
}
```
