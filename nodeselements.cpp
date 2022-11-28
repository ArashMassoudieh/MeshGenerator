#include "nodeselements.h"
#include <QFile>

NodesElements::NodesElements()
{

}

void NodesElements::SetParents()
{
    nodes->SetParents(this);
    elements->SetParents(this);
}

bool NodesElements::CreateOHQSingleLayer(const QString &filename)
{

    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    file.write("addtemplate; filename = /home/arash/Projects/QAquifolium/bin/Release/../../resources/unsaturated_soil.json\n");
    for (int i=0; i<elements->size(); i++)
        file.write(QString("create block;type=Soil,theta_sat=0.4,theta_res=0.05,specific_storage=0.01,x="+QString::number(elements->at(i).Centroid()[0]*1000)+",Evapotranspiration=,n=1.41,y="+QString::number(elements->at(i).Centroid()[1]*1000)+",area="+QString::number(elements->at(i).Area())+",theta=0.2,K_sat_original=1,_width=50,alpha=1,name=Soil ("+QString::number(i+1)+"$"+QString::number(1)+"),_height=50,bottom_elevation="+QString::number(-0.5)+",depth="+QString::number(-0.5)+",actual_x="+QString::number(elements->at(i).Centroid()[0])+",actual_y="+QString::number(elements->at(i).Centroid()[1])+"\n").toUtf8());

    file.close();
    return true;
}
