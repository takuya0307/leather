//
//  Resampling.h
//  leather3
//
//  Created by Takuya Ogashi on 2016/10/26.
//
//
#pragma once
#ifndef Resampling_h
#define Resampling_h
#include "ofMain.h"
#include "MeshCleave.h"
#include "MyEdge.h"
class Resampling{
public:
    std::vector<ofPoint> resample_by_length(std::vector<ofPoint> stroke, double UNIT_LENGTH, Boolean loop);
    std::vector<ofPoint> resample_by_number(std::vector<ofPoint> stroke, double n, Boolean loop);
    double get_length(std::vector<ofPoint> stroke);
    double distance(ofPoint n1, ofPoint n2);
    ofPoint interpolate(ofPoint start,ofPoint end, double t);
     double dividing_ratio(ofPoint start, ofPoint end, ofPoint divid_v);
};
#endif /* Resampling_h */
