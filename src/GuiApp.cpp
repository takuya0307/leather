#include "GuiApp.h"
#include <iostream>
//--------------------------------------------------------------
float rot;
void GuiApp::setup(){
    ofSetWindowShape(600, 400);
    ofEnableSmoothing();
    ofBackground(255, 255, 255);
    //ofNoFill();
    posX = 300;  posY = 200;
    //myImage.loadImage("nezumi.jpg");
    //leather.loadImage("animal.jpg");
    myImage.loadImage("inoshishi2.jpeg");
    
    //triangulation.addPoint(ofPoint(ofRandom(0, ofGetWidth()),ofRandom(0, ofGetHeight())));
    for(int i=0;i<1000;i++){
        isMeshIn[i]=false;
    }
}




//--------------------------------------------------------------
void GuiApp::update(){
    
    if(finish){
        /*for(std::vector<ofPoint>&line : lines)
         for(unsigned int i = 1; i < line.size(); i++)
         mesh3.addVertex(ofVec2f(line[i-1].x,line[i-1].y));
         mesh3.setMode(OF_PRIMITIVE_POINTS);
         ofSetColor(255,0,0);*/
        //mesh3.draw();
        for(std::vector<ofPoint>&line : lines){
            for(unsigned int i = 1; i < line.size(); i++){
                path2.lineTo(line[i-1].x,line[i-1].y);
                
                // if(abs(line[i-1].x-CLine[0].x)<5&&abs(line[i-1].y-CLine[0].y)<5){
                /*if(onceDrag){
                 if(abs(line[i-1].x-onceDragX)<3&&abs(line[i-1].y-onceDragY)<3){
                 
                 cout<<"updateIn"<<endl;
                 for(std::vector<ofPoint>&CLine : curveLine){
                 for(unsigned int j = 1; j < CLine.size(); j++){
                 path2.lineTo(CLine[j-1].x,CLine[j-1].y);
                 }
                 
                 
                 }
                 }
                 }*/
            }
        }
        for(std::vector<ofPoint>&line2 : lines2)
            for(unsigned int i = line2.size(); i >0; i--)
                path2.lineTo(line2[i-1].x,line2[i-1].y);
        
        //path2.setFillColor(ofColor(255,0,0));
        /*int between=(getY2-getY)/5;
         for(int i=0;i<5;i++){
         path2.lineTo(300,getY2-i*between);
         }*/
        //path2.lineTo(100,100);
        //mesh3=path2.getTessellation();
        testPoly=path2.getOutline()[0];
        //Poly2.triangulate(testPoly);
        //Poly2.triangulate(mesh3);
        
        // add the last point (so when we resample, it's a closed polygon)
        testPoly.addVertex(testPoly[0]);
        // resample
        testPoly = testPoly.getResampledBySpacing(20);
        // I want to make sure the first point and the last point are not the same, since triangle is unhappy:
        testPoly.getVertices().erase(testPoly.getVertices().begin());
        // if we have a proper set of points, mesh them:
        //if (testPoly.size() > 5){
        
        // angle constraint = 28
        // size constraint = -1 (don't constraint triangles by size);
        
        //triMesh.triangulate(testPoly, 28, -1);
        testPoly.clear();
        path2.clear();
        
        ofSetColor(0);
        
    }
}

