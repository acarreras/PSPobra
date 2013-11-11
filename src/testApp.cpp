#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(30);

    ofLog(OF_LOG_VERBOSE, "PSP: BENVINGUTS a PAIS SENSE PARAULES");

    // EXTENSIÓ pantalla
    screenWidth = 1024; //mida pantalla pral
    screenHeight = 768;
    bextenPantalla = false;

    // imatges
    fonsPantallaP.loadImage(ofToDataPath("IMG/fonsP.jpg"));
    fonsPantallaG.loadImage(ofToDataPath("IMG/fonsG.jpg"));

    // GUI de l'aplicacio
    int dim = 15;
    guiAPP = new ofxUICanvas(0, 0, screenWidth/5, screenHeight);
    guiAPP->addWidgetDown(new ofxUILabel("PSP", OFX_UI_FONT_LARGE));
    guiAPP->addSpacer(2);
    guiAPP->addWidgetDown(new ofxUILabel("FPS LABEL", OFX_UI_FONT_MEDIUM));
    guiAPP->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
    guiAPP->addSpacer(2);
    guiAPP->addWidgetDown(new ofxUILabel("CALIBRA", OFX_UI_FONT_MEDIUM));
    guiAPP->addToggle("bcalibrant", false, dim, dim);
    guiAPP->addSpacer(2);
    guiAPP->addWidgetDown(new ofxUILabel("PINTA PANTALLA GRAN", OFX_UI_FONT_MEDIUM));
    guiAPP->addButton("bclearPantallaG", false, dim, dim);
    guiAPP->addSpacer(2);
    guiAPP->addWidgetDown(new ofxUILabel("PINTA PETITA", OFX_UI_FONT_MEDIUM));
    guiAPP->addButton("bclearPantallaP", false, dim, dim);

    ofLog(OF_LOG_VERBOSE, "PSP: inicialitzada la guiAPP");

    // GUI de la pantalla GRAN
    guiG = new ofxUICanvas(screenWidth/5, 0, screenWidth/5, screenHeight);
    guiG->addWidgetDown(new ofxUILabel("PANTALLA GRAN", OFX_UI_FONT_LARGE));
    guiG->addSpacer(2);
    guiG->addWidgetDown(new ofxUILabel("FLIP image", OFX_UI_FONT_MEDIUM));
    guiG->addToggle("flipVpantallaG", false, dim, dim);
    guiG->addToggle("flipHpantallaG", false, dim, dim);
    guiG->addSpacer(2);
    guiG->addWidgetDown(new ofxUILabel("THRESHOLD", OFX_UI_FONT_MEDIUM));
    guiG->addToggle("bthinvertPantallaG", false, dim, dim);
    guiG->addSlider("thresholdPantallaG", 0.0, 255.0, thresholdPantallaG);
    ofxUISlider *sliderthG = (ofxUISlider*) guiG->getWidget("thresholdPantallaG");
    sliderthG->setIncrement(1.0f);
    guiG->addSpacer(2);
    guiG->addWidgetDown(new ofxUILabel("WARP", OFX_UI_FONT_MEDIUM));
    guiG->addButton("bsetWARPPantallaG", false, dim, dim);
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaG[0], "warpSrcPantallaG0"));
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaG[1], "warpSrcPantallaG1"));
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaG[2], "warpSrcPantallaG2"));
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaG[3], "warpSrcPantallaG3"));
    ofxUI2DPad *padG0 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG0");
    padG0->setIncrement(1.0f);
    ofxUI2DPad *padG1 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG1");
    padG1->setIncrement(1.0f);
    ofxUI2DPad *padG2 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG2");
    padG2->setIncrement(1.0f);
    ofxUI2DPad *padG3 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG3");
    padG3->setIncrement(1.0f);

    guiG2 = new ofxUICanvas(2*screenWidth/5, 0, screenWidth/5, screenHeight);
    guiG2->addWidgetRight(new ofxUILabel("IMATGE DRAW", OFX_UI_FONT_MEDIUM));
    guiG2->addSlider("imagePosXPantallaG", 0.0, screenWidth, imagePosXPantallaG);
    guiG2->addSlider("imagePosYPantallaG", 0.0, screenHeight, imagePosYPantallaG);
    guiG2->addSlider("imageWidthPantallaG", 0.0, screenWidth, imageWidthPantallaG);
    guiG2->addSlider("imageHeightPantallaG", 0.0, screenHeight, imageHeightPantallaG);
    guiG2->addSpacer(2);
    ofxUISlider *sliderposX = (ofxUISlider*) guiG2->getWidget("imagePosXPantallaG");
    sliderposX->setIncrement(1.0f);
    ofxUISlider *sliderposY = (ofxUISlider*) guiG2->getWidget("imagePosYPantallaG");
    sliderposY->setIncrement(1.0f);
    ofxUISlider *sliderposW = (ofxUISlider*) guiG2->getWidget("imageWidthPantallaG");
    sliderposW->setIncrement(1.0f);
    ofxUISlider *sliderposH = (ofxUISlider*) guiG2->getWidget("imageHeightPantallaG");
    sliderposH->setIncrement(1.0f);

    ofLog(OF_LOG_VERBOSE, "PSP: inicialitzada la guiG");

    // GUI de la pantalla PETITA
    guiP = new ofxUICanvas(3*screenWidth/5, 0, screenWidth/5, screenHeight);
    guiP->addWidgetDown(new ofxUILabel("PANTALLA PETITA", OFX_UI_FONT_LARGE));
    guiP->addSpacer(2);
    guiP->addWidgetDown(new ofxUILabel("FLIP image", OFX_UI_FONT_MEDIUM));
    guiP->addToggle("flipVpantallaP", false, dim, dim);
    guiP->addToggle("flipHpantallaP", false, dim, dim);
    guiP->addSpacer(2);
    guiP->addWidgetDown(new ofxUILabel("THRESHOLD", OFX_UI_FONT_MEDIUM));
    guiP->addToggle("bthinvertPantallaP", false, dim, dim);
    guiP->addSlider("thresholdPantallaP", 0.0, 255.0, thresholdPantallaP);
    ofxUISlider *sliderthP = (ofxUISlider*) guiP->getWidget("thresholdPantallaP");
    sliderthP->setIncrement(1.0f);
    guiP->addSpacer(2);
    guiP->addWidgetDown(new ofxUILabel("WARP", OFX_UI_FONT_MEDIUM));
    guiP->addButton("bsetWARPPantallaP", false, dim, dim);
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaP[0], "warpSrcPantallaP0"));
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaP[1], "warpSrcPantallaP1"));
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaP[2], "warpSrcPantallaP2"));
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,screenWidth),ofPoint(0,screenHeight), warpSrcPantallaP[3], "warpSrcPantallaP3"));
    ofxUI2DPad *padP0 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP0");
    padP0->setIncrement(1.0f);
    ofxUI2DPad *padP1 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP1");
    padP1->setIncrement(1.0f);
    ofxUI2DPad *padP2 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP2");
    padP2->setIncrement(1.0f);
    ofxUI2DPad *padP3 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP3");
    padP3->setIncrement(1.0f);


    guiP2 = new ofxUICanvas(4*screenWidth/5, 0, screenWidth/5, screenHeight);
    guiP2->addWidgetRight(new ofxUILabel("IMATGE DRAW", OFX_UI_FONT_MEDIUM));
    guiP2->addSlider("imagePosXPantallaP", 0.0, screenWidth, imagePosXPantallaP);
    guiP2->addSlider("imagePosYPantallaP", 0.0, screenHeight, imagePosYPantallaP);
    guiP2->addSlider("imageWidthPantallaP", 0.0, screenWidth, imageWidthPantallaP);
    guiP2->addSlider("imageHeightPantallaP", 0.0, screenHeight, imageHeightPantallaP);
    guiP2->addSpacer(2);
    ofxUISlider *sliderposXp = (ofxUISlider*) guiP2->getWidget("imagePosXPantallaP");
    sliderposXp->setIncrement(1.0f);
    ofxUISlider *sliderposYp = (ofxUISlider*) guiP2->getWidget("imagePosYPantallaP");
    sliderposYp->setIncrement(1.0f);
    ofxUISlider *sliderposWp = (ofxUISlider*) guiP2->getWidget("imageWidthPantallaP");
    sliderposWp->setIncrement(1.0f);
    ofxUISlider *sliderposHp = (ofxUISlider*) guiP2->getWidget("imageHeightPantallaP");
    sliderposHp->setIncrement(1.0f);

    ofLog(OF_LOG_VERBOSE, "PSP: inicialitzada la guiP");

    ofAddListener(guiAPP->newGUIEvent,this,&testApp::guiEvent);
    ofAddListener(guiG->newGUIEvent,this,&testApp::guiEvent);
    ofAddListener(guiP->newGUIEvent,this,&testApp::guiEvent);
    ofAddListener(guiG2->newGUIEvent,this,&testApp::guiEvent);
    ofAddListener(guiP2->newGUIEvent,this,&testApp::guiEvent);

    // LOAD els settings de les GUI dp del listenr!
    guiAPP->loadSettings("GUI/guiSettingsAPP.xml");
    guiG->loadSettings("GUI/guiSettingsG.xml");
    guiP->loadSettings("GUI/guiSettingsP.xml");
    guiG2->loadSettings("GUI/guiSettingsG2.xml");
    guiP2->loadSettings("GUI/guiSettingsP2.xml");

	// CAM or VIDEO img size
	#ifdef _USE_LIVE_VIDEO
        camWidth = 640;//752;
        camHeight = 480;
	#else
        camWidth = 320;
        camHeight = 240;
	#endif

	#ifdef _USE_LIVE_VIDEO
        vidGrabber.setVerbose(true);
        vidGrabber.listDevices();
        vidGrabber.setDeviceID(0); // uEye = 3
        vidGrabber.initGrabber(camWidth, camHeight);
	#else
        vidPlayer.loadMovie("fingers.mov");
        vidPlayer.play();
	#endif

    // ALLOCATE OPENCV IMAGES
    colorImgPantalla.allocate(camWidth, camHeight);
    grayImagePantalla.allocate(camWidth, camHeight);
    grayImageWarpedPantallaG.allocate(camWidth, camHeight);
    grayImageWarpedPantallaP.allocate(camWidth, camHeight);
    grayImageThPantallaG.allocate(camWidth, camHeight);
    grayImageThPantallaP.allocate(camWidth, camHeight);
    grayImagePintaPantallaG.allocate(camWidth, camHeight);
    grayImagePintaPantallaP.allocate(camWidth, camHeight);
    grayImagePintaPantallaG.set(0);
	grayImagePintaPantallaP.set(0);

    ofLog(OF_LOG_VERBOSE, "PSP: allocated les imatges");

	// TRANSFORMACIO perspectiva
	setWARPQUADPantallaG = 0;
	setWARPQUADPantallaP = 0;

	warpDstPantallaG[0].x = 0.0f;
    warpDstPantallaG[0].y = 0.0f;
    warpDstPantallaG[1].x = 0.0f;
    warpDstPantallaG[1].y = float(camHeight);
    warpDstPantallaG[2].x = float(camWidth);
    warpDstPantallaG[2].y = float(camHeight);
    warpDstPantallaG[3].x = float(camWidth);
    warpDstPantallaG[3].y = 0.0f;

    warpDstPantallaP[0].x = 0.0f;
    warpDstPantallaP[0].y = 0.0f;
    warpDstPantallaP[1].x = 0.0f;
    warpDstPantallaP[1].y = float(camHeight);
    warpDstPantallaP[2].x = float(camWidth);
    warpDstPantallaP[2].y = float(camHeight);
    warpDstPantallaP[3].x = float(camWidth);
    warpDstPantallaP[3].y = 0.0f;

    // carrega IMG
    textTracPintemG.allocate(camWidth, camHeight, GL_RGBA);
    textTracPintemP.allocate(camWidth, camHeight, GL_RGBA);
    pixelsText = new unsigned char[camWidth*camHeight*4];
    pixelsGrayImage = new unsigned char[camWidth*camHeight];


    // ESCENA 1
    guiESCENAP = new ofxUICanvas(0, 0, screenWidth/6, screenHeight);
    guiESCENAP->addWidgetDown(new ofxUILabel("ESCENES", OFX_UI_FONT_LARGE));
    guiESCENAP->addSpacer(2);
    guiESCENAP->addLabel("PANTALLA PETITA", OFX_UI_FONT_MEDIUM);
	vector<string> vnames;
	vnames.push_back("PpintaNO");
	vnames.push_back("PiniciBLANC");    // estatEscenaPantallaP = 0
	vnames.push_back("PiniciNEGRE");    // estatEscenaPantallaP = 1
	vnames.push_back("PpintaGROC");     // 2
	vnames.push_back("PpintaVMLL");     // 3
	vnames.push_back("PpintaGRANAT");   // 4
	vnames.push_back("PpintaGRIS");   // 9
	vnames.push_back("PpintaGROCclar");   // 11
	vnames.push_back("PpintaBLANC");    // 5
	vnames.push_back("PpintaNEGRE");    // 6
	vnames.push_back("PpintaBLANCalpha");   // 7
	vnames.push_back("PpintaNEGREalpha");   // 8
	vnames.push_back("PpintaIMATGE");   // 10
	guiESCENAP->addRadio("petita", vnames, OFX_UI_ORIENTATION_VERTICAL);

	guiESCENAG = new ofxUICanvas(screenWidth/6, 0, screenWidth/6, screenHeight);
    guiESCENAG->addLabel("PANTALLA GRAN", OFX_UI_FONT_MEDIUM);
	vnames.clear();
	vnames.push_back("GpintaNO");
	vnames.push_back("GiniciBLANC");    // 0
	vnames.push_back("GiniciNEGRE");    // 1
	vnames.push_back("GpintaROSA");     // 2
	vnames.push_back("GpintaBLAU");     // 3
	vnames.push_back("GpintaGROC");     // 4
	vnames.push_back("GpintaVMLL");     // 9
	vnames.push_back("GpintaGROCclar");   // 10
	vnames.push_back("GpintaBLANC");    // 5
	vnames.push_back("GpintaNEGRE");    // 6
	vnames.push_back("GpintaBLANCalpha");   // 7
	vnames.push_back("GpintaNEGREalpha");   // 8
	vnames.push_back("GpintaIMATGE");   // 11
	guiESCENAG->addRadio("escena2", vnames, OFX_UI_ORIENTATION_VERTICAL);

    guiESCENAP->setColorBack(ofColor(0,0,0,0));
	ofAddListener(guiESCENAP->newGUIEvent,this,&testApp::guiEvent);
    guiESCENAG->setColorBack(ofColor(0,0,0,0));
	ofAddListener(guiESCENAG->newGUIEvent,this,&testApp::guiEvent);

    bpintaPantallaP = false;
    bpintaPantallaG = false;
    estatEscenaPantallaP = 0;
    estatEscenaPantallaG = 0;

}

