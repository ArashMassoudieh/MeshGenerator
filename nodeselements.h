#ifndef NODESELEMENTS_H
#define NODESELEMENTS_H

#include "nodelist.h"
#include "elementlist.h"

class NodesElements
{
public:
    NodesElements();
    NodeList *nodes;
    ElementList *elements;
    void SetParents();
    bool CreateOHQSingleLayer(const QString &filename);
};

#endif // NODESELEMENTS_H
