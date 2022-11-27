#include "nodeselements.h"

NodesElements::NodesElements()
{

}

void NodesElements::SetParents()
{
    nodes->SetParents(this);
    elements->SetParents(this);
}
