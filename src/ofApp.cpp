#include "ofApp.h"
#include <iostream>
void ofApp::setup(){
    ofBackground(255);
    ofEnableDepthTest();
    ofEnableSmoothing();
    model.loadModel("harituke.stl",20);
    meshNum=model.getNumMeshes();
    light.enable();
    light2.enable();
    //light.setSpotlight();
    //light2.setSpotlight();
    light.setAmbientColor(ofFloatColor(1.0,1.0,1.0));
    float width     = ofGetWidth() * .12;
    float height    = ofGetHeight() * .12;
    cylinder.set(width*.7, height*2.2);


    //light.setPosition(-100, 100, 100);
    light2.setPosition(-100,-100,-300);
    light.setAmbientColor(ofFloatColor(0.1,0.1,0.5,1.0));
    //拡散反射光
    light.setDiffuseColor(ofFloatColor(0.2,0.2,1.0));
    //鏡面反射光
    light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
    light2.setAmbientColor(ofFloatColor(0.1,0.1,0.5,1.0));
    //拡散反射光
    light2.setDiffuseColor(ofFloatColor(0.2,0.2,1.0));
    //鏡面反射光
    light2.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
    /*light.setAmbientColor(ofColor(124,96,53,1.0));
    light.setDiffuseColor(ofColor(63,45,23));
    light.setSpecularColor(ofColor(125,125,125));*/
    
    /*light.setAmbientColor(ofFloatColor(0.1,0.1,0.5,1.0));
    //拡散反射光
    light.setDiffuseColor(ofFloatColor(0.2,0.2,1.0));
    //鏡面反射光
    light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));*/
    gui.setup();
    gui.add(RR.setup("RR", 0, 0, 1000));
    gui.add(RR2.setup("RR2", 0, 0, 1000));
    LightXYZ.setup();
    LightXYZ.add(XX.setup("X",0,-500,500));
    LightXYZ.add(YY.setup("Y",0,-500,500));
    LightXYZ.add(ZZ.setup("Z",0,-500,500));
    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess( 120 );
    // the light highlight of the material //
    material.setSpecularColor(ofColor(0, 0, 0, 255));
    box.set(200);
    box.setPosition(0, 0, 0);
    pillar_vertex=pillar.getVertices();
    for(int j=0;j<pillar.getNumVertices();j++){
        pillar.setVertex(j, ofVec3f(pillar.getVertex(j).x,pillar.getVertex(j).y,(pillar.getVertex(j).z-100)));
        if(pillar.getVertex(j)==ofPoint(-100,0,-150)){
            pillar_middle=pillar.getVertex(j);
            cout<<"attazoooooooooooooooooo"<<endl;
        }
    }
    
}

