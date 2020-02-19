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
#include "skl_execute_function.h"
#include "skl_execute_for.h"

/**
 * 
 * @param fors
 * @param variable_table
 * @return 
 */
statement_control_t *execute_for_statement(for_statement_t *fors, hash_t *variable_table) {
    execute_expression(fors->before, variable_table);
    zvalue_t *condition_res = execute_expression(fors->condition, variable_table);
    statement_control_t *control_exe;
    int is_break, is_continue;
    while (zvalue_convert_bool(condition_res)) {
        is_break = is_continue = 0;
        condition_res = execute_expression(fors->condition, variable_table);
        control_exe = execute_statement(fors->statement_list, variable_table);
        execute_expression(fors->after, variable_table);
        switch (control_exe->type) {
            case statement_control_type_return:
                return control_exe;
                break;
            case statement_control_type_break:
                is_break = 1;
                break;
            case statement_control_type_continue:
                is_continue = 1;
                break;
            case statement_control_type_default:
            default:
                break;
        }
        memory_free(control_exe->result);
        memory_free(control_exe);
        if (is_break) {
            break;
        }
        if (is_continue) {
            continue;
        }
    }
    return create_default_statement_control();
}
