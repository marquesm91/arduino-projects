#ifndef SAMSUNGREMOTE_H
#define SAMSUNGREMOTE_H

#include "Component.h"

class SamsungRemote : public Component{
  IRsend irsend;
public:
  SamsungRemote(char* name, int pin) : Component(name, pin){
    pinMode(pin, OUTPUT); // Infrared as OUTPUT
  }
  void powerButton(){
    irsend.sendSAMSUNG(0xE0E040BF, 32); // POWER
  }
  void sourceButton(){
    irsend.sendSAMSUNG(0xE0E0807F, 32); // SOURCE
  }
  void hdmiButton(){
    irsend.sendSAMSUNG(0xE0E0D12E, 32); // HDMI
  }
  void Button1(){
    irsend.sendSAMSUNG(0xE0E020DF, 32); // 1
  }
  void Button2(){
    irsend.sendSAMSUNG(0xE0E0A05F, 32); // 2
  }
  void Button3(){
    irsend.sendSAMSUNG(0xE0E0609F, 32); // 3
  }
  void Button4(){
    irsend.sendSAMSUNG(0xE0E010EF, 32); // 4
  }
  void Button5(){
    irsend.sendSAMSUNG(0xE0E0906F, 32); // 5
  }
  void Button6(){
    irsend.sendSAMSUNG(0xE0E050AF, 32); // 6
  }
  void Button7(){
    irsend.sendSAMSUNG(0xE0E030CF, 32); // 7
  }
  void Button8(){
    irsend.sendSAMSUNG(0xE0E0B04F, 32); // 8
  }
  void Button9(){
    irsend.sendSAMSUNG(0xE0E0708F, 32); // 9
  }
  void hyphenButton(){
    irsend.sendSAMSUNG(0xE0E0C43B, 32); // -
  }
  void Button0(){
    irsend.sendSAMSUNG(0xE0E08877, 32); // 0
  }
  void preChButton(){
    irsend.sendSAMSUNG(0xE0E0C837, 32); // PRE-CH
  }
  void volUpButton(){ 
    irsend.sendSAMSUNG(0xE0E0E01F, 32); // VOL UP
  }
  void volDownButton(){
    irsend.sendSAMSUNG(0xE0E0D02F, 32); // VOL DOWN
  }
  void muteButton(){
    irsend.sendSAMSUNG(0xE0E0F00F, 32); // MUTE
  }
  void chListButton(){
    irsend.sendSAMSUNG(0xE0E0D629, 32); // CH LIST
  }
  void chUpButton(){
    irsend.sendSAMSUNG(0xE0E048B7, 32); // CH UP
  }
  void chDownButton(){
    irsend.sendSAMSUNG(0xE0E008F7, 32); // CH DOWN
  }
  void contentButton(){
    irsend.sendSAMSUNG(0xE0E09E61, 32); // CONTENT
  }
  void menuButton(){
    irsend.sendSAMSUNG(0xE0E058A7, 32); // MENU
  }
  void guideButton(){
    irsend.sendSAMSUNG(0xE0E0F20D, 32); // GUIDE
  }
  void toolsButton(){
    irsend.sendSAMSUNG(0xE0E0D22D, 32); // TOOLS
  }
  void infoButton(){
    irsend.sendSAMSUNG(0xE0E0F807, 32); // INFO
  }
  void returnButton(){
    irsend.sendSAMSUNG(0xE0E01AE5, 32); // RETURN
  }
  void exitButton(){
    irsend.sendSAMSUNG(0xE0E0B44B, 32); // EXIT
  }
  void upButton(){
    irsend.sendSAMSUNG(0xE0E006F9, 32); // UP_ARROW
  }
  void leftButton(){
    irsend.sendSAMSUNG(0xE0E0A659, 32); // LEFT_ARROW
  }
  void rightButton(){
    irsend.sendSAMSUNG(0xE0E046B9, 32); // RIGHT_ARROW
  }
  void downButton(){
    irsend.sendSAMSUNG(0xE0E08679, 32); // DOWN_ARROW
  }
  void centerButton(){
    irsend.sendSAMSUNG(0xE0E016E9, 32); // CENTER_BUTTON
  }
  void aRedButton(){
    irsend.sendSAMSUNG(0xE0E036C9, 32); // A_RED
  }
  void bGreenButton(){
    irsend.sendSAMSUNG(0xE0E028D7, 32); // B_GREEN
  }
  void cYellowButton(){
    irsend.sendSAMSUNG(0xE0E0A857, 32); // C_YELLOW
  }
  void dBlueButton(){
    irsend.sendSAMSUNG(0xE0E06897, 32); // D_BLUE
  }
  void eManualButton(){
    irsend.sendSAMSUNG(0xE0E0FC03, 32); // E-MANUAL
  }
  void srsButton(){
    irsend.sendSAMSUNG(0xE0E07689, 32); // SRS
  }
  void pmodeButton(){
    irsend.sendSAMSUNG(0xE0E014EB, 32); // P.MODE
  }
  void psizeButton(){
    irsend.sendSAMSUNG(0xE0E07C83, 32); // P.SIZE
  }
  void ccButton(){
    irsend.sendSAMSUNG(0xE0E0A45B, 32); // CC
  }
  void mtsButton(){
    irsend.sendSAMSUNG(0xE0E000FF, 32); // MTS
  }
  void backwardButton(){
    irsend.sendSAMSUNG(0xE0E0A25D, 32); // BACKWARD
  }
  void pauseButton(){
    irsend.sendSAMSUNG(0xE0E052AD, 32); // PAUSE
  }
  void forwardButton(){
    irsend.sendSAMSUNG(0xE0E012ED, 32); // FORWARD
  }
  void recButton(){
    irsend.sendSAMSUNG(0xE0E0926D, 32); // REC
  }
  void playButton(){
    irsend.sendSAMSUNG(0xE0E0E21D, 32); // PLAY
  }
  void stopButton(){
    irsend.sendSAMSUNG(0xE0E0629D, 32); // STOP
  }
};

#endif
