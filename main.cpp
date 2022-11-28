#include <QCoreApplication>
#include "nodelist.h"
#include "elementlist.h"
#include "nodeselements.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NodeList nodeList("/home/arash/Dropbox/Drywell Project/Coordinates/nodes.csv");
    ElementList elementList("/home/arash/Dropbox/Drywell Project/Coordinates/elements.csv");
    NodesElements system;
    system.nodes = &nodeList;
    system.elements = &elementList;
    system.SetParents();
    system.CreateOHQSingleLayer("/home/arash/Dropbox/Drywell Project/Coordinates/model.ohq");
    return a.exec();
}
