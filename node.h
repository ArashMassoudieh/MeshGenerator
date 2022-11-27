#ifndef NODE_H
#define NODE_H

class NodeList;
class NodesElements;

class Node
{
public:
    Node();
    Node(const double &x, const double &y);
    Node(const Node& node);
    Node& operator=(const Node & node);
    void SetNodes(NodeList *_nodes) {nodes = _nodes;}
    NodesElements *GetNodesElements();
    double X() {return x;}
    double Y() {return y;}
private:
    NodeList* nodes = nullptr;

private:
    double x=0;
    double y=0;
};

#endif // NODE_H