//--------------------------------------------------------------
void GuiApp::draw(){
    //int Vertex3d=gui->radius
    ofSetColor(255);
    //nezumi
    myImage.draw(85,0);
    
    //zou
    //myImage.draw(125,0);
    //myImage.clear();
    ofSetColor(215, 0, 0);
    ofSetLineWidth(10);
    ofLine(300,0,300,400);
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1);
    
    if(onceDrag){
        paint_stroke(base_stroke, true);
        if(changeStroke){
            //base_stroke_Poly.addVertices(base_stroke);
            //triMesh.triangulate(base_stroke_Poly,24,-1);
            //base_stroke_Poly.clear();
        }
    }
    for(std::vector<ofPoint>&line : lines)
        for(unsigned int i = 1; i < line.size(); i++){
            ofLine(line[i-1].x, line[i-1].y, line[i].x, line[i].y);
            //mesh3.addVertex(ofVec2f(line[i-1].x,line[i-1].y));
        }
    for(std::vector<ofPoint>&line2 : lines2)
        for(unsigned int i = 1; i < line2.size(); i++)
            ofLine(line2[i-1].x, line2[i-1].y, line2[i].x, line2[i].y);
    for(std::vector<ofPoint>&CLine : curveLine){
        for(unsigned int i = 1; i < CLine.size(); i++){
            //ofSetLineWidth(20);
            //ofSetColor(255,0,0);
            ofLine(CLine[i-1].x, CLine[i-1].y, CLine[i].x, CLine[i].y);
            ofLine(600-CLine[i-1].x, CLine[i-1].y, 600-CLine[i].x, CLine[i].y);
            
            // ofSetLineWidth();
            ofSetColor(0,0,0);
            ofSetLineWidth(1);
            
        }
        
    }

    //testPoly.draw();
    //Poly2.triangulatedMesh.draw();
    //mesh3.draw();
    
    //leather.bind();
    // triMesh.draw();
    
    triMesh.triangulatedMesh.drawWireframe();
    /* isMeshIn[0]=false;
     if(fast==false){
     for(int i=0;i<MeshIndex.size();i++){
     isMeshIn[i]=1;
     }
     fast=true;
     }*/
    
    // triMesh.triangulatedMesh.draw();
    //triMesh.draw();
    // leather.unbind();
    if(inMouseXY){
        cout<<"inMouseXYhaittayo"<<endl;
        ofSetColor(255,0,0,50);
        
        // for(int i=0;i<MeshID.size();i=i+3){
        for(int i=0;i<MX1.size();i++){
            ofTriangle(MX1[i],MY1[i],MX2[i],MY2[i],MX3[i],MY3[i]);
            //ofTriangle(MeshPoint[MeshIndex[i]].x,MeshPoint[MeshIndex[i]].y,MeshPoint[MeshIndex[i+1]].x,MeshPoint[MeshIndex[i+1]].y,MeshPoint[MeshIndex[i+2]].x,MeshPoint[MeshIndex[i+2]].y);
        }
        if(blueSelect&&yellowSelect==false){
            ofSetColor(0,0,250,50);
            for(int i=0;i<BX1.size();i++){
                ofTriangle(BX1[i],BY1[i],BX2[i],BY2[i],BX3[i],BY3[i]);
            }
        }
        if(yellowSelect){
            ofSetColor(250,250,0,50);
            for(int i=0;i<YX1.size();i++){
                ofTriangle(YX1[i],YY1[i],YX2[i],YY2[i],YX3[i],YY3[i]);
            }
        }
    }
    if(isRedMesh){
        ofSetColor(255, 0, 0);
        redMesh.draw();
    }
    if(isBlueMesh){
        blueMesh.draw();
    }
    if(isYellowMesh){
        yellowMesh.draw();
    }
    if(isStrokeLine==true){
        path3.draw();
        PL.draw();
        ofLine(PressX,PressY,releaseX,releaseY);
    }
}

