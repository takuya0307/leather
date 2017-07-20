
//#endif /* ofApp_h */
#pragma once

#include "ofMain.h"
#include "GuiApp.h"
#include "ofxGui.h"
#include "ofRectangle.h"
#include "ofGraphics.h"
#include "ofxAssimpModelLoader.h"
class ofApp: public ofBaseApp {
private:
    bool flag=false;
    bool first=true;
    bool isMeshaa2=false;
    bool leg=false;
    bool isPillar=true;
    bool changeFirst=true;
    int minY;
    int minZ;
    int mesh_min_X;
    int mesh_max_X;
    int mesh_min_Y;
    int mesh_max_Y;
    int distance_num;
    int meshNum;
    float distanceX;
    float distanceY;
    float distanceZ;
    float distanceXYZ;
    float min_distanceXYZ=0;
    float maxX_meshaaa2;
     float maxY_meshaaa2;
     float minX_meshaaa2;
     float minY_meshaaa2;
    
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    float find_max(const std::vector<float>&v);
    float find_max_y(const std::vector<ofPoint>&v);
      float find_min_y(const std::vector<ofPoint>&v);
     float find_min(const std::vector<float>&v);
    float find_max_x(const std::vector<ofPoint>&v);
    float find_min_x(const std::vector<ofPoint>&v);

    bool find(const std::vector<int> &v, int val,int valNum);
    bool findIndex(const std::vector<ofIndexType> &v, int val,int valNum);
    ofBoxPrimitive box;
    ofxAssimpModelLoader model;
    ofMesh pillar=pillar.cylinder(100.0, 600.0,100,100);
    ofMesh pillar2=pillar2.cylinder(100,300.0,10,10);;
   
    ofPoint middlexyz=ofVec3f(0,0,0);
    std::vector<ofPoint>pillar_vertex;
    ofSpherePrimitive sphere;
    ofCylinderPrimitive cylinder;
    ofEasyCam cam;
    ofLight light;
    ofLight light2;
    ofMaterial material;
    ofMesh mesh;
    ofMesh meshaaa;
    ofMesh meshaaa2;
    ofMesh meshaaa_ori;
    ofPoint pillar_middle;
    ofPath XLine;
     ofPath XLine2;
    ofPath YLine;
    ofPath ZLine;
    std::vector<int>ofMeshID;
    std::vector<int>ofMeshID2;
    std::vector<int>ofMeshID3;
    std::vector<ofIndexType>ori_ID;
    std::vector<ofPoint>ori_Point;


    // place to store the sides of the box //
    ofVboMesh boxSides[ofBoxPrimitive::SIDES_TOTAL];
    ofVboMesh deformPlane;
    ofVboMesh topCap, bottomCap, body;
    ofPoint center;
    vector<ofMeshFace> triangles2;
    ofImage leather;
    shared_ptr<GuiApp> WriteOn;
    shared_ptr<GuiApp> lines;
    shared_ptr<GuiApp> meshGui;
    shared_ptr<GuiApp> triMesh;
    shared_ptr<GuiApp> redMesh;
    shared_ptr<GuiApp> isRedMesh;
    shared_ptr<GuiApp> blueMesh;
    shared_ptr<GuiApp> isBlueMesh;
    shared_ptr<GuiApp> yellowMesh;
    shared_ptr<GuiApp> isYellowMesh;
     shared_ptr<GuiApp> MeshID;
     shared_ptr<GuiApp> MeshID2;
     //shared_ptr<GuiApp>MeshID3;
    
    
    ofMeshFace triangles;
    ofxPanel gui;
    ofxPanel LightXYZ;
    ofxFloatSlider radius;
    ofxFloatSlider positionY;
    ofxFloatSlider positionZ;
    ofxFloatSlider positionXblue;
    ofxFloatSlider X;
    ofxFloatSlider radius2;
    ofxFloatSlider yellowPosX;
    ofxFloatSlider XX;
    ofxFloatSlider YY;
    ofxFloatSlider ZZ;
    ofxFloatSlider RR;
    ofxFloatSlider RR2;


};