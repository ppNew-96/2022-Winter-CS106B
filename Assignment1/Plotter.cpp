#include "Plotter.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    PenStyle style={1,"black"};
    bool pendown=false;
    double x=0;
    double y=0;

    for (string line; getline(input,line);){
        Vector<string> command = stringSplit(line," ");
        if(startsWith(toLowerCase(command[0]),"pendown")){
            pendown=true;
        }
        if(startsWith(toLowerCase(command[0]),"penup")){
            pendown=false;
        }
        if(startsWith(toLowerCase(command[0]),"pencolor")){
            style.color=command[1];
        }
        if(startsWith(toLowerCase(command[0]),"penwidth")){
            style.width=stringToReal(command[1]);
        }
        if(startsWith(toLowerCase(command[0]),"moveabs")){
            double xDes = stringToReal(command[1]);
            double yDes = stringToReal(command[2]);
            if(pendown==true)
            {
                drawLine(x,y,xDes,yDes,style);
            }
            x=xDes;
            y=yDes;
        }
        if(startsWith(toLowerCase(command[0]),"moverel")){
            double xRel = x+stringToReal(command[1]);
            double yRel = y+stringToReal(command[2]);
            if(pendown==true)
            {
                drawLine(x,y,xRel,yRel,style);
            }
            x=xRel;
            y=yRel;
        }
    }
}