void ofApp::update(){
    
    
}
string s = "Hello!";
void ofApp::draw(){
    gui.draw();
    // LightXYZ.draw();
    //light.setPosition(XX, YY, ZZ);
    cam.begin();

    XLine.setStrokeColor( ofColor( 255, 0, 0,100 ) );
    XLine.setFilled(true);
    XLine.setStrokeWidth( 10 );
    XLine.moveTo( -1000 , 0 , 0 );
    XLine.lineTo(0, 0, 0 );
    XLine.draw();
    XLine.close();
    XLine2.setStrokeColor( ofColor( 255, 0, 0,200 ) );
    XLine2.setFilled(true);
    XLine2.setStrokeWidth( 10 );
    XLine2.moveTo( 0 , 0 , 0 );
    XLine2.lineTo(1000, 0, 0 );
    XLine2.draw();
    XLine2.close();
    YLine.setStrokeColor( ofColor( 0, 255, 0,100 ) );
    YLine.setFilled(true);
    YLine.setStrokeWidth( 10 );
    YLine.moveTo( 0 , -1000 , 0 );
    YLine.lineTo(0, 1000, 0 );
    YLine.draw();
    YLine.close();
    ZLine.setStrokeColor( ofColor( 0, 0, 255,100 ) );
    ZLine.setFilled(true);
    ZLine.setStrokeWidth( 10 );
    ZLine.moveTo( 0 , 0 , -1000 );
    ZLine.lineTo(0, 0, 1000 );
    ZLine.draw();
    ZLine.close();
    ofSetColor(0);
    ofSetColor(255);
    box.set(200);
    box.setPosition(150,0,0);
    //box.draw();
    model.enableColors();
    // model.drawFaces();
    /*if(isPillar==true){
     pillar.drawWireframe();
     }*/
    //pillar2.draw();
    
    cout<<mouseX<<","<<mouseY<<endl;
    if(WriteOn->WriteOn){
        flag=true;
    }
    if(WriteOn->WriteOn==false){
        if(flag){
            for(const std::vector<ofPoint>&line3 : lines->lines){
                for(unsigned int i = 1; i < line3.size()-1; i++){
                    ofSetColor(255,0,0);
                    //ofLine(line3[i-1].x, line3[i-1].y, line3[i].x, line3[i].y);
                    //cout<<line3[i].x<<"No"<<i<<endl;
                    //mesh.setMode(OF_PRIMITIVE_LINES);
                    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
                    //mesh.addColor(128);
                }
            }
        }
        for (int i=0; i<meshGui->meshGui.getNumVertices(); i++) {
            if(i==0){
                //mesh.clearIndices();
            }
            ofVec2f p = meshGui->meshGui.getVertex(i);
            mesh.setMode(OF_PRIMITIVE_TRIANGLES);
            //mesh.addVertex(ofVec3f((int)p.x,(int)p.y,50));
            if(i>3){
                // mesh.addTriangle(i-2, i-1, i);
            }
            
        }
        meshaaa=triMesh->triMesh.triangulatedMesh;
        ofSetColor(255);
        //ofRotateY(90);
        //ofTranslate(-300.0,-100.0);
        
        
        // meshGui->meshGui.draw();
        
        meshaaa2=triMesh->triMesh.triangulatedMesh;
        //idou
        for(int i=0;i<meshaaa2.getNumVertices();i++){
            meshaaa2.setVertex(i,ofPoint(meshaaa2.getVertex(i).x-300,meshaaa2.getVertex(i).y-100,meshaaa2.getVertex(i).z));
        }
        
        
        
        //mageru mesh motonobasho
        /* for(int i=0;i<meshaaa2.getNumVertices();i++){
         //float PAI =abs(315.0-meshaaa2.getVertex(i).x)/RR;
         float PAI =meshaaa2.getVertex(i).x/RR;
         float tx=RR*sin(PAI);
         float ty=meshaaa2.getVertex(i).y;
         float tz=0;
         tz=RR-RR*cos(PAI);
         if(PAI>=PI/2){
         tx=RR*sin(PI/2);
         //tz=RR-RR*cos(PAI)+(meshaaa2.getVertex(i).x-RR*(PI/4));
         tz=RR-RR*cos(PAI);
         }
         if(PAI<=-PI/2){
         tx=RR*sin(-PI/2);
         //tz=RR-RR*cos(PAI)+(-tx-RR*(PI/2));
         tz=RR-RR*cos(PAI);
         }
         meshaaa2.setVertex(i,ofPoint(tx,meshaaa2.getVertex(i).y,tz));
         }*/
        //mageru mesh motonobasho
        //indexwotukau2017/6/19
        for(int i=0;i<meshaaa2.getNumIndices();i++){
            if(findIndex(meshaaa2.getIndices(), meshaaa2.getIndex(i),i)==false){
                //float PAI =abs(315.0-meshaaa2.getVertex(i).x)/RR;
                float PAI =meshaaa2.getVertex( meshaaa2.getIndex(i)).x/RR;
                float tx=RR*sin(PAI);
                float ty=meshaaa2.getVertex( meshaaa2.getIndex(i)).y;
                float tz=0;
                tz=RR-RR*cos(PAI);
                if(PAI>=PI/2){
                    tx=RR*sin(PI/2);
                    //tz=RR-RR*cos(PAI)+(meshaaa2.getVertex( meshaaa2.getIndex(i)).x-RR*(PI/4));
                    tz=RR-RR*cos(PAI);
                }
                if(PAI<=-PI/2){
                    tx=RR*sin(-PI/2);
                    //tz=RR-RR*cos(PAI)+(-tx-RR*(PI/2));
                    tz=RR-RR*cos(PAI);
                }
                //meshaaa_ori.setVertex(i, ofPoint(meshaaa2.getVertex(i).x,meshaaa2.getVertex(i).y,meshaaa2.getVertex(i).z));
                ori_ID.push_back(meshaaa2.getIndex(i));
                ori_Point.push_back(ofPoint(meshaaa.getVertex(meshaaa2.getIndex(i)).x,meshaaa.getVertex(meshaaa2.getIndex(i)).y,meshaaa.getVertex(meshaaa2.getIndex(i)).z));
                meshaaa2.setVertex(meshaaa.getIndex(i),ofPoint(tx,meshaaa2.getVertex( meshaaa2.getIndex(i)).y,tz));
            }
        }
        
        
        
        
        
        //}
        
        if(isRedMesh->isRedMesh){
            ofSetColor(255,0,0);
            ofMesh redMesh2=redMesh->redMesh;
            ofMeshID=MeshID->MeshID;
            center=meshaaa2.getCentroid();
            //center=redMesh2.getCentroid();
            ofMeshID2=MeshID2->MeshID2;
            //ofMeshID3=MeshID3->MeshID3;
            for(int i=0;i<redMesh2.getNumVertices();i++){
                redMesh2.setVertex(i,ofPoint(redMesh2.getVertex(i).x-300,redMesh2.getVertex(i).y-center.y,redMesh2.getVertex(i).z));
                redMesh2.getVertex(i);
            }
            //redMesh2.draw();
            for(int i=0;i<ofMeshID.size();i++){
                if(find(ofMeshID, ofMeshID[i],i)==false){
                    ofPushMatrix();
                    // 45Translate(-center.x,-center.y);
                    ofRotateZ(90);
                    //ofRectangle(0, 0, 100, 100);
                    ofFill();
                    //ofDrawRectangle(0,0,-100,10);
                    ofDrawRectangle(center.x,center.y,20,20);
                    
                    
                    //yzikunohouhou
                    /* float PAI =meshaaa2.getVertex(ofMeshID[i]).y/RR2;
                     float tx=meshaaa2.getVertex(ofMeshID[i]).x;
                     float ty=RR2*sin(PAI);
                     float tz=RR2-RR2*cos(PAI);*/
                    meshaaa2.setVertex(ofMeshID[i],ofPoint(meshaaa2.getVertex(ofMeshID[i]).x,meshaaa2.getVertex(ofMeshID[i]).y-center.y,meshaaa2.getVertex(ofMeshID[i]).z));
                    ofVec3f RotateP=meshaaa2.getVertex(ofMeshID[i]).rotate(90,ofVec3f(0,0,1));
                    float PAI =RotateP.x/RR2;
                    float PAIRR1 =meshaaa2.getVertex(ofMeshID[i]).x/RR;
                    float tx=RR2*sin(PAI);
                    float ty=RotateP.y;
                    float tz=meshaaa2.getVertex(ofMeshID[i]).z+RR2-RR2*cos(PAI);
                    // float tz2=RR-RR*cos(PAIRR1);
                    // tz=tz+tz2;
                    //float tz=RR2-RR2*cos(PAI)+(RR-RR*cos(PAIRR1));
                    ofVec3f ReRotateP=ofVec3f(tx,ty,tz);
                    
                    
                    meshaaa2.setVertex(ofMeshID[i],ReRotateP.rotate(-90,ofVec3f(0,0,1)));
                    meshaaa2.setVertex(ofMeshID[i],ofPoint(meshaaa2.getVertex(ofMeshID[i]).x,meshaaa2.getVertex(ofMeshID[i]).y+center.y,meshaaa2.getVertex(ofMeshID[i]).z));
                    ofPopMatrix();
                    // meshaaa2.setVertex(ofMeshID[i],ofPoint(meshaaa2.getVertex(ofMeshID[i]).x,meshaaa2.getVertex(ofMeshID[i]).y,meshaaa2.getVertex(ofMeshID[i]).z+30));
                }
            }
            //redMesh2.draw();
            //redMesh2.drawWireframe();
            
            
            //     leatheer.unbind();
        }
        //meshaaa2.draw();
        
        if(isBlueMesh->isBlueMesh){
            //ofSetColor(255,0, 255);
            ofMesh blueMesh2=blueMesh->blueMesh;
            // center=blueMesh2.getCentroid();
            center=meshaaa2.getCentroid();
            float MAX_Y=find_max_y(blueMesh2.getVertices());
            float MIN_Y=find_min_y(blueMesh2.getVertices());
            float MAX_X=find_max_x(blueMesh2.getVertices());
            float MIN_X=find_min_x(blueMesh2.getVertices());
            
            //cout<<MAX_Y<<"now"<<meshaaa2.getVertex(ofMeshID2[i]).y<<endl;
            cout<<MAX_Y<<"now_Y"<<MIN_Y<<endl;
            cout<<MAX_X<<"now2_X"<<MIN_X<<endl;
            float max;
            float min;
            float blue_maxY;
            float blue_minY;
            // if(changeFirst){
            for(int i=0;i<ofMeshID2.size();i++){
                if(i==0){
                    max=meshaaa2.getVertex(ofMeshID2[i]).x;
                    min=meshaaa2.getVertex(ofMeshID2[i]).x;
                    blue_maxY=meshaaa2.getVertex(ofMeshID2[i]).y;
                    blue_minY=meshaaa2.getVertex(ofMeshID2[i]).y;
                }
                if( meshaaa2.getVertex(ofMeshID2[i]).x >max ){
                    max=meshaaa2.getVertex(ofMeshID2[i]).x;
                }
                if(meshaaa2.getVertex(ofMeshID2[i]).x<min){
                    min=meshaaa2.getVertex(ofMeshID2[i]).x;
                }
                if( meshaaa2.getVertex(ofMeshID2[i]).y >blue_maxY ){
                    blue_maxY=meshaaa2.getVertex(ofMeshID2[i]).y;
                }
                if( meshaaa2.getVertex(ofMeshID2[i]).y <blue_minY ){
                    blue_minY=meshaaa2.getVertex(ofMeshID2[i]).y;
                }
            }
            for(int i=0;i<ofMeshID2.size();i++){

                if(find(ofMeshID2, ofMeshID2[i],i)==false){
                    for(int j=0;j<ori_ID.size();j++){
                        if(ori_ID[j]==ofMeshID2[i]){
                             meshaaa2.setVertex(ofMeshID2[i], ofPoint(ori_Point[j].x-300,ori_Point[j].y-100,ori_Point[j].z));
                        }
                    }
                    //  2017/7/9
                     float RR3=RR2;
                     //RR3=RR3*(blue_maxY-meshaaa2.getVertex(ofMeshID2[i]).y)/(blue_maxY-blue_minY);
                    RR3=RR3*(meshaaa2.getVertex(ofMeshID2[i]).y-blue_minY)/(blue_maxY-blue_minY);
                    //RR3=RR3*meshaaa2.getVertex(ofMeshID2[i]).y/(blue_maxY-blue_minY);
                    //RR3=RR3*(blue_minY-meshaaa2.getVertex(i).y)/(blue_minY-blue_maxY);
                    float PAI =meshaaa2.getVertex(ofMeshID2[i]).x/RR3;
                    float tx=RR3*sin(PAI);
                    float ty=meshaaa2.getVertex(ofMeshID2[i]).y;
                    float tz=0;
                    tz=RR3-RR3*cos(PAI);
                    meshaaa2.setVertex(ofMeshID2[i],ofPoint(tx,meshaaa2.getVertex(ofMeshID2[i]).y,tz));
                    ofPoint  RotateP=meshaaa2.getVertex(ofMeshID2[i]).rotate(-45,ofVec3f(1,0,0));
                    meshaaa2.setVertex(ofMeshID2[i], RotateP);
                   
                    // RR3=RR3*(blue_maxY-meshaaa2.getVertex(ofMeshID2[i]).y)/(blue_maxY-blue_minY);
                    
                    
                    //yzikunohouhou
                    /* float PAI =meshaaa2.getVertex(ofMeshID[i]).y/RR2;
                     float tx=meshaaa2.getVertex(ofMeshID[i]).x;
                     float ty=RR2*sin(PAI);
                     float tz=RR2-RR2*cos(PAI);*/
                    /*
                     meshaaa2.setVertex(ofMeshID2[i],ofPoint(meshaaa2.getVertex(ofMeshID2[i]).x,meshaaa2.getVertex(ofMeshID2[i]).y-center.y,meshaaa2.getVertex(ofMeshID2[i]).z));
                     ofVec3f RotateP=meshaaa2.getVertex(ofMeshID2[i]).rotate(90,ofVec3f(0,0,1));
                     float PAI =RotateP.x/RR2;
                     float PAIRR1 =meshaaa2.getVertex(ofMeshID2[i]).x/RR;
                     float tx=RR2*sin(PAI);
                     float ty=RotateP.y;
                     float tz=meshaaa2.getVertex(ofMeshID2[i]).z+RR2-RR2*cos(PAI);
                     // float tz2=RR-RR*cos(PAIRR1);
                     // tz=tz+tz2;
                     //float tz=RR2-RR2*cos(PAI)+(RR-RR*cos(PAIRR1));
                     ofVec3f ReRotateP=ofVec3f(tx,ty,tz);
                     
                     
                     meshaaa2.setVertex(ofMeshID2[i],ReRotateP.rotate(-90,ofVec3f(0,0,1)));
                     meshaaa2.setVertex(ofMeshID2[i],ofPoint(meshaaa2.getVertex(ofMeshID2[i]).x,meshaaa2.getVertex(ofMeshID2[i]).y+center.y,meshaaa2.getVertex(ofMeshID2[i]).z));
                     ofPopMatrix();*/
                    
                    
                    //float RR3=RR2*(MAX_Y-MIN_Y)/(MAX_Y-(meshaaa2.getVertex(i).y-MIN_Y));
                    // float RR3=RR2*(MAX_Y-(meshaaa2.getVertex(i).y-MIN_Y))/(MAX_Y-MIN_Y);
                    
                   
                    /*if(i==0){
                        max=meshaaa2.getVertex(i).x;
                        min=meshaaa2.getVertex(i).x;
                        blue_maxY=meshaaa2.getVertex(i).y;
                        blue_minY=meshaaa2.getVertex(i).y;
                    }
                    if( meshaaa2.getVertex(i).x >max ){
                        max=meshaaa2.getVertex(i).x;
                    }
                    if(meshaaa2.getVertex(i).x<min){
                        min=meshaaa2.getVertex(i).x;
                    }
                    if( meshaaa2.getVertex(i).y >max ){
                        blue_maxY=meshaaa2.getVertex(i).y;
                    }
                    if( meshaaa2.getVertex(i).y <minY ){
                        blue_minY=meshaaa2.getVertex(i).y;
                    }*/
                    // }
                    changeFirst=false;
                }
            }
           /* for(int i=0;i<ofMeshID2.size();i++){
                if(find(ofMeshID2,ofMeshID2[i],i)==false){
                float RR3=RR2;
               // RR3=RR3*(blue_maxY-meshaaa2.getVertex(ofMeshID2[i]).y)/(blue_maxY-blue_minY);
                
                float PAI =meshaaa2.getVertex(ofMeshID2[i]).x/RR3;
                float tx=RR3*sin(PAI);
                float ty=meshaaa2.getVertex(ofMeshID2[i]).y;
                float tz=0;
                tz=RR3-RR3*cos(PAI);
                //float resultA=max-meshaaa2.getVertex(ofMeshID2[i]).x;
                //float result_tan=resultA*tan(PI/3);
                //cout<<"hikizan"<<resultA<<"tan keisan"<<result_tan<<endl;
                // meshaaa2.setVertex(ofMeshID2[i],ofPoint(tx,meshaaa2.getVertex(ofMeshID2[i]).y,tz));
                /* float tz;
                 if(meshaaa2.getVertex(ofMeshID2[i]).x>0){
                 tz=(max-meshaaa2.getVertex(ofMeshID2[i]).x)*tan(PI/3);
                 } if(meshaaa2.getVertex(i).x<0){
                 tz=(-min+meshaaa2.getVertex(i).x)*tan(PI/3);
                 }*/
                
                
                //meshaaa2.setVertex(ofMeshID2[i],ofPoint(tx,meshaaa2.getVertex(ofMeshID2[i]).y,tz));
                
               // }
                
            //}
            //cout<<"max_meshaaa2.x"<<max<<"min_meshaaa2.x"<<min<<endl;
            
            
        }
        meshaaa2.drawWireframe();
       // meshaaa2.draw();
        if(isYellowMesh->isYellowMesh){
            // ofSetColor(255,0, 255);
            
            ofMesh yellowMesh2=yellowMesh->yellowMesh;
            
            for(int i=0;i<yellowMesh2.getNumVertices();i++){
                if(i==0){
                    minY=yellowMesh2.getVertex(i).y;
                }
                if(minY>yellowMesh2.getVertex(i).y){
                    minY=yellowMesh2.getVertex(i).y;
                    minZ=yellowMesh2.getVertex(i).z;
                }
                
            }
            cout<<"minY="<<minY<<","<<"minZ="<<minZ<<endl;
            
            for(int i=0;i<yellowMesh2.getNumVertices();i++){
                yellowMesh2.setVertex(i,ofPoint((yellowMesh2.getVertex(i).x/X),yellowMesh2.getVertex(i).y,-sin(PI*yellowMesh2.getVertex(i).x/302)*(302-yellowMesh2.getVertex(i).x)));
            }
            for(int i=0;i<yellowMesh2.getNumVertices();i++){
                yellowMesh2.setVertex(i,ofPoint(yellowMesh2.getVertex(i).x,yellowMesh2.getVertex(i).y,yellowMesh2.getVertex(i).z).rotate(-100,ofVec3f(1,0,0)));
            }
            for(int i=0;i<yellowMesh2.getNumVertices();i++){
                yellowMesh2.setVertex(i,ofPoint(yellowMesh2.getVertex(i).x,yellowMesh2.getVertex(i).y+200,yellowMesh2.getVertex(i).z+yellowPosX));
            }
            
            //  leather.bind();
            yellowMesh2.draw();
            yellowMesh2.drawWireframe();
            
            //leather.unbind();
            
        }
        ofSetColor(255,255,255);
        // leather.bind();
        if(isMeshaa2==false){
            //meshaaa2.draw();
        }else{
            meshaaa2.clear();
        }
        meshaaa2.save("",true);
        //leather.unbind();
        ofSetColor(255,0,0);
        
        mesh.drawFaces();
        //ofSetColor(0,255,0);
        ofTranslate(0,0,10);
        //triMesh->triMesh.triangulatedMesh.drawWireframe();
        meshaaa.clearTexCoords();
        /* for(const std::vector<ofPoint>&line3 : lines->lines){
         for(unsigned int i = 1; i < line3.size()-1; i++){
         meshaaa.addTexCoord(ofPoint(line3[i].x,line3[i].y));
         }
         for(unsigned int i = 1; i < line3.size()-1; i++){
         meshaaa.addTexCoord(ofPoint(600-line3[i].x,line3[i].y));
         }
         }*/
        if(first){
            for(int i=0;i<meshaaa.getNumVertices();i++){
                //meshaaa.setVertex(i,ofPoint(meshaaa.getVertex(i).x,meshaaa.getVertex(i).y,i));
                if(meshaaa.getVertex(i).x<302){
                    
                    meshaaa.setVertex(i,ofPoint(meshaaa.getVertex(i).x,meshaaa.getVertex(i).y,-(302-meshaaa.getVertex(i).x)));
                    
                }else if(meshaaa.getVertex(i).x>302){
                    meshaaa.setVertex(i,ofPoint(meshaaa.getVertex(i).x,meshaaa.getVertex(i).y,302-meshaaa.getVertex(i).x));
                }
                
            }
            
        }
        //cout<<meshaaa.getCentroid()<<endl;
        ofSetColor(0,255,0);
        
        //leather.bind();
        //meshaaa.draw();
        //leather.unbind();
        ofTranslate(0,0,-10);
        
    }
    
    cam.end();
    
}
void ofApp::keyPressed(int key){
    if( key == ' ' ){
        //triangles = meshaaa.getUniqueFaces();
        cout << "solid test-of" << endl;
        
        for( int i = 0; i < meshaaa2.getUniqueFaces().size(); i++ ){
            cout << "facet normal 0 0 0" << endl;
            cout << "outer loop" << endl;
            
            for( int j = 0; j < 3; j++ ){
                cout << "vertex ";
                cout << meshaaa2.getUniqueFaces()[i].getVertex(j).x << " ";
                cout << meshaaa2.getUniqueFaces()[i].getVertex(j).y << " ";
                cout << meshaaa2.getUniqueFaces()[i].getVertex(j).z << endl;
            }
            cout << "endloop" << endl;
            cout << "endfacet" << endl;
        }
        cout << "endsolid test-of" << endl;
    }
    if(key=='a'){
        cout<<"a"<<endl;
        isMeshaa2=true;
        
    }if(key=='d'){
        isPillar=true;
    }if(key=='c'){
        isPillar=false;
    }
    if(key=='l'){
        leg=true;
    }
}