void GuiApp::save(string numX,string filename){
    string fileName = filename + ".txt";
    ofBuffer buffer;
    buffer.append(numX);
    ofBufferToFile( fileName, buffer );
}
void GuiApp::saveVector(std::vector<ofPoint> point,string filename){
    string fileName = filename + ".txt";
    ofBuffer buffer;
    for(int i=0;i<point.size();i++){
        //buffer.append(point[i]);
        buffer.append("x="+ofToString(point[i].x)+"y"+ofToString(point[i].y)+",");
        //buffer=ofBuffer(point[i]);
    }
    //buffer.append(point);
    ofBufferToFile( fileName, buffer );
}
void GuiApp::load(string filename){
    string fileName = filename + ".txt";
    text = string( ofBufferFromFile( fileName ) );
}
void GuiApp::paint_stroke(std::vector<ofPoint> stroke, Boolean loop){
    cout<<"paint_stroke in"<<endl;
    cout<<stroke.size()<<endl;
    if(stroke.size()<=1) return;
    ofPoint prev;
    prev.set(stroke[0]);
    ofCircle(prev.x, prev.y,10);
    
    for(int i=1; i<stroke.size(); i++){
        //PVector v = (PVector)stroke.get(i);
        ofPoint v;
        v.set(stroke[i]);
        ofCircle(v.x, v.y, 3);
        
        ofLine(prev.x, prev.y, v.x, v.y);
        prev = v;
    }
    
    if(loop){
        // PVector v = (PVector)stroke.get(0);
        ofPoint v;
        v.set(stroke[0]);
        ofLine(prev.x, prev.y, v.x, v.y);
    }
}
ofVec3f GuiApp::sub_vector(ofPoint vec1,ofPoint vec2){
    ofPoint ret;
    ret.x = vec1.x - vec2.x;
    ret.y = vec1.y - vec2.y;
    return ret;
}
bool  GuiApp::hittest_point_polygon_2d( ofPoint A, ofPoint B, ofPoint C, ofPoint P ) {
    ofPoint AB = sub_vector(B, A);
    ofPoint BP = sub_vector(P, B);
    
    ofPoint BC = sub_vector(C, B);
    ofPoint CP = sub_vector(P, C);
    
    ofPoint CA = sub_vector(A, C);
    ofPoint AP = sub_vector(P, A);
    double c1 = AB.x * BP.y - AB.y * BP.x;
    double c2 = BC.x * CP.y - BC.y * CP.x;
    double c3 = CA.x * AP.y - CA.y * AP.x;
    if( ( c1 > 0 && c2 > 0 && c3 > 0 ) || ( c1 < 0 && c2 < 0 && c3 < 0 ) ) {
        return true;
    }
    return false;
    
}

