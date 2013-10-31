#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxXmlSettings.h"
#include "ofxUI.h"

#define _USE_LIVE_VIDEO		// uncomment this to use a live camera
                            // otherwise, we'll use a movie file
#define IMG_BUFFER_LENGTH   5

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void guiEvent(ofxUIEventArgs &e);

        // APP PSP
        bool bcalibrant;
        bool bclearPantallaG, bclearPantallaP;
        bool bpintaPantallaG, bpintaPantallaP;

        #ifdef _USE_LIVE_VIDEO
		  ofVideoGrabber vidGrabber;
		#else
		  ofVideoPlayer vidPlayer;
		#endif

        // GUI
        ofxUICanvas             *guiAPP, *guiG, *guiP, *guiG2, *guiP2;
        ofxUICanvas             *guiESCENA;

        // OPENCV
        ofxCvColorImage         colorImgPantalla;
        ofxCvGrayscaleImage     grayImagePantalla;
        ofxCvGrayscaleImage     grayImageWarpedPantallaG, grayImageWarpedPantallaP;
        ofxCvGrayscaleImage     grayImageThPantallaG, grayImageThPantallaP;
        bool flipVpantallaG, flipHpantallaG;
        bool flipVpantallaP, flipHpantallaP;
        int thresholdPantallaG, thresholdPantallaP;
		bool bthinvertPantallaG, bthinvertPantallaP;
		ofxCvGrayscaleImage     grayImagePintaPantallaG, grayImagePintaPantallaP;

		// CAMERA
        int deviceCam;
        int camWidth, camHeight;

		// WARP CAMERA IMAGE
		bool bsetWARPPantallaG, bsetWARPPantallaP;
		int setWARPQUADPantallaG, setWARPQUADPantallaP;
        ofPoint             warpSrcPantallaG[4], warpSrcPantallaP[4];
		ofPoint             warpDstPantallaG[4], warpDstPantallaP[4];

        // DRAW
        int imagePosXPantallaG, imagePosYPantallaG, imageWidthPantallaG, imageHeightPantallaG;
        int imagePosXPantallaP, imagePosYPantallaP, imageWidthPantallaP, imageHeightPantallaP;

        // COLOR pinta PANTALLA
        int red, green, blue;
        ofTexture textTracPintemG, textTracPintemP;
        unsigned char * pixelsText;
        unsigned char * pixelsGrayImage;

        // ESCENES
        ofImage capturaElQuePintaIlona;

        // ESCENA 1
        void drawEscena1();
        int estatEscena1;
        ofImage imgNegra;
        ofImage imgSalaSo;

        // ESCENA 2
        void drawEscena2();
        int estatEscena2;
        ofImage imgQuadreCezanne;

};

