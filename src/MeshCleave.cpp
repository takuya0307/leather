//
//  MeshCleave.cpp
//  leather3
//
//  Created by Takuya Ogashi on 2016/10/24.
//
//

#include <stdio.h>
#include <iostream>
#include <MeshCleave.h>
int cleave_width = 10; //切れ込みを入れる幅。ここを変えて実験すると良い
int cross_point_base_edge_start_index = -1; // ベースストロークにおいて、交点があるEdgeのstartにあたるインデックス
int cross_point_insert_edge_start_index = -1; //切れ込みストロークにおいて、交点があるEdgeのstartにあたるインデックス
ofPoint cross_point; //ベースストロークと切れ込みストロークの交点

// 外側のループに対して切れ込みのストロークを入れたら、
// 切れ込みを入れたループを作り直す関数
std::vector<ofPoint> MeshCleave::meshCleave(std::vector<ofPoint> base_stroke, std::vector<ofPoint> insert_stroke){
    std::vector<ofPoint> new_stroke;
    
    
    // まず、外側のEdgeクラスリストを作る (交点を求めるため)
    std::vector<MyEdge> base_stroke_edges;
    
    //ofPoint v0 = base_stroke.getMapped(base_stroke.size()-1);
    ofPoint v0=base_stroke[base_stroke.size()-1];
    for(int i=0; i<base_stroke.size(); i++){
       // ofPoint v1 = base_stroke.get(i);
        //ofPoint v1=base_stroke[i];
        ofPoint *adV1=&base_stroke[i];
        ofPoint v1=*adV1;
        MyEdge *edgePtr=new MyEdge(v0,v1);
        base_stroke_edges.push_back(*edgePtr);
        v0 = v1;
    }
    
    // 切れ込みのストロークからEdgeクラスを作って、EdgeとEdgeの交点を求める
    for(int i=0; i<insert_stroke.size()-1; i++){
        //ofPoint _v0 = insert_stroke.get(i);
        //ofPoint _v1 = insert_stroke.get(i+1);
        ofPoint *_v0Ptr = &insert_stroke[i];
        ofPoint *_v1Ptr = &insert_stroke[i+1];
        ofPoint _v0=*_v0Ptr;
        ofPoint _v1=*_v1Ptr;
        MyEdge *edgePtr2 = new MyEdge(_v0, _v1);
        //ここまでやった
        Boolean cross =  exist_cross_point(base_stroke_edges, *edgePtr2);
        if(cross){
            cross_point_insert_edge_start_index = i;
            cross_point = get_cross_point(base_stroke_edges, *edgePtr2);
        }
    }
    
    // この段階でcross_point　に交点が入っている。
    
    // 切れ込みストロークを交点から内側のみに更新する
    insert_stroke = insert_stroke_update(insert_stroke);
    
    //////////////////////////////////
    // ここまでで、入力したストロークが切れた
    
    // 入力した線に対して、行って帰ってくるストロークを作る
    //ArrayList cleave_stroke = get_cleave_stroke(insert_stroke);
    std::vector<ofPoint>cleave_stroke=get_cleave_stroke(insert_stroke);
    
    
    /////////////////////////////////////
    /// ベースのストロークを上でできた切れ込みストロークを使って更新する
    base_stroke = base_stroke_update(base_stroke, cleave_stroke);
    
    return base_stroke;
    //return cleave_stroke;
    // return insert_stroke;
}

// 切れ込みストロークをベースストロークの内部のみにする
std::vector<ofPoint> MeshCleave::insert_stroke_update(std::vector<ofPoint> insert_stroke){
    std::vector<ofPoint> new_stroke;
    new_stroke.push_back(cross_point);
    for(int i=cross_point_insert_edge_start_index+1; i<insert_stroke.size(); i++){
     //   new_stroke.add((PVector)insert_stroke.get(i));
        new_stroke.push_back(insert_stroke[i]);
    }
    return new_stroke;
}

// Edgeリスト：edgesの中にEdgeと交点をもつEdgeがあるか？
Boolean MeshCleave::exist_cross_point(std::vector<MyEdge>edges, MyEdge edge){
    for(int i=0; i<edges.size(); i++){
        Boolean cross_point = edges[i].cross(edge);
        if(cross_point)
            return true;
    }
    return false;
}

// Edgeリスト：edgesの中にEdgeと交点をもつEdgeがある場合、その交点を返す
ofPoint MeshCleave::get_cross_point(std::vector<MyEdge>edges, MyEdge edge2){
    for(int i=0; i<edges.size(); i++){
        //Edge e = (Edge)edges.get(i);
        //dekinakattarasannshou
        ofPoint v0=edges[i].start;
        ofPoint v1=edges[i].end;
        MyEdge *ePtr=new MyEdge(v0,v1);
        Boolean _cross_point = edges[i].cross(edge2);
        if(_cross_point){
            cross_point_base_edge_start_index = i;  // 交点をもつエッジのstartのインデックスを入力
              // 交点をもつエッジを入力
            cross_base_edge =*ePtr;
            return ePtr->cross_point(edge2);
        }
        
    }
    return ofPoint::zero();
    
}