//--------------------------------------------------------------
void GuiApp::keyPressed(int key){
    if(key == ('z' - 'a' + 1))
    {
        if(lines.size())
            lines.pop_back();
    }
    if(key=='m'){
        if(redSelect==false&&blueSelect==false&&yellowSelect==false){
            for(int i=0;i<MX1.size();i++){
                redMesh.addVertex(ofVec3f(MX1[i],MY1[i],0));
                redMesh.addVertex(ofVec3f(MX2[i],MY2[i],0));
                redMesh.addVertex(ofVec3f(MX3[i],MY3[i],0));
                
            }
            redSelect=true;
            cout<<"red in"<<endl;
        }
        if(blueSelect==true&&yellowSelect==false){
            for(int i=0;i<BX1.size();i++){
                blueMesh.addVertex(ofVec3f(BX1[i],BY1[i],0));
                blueMesh.addVertex(ofVec3f(BX2[i],BY2[i],0));
                blueMesh.addVertex(ofVec3f(BX3[i],BY3[i],0));
            }
            isBlueMesh=true;
            redSelect=false;
            cout<<"blue in"<<endl;
            cout<<"yellowSelect true"<<endl;
        }
        if(yellowSelect==true){
            for(int i=0;i<YX1.size();i++){
                yellowMesh.addVertex(ofVec3f(YX1[i],YY1[i],0));
                yellowMesh.addVertex(ofVec3f(YX2[i],YY2[i],0));
                yellowMesh.addVertex(ofVec3f(YX3[i],YY3[i],0));
            }
            isYellowMesh=true;
            blueSelect=false;
            cout<<"yellow in"<<endl;
            
        }
        isRedMesh=true;
        if(redSelect){
            blueSelect=true;
        }
        if(blueSelect&&redSelect==false){
            yellowSelect=true;
        }
        
    }
    if(key=='f'){
        isStrokeLine=true;
    }
    if(key == 'd'){
        WriteOn=true;
        finish=false;
        triMesh.triangulatedMesh.clear();
        triSelect=false;
        lines.clear();
        lines2.clear();
        newLine.clear();
        newLine2.clear();
        stroke.clear();
        stroke_reverse.clear();
        //base_stroke.clear();
        changeStroke=false;
        onceDrag=false;
        
    }
    
    if(key=='a'){
        
        myImage.clear();
        load(test);
        loadPointX=ofSplitString(text, ",");
        load("test2");
        loadPointY=ofSplitString(text, ",");
        lines.push_back(std::vector<ofPoint>());
        lines2.push_back(std::vector<ofPoint>());
        for(int i=0;i<loadPointX.size();i++){
            (lines.end()-1)->push_back(ofPoint(ofToInt(loadPointX[i]),ofToInt(loadPointY[i])));
            (lines2.end()-1)->push_back(ofPoint(600-ofToInt(loadPointX[i]),ofToInt(loadPointY[i])));
        }
        WriteOn=true;
        finish=true;
        onceDrag=true;
        
    }
    if(key=='b'){
        WriteOn=false;
    }
    if(key=='t'){
        for(int i=base_stroke.size()-1;i>=0;i--){
            base_stroke.push_back(ofPoint(600-base_stroke[i].x,base_stroke[i].y));
            
        }
        base_stroke_Poly.addVertices(base_stroke);
        triMesh.triangulate(base_stroke_Poly,-1,80);
        MeshPoint=triMesh.triangulatedMesh.getVertices();
        MeshIndex=triMesh.triangulatedMesh.getIndices();
        //fast=false;
        
        
        onceDrag=false;
        changeStroke=false;
        WriteOn=false;
        base_stroke_Poly.clear();
        triSelect=true;
        myImage.clear();
    }
    if(key=='c'){
        
        myImage.clear();
        load("bird");
        loadPointX=ofSplitString(text, ",");
        load("bird2");
        loadPointY=ofSplitString(text, ",");
        lines.push_back(std::vector<ofPoint>());
        lines2.push_back(std::vector<ofPoint>());
        for(int i=0;i<loadPointX.size();i++){
            (lines.end()-1)->push_back(ofPoint(ofToInt(loadPointX[i]),ofToInt(loadPointY[i])));
            (lines2.end()-1)->push_back(ofPoint(600-ofToInt(loadPointX[i]),ofToInt(loadPointY[i])));
        }
        WriteOn=true;
        finish=true;
        onceDrag=true;
        
    }
    if(key=='e'){
        for(int i=0;i<MeshIndex.size();i=i+3){
            if(MeshPoint[MeshIndex[i]].x<300||MeshPoint[MeshIndex[i+1]].x<300||MeshPoint[MeshIndex[i+2]].x<300){
                //  ofTriangle(MeshPoint[MeshIndex[i]].x,MeshPoint[MeshIndex[i]].y,MeshPoint[MeshIndex[i+1]].x,MeshPoint[MeshIndex[i+1]].x,MeshPoint[MeshIndex[i+2]].x,MeshPoint[MeshIndex[i+2]].y);
                MeshID.push_back((int)MeshIndex[i]);
                MeshID.push_back((int)MeshIndex[i+1]);
                MeshID.push_back((int)MeshIndex[i+2]);
                isMeshIn[i/3]=true;
                inMouseXY=true;
                ofPoint Mesh1=MeshPoint[MeshIndex[i]];
                
                ofPoint Mesh2=MeshPoint[MeshIndex[i+1]];
                
                ofPoint Mesh3=MeshPoint[MeshIndex[i+2]];
                MX1.push_back((int)Mesh1.x);
                MX2.push_back((int)Mesh2.x);
                MX3.push_back((int)Mesh3.x);
                MY1.push_back((int)Mesh1.y);
                MY2.push_back((int)Mesh2.y);
                MY3.push_back((int)Mesh3.y);
            }
        }
    }
    
}

