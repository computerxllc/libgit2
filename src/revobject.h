#ifndef INCLUDE_objecttable_h__
#define INCLUDE_objecttable_h__

#include "git/common.h"
#include "git/oid.h"

struct git_revpool_object
{
    git_oid id;
    git_revpool *pool;
};

struct git_revpool_node
{
    struct git_revpool_object *object;
    unsigned int hash;
    struct git_revpool_node *next;
};

struct git_revpool_table
{
    unsigned int size_mask;
    unsigned int count;
    unsigned int max_count;
    struct git_revpool_node **nodes;
};


typedef struct git_revpool_node git_revpool_node;
typedef struct git_revpool_object git_revpool_object;
typedef struct git_revpool_table git_revpool_table;

git_revpool_table *git_revpool_table_create(unsigned int min_size);
int git_revpool_table_insert(git_revpool_table *table, git_revpool_object *object);
git_revpool_object *git_revpool_table_lookup(git_revpool_table *table, const git_oid *id);
void git_revpool_table_resize(git_revpool_table *table);


#endif
