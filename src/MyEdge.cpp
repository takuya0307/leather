//
//  MyEdge.cpp
//  leather3
//
//  Created by Takuya Ogashi on 2016/10/19.
//
//

#include "MyEdge.h"

MyEdge::MyEdge(ofPoint _start, ofPoint _end){
    start = _start;
    end = _end;
}
MyEdge::MyEdge(){
    
}
//MyEdge::~MyEdge(){
//}


Boolean MyEdge::cross(MyEdge e){
    return cross2(
                 start.x,   start.y,   end.x,   end.y,
                 e.start.x, e.start.y, e.end.x, e.end.y);
}
Boolean MyEdge::cross2(
                         double x1,  double y1,  double x2,  double y2,
                         double xx1, double yy1, double xx2, double yy2){
        
        // a * x + b * y + c = 0
        double a0, b0, c0,
        a1, b1, c1;
        a0 = y1 - y2;
        b0 = x2 - x1;
        c0 = y2 * x1 - x2 * y1;
        a1 = yy1 - yy2;
        b1 = xx2 - xx1;
        c1 = yy2 * xx1 - xx2 * yy1;
        
        if (((a0* xx1+b0* yy1+c0)*(a0* xx2+b0* yy2+c0)<= 0) &&
            ((a1*  x1+b1*  y1+c1)*(a1*  x2+b1*  y2+c1)<= 0)){
            return true;
        }
        else
        {
            return false;
        }
    }

ofPoint MyEdge::cross_point(MyEdge e){
    return cross_point2( start.x,   start.y,   end.x,   end.y,
                       e.start.x, e.start.y, e.end.x, e.end.y);
}

ofPoint MyEdge::cross_point2(
                           double x1,  double y1,  double x2,  double y2,
                           double xx1, double yy1, double xx2, double yy2){
    
    // a * x + b * y + c = 0
    double a0, b0, c0,
    a1, b1, c1;
    a0 = y1 - y2;
    b0 = x2 - x1;
    c0 = y2 * x1 - x2 * y1;
    a1 = yy1 - yy2;
    b1 = xx2 - xx1;
    c1 = yy2 * xx1 - xx2 * yy1;
    //booleanで
    if (abs(a0 * b1 - a1 * b0) < ERROR_RANGE){
        return ofPoint::zero();
    }
    
    double x = ((b0 * c1 - b1 * c0)/(a0 * b1 - a1 * b0)) ;
    double y = ((a0 * c1 - a1 * c0)/(a1 * b0 - a0 * b1));
    return ofPoint((int)x,(int)y);
}