//--------------------------------------------------------------
void GuiApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void GuiApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void GuiApp::mouseDragged(int x, int y, int button){
    count++;
    if(triSelect==false){
        if(x>305){
            WriteOn=false;
        }
        if(WriteOn){
            (lines.end()-1)->push_back(ofPoint(x, y));
            (lines2.end()-1)->push_back(ofPoint((600-x), y));
            newLine.push_back(ofPoint(x,y));
            newLine2.push_back(ofPoint((600-x),y));
            Polylines.push_back(ofPoint(x,y));
            if(count%3==0){
                triangulation.addPoint(ofPoint(x,y));
            }
        }
        if(onceDrag){
            (curveLine.end()-1)->push_back(ofPoint(x, y));
            ofPoint NowXY=ofPoint(x,y);
            stroke.push_back(NowXY);
            
            stroke_reverse.push_back(ofPoint(600-x,y));
        }
    }else if(triSelect==true&&isStrokeLine==false){
        // std::vector<ofPoint> MeshPoint=triMesh.triangulatedMesh.getVertices();
        //const std::vector<ofIndexType> MeshIndex=triMesh.triangulatedMesh.getIndices();
        
        for(int i=0;i<MeshIndex.size();i=i+3){
            ofPoint Mesh1=MeshPoint[MeshIndex[i]];
            
            ofPoint Mesh2=MeshPoint[MeshIndex[i+1]];
            
            ofPoint Mesh3=MeshPoint[MeshIndex[i+2]];
 

            if(hittest_point_polygon_2d(Mesh1, Mesh2,Mesh3, ofPoint(x,y))){
                
                //cout<<"attayo"<<endl;
                
                ofSetColor(255, 0, 0);
                
                
                if(isMeshIn[i/3]==false){
                    ofTriangle(Mesh1.x,Mesh1.y,Mesh2.x,Mesh2.y,Mesh3.x,Mesh3.y);
                    if(blueSelect==false){
                        MX1.push_back((int)Mesh1.x);
                        MX2.push_back((int)Mesh2.x);
                        MX3.push_back((int)Mesh3.x);
                        MY1.push_back((int)Mesh1.y);
                        MY2.push_back((int)Mesh2.y);
                        MY3.push_back((int)Mesh3.y);
                        MeshID.push_back((int)MeshIndex[i]);
                        MeshID.push_back((int)MeshIndex[i+1]);
                        MeshID.push_back((int)MeshIndex[i+2]);

                    }else if(blueSelect==true&&yellowSelect==false){
                        BX1.push_back((int)Mesh1.x);
                        BX2.push_back((int)Mesh2.x);
                        BX3.push_back((int)Mesh3.x);
                        BY1.push_back((int)Mesh1.y);
                        BY2.push_back((int)Mesh2.y);
                        BY3.push_back((int)Mesh3.y);
                        MeshID2.push_back((int)MeshIndex[i]);
                        MeshID2.push_back((int)MeshIndex[i+1]);
                        MeshID2.push_back((int)MeshIndex[i+2]);
                        
                    }else{
                        YX1.push_back((int)Mesh1.x);
                        YX2.push_back((int)Mesh2.x);
                        YX3.push_back((int)Mesh3.x);
                        YY1.push_back((int)Mesh1.y);
                        YY2.push_back((int)Mesh2.y);
                        YY3.push_back((int)Mesh3.y);
                    }
                    isMeshIn[i/3]=true;
                    
                    inMouseXY=true;
                    
                    //}else{
                    //inMouseXY=false;
                    // }
                }
                
            
            }else{
                
                //cout<<"naiyo"<<endl;
                
                //inMouseXY=false;
                
            }
            
            
            
        }
        
    }else if(triSelect==true&&isStrokeLine==true){
        cout<<"in the isStrokeLine"<<x<<y<<endl;
       
        path3.lineTo(x,y);
        ofPoint p;
        p.set(x,y);
        PL.addVertex(p);
    }
    
}


