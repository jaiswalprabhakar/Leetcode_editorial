#include <bits/stdc++.h>
#define CellCount 20
#define VoltageTXSize ((CellCount*3)+12)
#define VoltageCode 0x1111
#define  ASCIICOMA ','
#define ASCIISEMI ';'
#define CRCdata 0xFFFF

#define lowByte(x) (x & 0x00ff)
#define highByte(x) ((x & 0xff00)>>8)

uint16_t CellVoltage[CellCount];

using namespace std;

typedef union
{
  struct
  {
    uint8_t byt[2];
  }_8bit;
    uint16_t Data16;
}QFByteConvert;

QFByteConvert FunctionCodeTx;

typedef union
{
  struct
  {
    uint16_t FunctionCode;
    uint8_t StartSeperator;
    uint8_t ModuleLetter;
    uint8_t ModeulNumber;
    uint8_t LetterC;
    uint8_t CellCnt;
    uint8_t DataSeperator; 
    uint8_t data[CellCount*3];
    uint8_t CRCSeperator; 
    uint16_t CRC;
    uint8_t StringEnd;
  }_16bit;
  struct
  {
    uint8_t FunctionCodeLo;
    uint8_t FunctionCodeHo;
    uint8_t StartSeperator;
    uint8_t ModuleLetter;
    uint8_t ModeulNumber;
    uint8_t LetterC;
    uint8_t CellCnt;
    uint8_t DataSeperator; 
    uint8_t data[CellCount*3];
    uint8_t CRCSeperator; 
    uint8_t CRCLo;
    uint8_t CRCHo;
    uint8_t StringEnd; 
  }_8bit;
  uint8_t BoostVoltageTx[VoltageTXSize];
}QFappTxVoltageTypedef;

void sendVoltageData(uint16_t *Voltages,uint8_t ModuleNum,uint8_t CellCnt)
{
  QFappTxVoltageTypedef  VoltageData;
  uint8_t *pPointer = &VoltageData._8bit. data[0];
  VoltageData._16bit.FunctionCode = VoltageCode;
  VoltageData._16bit.CRC =CRCdata;
  VoltageData._16bit.StartSeperator = ASCIICOMA;
  VoltageData._16bit.ModuleLetter = 'M';
  VoltageData._16bit.ModeulNumber =  ModuleNum;
  VoltageData._16bit.LetterC = 'C';
  VoltageData._16bit.CellCnt =CellCnt;
  VoltageData._16bit.DataSeperator = ',';
  VoltageData._16bit.CRCSeperator = ',';
  VoltageData._16bit.StringEnd = ';';

  for(uint8_t i=1; i<=CellCount;i++)
  {
    *pPointer = i;
    *(pPointer +1) = lowByte(Voltages[i-1]);
    *(pPointer +2) = highByte(Voltages[i-1]);
    pPointer  = pPointer +3;
    cout<<VoltageData.BoostVoltageTx[i];
  }
  // Replace this comment with UART DMA SIZE  CellCount*3+12
    

   
  //Serial.write(VoltageData.BoostVoltageTx, CellCount*3+12);
}

int main(){
    float randNumber;
    for(char i= 0; i < CellCount ; i++)
    {
       randNumber = rand(); //generating random voltage between 2100 and 3000
        CellVoltage[i] = randNumber;    //3000+ i; 
    }
    sendVoltageData(CellVoltage, 0x02, CellCount);
    return 0;
}