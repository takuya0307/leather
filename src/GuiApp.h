#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDelaunay.h"
#include "ofxPoly2Tri.h"
#include "Resampling.h"
#include "MeshCleave.h"
#include "ofxTriangleMesh.h"
class GuiApp : public ofBaseApp{
//    std::vector<std::vector<ofPoint> > lines;
//    std::vector<std::vector<ofPoint> > lines2;
private:
    float posX, posY;
    int getY=0;
    int getY2=0;
    int moveX;
    int moveY;
    bool flag=false;
    bool flagChangePoint=false;
    bool changePoint=false;
    bool finish=false;
    int count=0;
    int changePointNum;
    int onceDrag=false;
    int onceDragX;
    int onceDragY;
    
public:
    void setup();
    void update();
    void draw();
    void save(string text,string fileName);
    void saveVector(std::vector<ofPoint> point,string filename);
    void load(string fileName);
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void paint_stroke(std::vector<ofPoint> stroke, Boolean loop);
    ofVec3f sub_vector(ofPoint vec1,ofPoint vec2);
    bool hittest_point_polygon_2d( ofPoint A, ofPoint B, ofPoint C, ofPoint P );
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    std::vector<std::vector<ofPoint> > lines;
    std::vector<std::vector<ofPoint> > lines2;
    std::vector<std::vector<ofPoint> > curveLine;
    std::vector<ofPoint> Polylines;
    std::vector<string>loadPointX;
    std::vector<string>loadPointY;
    std::vector<ofPoint> stroke;
    std::vector<ofPoint>stroke_reverse;
    std::vector<ofPoint>newLine;
    std::vector<ofPoint>newLine2;
    std::vector<ofPoint>base_stroke;
    std::vector<ofPoint>change_base_stroke;
    std::vector<ofPoint>change_base_stroke2;
    std::vector<ofPoint>resamp_stroke;
    std::vector<ofPoint>resamp_stroke2;
    
    Resampling resamp;
    Resampling resamp2;
    MeshCleave meshCl;
    
    
    bool WriteOn=false;
    bool changeStroke=false;
    ofxDelaunay triangulation;
    ofxPoly2Tri Poly2;
    ofVboMesh meshGui;
    ofVboMesh mesh2;
    ofMesh mesh3;
    ofMesh redMesh;
    ofMesh blueMesh;
    ofMesh yellowMesh;
    ofPolyline testPoly;
    ofPolyline base_stroke_Poly;
    ofPolyline bounds;
    ofxTriangleMesh triMesh;
    ofImage myImage;
    ofImage grabbedImage;
    ofImage leather;
    ofPoint loadX;
    ofPoint loadY;
    //bool saveFile=false;
    string abc="abcde";
    string def="1234";
    string test="test";
    int resample_size = 10;
    int PressX;
    int PressY;
    int releaseX;
    int releaseY;
    bool changeDragFirst=true;
    bool triSelect=false;
    bool inMouseXY=false;
    bool redSelect=false;
    bool isRedMesh=false;
    bool blueSelect=false;
    bool isBlueMesh=false;
    bool yellowSelect=false;
    bool isYellowMesh=false;
    bool fast=true;
    std::vector<int>MeshID;
    std::vector<int>MeshID2;
    //std::vector<int>MeshID3;
    std::vector<int> MX1;
    std::vector<int> MX2;
    std::vector<int> MX3;
    std::vector<int> MY1;
    std::vector<int> MY2;
    std::vector<int> MY3;
    std::vector<int> BX1;
    std::vector<int> BX2;
    std::vector<int> BX3;
    std::vector<int> BY1;
    std::vector<int> BY2;
    std::vector<int> BY3;
    std::vector<int> YX1;
    std::vector<int> YX2;
    std::vector<int> YX3;
    std::vector<int> YY1;
    std::vector<int> YY2;
    std::vector<int> YY3;
    //std::vector<int> IsMeshIn;
    //std::vector<bool>isSetColor;
    std::vector<bool>isInred;
    //std::vector<bool> isMeshIn;
    bool isMeshIn[1000];
    bool isStrokeLine=false;
    std::vector<ofPoint> MeshPoint;
    std::vector<ofIndexType> MeshIndex;
    string text;
    
    
    ofPath path;
    ofPath path2;
    ofPath path3;
    ofPolyline PL;
    //ofxPanel gui;
    
    //ofMesh mesh;
};

