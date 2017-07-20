//
//  Resampling.cpp
//  leather3
//
//  Created by Takuya Ogashi on 2016/10/26.
//
//

#include <stdio.h>
#include "Resampling.h"
#include <iostream>

// UNIT_LENGTHの長さごとに分割する
std::vector<ofPoint> Resampling::resample_by_length(std::vector<ofPoint> stroke, double UNIT_LENGTH, Boolean loop){
    if (stroke.size() <=1)
        return stroke;
    
    double length = get_length(stroke);
    cout<<"length"<<length<<endl;
    int n = (int) (length / UNIT_LENGTH + 0.5);
    if (n < 2)
        n = 2;
    
    cout<<"n"<<n<<endl;
    return resample_by_number(stroke, n, loop);
}


// n個の頂点に分割する
// loopがtrueだったら、ループ。
std::vector<ofPoint> Resampling::resample_by_number(std::vector<ofPoint> stroke, double n, Boolean loop){
    if (stroke.size() <=1)
        return stroke;
     cout<<"stroke size"<<stroke.size()<<endl;
    if(loop){
       // stroke.add((PVector)stroke.get(0));
        stroke.push_back(stroke[0]);
    }
     cout<<"stroke size 2"<<stroke.size()<<endl;
    
    double length = get_length(stroke);
    double unit = length/n;
    
    cout<<"unit"<<unit<<endl;
    
   // PVector v0 = (PVector) stroke.get(0);
   // PVector v1 = (PVector) stroke.get(stroke.size()-1);
    ofPoint v0;
    ofPoint v1;
    v0.set(stroke[0]);
    v1.set(stroke[stroke.size()-1]);
     cout<<"v0"<<v0<<endl;
    cout<<"v1"<<v1<<endl;
    
    
    
   // ArrayList resampled = new ArrayList();
    std::vector<ofPoint> resampled;
    resampled.push_back(v0);
    
    double total = 0;
    double prev_total=0;
    ofPoint prev = v0;
    ofPoint next;
    double next_spot = unit;
    int index = 1;
    int count = 0;
    while(true){
        if (index == stroke.size())
            break;
       // next = (PVector) stroke.get(index);
        next.set(stroke[index]);
        cout<<"next"<<next<<endl;
        total += distance(prev, next);
        cout<<"total"<<total<<endl;
        cout<<"next_spot"<<next_spot<<endl;
        while (total >= next_spot)  {//点が荒かった時に細かくする
            cout<<"total in while "<<total<<endl;
            ofPoint new_vertex = interpolate(prev, next, (next_spot-prev_total)/(total-prev_total));
            //resampled.add(new_vertex);
            resampled.push_back(new_vertex);
            next_spot += unit;
            count++;
            if (count == n-1)
                break;
        }
        if (count == n-1)
            break;
        prev = next;
        prev_total = total;
        index++;
        
    }
    
    //resampled.add(v1);
    resampled.push_back(v1);
    
    if(loop)
         resampled.erase(resampled.end()-1);
    cout<<"size"<<resampled.size()<<endl;
    cout<<resampled[0]<<endl;
    return resampled;
}

// ストロークの長さを求める
double Resampling::get_length(std::vector<ofPoint> stroke){
    double length = 0;
    for(int i=0; i<stroke.size()-1; i++){
        //PVector p = (PVector) stroke.get(i);
        //PVector q = (PVector) stroke.get(i+1);
        ofPoint p;
        p.set(stroke[i]);
        ofPoint q;
        q.set(stroke[i+1]);
        length += distance(p,q);
    }
    return length;
}
//n1とn2の距離を求める
 double Resampling::distance(ofPoint n1, ofPoint n2){
    return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}

// startとendの間をt:1-tに内分する点を求める
ofPoint Resampling::interpolate(ofPoint start,ofPoint end, double t){
    return ofPoint((int)(start.x * (1-t) + end.x * t), (int)(start.y * (1-t) + end.y * t));
}

double Resampling::dividing_ratio(ofPoint start, ofPoint end, ofPoint divid_v){
    return distance(start, divid_v)/distance(start, end);
}
