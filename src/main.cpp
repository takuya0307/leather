#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"


//========================================================================
int main( ){
    //ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    //ofRunApp(new ofApp());
    ofGLFWWindowSettings settings;
    
    settings.width =600;
    settings.height = 600;
    settings.setPosition(ofVec2f(1024,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 1024;
    settings.height = 768;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<GuiApp> guiApp(new GuiApp);
    mainApp->WriteOn = guiApp;
    mainApp->lines=guiApp;
    mainApp->meshGui=guiApp;
    mainApp->triMesh=guiApp;
    mainApp->redMesh=guiApp;
    mainApp->isRedMesh=guiApp;
    mainApp->blueMesh=guiApp;
     mainApp->isBlueMesh=guiApp;
    mainApp->yellowMesh=guiApp;
    mainApp->isYellowMesh=guiApp;
    mainApp->MeshID=guiApp;
    mainApp->MeshID2=guiApp;
    //mainApp->MeshID3=guiApp;
    
    ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
    
    
}
