#include "skl_core.h"
#include "skl_variable.h"

/**
 * 
 * @param identifier
 * @param value
 * @return 
 */
variable_t *create_variable(char *identifier, zvalue_t *value) {
    variable_t *v = (variable_t *) memory_alloc(sizeof (variable_t));
    v->identifier = identifier;
    v->value = value;
    return v;
}