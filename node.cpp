#include "node.h"
#include "nodeselements.h"
#include "nodelist.h"

Node::Node()
{

}

Node::Node(const double &_x, const double &_y)
{
    x=_x;
    y=_y;
}
Node::Node(const Node& node)
{
    x = node.x;
    y = node.y;
}
Node& Node::operator=(const Node & node)
{
    x = node.x;
    y = node.y;
    return *this;
}

NodesElements *Node::GetNodesElements()
{
    return nodes->nodes_elements;
}