//--------------------------------------------------------------
void testApp::update(){

	bool bNewFrame = false;

	#ifdef _USE_LIVE_VIDEO
       vidGrabber.update();
	   bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.update();
        bNewFrame = vidPlayer.isFrameNew();
	#endif

	if (bNewFrame){

		#ifdef _USE_LIVE_VIDEO
            colorImgPantalla.setFromPixels(vidGrabber.getPixels(), camWidth, camHeight);
	    #else
            colorImgPantalla.setFromPixels(vidPlayer.getPixels(), camWidth, camHeight);
        #endif

        grayImagePantalla = colorImgPantalla;
        grayImageWarpedPantallaG.warpIntoMe(grayImagePantalla, warpSrcPantallaG,warpDstPantallaG);
        grayImageWarpedPantallaP.warpIntoMe(grayImagePantalla, warpSrcPantallaP,warpDstPantallaP);

		if(flipVpantallaG){
            grayImageWarpedPantallaG.mirror(true,false);
		}
		if(flipHpantallaG){
            grayImageWarpedPantallaG.mirror(false,true);
		}
		if(flipVpantallaP){
            grayImageWarpedPantallaP.mirror(true,false);
		}
		if(flipHpantallaP){
            grayImageWarpedPantallaP.mirror(false,true);
		}

		grayImageThPantallaG = grayImageWarpedPantallaG;
		grayImageThPantallaG.threshold(thresholdPantallaG, bthinvertPantallaG);
		grayImageThPantallaP = grayImageWarpedPantallaP;
		grayImageThPantallaP.threshold(thresholdPantallaP, bthinvertPantallaP);

		if(bpintaPantallaG){
            grayImagePintaPantallaG += grayImageThPantallaG;
            pixelsGrayImage = grayImagePintaPantallaG.getPixels();

            for (int i=0; i<camWidth; i++){
                for (int j=0; j<camHeight; j++){
                    int pos = (j*camWidth+i);
                    if(pixelsGrayImage[pos] > 0){
                        pixelsText[pos*4  ] = 255;
                        pixelsText[pos*4+1] = 255;
                        pixelsText[pos*4+2] = 255;
                        pixelsText[pos*4+3] = 255;
                    }
                    else{
                        pixelsText[pos*4  ] = 0;
                        pixelsText[pos*4+1] = 0;
                        pixelsText[pos*4+2] = 0;
                        pixelsText[pos*4+3] = 0;
                    }
                }
            }
            textTracPintemG.loadData(pixelsText, camWidth,camHeight, GL_RGBA);
		}
		if(bpintaPantallaP){
		    grayImagePintaPantallaP += grayImageThPantallaP;
            pixelsGrayImage = grayImagePintaPantallaP.getPixels();

            for (int i=0; i<camWidth; i++){
                for (int j=0; j<camHeight; j++){
                    int pos = (j*camWidth+i);
                    if(pixelsGrayImage[pos] > 0){
                        pixelsText[pos*4  ] = 255;
                        pixelsText[pos*4+1] = 255;
                        pixelsText[pos*4+2] = 255;
                        pixelsText[pos*4+3] = 255;
                    }
                    else{
                        pixelsText[pos*4  ] = 0;
                        pixelsText[pos*4+1] = 0;
                        pixelsText[pos*4+2] = 0;
                        pixelsText[pos*4+3] = 0;
                    }
                }
            }
            textTracPintemP.loadData(pixelsText, camWidth,camHeight, GL_RGBA);
		}

		if(bclearPantallaG){
            grayImagePintaPantallaG.set(0);
            bclearPantallaG = false;
		}
		if(bclearPantallaP){
		    grayImagePintaPantallaP.set(0);
		    bclearPantallaP =  false;
		}
	}

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetWindowTitle("Pais Sense Paraules");
    ofBackground(10);

    if(bcalibrant){
        ofPushStyle();

        // rectangle pantalla calibrat
        ofSetColor(255,255,0);
        ofNoFill();
        ofRect(0,0, screenWidth,screenHeight);

        // imatge cam
        ofSetColor(255,255,255);
        grayImagePantalla.draw(0,0, camWidth,camHeight);

        ofSetColor(255,255,255);
        grayImageWarpedPantallaG.draw(2*screenWidth/5,3*screenHeight/5, screenWidth/5, screenHeight/5);
        grayImageThPantallaG.draw(2*screenWidth/5,4*screenHeight/5, screenWidth/5, screenHeight/5);

        grayImageWarpedPantallaP.draw(4*screenWidth/5,2*screenHeight/5, screenWidth/5, screenHeight/5);
        grayImageThPantallaP.draw(4*screenWidth/5,3*screenHeight/5, screenWidth/5, screenHeight/5);

        ofSetColor(255,255,0);
        ofNoFill();
        ofRect(2*screenWidth/5,3*screenHeight/5, screenWidth/5, screenHeight/5);
        ofRect(2*screenWidth/5,4*screenHeight/5, screenWidth/5, screenHeight/5);
        ofRect(4*screenWidth/5,2*screenHeight/5, screenWidth/5, screenHeight/5);
        ofRect(4*screenWidth/5,3*screenHeight/5, screenWidth/5, screenHeight/5);

        // rectangles d'imatge
        ofSetLineWidth(0);
        ofNoFill();
        ofSetColor(250,100,0);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        ofSetColor(220,0,100);
        ofRect(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);

        // warp points
        ofFill();
        ofSetColor(250,100,0);
        ofCircle(warpSrcPantallaG[0],3);
        ofCircle(warpSrcPantallaG[1],3);
        ofCircle(warpSrcPantallaG[2],3);
        ofCircle(warpSrcPantallaG[3],3);
        ofSetColor(220,0,100);
        ofCircle(warpSrcPantallaP[0],3);
        ofCircle(warpSrcPantallaP[1],3);
        ofCircle(warpSrcPantallaP[2],3);
        ofCircle(warpSrcPantallaP[3],3);

        ofPopStyle();
    }
    else{ // escena
        ofPushStyle();
            drawPantallaG();
            drawPantallaP();
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void testApp::exit()
{
    guiAPP->saveSettings("GUI/guiSettingsAPP.xml");
    guiG->saveSettings("GUI/guiSettingsG.xml");
    guiP->saveSettings("GUI/guiSettingsP.xml");
    guiG2->saveSettings("GUI/guiSettingsG2.xml");
    guiP2->saveSettings("GUI/guiSettingsP2.xml");
	delete guiAPP;
	delete guiG;
    delete guiP;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch (key){
	    case 'c':
            guiAPP->toggleVisible();
			guiG->toggleVisible();
			guiP->toggleVisible();
			guiG2->toggleVisible();
			guiP2->toggleVisible();
			break;
        case '1':
            guiESCENAP->toggleVisible();
			guiESCENAG->toggleVisible();
			break;
        case 'f':
            ofToggleFullscreen();
			break;
        case 'e':
            bextenPantalla = !bextenPantalla;
			break;
        case '0':
            estatEscenaPantallaP = 1;
            estatEscenaPantallaG = 1;
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
     if(button==0){
        if (setWARPQUADPantallaG == 5){
             setWARPQUADPantallaG = 0;
        }
        if(setWARPQUADPantallaG > 0){
             warpSrcPantallaG[setWARPQUADPantallaG-1].x = x;
             warpSrcPantallaG[setWARPQUADPantallaG-1].y = y;
             setWARPQUADPantallaG++;
        }
        if (setWARPQUADPantallaP == 5){
             setWARPQUADPantallaP = 0;
        }
        if(setWARPQUADPantallaP > 0){
             warpSrcPantallaP[setWARPQUADPantallaP-1].x = x;
             warpSrcPantallaP[setWARPQUADPantallaP-1].y = y;
             setWARPQUADPantallaP++;
        }
     }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
void testApp::drawPantallaP(){

    int desplacaX = 0;
    if(bextenPantalla){ // extensio
        desplacaX = screenWidth;
    }

    if(bpintaPantallaP){
        // pantalla petita
        if(estatEscenaPantallaP == 0){ // PiniciBLANC
            ofSetColor(250,249,244,255);
            ofRect(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        }
        else if(estatEscenaPantallaP == 1){ // PiniciNEGRE
            ofSetColor(0,0,0,255);
            ofRect(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        }
        else if(estatEscenaPantallaP == 2){ // PpintaGROC
            // http://stackoverflow.com/questions/5097145/opengl-mask-with-multiple-textures
            // http://forum.openframeworks.cc/index.php/topic,339.0.html -> solucio crear textura a ma
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(248,196,58,250);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 3){ // PpintaVMLL
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(198,6,1,255);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 4){ // PpintaGRANAT
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(152,6,5,250);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 5){ // PpintaBLANC
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(250,250,250,250);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 6){ // PpintaNEGRE
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(+ofRandom(0,+5),+ofRandom(0,+5),+ofRandom(0,+5),250);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 7){ // PpintaBLANCalpha
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(255,255,255, 190);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 8){ // PpintaNEGREalpha
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(0,0,0,190);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 9){ // PpintaGRIS
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(131,125,113,250);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaP == 10){ // PpintaIMATGE
            ofSetColor(255,255,255,255);
            fonsPantallaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        }
        else if(estatEscenaPantallaP == 11){ // PpintaGROCclar
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofSetColor(219,195,131,250);
            textTracPintemP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
            ofDisableAlphaBlending();
        }
    }
    else{
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlonaP.draw(desplacaX+imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
    }
}

//--------------------------------------------------------------
void testApp::drawPantallaG(){

    int desplacaX = 0;
    if(bextenPantalla){ // extensio
        desplacaX = screenWidth;
    }
    if(bpintaPantallaG){
        // pantalla gran
        if(estatEscenaPantallaG == 0){ // GiniciBLANC
            ofSetColor(255,250,238,255);
            ofRect(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        }
        if(estatEscenaPantallaG == 1){ // GiniciNEGRE
            ofSetColor(0,0,0,255);
            ofRect(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        }
        if(estatEscenaPantallaG == 2){ // GpintaROSA
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(208,79,133,250);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 3){ // GpintaBLAU
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(12,36,74,250);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 4){ // GpintaGROC
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(240,178,43,250);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 5){ // GpintaBLANC
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(250,250,250,250);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 6){ // GpintaNEGRE
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(+ofRandom(0,+5),+ofRandom(0,+5),+ofRandom(0,+5),250);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 7){ // GpintaBLANCalpha
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(255,255,255,190);
            textTracPintemG.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 8){ // GpintaNEGREalpha
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(0,0,0,190);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 9){ // GpintaVMLL
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(168,0,0,250);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        if(estatEscenaPantallaG == 10){ // GpintaGROCclar
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,255);
            capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofSetColor(228,205,137,250);
            textTracPintemG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
            ofDisableAlphaBlending();
        }
        else if(estatEscenaPantallaG == 11){ // PpintaIMATGE
            ofSetColor(255,255,255,255);
            fonsPantallaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        }
    }
    else{
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlonaG.draw(desplacaX+imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
    }
    //capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	int kind = e.widget->getKind();

	ofLog(OF_LOG_NOTICE, "PSP: event de  " + name + " de tipus " + ofToString(kind));

	if(name == "bcalibrant"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		bcalibrant = toggle->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: bcalibrant: " + ofToString(bcalibrant));
	}
	else if(name == "imagePosXPantallaG"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imagePosXPantallaG = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imagePosXPantallaG: " + ofToString(imagePosXPantallaG));
	}
	else if(name == "imagePosYPantallaG"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imagePosYPantallaG = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imagePosYPantallaG: " + ofToString(imagePosYPantallaG));
	}
	else if(name == "imageWidthPantallaG"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imageWidthPantallaG = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imageWidthPantallaG: " + ofToString(imageWidthPantallaG));
	}
	else if(name == "imageHeightPantallaG"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imageHeightPantallaG = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imageHeightPantallaG: " + ofToString(imageHeightPantallaG));
	}
	else if(name == "imagePosXPantallaP"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imagePosXPantallaP = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imagePosXPantallaP: " + ofToString(imagePosXPantallaP));
	}
	else if(name == "imagePosYPantallaP"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imagePosYPantallaP = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imagePosYPantallaP: " + ofToString(imagePosYPantallaP));
	}
	else if(name == "imageWidthPantallaP"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imageWidthPantallaP = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imageWidthPantallaP: " + ofToString(imageWidthPantallaP));
	}
	else if(name == "imageHeightPantallaP"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		imageHeightPantallaP = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: imageHeightPantallaP: " + ofToString(imageHeightPantallaP));
	}
	else if(name == "warpSrcPantallaG0"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaG[0] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaG0 (" + ofToString(warpSrcPantallaG[0].x) + "," + ofToString(warpSrcPantallaG[0].y) + ")");
	}
	else if(name == "warpSrcPantallaG1"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaG[1] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaG1 (" + ofToString(warpSrcPantallaG[1].x) + "," + ofToString(warpSrcPantallaG[1].y) + ")");
	}
	else if(name == "warpSrcPantallaG2"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaG[2] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaG2 (" + ofToString(warpSrcPantallaG[2].x) + "," + ofToString(warpSrcPantallaG[2].y) + ")");
	}
	else if(name == "warpSrcPantallaG3"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaG[3] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaG3 (" + ofToString(warpSrcPantallaG[3].x) + "," + ofToString(warpSrcPantallaG[3].y) + ")");
	}
	else if(name == "warpSrcPantallaP0"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaP[0] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaP0 (" + ofToString(warpSrcPantallaP[0].x) + "," + ofToString(warpSrcPantallaP[0].y) + ")");
	}
	else if(name == "warpSrcPantallaP1"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaP[1] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaP1 (" + ofToString(warpSrcPantallaP[1].x) + "," + ofToString(warpSrcPantallaP[1].y) + ")");
	}
	else if(name == "warpSrcPantallaP2"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaP[2] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaP2 (" + ofToString(warpSrcPantallaP[2].x) + "," + ofToString(warpSrcPantallaP[2].y) + ")");
	}
	else if(name == "warpSrcPantallaP3"){
		ofxUI2DPad *pad = (ofxUI2DPad*) e.widget;
		warpSrcPantallaP[3] = pad->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: warpSrcPantallaP3 (" + ofToString(warpSrcPantallaP[3].x) + "," + ofToString(warpSrcPantallaP[3].y) + ")");
	}
	else if(name == "bsetWARPPantallaG"){
		ofxUIButton *button = (ofxUIButton *) e.widget;
		bsetWARPPantallaG = button->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: bsetWARPPantallaG: " + ofToString(bsetWARPPantallaG));
		setWARPQUADPantallaG = 1;
		ofLog(OF_LOG_NOTICE, "PSP: setWARPQUADPantallaG: " + ofToString(setWARPQUADPantallaG) + " to start warping");
	}
	else if(name == "bsetWARPPantallaP"){
		ofxUIButton *button = (ofxUIButton *) e.widget;
		bsetWARPPantallaP = button->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: bsetWARPPantallaP: " + ofToString(bsetWARPPantallaP));
		setWARPQUADPantallaP = 1;
		ofLog(OF_LOG_NOTICE, "PSP: setWARPQUADPantallaP: " + ofToString(setWARPQUADPantallaP) + " to start warping");
	}
	else if(name == "bthinvertPantallaG"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		bthinvertPantallaG = toggle->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: bthinvertPantallaG: " + ofToString(bthinvertPantallaG));
	}
	else if(name == "bthinvertPantallaP"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		bthinvertPantallaP = toggle->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: bthinvertPantallaP: " + ofToString(bthinvertPantallaP));
	}
	else if(name == "flipVpantallaG"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		flipVpantallaG = toggle->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: flipVpantallaG: " + ofToString(flipVpantallaG));
	}
	else if(name == "flipHpantallaG"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		flipHpantallaG = toggle->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: flipHpantallaG: " + ofToString(flipHpantallaG));
	}
	else if(name == "flipVpantallaP"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		flipVpantallaP = toggle->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: flipVpantallaP: " + ofToString(flipVpantallaP));
	}
	else if(name == "flipHpantallaP"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		flipHpantallaP = toggle->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: flipHpantallaP: " + ofToString(flipHpantallaP));
	}
	else if(name == "thresholdPantallaG"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		thresholdPantallaG = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: thresholdPantallaG: " + ofToString(thresholdPantallaG));
	}
	else if(name == "thresholdPantallaP"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		thresholdPantallaP = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: thresholdPantallaP: " + ofToString(thresholdPantallaP));
	}
	else if(name == "bclearPantallaG"){
		ofxUIButton *button = (ofxUIButton *) e.widget;
		bclearPantallaG = button->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: bclearPantallaG: " + ofToString(bclearPantallaG));
	}
	else if(name == "bclearPantallaP"){
		ofxUIButton *button = (ofxUIButton *) e.widget;
		bclearPantallaP = button->getValue();
		ofLog(OF_LOG_NOTICE, "PSP: bclearPantallaP: " + ofToString(bclearPantallaP));
	}
	// ESCENA
	// pantalla petita
	else if(name == "PpintaNO"){
		bpintaPantallaP = false;
        capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PiniciBLANC"){
		estatEscenaPantallaP = 0;
		bpintaPantallaP = true;
	}
	else if(name == "PiniciNEGRE"){
		estatEscenaPantallaP = 1;
		bpintaPantallaP = true;
	}
	else if(name == "PpintaGROC"){
	    estatEscenaPantallaP = 2;
		bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaVMLL"){
		estatEscenaPantallaP = 3;
		bclearPantallaP = true;
		bpintaPantallaP = true;
        capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaGRANAT"){
        estatEscenaPantallaP = 4;
        bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaBLANC"){
		estatEscenaPantallaP = 5;
		bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaNEGRE"){
		estatEscenaPantallaP = 6;
		bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaBLANCalpha"){
		estatEscenaPantallaP = 7;
        bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaNEGREalpha"){
		estatEscenaPantallaP = 8;
        bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaGRIS"){
	    estatEscenaPantallaP = 9;
        bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	else if(name == "PpintaIMATGE"){
	    estatEscenaPantallaP = 10;
        bclearPantallaP = true;
		bpintaPantallaP = true;
	}
	else if(name == "PpintaGROCclar"){
	    estatEscenaPantallaP = 11;
        bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlonaP.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	    grayImagePintaPantallaP.set(0);
	}
	// pantalla gran
	else if(name == "GpintaNO"){
		bpintaPantallaG = false;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        grayImagePintaPantallaG.set(0);
	}
	else if(name == "GiniciBLANC"){
		estatEscenaPantallaG = 0;
		bpintaPantallaG = true;
	}
	else if(name == "GiniciNEGRE"){
		estatEscenaPantallaG = 1;
		bpintaPantallaG = true;
	}
	else if(name == "GpintaROSA"){
		estatEscenaPantallaG = 2;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
		grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaBLAU"){
		estatEscenaPantallaG = 3;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
		grayImagePintaPantallaG.set(0);
    }
	else if(name == "GpintaGROC"){
		estatEscenaPantallaG = 4;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaBLANC"){
		estatEscenaPantallaG = 5;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
	    grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaNEGRE"){
		estatEscenaPantallaG = 6;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
	    grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaBLANCalpha"){
		estatEscenaPantallaG = 7;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
	    grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaNEGREalpha"){
		estatEscenaPantallaG = 8;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
	    grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaVMLL"){
		estatEscenaPantallaG = 9;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
	    grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaGROCclar"){
		estatEscenaPantallaG = 10;
        bclearPantallaG = true;
		bpintaPantallaG = true;
		capturaElQuePintaIlonaG.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
	    grayImagePintaPantallaG.set(0);
	}
	else if(name == "GpintaIMATGE"){
	    estatEscenaPantallaG = 11;
        bclearPantallaG = true;
		bpintaPantallaG = true;
	}
}