// 入力した線に対して、行って帰ってくるストロークを作る
std::vector<ofPoint> MeshCleave::get_cleave_stroke(std::vector<ofPoint> insert_stroke){
   // ArrayList cleave_stroke = new ArrayList();
    std::vector<ofPoint> cleave_stroke;
    
    // 切れ込みストロークの最初を決める。
    // 交点より少し手前を求めるために、内分している比率を知る
    double t = dividing_ratio(cross_base_edge.start, cross_base_edge.end, cross_point);
    cout<<t<<endl;
    ofPoint cleave_start = interpolate(cross_base_edge.start, cross_base_edge.end, t-0.1);
    ofPoint cleave_end = interpolate(cross_base_edge.start, cross_base_edge.end, t+0.1);
    
    //cleave_stroke.add(cleave_start);
    cleave_stroke.push_back(cleave_start);
    
    //PVector v0 = (PVector)insert_stroke.get(0);
    ofPoint v0=insert_stroke[0];
    // cleave_stroke.add(v0);
    
    // ベースストロークとの交点から内側にたどっていく
    for(int i=1; i<insert_stroke.size(); i++){
        //PVector v1 = (PVector)insert_stroke.get(i);
        ofPoint v1=insert_stroke[i];
        //PVector vec01 = new PVector(v1.x-v0.x, v1.y-v0.y);
        ofPoint vec01;
        vec01.set(v1.x-v0.x, v1.y-v0.y);
        //vec01.rotate(270); // 90度回転させることで、法線ベクトルを得る
        vec01.rotate(270,ofVec3f(1,1,0));
        vec01.normalize(); // 単位ベクトルにする
      //  vec01.mult(cleave_width); //切れ込み幅の長さのベクトルに変換
        vec01=vec01*(cleave_width);
     //   PVector new_v1 = new PVector(v1.x+vec01.x, v1.y+vec01.y); //頂点を法線方向に切れ込み幅の分だけずらす
        ofPoint new_v1;
        new_v1.set(v1.x+vec01.x, v1.y+vec01.y);
       // cleave_stroke.add(new_v1);
        cleave_stroke.push_back(new_v1);
        v0 = v1;
    }
    
    
    //  // 一番内側から外側へ戻っていく
    //  for(int i=insert_stroke.size()-1; i>=0; i--){
    //    PVector v1 = (PVector)insert_stroke.get(i);
    //    PVector vec01 = new PVector(v1.x-v0.x, v1.y-v0.y); // ベクトルの向きがさっきと逆になるので、やはり90度回転でよくなる
    //    vec01.rotate(90); // 90度回転させることで、法線ベクトルを得る
    //    vec01.normalize(); // 単位ベクトルにする
    //    vec01.mult(cleave_width); //切れ込み幅の長さのベクトルに変換
    //
    //    PVector new_v0 = new PVector(v1.x+vec01.x, v1.y+vec01.y); //頂点を法線方向に切れ込み幅の分だけずらす
    //    cleave_stroke.add(new_v0);
    //    v0 = v1;
    //  }
    for(int i=insert_stroke.size()-1; i>0; i--){ //戻ってくるときは切れ込みストロークをそのまま利用
        //PVector v = (PVector)insert_stroke.get(i);
        ofPoint v;
        v.set(insert_stroke[i].x,insert_stroke[i].y);
        //cleave_stroke.add(v);
        cleave_stroke.push_back(v);
    }
    //cleave_stroke.add(cleave_end);
     cleave_stroke.push_back(cleave_end);
    
    return cleave_stroke;
}


/////////////////////////////////////
/// ベースのストロークを上でできた切れ込みストロークを使って更新する
std::vector<ofPoint> MeshCleave::base_stroke_update(std::vector<ofPoint> base_stroke, std::vector<ofPoint> cleave_stroke){
   // ArrayList new_base_stroke = new ArrayList();
    std::vector<ofPoint> new_base_stroke;
    for(int i=0;i<cross_point_base_edge_start_index; i++){
       // PVector v = (PVector)base_stroke.get(i);
        ofPoint v;
        v.set(base_stroke[i].x,base_stroke[i].y);
        //new_base_stroke.add(v);
        new_base_stroke.push_back(v);
    }
    
    for(int i=0; i<cleave_stroke.size(); i++){
        //PVector v = (PVector)cleave_stroke.get(i);
        //new_base_stroke.add(v);
        ofPoint v;
        v.set(cleave_stroke[i].x,cleave_stroke[i].y);
        new_base_stroke.push_back(v);
    }
    
    for(int i=cross_point_base_edge_start_index+1; i<base_stroke.size(); i++){
       // PVector v = (PVector)base_stroke.get(i);
       // new_base_stroke.add(v);
        ofPoint v;
        v.set(base_stroke[i].x,base_stroke[i].y);
        new_base_stroke.push_back(v);
    }
    
    return new_base_stroke;
    
}

//n1とn2の距離を求める
double MeshCleave::distance(ofPoint n1, ofPoint n2){
    return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}

// startとendの間をt:1-tに内分する点を求める
ofPoint MeshCleave::interpolate(ofPoint start,ofPoint end, double t){
    return ofPoint((int)(start.x * (1-t) + end.x * t), (int)(start.y * (1-t) + end.y * t));
}

double MeshCleave::dividing_ratio(ofPoint start, ofPoint end, ofPoint divid_v){
    return distance(start, divid_v)/distance(start, end);
}
