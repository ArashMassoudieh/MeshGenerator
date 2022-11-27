#include "nodelist.h"
#include "QFile"
#include "QTextStream"

NodeList::NodeList():map<int,Node>()
{

}

NodeList::NodeList(const NodeList& nodelist):map<int,Node>(nodelist)
{

}
NodeList& NodeList::operator=(const NodeList & nodeList)
{
    map<int,Node>::operator=(nodeList);
    return *this;
}

NodeList::NodeList(const QString &filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QStringList line = in.readLine().split(",");
        if (line.size()==3)
        {
            map<int,Node>::operator[](line[0].toInt()) = Node(line[1].toDouble(),line[2].toDouble());
        }
    }

    file.close();
}

void NodeList::SetParents(NodesElements *_nodeselements)
{
    nodes_elements = _nodeselements;
    for (map<int,Node>::iterator it = begin(); it!=end(); it++)
    {
        it->second.SetNodes(this);
    }
}
