/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skl_function.h"
extern hash_t *global_function_table;


void register_internal_function(void *function_addr, char *function_name) {
    insert_or_update_hash(global_function_table, function_name, strlen(function_name), function_addr);
}

/**
 * 
 * @param call_params_list
 */
variable_t *function_var_dump(call_params_list_t *call_params_list) {
    call_params_list_t *item = call_params_list;
    variable_t *v;
    while (item) {
        v = item->var;
        switch (v->type) {
            case variable_type_null:
                printf("(null)\n");
                break;
            case variable_type_bool:
                printf("(bool) %s\n", v->value.b ? "true" : "false");
                break;
            case variable_type_int:
                printf("(integer) %d\n", v->value.i);
                break;
            case variable_type_double:
                printf("(double) %f\n", v->value.d);
                break;
            case variable_type_string:
                printf("(string) %s\n", v->value.str);
                break;
            default:
                printf("unkown type\n");
                break;
        }
        item = item->next;
    }
    return NULL;
}

//register_internal_function(function_var_dump, "var_dump");