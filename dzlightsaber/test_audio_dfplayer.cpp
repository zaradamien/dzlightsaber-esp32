// #include <SoftwareSerial.h>
// #include <DFMiniMp3.h>

// #define AUDIOPINTX 10
// #define AUDIOPINRX 11
// SoftwareSerial mySoftwareSerial(AUDIOPINTX,AUDIOPINRX); 
// // forward declare the notify class, just the name
// //
// class Mp3Notify; 

// typedef DFMiniMp3<SoftwareSerial, Mp3Notify> DfMp3;
//  DfMp3 dfmp3(mySoftwareSerial);

//  bool repeat = false;

// // implement a notification class,
// // its member methods will get called 
// //
// class Mp3Notify
// {
// public:
//   static void PrintlnSourceAction(DfMp3_PlaySources source, const char* action)
//   {
//     if (source & DfMp3_PlaySources_Sd) 
//     {
//         Serial.print("SD Card, ");
//     }
//     if (source & DfMp3_PlaySources_Usb) 
//     {
//         Serial.print("USB Disk, ");
//     }
//     if (source & DfMp3_PlaySources_Flash) 
//     {
//         Serial.print("Flash, ");
//     }
//     Serial.println(action);
//   }
//   static void OnError(DfMp3& mp3, uint16_t errorCode)
//   {
//     // see DfMp3_Error for code meaning
//     Serial.println();
//     Serial.print("Com Error ");
//     Serial.println(errorCode);
//   }
//   static void OnPlayFinished(DfMp3& mp3, DfMp3_PlaySources source, uint16_t track)
//   {
//     Serial.print("Play finished for #");
//     Serial.println(track);  
//     Serial.println(repeat); 

//     if (repeat == 1){ 
//       dfmp3.playGlobalTrack(track);
//     }
//     Serial.println("repeat");  
    
//   }
//   static void OnPlaySourceOnline(DfMp3& mp3, DfMp3_PlaySources source)
//   {
//     PrintlnSourceAction(source, "online");
//   }
//   static void OnPlaySourceInserted(DfMp3& mp3, DfMp3_PlaySources source)
//   {
//     PrintlnSourceAction(source, "inserted");
//   }
//   static void OnPlaySourceRemoved(DfMp3& mp3, DfMp3_PlaySources source)
//   {
//     PrintlnSourceAction(source, "removed");
//   }

//   // static void RepeatTrack([[maybe_unused]] DfMp3& mp3, [[maybe_unused]] DfMp3_PlaySources source, uint16_t track)
//   // {
//   //   Serial.print("Play finished for #");
//   //   Serial.println(track);  

//   //   // start next track
//   //   track += 1;
//   //   // this example will just start back over with 1 after track 3
//   //   if (track > 3) 
//   //   {
//   //     track = 1;
//   //   }
//   //   dfmp3.playMp3FolderTrack(track);  // sd:/mp3/0001.mp3, sd:/mp3/0002.mp3, sd:/mp3/0003.mp3
//   // }
// };

// void setup() 
// {
//   Serial.begin(115200);
//   Serial.println("initializing...");
//   dfmp3.begin();
//   uint16_t volume = dfmp3.getVolume();
//   Serial.print("volume ");
//   Serial.println(volume);
//   dfmp3.setVolume(12);
  
//   uint16_t count = dfmp3.getTotalTrackCount(DfMp3_PlaySource_Sd);
//   Serial.print("files ");
//   Serial.println(count);
  
//   Serial.println("starting...");
// }

// void waitMilliseconds(uint16_t msWait)
// {
//   uint32_t start = millis();
  
//   while ((millis() - start) < msWait)
//   {
//     dfmp3.loop(); 
//     delay(1);
//   }
// }

// // Folder : 01 default, 02 Vader, 03 Kylo, 04 Redux, 05 Godzilla, 06 Vader GEN 3
// // File : 001 menu, 002 out, 003 wait, 004 swing, 005 in, 006 strike, 006 hold


// void loop() 
// {
//   Serial.println("track 2/Folder 3"); 
//   dfmp3.playFolderTrack(2,3);
//   repeat = true;
 

  
//   waitMilliseconds(105000);
  
//   // Serial.println("track 2"); 
//   // dfmp3.playFolderTrack(1,2);
  
//   // waitMilliseconds(5000);
  
//   // Serial.println("track 3");
//   // dfmp3.playFolderTrack(1,3);
  
//   // waitMilliseconds(5000); 
// }