bool ofApp::find(const std::vector<int> &v, int val,int valNum){
    for(int i = 0; i < valNum; ++i) {
        if( v[i] == val )
            return true;
    }
    return false;
}
bool ofApp::findIndex(const std::vector<ofIndexType> &v, int val,int valNum){
    for(int i = 0; i < valNum; ++i) {
        if( v[i] == val )
            return true;
    }
    return false;
}
float ofApp::find_max(const std::vector<float>&v){
    float max;
    for(int i = 0; i < v.size(); ++i) {
        if(i==0){
            max=v[i];
        }
        if( v[i] >max ){
            max=v[i];
        }
    }
    return max;
}
float ofApp::find_max_y(const std::vector<ofPoint>&v){
    float max;
    for(int i = 0; i < v.size(); ++i) {
        if(i==0){
            max=v[i].y;
        }
        if( v[i].y >max ){
            max=v[i].y;
        }
    }
    return max;
}
float ofApp::find_min_y(const std::vector<ofPoint>&v){
    float min;
    for(int i = 0; i < v.size(); ++i) {
        if(i==0){
            min=v[i].y;
        }
        if( v[i].y <min ){
            min=v[i].y;
        }
    }
    return min;
}
float ofApp::find_max_x(const std::vector<ofPoint>&v){
    float max;
    for(int i = 0; i < v.size(); ++i) {
        if(i==0){
            max=v[i].x;
        }
        if( v[i].y >max ){
            max=v[i].x;
        }
    }
    return max;
}
float ofApp::find_min_x(const std::vector<ofPoint>&v){
    float min;
    for(int i = 0; i < v.size(); ++i) {
        if(i==0){
            min=v[i].x;
        }
        if( v[i].y <min ){
            min=v[i].x;
        }
    }
    return min;
}
float ofApp::find_min(const std::vector<float>&v){
    float min;
    for(int i = 0; i < v.size(); ++i) {
        if(i==0){
            min=v[i];
        }
        if( v[i] <min ){
            min=v[i];
        }
    }
    return min;
}