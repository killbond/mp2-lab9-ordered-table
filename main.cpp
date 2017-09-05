#include "include/OrderedTable.h"
#include <iostream>

int main(void)
{
    OrderedTable<int,char*> table(10);

    table.add("e", 7);
    table.add("a", 1);
    table.add("b", 3);
    table.add("d", 5);
    table.add("c", 4);

    table.getall();
}