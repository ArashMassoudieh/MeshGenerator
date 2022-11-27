#ifndef NODELIST_H
#define NODELIST_H

#include <vector>
#include "node.h"
#include <QString>
#include <map>

class NodesElements;

using namespace std;

class NodeList: public map<int,Node>
{
public:
    NodeList();
    NodeList(const NodeList& nodelist);
    NodeList& operator=(const NodeList & nodeList);
    NodeList(const QString &filename);
    NodesElements *nodes_elements = nullptr;
    void SetParents(NodesElements *_nodeselements);
};

#endif // NODELIST_H
