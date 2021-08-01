#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <flappy.h>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

double queuedMilliseconds,prev0,fps,responseTime;
int resX,resY,movementX,startFlag;
double movementY;

//... Reshaping settings & rendering parameters.
void reshape(int w, int h)
{
   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glOrtho(0,resX,0,resY,-5,10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

//....  Keyboard input and movement physics
vector<char> inputKey; 
double g,v,tmp2;
int cnt;

void gameoverAnimation()
{
	inputKey.push_back('U');
	v=1.2;
	
}

void movePhysics()
{
unsigned int ii;
g=9.81;
for(ii=0;ii<inputKey.size();ii++)	
	{

		if(inputKey[ii]=='U')
			{
				if((movementY+(resY/2)+50)<resY)
				movementY+=4;
				cnt++;
			}	
		if(cnt>=10)
			{	
				cnt=0;	
				inputKey.erase(inputKey.begin()+ii);
			}		
		
	}
if(startFlag==1)
{ 

//...GRAVITY
if(inputKey.size()==0)
{
// 0.021125
if(gameover==0)
{	
tmp2=resY/2;
v=0.65+(abs(movementY)/tmp2)/5;
}
else
{

	if( (inputKey.size()==0 ) && (movementY <- (resY/2) ) )
	{	
		gameover=0;
		resetFunc();
	}
}
	movementY-= v*v/2*g;	

}

}

}

void keyboard (unsigned char key, int x, int y)
{
  if(key==32)
  	startFlag=1;

   switch (key) {
      case 27:
         exit(0);
         break;
 	  case 32:
 	  	if(gameover==0)	
		inputKey.push_back('U');
		break;			
   }

}

//... keyboard input end.

int main(int argc, char** argv)
{
   //..frame-update setup
   queuedMilliseconds=0;
   prev0=0;
   fps=60;
   responseTime=(1/fps)*1000;

//... Rendering resoultion
   resX=854;resY=480;

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutGameModeString("1920x1080");
   if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
    glutEnterGameMode();
   glutIgnoreKeyRepeat(1);
   glutDisplayFunc(draw); 
   glutIdleFunc(mixedStepLoop); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0; 
}