//--------------------------------------------------------------
void GuiApp::mousePressed(int x, int y, int button){
    getY=y;
    //cout<<"press"<<endl;
    if(triSelect==false){
        if(onceDrag==false){
            if(x>295&&x<305){
                cout<<"in"<<endl;
                WriteOn=true;
            }
            if(WriteOn){
                cout<<"in2"<<endl;
                lines.push_back(std::vector<ofPoint>());
                lines2.push_back(std::vector<ofPoint>());
                newLine.push_back(ofPoint(x,y));
                newLine2.push_back(ofPoint(x,y));
            }
        }
        if(flagChangePoint==true){
            cout<<"in3"<<endl;
            cout<<"truedayo"<<endl;
            for(std::vector<ofPoint>&line : lines){
                for(unsigned int i = 1; i < line.size(); i++){
                    // ofLine(line[i-1].x, line[i-1].y, line[i].x, line[i].y);
                    if(x>line[i].x-10&&x<line[i].x+10&&y>line[i].y-10&&y<line[i].y+10){
                        changePointNum=i;
                        cout<<i<<endl;
                        changePoint=true;
                    }
                }
            }
            
            
        }
        if(onceDrag){
            cout<<"in4"<<endl;
            onceDragX=x;
            onceDragY=y;
            curveLine.push_back(std::vector<ofPoint>());
            ofPoint NowXY=ofPoint(x,y);
            stroke.push_back(NowXY);
            stroke_reverse.push_back(ofPoint(600-x,y-0.1));
            changeStroke=true;
        }
    }else{
        for(int i=0;i<MeshIndex.size();i=i+3){
            ofPoint Mesh1=MeshPoint[MeshIndex[i]];
            
            ofPoint Mesh2=MeshPoint[MeshIndex[i+1]];
            
            ofPoint Mesh3=MeshPoint[MeshIndex[i+2]];
            ofTriangle(Mesh1.x,Mesh1.y,Mesh2.x,Mesh2.y,Mesh3.x,Mesh3.y);
            
            if(hittest_point_polygon_2d(Mesh1, Mesh2,Mesh3, ofPoint(x,y))){
                
                cout<<"attayo"<<endl;
                
                ofSetColor(255, 0, 0);
                if(isMeshIn[i/3]==false){
                     if(blueSelect==false){
                    ofTriangle(Mesh1.x,Mesh1.y,Mesh2.x,Mesh2.y,Mesh3.x,Mesh3.y);
                    
                    MX1.push_back((int)Mesh1.x);
                    MX2.push_back((int)Mesh2.x);
                    MX3.push_back((int)Mesh3.x);
                    MY1.push_back((int)Mesh1.y);
                    MY2.push_back((int)Mesh2.y);
                    MY3.push_back((int)Mesh3.y);
                    MeshID.push_back((int)MeshIndex[i]);
                    MeshID.push_back((int)MeshIndex[i+1]);
                    MeshID.push_back((int)MeshIndex[i+2]);
                    
                    inMouseXY=true;
                    isMeshIn[i/3]=true;
                     }
                }
                
                
                
            }else{
                
                //cout<<"naiyo"<<endl;
                
                //inMouseXY=false;
                
            }
        }
        
    }
    if(isStrokeLine){
        PressX=x;
        PressY=y;
    }
}


