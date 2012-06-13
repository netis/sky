#include <stdlib.h>
#include "../../dbg.h"

#include "var_ref.h"
#include "node.h"

//==============================================================================
//
// Functions
//
//==============================================================================

// Creates an AST node for a variable reference.
//
// name - The name of the variable value.
// ret  - A pointer to where the ast node will be returned.
//
// Returns 0 if successful, otherwise returns -1.
int eql_ast_var_ref_create(bstring name, eql_ast_node **ret)
{
    eql_ast_node *node = malloc(sizeof(eql_ast_node)); check_mem(node);
    node->type = EQL_AST_TYPE_VAR_REF;
    node->parent = NULL;
    node->var_ref.name = bstrcpy(name);
    check_mem(node->var_ref.name);
    *ret = node;
    return 0;

error:
    eql_ast_node_free(node);
    (*ret) = NULL;
    return -1;
}

// Frees a variable reference AST node from memory.
//
// node - The AST node to free.
void eql_ast_var_ref_free(struct eql_ast_node *node)
{
    if(node->var_ref.name) {
        bdestroy(node->var_ref.name);
    }
    node->var_ref.name = NULL;
}
