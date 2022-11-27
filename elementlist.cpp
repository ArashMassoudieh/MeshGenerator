#include "elementlist.h"
#include "QFile"
#include "QTextStream"

ElementList::ElementList():vector<Element>()
{

}

ElementList::ElementList(const ElementList& elementlist):vector<Element>(elementlist)
{

}
ElementList& ElementList::operator=(const ElementList & elementlist)
{
    vector<Element>::operator=(elementlist);
    return *this;
}
ElementList::ElementList(const QString &filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QStringList line = in.readLine().split(",");
        if (line.size()==4)
        {
            Element element(line[1].toInt(),line[2].toInt(),line[3].toInt());
            push_back(element);
        }
        else if (line.size()==5)
        {
            Element element(line[1].toInt(),line[2].toInt(),line[3].toInt(),line[4].toInt());
            push_back(element);
        }

    }

    file.close();
}

void ElementList::SetParents(NodesElements *_nodeselements)
{
    nodes_elements = _nodeselements;
    for (int i=0; i<size(); i++)
    {
        operator[](i).SetElements(this);
    }
}
