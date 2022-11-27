#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>

class ElementList;
class NodesElements;
class Node;

using namespace std;
class Element: public vector<int>
{
public:
    Element();
    Element(const Element& element);
    Element& operator=(const Element & element);
    Element(vector<int> nodes);
    Element(int i1, int i2, int i3);
    Element(int i1, int i2, int i3, int i4);
    void SetElements(ElementList *_elements) {elements = _elements;}
    NodesElements *GetNodeElements();
    double Area();
    double Area1();
    double Area2();
    vector<double> Centroid();
    vector<double> Centroid1();
    vector<double> Centroid2();
    vector<Node*> Nodes();
private:
    ElementList* elements = nullptr;
};

#endif // ELEMENT_H
