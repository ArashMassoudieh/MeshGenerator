#include "element.h"
#include "elementlist.h"
#include "nodeselements.h"
#include "math.h"

Element::Element():vector<int>()
{

}

Element::Element(vector<int> nodes):vector<int>(nodes)
{

}
Element::Element(const Element& element):vector<int>(element)
{

}

Element::Element(int i1, int i2, int i3)
{
    clear();
    push_back(i1);
    push_back(i2);
    push_back(i3);
}
Element::Element(int i1, int i2, int i3, int i4)
{
    clear();
    push_back(i1);
    push_back(i2);
    push_back(i3);
    push_back(i4);
}

Element& Element::operator=(const Element & element)
{
    vector<int>::operator=(element);
    return *this;

}

NodesElements *Element::GetNodeElements()
{
    return elements->nodes_elements;
}

double Element::Area()
{
    vector<Node*> vertexes = Nodes();
    if (vertexes.size()==4)
        return fabs(0.5*((vertexes[0]->X()-vertexes[2]->X())*(vertexes[1]->Y()-vertexes[3]->Y())-(vertexes[1]->X()-vertexes[3]->X())*(vertexes[0]->Y()-vertexes[2]->Y())));
    else
        return fabs(0.5* (vertexes[0]->X()*(vertexes[1]->Y() - vertexes[2]->Y()) + vertexes[1]->X()*(vertexes[2]->Y() - vertexes[0]->Y()) + vertexes[2]->X()*(vertexes[0]->Y() - vertexes[1]->Y())));
}

double Element::Area1()
{
    vector<Node*> vertexes = Nodes();
    if (vertexes.size()==4)
        return fabs(0.5* (vertexes[0]->X()*(vertexes[1]->Y() - vertexes[2]->Y()) + vertexes[1]->X()*(vertexes[2]->Y() - vertexes[0]->Y()) + vertexes[2]->X()*(vertexes[0]->Y() - vertexes[1]->Y())));
    else
        return 0;
}

double Element::Area2()
{
    vector<Node*> vertexes = Nodes();
    if (vertexes.size()==4)
        return fabs(0.5* (vertexes[0]->X()*(vertexes[3]->Y() - vertexes[2]->Y()) + vertexes[3]->X()*(vertexes[2]->Y() - vertexes[0]->Y()) + vertexes[2]->X()*(vertexes[0]->Y() - vertexes[3]->Y())));
            else
        return 0;
}

vector<Node*> Element::Nodes()
{
    vector<Node*> nodes;
    for (int i=0; i<size(); i++)
        nodes.push_back(&GetNodeElements()->nodes->at(at(i)));

    return nodes;
}

vector<double> Element::Centroid()
{
    vector<Node*> vertexes = Nodes();
    vector<double> cent(2);
    if (vertexes.size()==3)
    {
        cent[0] = (vertexes[0]->X()+vertexes[1]->X()+vertexes[2]->X())/3.0;
        cent[1] = (vertexes[0]->Y()+vertexes[1]->Y()+vertexes[2]->Y())/3.0;
    }
    else if (vertexes.size()==4)
    {
        double area1 = Area1();
        double area2 = Area2();
        vector<double> centroid1 = Centroid1();
        vector<double> centroid2 = Centroid2();
        cent[0] = area1*centroid1[0] + area2*centroid2[0]/(area1+area2);
        cent[1] = area1*centroid1[1] + area2*centroid2[1]/(area1+area2);
    }
    return cent;
}

vector<double> Element::Centroid1()
{
    vector<double> cent;
    vector<Node*> vertexes = Nodes();

    if (vertexes.size()==4)
    {
        cent.push_back((vertexes[0]->X()+vertexes[1]->X()+vertexes[2]->X())/3.0);
        cent.push_back((vertexes[0]->Y()+vertexes[1]->Y()+vertexes[2]->Y())/3.0);
    }
    return cent;
}

vector<double> Element::Centroid2()
{
    vector<double> cent;
    vector<Node*> vertexes = Nodes();

    if (vertexes.size()==4)
    {
        cent.push_back((vertexes[0]->X()+vertexes[3]->X()+vertexes[2]->X())/3.0);
        cent.push_back((vertexes[0]->Y()+vertexes[3]->Y()+vertexes[2]->Y())/3.0);
    }
    return cent;
}

bool Element::IsAdjacent(int element_number)
{
    vector<Node*> vertexes = Nodes();
    vector<Node*> othervertexes = AllElements()->at(element_number).Nodes();
    int count_commons = 0;
    for (int i=0; i<vertexes.size(); i++)
        for (int j=0; j<othervertexes.size(); j++)
            if (vertexes[i]==othervertexes[j])
                count_commons += 1;

    if (count_commons==2)
        return true;
    else
        return false;
}

vector<int> Element::FindAdjacentElements()
{
    vector<int> out;
    for (int i=0; i<AllElements()->size(); i++)
    {
        if (IsAdjacent(i) && AllElements()->at(i)!=*this)
        {
            out.push_back(i);
        }
    }
    return out;
}
