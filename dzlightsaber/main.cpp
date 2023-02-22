// TEST AUDIO

// #include "Arduino.h"
// #include "SoftwareSerial.h"
// #include "DFRobotDFPlayerMini.h"

// SoftwareSerial mySoftwareSerial(10, 11); // RX, TX

// // Create the DFPlayer Mini object.
// DFRobotDFPlayerMini myDFPlayer;

// void setup() {
//   // Initiate the DFPlayer.
//   mySoftwareSerial.begin(9600);
//   Serial.begin(115200);
  
//   // Check whether the DFPlayer is running accurately or not.
//   if (!myDFPlayer.begin(mySoftwareSerial)) {  // Use SoftwareSerial to communicate with the DFPlayer.
//     Serial.println(F("Unable to begin:"));
//     Serial.println(F("1.Please recheck the connection!"));
//     Serial.println(F("2.Please insert the SD card!"));
//     while(true);
//   }
//   Serial.println(F("DFPlayer Mini online."));
  
//   myDFPlayer.setTimeOut(500); //Set serial communication time out 500ms
  
//    //----Set volume----
//   myDFPlayer.volume(20);  //Set volume value (0~30).
//   myDFPlayer.volumeUp(); //Volume Up
//   myDFPlayer.volumeDown(); //Volume Down

//   //----Set different EQ----
//   myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
// //  myDFPlayer.EQ(DFPLAYER_EQ_POP);
// //  myDFPlayer.EQ(DFPLAYER_EQ_ROCK);
// //  myDFPlayer.EQ(DFPLAYER_EQ_JAZZ);
// //  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
// //  myDFPlayer.EQ(DFPLAYER_EQ_BASS);

//   //----Set device we use SD as default----
// //  myDFPlayer.outputDevice(DFPLAYER_DEVICE_U_DISK);
//   myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
// //  myDFPlayer.outputDevice(DFPLAYER_DEVICE_AUX);
// //  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SLEEP);
// //  myDFPlayer.outputDevice(DFPLAYER_DEVICE_FLASH);

//   //----Mp3 control----
// //  myDFPlayer.sleep();     //sleep
// //  myDFPlayer.reset();     //Reset the module
// //  myDFPlayer.enableDAC();  //Enable On-chip DAC
// //  myDFPlayer.disableDAC();  //Disable On-chip DAC
// //  myDFPlayer.outputSetting(true, 15); //output setting, enable the output and set the gain to 15

//   //----Mp3 play----
//   myDFPlayer.next();  //Play next mp3
//   delay(1000);
//   // myDFPlayer.previous();  //Play previous mp3
//   // delay(1000);
//   // myDFPlayer.play(1);  //Play the first mp3
//   // delay(1000);
//   // myDFPlayer.loop(1);  //Loop the first mp3
//   // delay(1000);
//   // myDFPlayer.pause();  //pause the mp3
//   // delay(1000);
//   // myDFPlayer.start();  //start the mp3 from the pause
//   // delay(1000);
//   // myDFPlayer.playFolder(15, 3);  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
//   // delay(1000);
//   // myDFPlayer.enableLoopAll(); //loop all mp3 files.
//   // delay(1000);
//   // myDFPlayer.disableLoopAll(); //stop loop all mp3 files.
//   // delay(1000);
//   // myDFPlayer.playMp3Folder(3); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
//   // delay(1000);
//   // myDFPlayer.advertise(3); //advertise specific mp3 in SD:/ADVERT/0003.mp3; File Name(0~65535)
//   // delay(1000);
//   // myDFPlayer.stopAdvertise(); //stop advertise
//   // delay(1000);
//   // myDFPlayer.playLargeFolder(1, 1); //play specific mp3 in SD:/02/004.mp3; Folder Name(1~10); File Name(1~1000)
//   // delay(1000);
//   // myDFPlayer.loopFolder(5); //loop all mp3 files in folder SD:/05.
//   // delay(1000);
//   // myDFPlayer.randomAll(); //Random play all the mp3.
//   // delay(1000);
//   // myDFPlayer.enableLoop(); //enable loop.
//   // delay(1000);
//   // myDFPlayer.disableLoop(); //disable loop.
//   // delay(1000);
  
// }

// void loop(){
//   //   myDFPlayer.next(); 
//   // delay(1000);
// }