//
//  MyEdge.h
//  leather3
//
//  Created by Takuya Ogashi on 2016/10/19.
//
//
#pragma once
#ifndef MyEdge_h
#define MyEdge_h
#include "ofMain.h"
class MyEdge:public ofBaseApp{
public:
    ofPoint start;
    ofPoint end;
    MyEdge(ofPoint start,ofPoint end);
    MyEdge();
    //~MyEdge();
    double ERROR_RANGE = +1.0E-5;
    Boolean cross(MyEdge e);
    Boolean cross2( double x1,  double y1,  double x2,  double y2,double xx1, double yy1, double xx2, double yy2);
    ofPoint cross_point(MyEdge e);
    ofPoint cross_point2( double x1,  double y1,  double x2,  double y2,
                                double xx1, double yy1, double xx2, double yy2);
};


#endif /* MyEdge_h */
