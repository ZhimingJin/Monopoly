#include "controller.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]){
	Controller c;
	bool testing=false;
	bool load=false;
        string testingP="-testing";
        string loadP="-load";//added two strings in order to use compare() in stead of strcmp()
	string file;
	for(int i=1; i<argc; i++){
		if(testingP.compare(argv[i])==0){
			testing=true;
		}else if(loadP.compare(argv[i])==0){
			if(i!=argc-1){
				load=true;
				file=argv[i+1];
			}			
		}
	}
			
	if(testing&&load){;
		c.play(file,"-testing");
	}else if(testing){
		c.play("","-testing");
	}else if(load){
		c.play(file,"normal");
	}else{
		c.play("","normal");
	}
	exit(0);
}
