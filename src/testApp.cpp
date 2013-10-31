#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(30);

    ofLog(OF_LOG_VERBOSE, "PSP: BENVINGUTS a PAIS SENSE PARAULES");

    // GUI de l'aplicacio
    int dim = 15;
    guiAPP = new ofxUICanvas(0, 0, ofGetWidth()/5, ofGetHeight());
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
    guiAPP->addSpacer(2);
    guiAPP->addWidgetDown(new ofxUILabel("COLOR PINTA", OFX_UI_FONT_MEDIUM));
    guiAPP->addSlider("red", 0.0, 255.0, red);
    ofxUISlider *sliderred = (ofxUISlider*) guiAPP->getWidget("red");
    sliderred->setIncrement(1.0f);
    guiAPP->addSlider("green", 0.0, 255.0, green);
    ofxUISlider *slidergreen = (ofxUISlider*) guiAPP->getWidget("green");
    slidergreen->setIncrement(1.0f);
    guiAPP->addSlider("blue", 0.0, 255.0, blue);
    ofxUISlider *sliderblue = (ofxUISlider*) guiAPP->getWidget("blue");
    sliderblue->setIncrement(1.0f);

    ofLog(OF_LOG_VERBOSE, "PSP: inicialitzada la guiAPP");

    // GUI de la pantalla GRAN
    guiG = new ofxUICanvas(ofGetWidth()/5, 0, ofGetWidth()/5, ofGetHeight());
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
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaG[0], "warpSrcPantallaG0"));
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaG[1], "warpSrcPantallaG1"));
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaG[2], "warpSrcPantallaG2"));
    guiG->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaG[3], "warpSrcPantallaG3"));
    ofxUI2DPad *padG0 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG0");
    padG0->setIncrement(1.0f);
    ofxUI2DPad *padG1 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG1");
    padG1->setIncrement(1.0f);
    ofxUI2DPad *padG2 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG2");
    padG2->setIncrement(1.0f);
    ofxUI2DPad *padG3 = (ofxUI2DPad*) guiG->getWidget("warpSrcPantallaG3");
    padG3->setIncrement(1.0f);

    guiG2 = new ofxUICanvas(2*ofGetWidth()/5, 0, ofGetWidth()/5, ofGetHeight());
    guiG2->addWidgetRight(new ofxUILabel("IMATGE DRAW", OFX_UI_FONT_MEDIUM));
    guiG2->addSlider("imagePosXPantallaG", 0.0, ofGetWidth(), imagePosXPantallaG);
    guiG2->addSlider("imagePosYPantallaG", 0.0, ofGetHeight(), imagePosYPantallaG);
    guiG2->addSlider("imageWidthPantallaG", 0.0, ofGetWidth(), imageWidthPantallaG);
    guiG2->addSlider("imageHeightPantallaG", 0.0, ofGetHeight(), imageHeightPantallaG);
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
    guiP = new ofxUICanvas(3*ofGetWidth()/5, 0, ofGetWidth()/5, ofGetHeight());
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
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaP[0], "warpSrcPantallaP0"));
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaP[1], "warpSrcPantallaP1"));
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaP[2], "warpSrcPantallaP2"));
    guiP->addWidgetDown(new ofxUI2DPad(dim*9, dim*6, ofPoint(0,ofGetWidth()),ofPoint(0,ofGetHeight()), warpSrcPantallaP[3], "warpSrcPantallaP3"));
    ofxUI2DPad *padP0 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP0");
    padP0->setIncrement(1.0f);
    ofxUI2DPad *padP1 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP1");
    padP1->setIncrement(1.0f);
    ofxUI2DPad *padP2 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP2");
    padP2->setIncrement(1.0f);
    ofxUI2DPad *padP3 = (ofxUI2DPad*) guiP->getWidget("warpSrcPantallaP3");
    padP3->setIncrement(1.0f);


    guiP2 = new ofxUICanvas(4*ofGetWidth()/5, 0, ofGetWidth()/5, ofGetHeight());
    guiP2->addWidgetRight(new ofxUILabel("IMATGE DRAW", OFX_UI_FONT_MEDIUM));
    guiP2->addSlider("imagePosXPantallaP", 0.0, ofGetWidth(), imagePosXPantallaP);
    guiP2->addSlider("imagePosYPantallaP", 0.0, ofGetHeight(), imagePosYPantallaP);
    guiP2->addSlider("imageWidthPantallaP", 0.0, ofGetWidth(), imageWidthPantallaP);
    guiP2->addSlider("imageHeightPantallaP", 0.0, ofGetHeight(), imageHeightPantallaP);
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
    imgSalaSo.loadImage(ofToDataPath("IMG/saladelso-fonsnet.png"));
    imgQuadreCezanne.loadImage(ofToDataPath("IMG/cezanne.jpg"));
    textTracPintemG.allocate(camWidth, camHeight, GL_RGBA);
    textTracPintemP.allocate(camWidth, camHeight, GL_RGBA);
    pixelsText = new unsigned char[camWidth*camHeight*4];
    pixelsGrayImage = new unsigned char[camWidth*camHeight];


    // ESCENA 1
    guiESCENA = new ofxUICanvas(0, 0, ofGetWidth()/5, ofGetHeight());
    guiESCENA->addWidgetDown(new ofxUILabel("ESCENES", OFX_UI_FONT_LARGE));
    guiESCENA->addSpacer(2);
    guiESCENA->addLabel("ESCENA1", OFX_UI_FONT_MEDIUM);
	vector<string> vnames;
	vnames.push_back("1ENTRADA");    // estatEscena1 = 1
	vnames.push_back("1ESBORRA");    // estatEscena1 = 2
	vnames.push_back("1LLAPIS");     // estatEscena1 = 3
	vnames.push_back("1GARGOTS");    // 4
	vnames.push_back("1TRENCA");     // 5
	vnames.push_back("1BORRA alpha");// 6
	vnames.push_back("1TAQUES");     // 7
	vnames.push_back("1BORRA fi");   // 8
	guiESCENA->addRadio("escena1", vnames, OFX_UI_ORIENTATION_VERTICAL);
	guiESCENA->addSpacer(2);
	guiESCENA->addLabel("ESCENA2", OFX_UI_FONT_MEDIUM);
	vnames.clear();
	vnames.push_back("2CEZANNE");   // estatEscena2 = 1
	vnames.push_back("2PINTA GP");  // estatEscena2 = 2
	vnames.push_back("2BORRA G");   // estatEscena2 = 3
	vnames.push_back("2RATLLOTS");  // 4
	guiESCENA->addRadio("escena2", vnames, OFX_UI_ORIENTATION_VERTICAL);
	guiESCENA->addSpacer(2);

	ofAddListener(guiESCENA->newGUIEvent,this,&testApp::guiEvent);
    estatEscena1 = 0; // idle
    estatEscena2 = 0;
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

    // imatge cam
    ofSetColor(255,255,255);
    grayImagePantalla.draw(0,0, camWidth,camHeight);

    if(bcalibrant){
        ofPushStyle();

        // imatges
        ofSetColor(255,255,255);

        grayImageWarpedPantallaG.draw(2*ofGetWidth()/5,2*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);
        grayImageThPantallaG.draw(2*ofGetWidth()/5,3*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);

        grayImageWarpedPantallaP.draw(4*ofGetWidth()/5,2*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);
        grayImageThPantallaP.draw(4*ofGetWidth()/5,3*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);

        ofSetColor(255,255,0);
        ofNoFill();
        ofRect(2*ofGetWidth()/5,2*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);
        ofRect(2*ofGetWidth()/5,3*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);
        ofRect(4*ofGetWidth()/5,2*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);
        ofRect(4*ofGetWidth()/5,3*ofGetHeight()/5, ofGetWidth()/5, ofGetHeight()/5);

        // rectangles d'imatge
        ofSetLineWidth(3);
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

        ofSetColor(red, green, blue);
        if(bpintaPantallaG){
            grayImagePintaPantallaG.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        }
        if(bpintaPantallaP){
            grayImagePintaPantallaP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        }
        ofPopStyle();
    }

    ofPushStyle();
        if(estatEscena1 != 0){
            drawEscena1();
        }
        if(estatEscena2 != 0){
            drawEscena2();
        }
    ofPopStyle();
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
			guiESCENA->toggleVisible();
			break;
        case 'a':
            guiAPP->toggleVisible();
			break;
        case '1':
            guiESCENA->toggleVisible();
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
void testApp::drawEscena1(){

    if(estatEscena1 == 1){ // ENTRADA
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofSetColor(255,255,255,255);
        imgSalaSo.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
    }
    else if(estatEscena1 == 2){ // ESBORRA
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        // http://stackoverflow.com/questions/5097145/opengl-mask-with-multiple-textures
        // http://forum.openframeworks.cc/index.php/topic,339.0.html -> solucio crear textura a ma
        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        imgSalaSo.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofSetColor(0,0,0,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    else if(estatEscena1 == 3){ // LLAPIS
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofSetColor(255,200,0,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    else if(estatEscena1 == 4){ // GARGOTS
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofSetColor(255,0,0,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    else if(estatEscena1 == 5){ // TRENCA
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofSetColor(255,255,255,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    else if(estatEscena1 == 6){ // BORRA alpha
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofSetColor(0,0,0,128);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    else if(estatEscena1 == 7){ // TAQUES
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofSetColor(200,20,0,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    else if(estatEscena1 == 8){ // BORRA FI
        ofSetColor(0,0,0,255);
        ofRect(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofSetColor(0,0,0,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
}

//--------------------------------------------------------------
void testApp::drawEscena2(){

    if(estatEscena2 == 1){ // CEZZANE
        ofSetColor(255,255,255,255);
        imgQuadreCezanne.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);

        ofSetColor(50,50,255,255);
        ofRect(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
    }
    if(estatEscena2 == 2){ // PINTA GP
        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        imgQuadreCezanne.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        ofSetColor(50,50,255,255);
        textTracPintemG.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        ofDisableAlphaBlending();

        ofEnableAlphaBlending();
        ofSetColor(50,50,255,255);
        ofRect(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);ofSetColor(0,0,0,255);
        ofSetColor(50,250,55,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    if(estatEscena2 == 3){ // BORRA G
        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        ofSetColor(0,0,0,255);
        textTracPintemG.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        ofDisableAlphaBlending();

        ofEnableAlphaBlending();
        ofSetColor(50,50,255,255);
        ofRect(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);ofSetColor(0,0,0,255);
        ofSetColor(50,250,55,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
    if(estatEscena2 == 4){ // RATLLOTS a la gran
        ofEnableAlphaBlending();
        ofSetColor(255,255,255,255);
        capturaElQuePintaIlona.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        ofSetColor(255,255,255,255);
        textTracPintemG.draw(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        ofDisableAlphaBlending();

        ofEnableAlphaBlending();
        ofSetColor(50,50,255,255);
        ofRect(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);ofSetColor(0,0,0,255);
        ofSetColor(50,250,55,255);
        textTracPintemP.draw(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
        ofDisableAlphaBlending();
    }
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
	else if(name == "red"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		red = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: red: " + ofToString(red));
	}
	else if(name == "green"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		green = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: green: " + ofToString(green));
	}
	else if(name == "blue"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		blue = slider->getScaledValue();
		ofLog(OF_LOG_NOTICE, "PSP: blue: " + ofToString(blue));
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

	// ESCENA 1
	else if(name == "1ENTRADA"){
		estatEscena1 = 1;
	}
	else if(name == "1ESBORRA"){
		estatEscena1 = 2;
		bclearPantallaP = true;
		bpintaPantallaP = true;
	}
	else if(name == "1LLAPIS"){
	    estatEscena1 = 3;
		bclearPantallaP = true;
		bpintaPantallaP = true;
		capturaElQuePintaIlona.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	}
	else if(name == "1GARGOTS"){
		estatEscena1 = 4;
		bclearPantallaP = true;
		bpintaPantallaP = true;
        capturaElQuePintaIlona.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	}
	else if(name == "1TRENCA"){
        estatEscena1 = 5;
        bclearPantallaP = true;
		bpintaPantallaP = true;
        capturaElQuePintaIlona.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	}
	else if(name == "1BORRA alpha"){
		estatEscena1 = 6;
		bclearPantallaP = true;
		bpintaPantallaP = true;
        capturaElQuePintaIlona.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	}
	else if(name == "1TAQUES"){
		estatEscena1 = 7;
		bclearPantallaP = true;
		bpintaPantallaP = true;
        capturaElQuePintaIlona.grabScreen(imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP);
	}
	else if(name == "1BORRA fi"){
		estatEscena1 = 8;
		bclearPantallaP = true;
		bpintaPantallaP = true;
	}
	else if(name == "2CEZANNE"){
		estatEscena1 = 0;
		estatEscena2 = 1;
	}
	else if(name == "2PINTA GP"){
		estatEscena2 = 2;
		bclearPantallaG = true;
		bpintaPantallaG = true;
		bclearPantallaP = true;
		bpintaPantallaP = true;
	}
	else if(name == "2BORRA G"){
		estatEscena2 = 3;
		capturaElQuePintaIlona.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        bclearPantallaG = true;
		bpintaPantallaG = true;
		bpintaPantallaP = true;
	}
	else if(name == "2RATLLOTS"){
		estatEscena2 = 4;
		capturaElQuePintaIlona.grabScreen(imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG);
        bclearPantallaG = true;
		bpintaPantallaG = true;
		bpintaPantallaP = true;
	}

}

