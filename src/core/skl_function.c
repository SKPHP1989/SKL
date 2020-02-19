/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#include "skl_execute.h"
#include "skl_execute_expression.h"

extern global_info_t global_info;

/**
 * 
 * @return 
 */
int register_all_internal_function() {
    char *function_name = memory_alloc(sizeof ("var_dump"));
    strcpy(function_name, "var_dump");
    register_internal_function(function_name, function_var_dump);
    //
    function_name = memory_alloc(sizeof ("sleep"));
    strcpy(function_name, "sleep");
    register_internal_function(function_name, function_sleep);
    //
    function_name = memory_alloc(sizeof ("time"));
    strcpy(function_name, "time");
    register_internal_function(function_name, function_time);
    return RET_SUCCESS;
}

/**
 * 
 * @param function_name
 * @param function_addr
 */
void register_internal_function(char *function_name, void *(*func_addr)(call_params_list_t *)) {
    if (is_not_empty(find_hash(global_info.function_table, function_name, strlen(function_name)))) {
        error_exception("Internal Function:%s has been defined!", function_name);
    }
    function_t * function = (function_t *) memory_alloc(sizeof (function_t));
    function->func_addr = func_addr;
    function->identifier = function_name;
    function->is_native = 1;
    function->param_list = NULL;
    function->statement_list = NULL;
    insert_or_update_hash(global_info.function_table, function_name, strlen(function_name), function);
}

/**
 * 
 * @param call_params_list
 */
void *function_var_dump(call_params_list_t *call_params_list) {
    call_params_list_t *item = call_params_list;
    zvalue_t *v;
    while (item) {
        v = item->value;
        switch (v->type) {
            case zvalue_type_null:
                printf("(null)\n");
                break;
            case zvalue_type_bool:
                printf("(bool) %s\n", v->value.b ? "true" : "false");
                break;
            case zvalue_type_integer:
                printf("(integer) %d\n", v->value.i);
                break;
            case zvalue_type_double:
                printf("(double) %f\n", v->value.d);
                break;
            case zvalue_type_string:
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

void *function_sleep(call_params_list_t *call_params_list) {
    call_params_list_t *item = call_params_list;
    zvalue_t *v;
    while (item) {
        v = item->value;
        switch (v->type) {
            case zvalue_type_integer:
                sleep(abs(v->value.i));
                break;
            case zvalue_type_double:
                sleep(floor(fabs(v->value.d)));
                break;
            case zvalue_type_string:
            case zvalue_type_null:
            case zvalue_type_bool:
            default:
                break;
        }
        item = item->next;
    }
    return NULL;
}

void *function_time(call_params_list_t *call_params_list) {
    zvalue_t *res = create_null_zvalue();
    res->type = zvalue_type_integer;
    struct timeval stamp;
    gettimeofday(&stamp, NULL);
    res->value.i = stamp.tv_sec;
    return res;
}