//--------------------------------------------------------------
void GuiApp::mouseReleased(int x, int y, int button){
    
    cout<<"release"<<endl;
    //myImage.clear();
    curveLine.clear();
    string X;
    string Y;
    getY2=y;
    if(triSelect==false){
        if(onceDrag==false){
            cout<<"in1R"<<endl;
            
            /* for(int i=newLine.size()-1;i>=0;i--){
             newLine.push_back(newLine2[i]);
             }*/
            cout<<"newLine end"<<endl;
            base_stroke=resamp.resample_by_length(newLine, resample_size, true);
            /*for(int i =0;i<base_stroke.size()-2;i++){
             ofLine(base_stroke[i].x,base_stroke[i].y,base_stroke[i+1].x,base_stroke[i+1].y);
             cout<<"okok"<<endl;
             }*/
            
            onceDrag=true;
            //cout<<base_stroke.size()<<endl;
            cout<<"base_stroke_start"<<endl;
            for(int i =0;i<base_stroke.size()-1;i++){
                cout<<"base_stroke"<<base_stroke[i]<<endl;
            }
            cout<<"base_stroke_end"<<endl;
        }
        if(x>295&&x<305){
            cout<<"in2R"<<endl;
            
            WriteOn=false;
            flag=true;
            flagChangePoint=true;
            for(std::vector<ofPoint>&line : lines){
                for(unsigned int i = 1; i < line.size(); i++){
                    //save(ofToString(line[i-1].x),test);
                    if(i==line.size()-1){
                        X=X+ofToString(line[i-1].x);
                        Y=Y+ofToString(line[i-1].y);
                        break;
                    }
                    X=X+ofToString(line[i-1].x)+",";
                    Y=Y+ofToString(line[i-1].y)+",";
                    
                }
            }
            //save(X,test);
            //save(Y,"test2");
            //save(X,"bird");
            //save(Y,"bird2");
            // save(X,"zouX");
            //save(Y,"zouY");
            
            finish=true;
            
        }
        /*if(changePoint){
         
         for(std::vector<ofPoint>&line : lines){
         cout<<"No"<<endl;
         line[changePointNum].x=x;
         line[changePointNum].y=y;
         
         }
         
         }*/
        
        //triangulation.addPoint(ofPoint(x,y));
        //triangulation.triangulate();
        finish=true;
        /*if(base_stroke == null){
         // もし、base_strokeがまだnullだったら、描いたストロークをリサンプリングして閉じたフラグをたてて
         // base_strokeへ入れる
         base_stroke = resample_by_length(stroke, resample_size, true);
         }else{
         // すでにbase_strokeが存在したら、描いたストロークは切れ目ストロークとする
         stroke = resample_by_length(stroke, resample_size, false);
         
         // base_strokeをstrokeで切れ込みを入れて、更新する
         base_stroke = meshCleave(base_stroke, stroke);
         }*/
        if(changeStroke){
            resamp_stroke=resamp2.resample_by_length(stroke, resample_size, false);
            resamp_stroke2=resamp2.resample_by_length(stroke_reverse, resample_size, false);
            
            cout<<"base_stroke_before "<<base_stroke.size()<<endl;
            
            base_stroke = meshCl.meshCleave(base_stroke, resamp_stroke);
            //base_stroke=meshCl.meshCleave(base_stroke,resamp_stroke2);
            
            if(changeDragFirst){
                for(int i=4;i<base_stroke.size();i++){
                    /*if(countX<base_stroke[i].x){
                     countX=base_stroke[i].x;
                     }
                     cout<<"countX is"<<countX<<endl;*/
                   /* if(abs(base_stroke[i].x-base_stroke[0].x)<1){
                        base_stroke.erase(base_stroke.begin()+i,base_stroke.end());
                        cout<<"kesitayo"<<endl;
                    }*/
                    
                }
                changeDragFirst=false;
            }
            
            /*for(int i=base_stroke.size()-1;i>=0;i--){
             base_stroke.push_back(ofPoint(600-base_stroke[i].x,base_stroke[i].y));
             
             }*/
            string base_stroke_string="base_stroke";
            saveVector(base_stroke,base_stroke_string);
            
            
            // base_stroke=meshCl.meshCleave(base_stroke,stroke);
            // base_stroke = meshCl.meshCleave(base_stroke, stroke_reverse);
            // change_base_stroke=meshCl.meshCleave(base_stroke, resamp_stroke);
            //change_base_stroke2=meshCl.meshCleave(change_base_stroke, resamp_stroke2);
            //base_stroke.clear();
            //base_stroke.shrink_to_fit();
            /*for(int i=0;i<change_base_stroke2.size();i++){
             base_stroke[i]=change_base_stroke2[i];
             }*/
            // base_stroke=change_base_stroke2;
            
            cout<<"base_stroke_after "<<base_stroke.size()<<endl;
            /*for(int i=0;i<stroke.size();i++){
             cout<<i<<endl;
             cout<<stroke[i]<<endl;
             }*/
        }
    }else{
        
    }
    if(triSelect==true&&isStrokeLine==true){
        path3.lineTo(x,y);
        path3.close();
        releaseX=x;
        releaseY=y;
    }
    
}
//void GuiApp::resample_by_length(

//--------------------------------------------------------------
void GuiApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void GuiApp::mouseExited(int x, int y){
    
}
void GuiApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void GuiApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void GuiApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
