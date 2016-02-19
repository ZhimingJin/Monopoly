#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(Controller *c, char *players, int totalP): c(c),blockLen(6),blockWid(9){
   board=new string *[11];

   for(int i=0; i<totalP; i++){
      playerPos[players[i]]=0;
   }
//initialize board   
   for(int i=0;i<11;i++){
      if(i==0) board[0]=new string[blockLen];
      else board[i]=new string[blockLen-1];
   }
  board[0][0]="_________________________________________________________________________________________";
  board[0][1]="|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
  board[0][2]="|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
  board[0][3]="|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
  board[0][4]="|       |       |       |       |       |       |       |       |       |       |       |";
  board[0][5]="|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
  board[1][0]="|       |                                                                       |       |";
  board[1][1]="|-------|                                                                       |-------|";
  board[1][2]="|OPT    |                                                                       |EIT    |";
  board[1][3]="|       |                                                                       |       |";
  board[1][4]="|_______|                                                                       |_______|";
  board[2][0]="|       |                                                                       |       |";
  board[2][1]="|-------|                                                                       |-------|";
  board[2][2]="|BMH    |                                                                       |ESC    |";
  board[2][3]="|       |                                                                       |       |";
  board[2][4]="|_______|                                                                       |_______|";
  board[3][0]="|SLC    |                                                                       |SLC    |";
  board[3][1]="|       |                                                                       |       |";
  board[3][2]="|       |                                                                       |       |";
  board[3][3]="|       |                                                                       |       |";
  board[3][4]="|_______|                                                                       |_______|";
  board[4][0]="|       |                                                                       |       |";
  board[4][1]="|-------|                                                                       |-------|";
  board[4][2]="|LHI    |                                                                       |C2     |";
  board[4][3]="|       |              ________________________________________                 |       |";
  board[4][4]="|_______|              |                                       |                |_______|";
  board[5][0]="|UWP    |              |  ###   ###   #####   ###   ###   ###  |                |REV    |";
  board[5][1]="|       |              |  #  #  #  #     #   #   # #   # #   # |                |       |";
  board[5][2]="|       |              |  ####  ####    #    #   # #   # #   # |                |       |";
  board[5][3]="|       |              |  #   # #   #  #     #   # #   # #   # |                |       |";
  board[5][4]="|_______|              |  ####  ####  #       ###   ###   ###  |                |_______|";
  board[6][0]="|       |              |                                       |                |NEEDLES|";
  board[6][1]="|-------|              |_______________________________________|                |HALL   |";
  board[6][2]="|CPH    |                                                                       |       |";
  board[6][3]="|       |                                                                       |       |";
  board[6][4]="|_______|                                                                       |_______|";
  board[7][0]="|       |                                                                       |       |";
  board[7][1]="|-------|                                                                       |-------|";
  board[7][2]="|DWE    |                                                                       |MC     |";
  board[7][3]="|       |                                                                       |       |";
  board[7][4]="|_______|                                                                       |_______|";
  board[8][0]="|PAC    |                                                                       |COOP   |";
  board[8][1]="|       |                                                                       |FEE    |";
  board[8][2]="|       |                                                                       |       |";
  board[8][3]="|       |                                                                       |       |";
  board[8][4]="|_______|                                                                       |_______|";
  board[9][0]="|       |                                                                       |       |";
  board[9][1]="|-------|                                                                       |-------|";
  board[9][2]="|RCH    |                                                                       |DC     |";
  board[9][3]="|       |                                                                       |       |";
  board[9][4]="|_______|_______________________________________________________________________|_______|";
 board[10][0]="|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
 board[10][1]="|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
 board[10][2]="|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
 board[10][3]="|       |       |       |       |       |       |       |       |       |       |       |";
 board[10][4]="|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";

}


/*string operator*(string s, int scaler){//internal helper function, scaler>=1;
   string output="";
   for(int i=1; i<=scaler;i++){
      output=output+s;
   }
   return output;
}*/

