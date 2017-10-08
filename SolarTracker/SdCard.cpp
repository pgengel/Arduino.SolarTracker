#include "SdCard.h"

SdCard::SdCard()
{
}

SdCard::~SdCard()
{
}

void SdCard::Init()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
     // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

int SdCard::GetAngle(char fileName[], DateTime now)
{
  int angle;
  // re-open the file for reading:
  myFile = SD.open(fileName);
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      fileContents[index++] = myFile.parseInt();
      fileContents[index] = '\0'; // NULL terminate the array
      Serial.write(fileContents);
    }
    // close the file:
    myFile.close();
  }
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  // close the file:
  myFile.close();

  for (size_t i = 0; i < 128; i++)
  {
    if (fileContents[i] == now.hour())
    {
      angle = fileContents[i++];
    }
  }

  return 1;
}

void SdCard::Write(char fileName[])
{
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(fileName, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  }
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  // close the file:
  myFile.close();
}

void SdCard::FindAngle(int time)
{

}
