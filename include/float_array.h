
#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

/**************** PUBLIC INTERFACE IMPLEMENTATION ****************/
typedef struct float_array floatArray;

floatArray *ena_create(int capacity);
void ena_destroy(floatArray **array);
int ena_size(const floatArray *array);
int ena_capacity(const floatArray *array);
float ena_at(const floatArray *array, int index);
float ena_get(const floatArray *array, int index);
void ena_append(floatArray *array, float value);
void ena_set(floatArray *array, int index, float value);
void ena_print(const floatArray *array);
void ena_remove(floatArray *array, int index);
void ena_erase(floatArray *array);
floatArray *ena_clone(const floatArray *array);
/****************************************************************/


#endif