TextDisplay::~TextDisplay(){
   for(int i=0; i<11;i++){
      delete [] board[i];
   }
   delete [] board;
}

bool TextDisplay::put(char oldvalue,char newvalue, int currentP, int block, int col){
   bool succeed=false;
   for(int i=1; i<8;i++){
       if(board[block][col][(10-currentP)*8+i]==oldvalue){
          board[block][col][(10-currentP)*8+i]=newvalue;
          succeed=true;
          break;
       }
   }
   return succeed;
}

void TextDisplay::notified(char c, int move){
    int previousP=playerPos[c];   
    bool succeed;
    if(previousP<=10){
       succeed=put(c,' ',previousP,10,3);
       if(!succeed){
         put(c,'_',previousP,10,4);
       }
    }else if(previousP<20){
       succeed=put(c,' ',10,20-previousP,3);
       if(!succeed){
         put(c,'_',previousP,20-previousP,4);
       }
    }else if(previousP<=30){
       succeed=put(c,' ',30-previousP,0,4);
       if(!succeed){
         put(c,'_',30-previousP,0,5);
       }
    }else if(previousP<=40){
       succeed=put(c,' ',0,previousP-30,3);
       if(!succeed){
         put(c,'_',0,previousP-30,4);
       }
    }
    int currentP=0;
    if(move!=-100) currentP=previousP+move;
    else currentP=10;
    if(currentP>39) currentP=currentP-40;
    if(currentP<=10){
       succeed=put(' ',c,currentP,10,3);
       if(!succeed){
         put('_',c,currentP,10,4);
       }
    }else if(currentP<20){
       succeed=put(' ',c,10,20-currentP,3);
       if(!succeed){
         put('_',c,currentP,20-currentP,4);
       }
    }else if(currentP<=30){
       succeed=put(' ',c,30-currentP,0,4);
       if(!succeed){
         put('_',c,30-currentP,0,5);
       }
    }else if(currentP<=40){
       succeed=put(' ',c,0,currentP-30,3);
       if(!succeed){
         put('_',c,0,currentP-30,4);
       }
    }
    playerPos[c]=currentP;
}

void TextDisplay::printBoard(ostream &out){
   for(int j=0;j<6;j++){
         out<<board[0][j]<<endl;
      }

   for(int i=1; i<11;i++){
      for(int j=0;j<5;j++){
         out<<board[i][j]<<endl;
      }
    }
} 

void TextDisplay::printImprove(ostream &out, int building,string action){
 if(action=="improve"){
   if(building<=10){
       put('-','I',building,10,1);
    }else if(building<20){
       put('-','I',10,20-building,1);
    }else if(building<=30){
       put('-','I',30-building,0,2);
    }else if(building<=40){
       put('-','I',0,building-30,1);
    }
 }else if(action=="sell"){
    if(building<=10){
       put('I','-',building,10,1);
    }else if(building<20){
       put('I','-',10,20-building,1);
    }else if(building<=30){
       put('I','-',30-building,0,2);
    }else if(building<=40){
       put('I','-',0,building-30,1);
    }
 }
}

void TextDisplay::removePlayer(char c){
  bool succeed;
    int pos=playerPos[c];
   if(pos<=10){
       succeed=put(c,' ',pos,10,3);
       if(!succeed){
         put(c,'_',pos,10,4);
       }
    }else if(pos<20){
       succeed=put(c,' ',10,20-pos,3);
       if(!succeed){
         put(c,'_',pos,20-pos,4);
       }
    }else if(pos<=30){
       succeed=put(c,' ',30-pos,0,4);
       if(!succeed){
         put(c,'_',30-pos,0,5);
       }
    }else if(pos<=40){
       succeed=put(c,' ',0,pos-30,3);
       if(!succeed){
         put(c,'_',0,pos-30,4);
       }
    }
}

