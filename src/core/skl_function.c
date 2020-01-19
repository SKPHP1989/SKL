/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"

extern hash_t *global_function_table;

int register_all_internal_function() {
    char *var_dump_name = memory_alloc(sizeof ("var_dump"));
    strcpy(var_dump_name, "var_dump");
    register_internal_function(var_dump_name, function_var_dump);
    return RET_SUCCESS;
}

/**
 * 
 * @param function_name
 * @param function_addr
 */
void register_internal_function(char *function_name, variable_t *(*func_addr)(call_params_list_t *)) {
    if (is_not_empty(find_hash(global_function_table, function_name, strlen(function_name)))) {
        error_exception("Internal Function:%s has been defined!", function_name);
    }
    function_t * function = (function_t *) memory_alloc(sizeof (function_t));
    function->func_addr = func_addr;
    function->identifier = function_name;
    function->is_native = 1;
    function->param_list = NULL;
    function->statement_list = NULL;
    insert_or_update_hash(global_function_table, function_name, strlen(function_name), function);
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
                printf("(string) %s\n", v->value.str.val);
                break;
            default:
                printf("unkown type\n");
                break;
        }
        item = item->next;
    }
    return NULL;
}