//
//  MeshCleave.h
//  leather3
//
//  Created by Takuya Ogashi on 2016/10/24.
//
//

#ifndef MeshCleave_h
#define MeshCleave_h

#include "ofMain.h"
#include "MyEdge.h"
class MeshCleave{
public:
   
    //int cleave_width = 10; //切れ込みを入れる幅。ここを変えて実験すると良い
    //int cross_point_base_edge_start_index = -1; // ベースストロークにおいて、交点があるEdgeのstartにあたるインデックス
    //int cross_point_insert_edge_start_index = -1; //切れ込みストロークにおいて、交点があるEdgeのstartにあたるインデックス
    //ofPoint cross_point; //ベースストロークと切れ込みストロークの交点
    MyEdge *edgePtr;
    
    //ベースストローク上の交点を持つエッジ
    std::vector<ofPoint> meshCleave(std::vector<ofPoint> base_stroke,std::vector<ofPoint>insert_stroke);
    std::vector<ofPoint> insert_stroke_update(std::vector<ofPoint> insert_stroke);
    std::vector<ofPoint> Meshget_cleave_stroke(std::vector<ofPoint> insert_stroke);
    std::vector<ofPoint> get_cleave_stroke(std::vector<ofPoint> insert_stroke);
    std::vector<ofPoint> base_stroke_update(std::vector<ofPoint> base_stroke, std::vector<ofPoint> cleave_stroke);
    Boolean exist_cross_point(std::vector<MyEdge>edges, MyEdge edge);
    ofPoint get_cross_point(std::vector<MyEdge>edges, MyEdge edge);
    double distance(ofPoint n1, ofPoint n2);
    ofPoint interpolate(ofPoint start,ofPoint end, double t);
    double dividing_ratio(ofPoint start, ofPoint end, ofPoint divid_v);
    MyEdge cross_base_edge;
    int i=0;

};
#endif /* MeshCleave_h */

