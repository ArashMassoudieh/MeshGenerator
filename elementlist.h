#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H

#include "element.h"
#include <vector>
#include <QString>

class NodesElements;

using namespace std;

class ElementList : public vector<Element>
{
public:
    ElementList();
    ElementList(const ElementList& ElementList);
    ElementList& operator=(const ElementList & ElementList);
    ElementList(const QString &filename);
    NodesElements *nodes_elements = nullptr;
    void SetParents(NodesElements *_nodeselements);

};

#endif // ELEMENTLIST_H
