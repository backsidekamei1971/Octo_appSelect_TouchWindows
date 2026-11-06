/*
 Name:		TouchTest.ino
 Created:	2019-12-25 12:52:14 AM
 Author:	Michael
*/

// the setup function runs once when you press reset or power the board

#include <Arduino.h>

#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Waveshare4InchTftShield.h>

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ORANGE  0xfc40
#define SILVER  0xBDF7

int j=0;
//int xxx=0;



namespace
{
    Waveshare4InchTftShield Waveshield;
}

void setup() 
{
    SPI.begin();
    Waveshield.begin();

    Waveshield.setRotation(1);
    Waveshield.setTextSize(2);
    //Waveshield.print("Let's Draw!");

    Waveshield.setRotation(0);

    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");

    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80,0,88,80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);

}

int i = 0;
int k = 0;
int missile = 0;
int app_select=0;
int posx=50;
int posy=50;
int dx=5;
int dy=5;
int slideYValue=80;

// the loop function runs over and over again until power down or reset
void loop()
{
    Waveshield.setRotation(0);
    //  Get raw touchscreen values.
    TSPoint p = Waveshield.getPoint();

    //  Remaps raw touchscreen values to screen co-ordinates.  Automatically handles
    //  rotation!
    Waveshield.normalizeTsPoint(p);



    //  Now that we have a point in screen co-ordinates, draw something there.
    //Waveshield.fillCircle(p.x, p.y, 3, BLUE);

    Waveshield.setRotation(0);

    if (p.x <= 80 && p.y <= 80 && p.x > 0 ) { //Clear button
      j=1;
      j=2;
    Waveshield.fillScreen(BLACK);
    app_select=0;

    Waveshield.setRotation(1);
    Waveshield.setTextSize(2);
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(WHITE);
    //Waveshield.print("Let's Draw!");

    Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);
    }

    if (p.x <= 80 && p.y <= 160 && p.x > 0 && p.y >= 80 && app_select !=5) {  ////MAGENTA(Pink) Invaders Gamen
    j=1;
    j=2;
    posx=50;
    posy=50;
      app_select=4;
    Waveshield.fillScreen(BLACK);

    Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);

    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);

    k=0;
    }

    if (app_select==4){
    if (p.x <= 380 && p.y <= 450 && p.x > 70 && p.y >= 290){
    k=k+8;
    if (k>=8*15){
      k=120;
    }
    }
    if (p.x <= 380 && p.y <= 270 && p.x > 70 && p.y >= 110){
    k=k-8;
    if (k<=-8*15){
      k=-120;
    }
    }

  posx=posx+dx;
  posy=posy+dy;

  if (posx>=115 or posx<=-100){  //Yoko limit
    dx=-dx;
  }

  //if (posy>=170 or posy<=40){  //Tate limit
  //  dy=-dy;
  //}

    Waveshield.fillRect(280, 220+k, 35, 100, MAGENTA);
    Waveshield.fillRect(255, 253+k, 25, 33, MAGENTA);

    Waveshield.fillRect(95, 190+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(95, 230+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(105, 200+posx, 10, 30, MAGENTA);
    Waveshield.fillRect(115, 190+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(115, 200+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 210+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(115, 220+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 230+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(125, 190+posx, 10, 50, MAGENTA);
    Waveshield.fillRect(145, 190+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(145, 230+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(135, 200+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(135, 220+posx, 10, 10, MAGENTA);

    Waveshield.fillRect(95, 250+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(95, 290+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(105, 260+posx, 10, 30, MAGENTA);
    Waveshield.fillRect(115, 250+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(115, 260+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 270+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(115, 280+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 290+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(125, 250+posx, 10, 50, MAGENTA);
    Waveshield.fillRect(145, 250+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(145, 290+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(135, 260+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(135, 280+posx, 10, 10, MAGENTA);

    Waveshield.fillRect(95, 310+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(95, 350+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(105, 320+posx, 10, 30, MAGENTA);
    Waveshield.fillRect(115, 310+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(115, 320+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 330+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(115, 340+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 350+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(125, 310+posx, 10, 50, MAGENTA);
    Waveshield.fillRect(145, 310+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(145, 350+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(135, 320+posx, 10, 10, MAGENTA);
    Waveshield.fillRect(135, 340+posx, 10, 10, MAGENTA);

    delay(150);

    Waveshield.fillRect(280, 220+k, 35, 100, BLACK);
    Waveshield.fillRect(255, 253+k, 25, 33, BLACK);

    Waveshield.fillRect(95, 190+posx, 10, 10, BLACK);
    Waveshield.fillRect(95, 230+posx, 10, 10, BLACK);
    Waveshield.fillRect(105, 200+posx, 10, 30, BLACK);
    Waveshield.fillRect(115, 190+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 200+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 210+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 220+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 230+posx, 10, 10, BLACK);
    Waveshield.fillRect(125, 190+posx, 10, 50, BLACK);
    Waveshield.fillRect(145, 190+posx, 10, 10, BLACK);
    Waveshield.fillRect(145, 230+posx, 10, 10, BLACK);
    Waveshield.fillRect(135, 200+posx, 10, 10, BLACK);
    Waveshield.fillRect(135, 220+posx, 10, 10, BLACK);

    Waveshield.fillRect(95, 250+posx, 10, 10, BLACK);
    Waveshield.fillRect(95, 290+posx, 10, 10, BLACK);
    Waveshield.fillRect(105, 260+posx, 10, 30, BLACK);
    Waveshield.fillRect(115, 250+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 260+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 270+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 280+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 290+posx, 10, 10, BLACK);
    Waveshield.fillRect(125, 250+posx, 10, 50, BLACK);
    Waveshield.fillRect(145, 250+posx, 10, 10, BLACK);
    Waveshield.fillRect(145, 290+posx, 10, 10, BLACK);
    Waveshield.fillRect(135, 260+posx, 10, 10, BLACK);
    Waveshield.fillRect(135, 280+posx, 10, 10, BLACK);

    Waveshield.fillRect(95, 310+posx, 10, 10, BLACK);
    Waveshield.fillRect(95, 350+posx, 10, 10, BLACK);
    Waveshield.fillRect(105, 320+posx, 10, 30, BLACK);
    Waveshield.fillRect(115, 310+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 320+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 330+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 340+posx, 10, 10, BLACK);
    Waveshield.fillRect(115, 350+posx, 10, 10, BLACK);
    Waveshield.fillRect(125, 310+posx, 10, 50, BLACK);
    Waveshield.fillRect(145, 310+posx, 10, 10, BLACK);
    Waveshield.fillRect(145, 350+posx, 10, 10, BLACK);
    Waveshield.fillRect(135, 320+posx, 10, 10, BLACK);
    Waveshield.fillRect(135, 340+posx, 10, 10, BLACK);



        }


    

    if (p.x <= 80 && p.y <= 240 && p.x > 0 && p.y >= 160 && app_select !=5) {   ////Green Invaders Gamen
    j=1;
    j=2;
      app_select=3;
    Waveshield.fillScreen(BLACK);

        Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);

    Waveshield.fillRect(0, 160, 80, 80, GREEN);

    Waveshield.fillRect(120, 190, 10, 10, GREEN);
    Waveshield.fillRect(120, 230, 10, 10, GREEN);
    Waveshield.fillRect(130, 200, 10, 30, GREEN);
    Waveshield.fillRect(140, 190, 10, 10, GREEN);
    Waveshield.fillRect(140, 200, 10, 10, BLACK);
    Waveshield.fillRect(140, 210, 10, 10, GREEN);
    Waveshield.fillRect(140, 220, 10, 10, BLACK);
    Waveshield.fillRect(140, 230, 10, 10, GREEN);
    Waveshield.fillRect(150, 190, 10, 50, GREEN);
    Waveshield.fillRect(170, 190, 10, 10, GREEN);
    Waveshield.fillRect(170, 230, 10, 10, GREEN);
    Waveshield.fillRect(160, 200, 10, 10, GREEN);
    Waveshield.fillRect(160, 220, 10, 10, GREEN);

    Waveshield.fillRect(120, 250, 10, 10, GREEN);
    Waveshield.fillRect(120, 290, 10, 10, GREEN);
    Waveshield.fillRect(130, 260, 10, 30, GREEN);
    Waveshield.fillRect(140, 250, 10, 10, GREEN);
    Waveshield.fillRect(140, 260, 10, 10, BLACK);
    Waveshield.fillRect(140, 270, 10, 10, GREEN);
    Waveshield.fillRect(140, 280, 10, 10, BLACK);
    Waveshield.fillRect(140, 290, 10, 10, GREEN);
    Waveshield.fillRect(150, 250, 10, 50, GREEN);
    Waveshield.fillRect(170, 250, 10, 10, GREEN);
    Waveshield.fillRect(170, 290, 10, 10, GREEN);
    Waveshield.fillRect(160, 260, 10, 10, GREEN);
    Waveshield.fillRect(160, 280, 10, 10, GREEN);

    Waveshield.fillRect(120, 310, 10, 10, GREEN);
    Waveshield.fillRect(120, 350, 10, 10, GREEN);
    Waveshield.fillRect(130, 320, 10, 30, GREEN);
    Waveshield.fillRect(140, 310, 10, 10, GREEN);
    Waveshield.fillRect(140, 320, 10, 10, BLACK);
    Waveshield.fillRect(140, 330, 10, 10, GREEN);
    Waveshield.fillRect(140, 340, 10, 10, BLACK);
    Waveshield.fillRect(140, 350, 10, 10, GREEN);
    Waveshield.fillRect(150, 310, 10, 50, GREEN);
    Waveshield.fillRect(170, 310, 10, 10, GREEN);
    Waveshield.fillRect(170, 350, 10, 10, GREEN);
    Waveshield.fillRect(160, 320, 10, 10, GREEN);
    Waveshield.fillRect(160, 340, 10, 10, GREEN);
    }

    if (app_select == 3){
    missile = missile - 1;
    Waveshield.fillRect(220 + missile, 265, 30, 10, GREEN);
    delay(20);
    Waveshield.fillRect(220 + missile, 265, 30, 10, BLACK);

    Waveshield.fillRect(280, 220, 35, 100, GREEN);
    Waveshield.fillRect(255, 253, 25, 33, GREEN);
    //Waveshield.setCursor(10, 350);
    //Waveshield.print(missile);

    if (missile <= -50){
      missile = 0;

    Waveshield.fillRect(120, 250, 10, 10, BLACK);
    Waveshield.fillRect(120, 290, 10, 10, BLACK);
    Waveshield.fillRect(130, 260, 10, 30, BLACK);
    Waveshield.fillRect(140, 250, 10, 10, BLACK);
    Waveshield.fillRect(140, 260, 10, 10, BLACK);
    Waveshield.fillRect(140, 270, 10, 10, BLACK);
    Waveshield.fillRect(140, 280, 10, 10, BLACK);
    Waveshield.fillRect(140, 290, 10, 10, BLACK);
    Waveshield.fillRect(150, 250, 10, 50, BLACK);
    Waveshield.fillRect(170, 250, 10, 10, BLACK);
    Waveshield.fillRect(170, 290, 10, 10, BLACK);
    Waveshield.fillRect(160, 260, 10, 10, BLACK);
    Waveshield.fillRect(160, 280, 10, 10, BLACK);
    delay(200);
    Waveshield.fillRect(120, 250, 10, 10, GREEN);
    Waveshield.fillRect(120, 290, 10, 10, GREEN);
    Waveshield.fillRect(130, 260, 10, 30, GREEN);
    Waveshield.fillRect(140, 250, 10, 10, GREEN);
    Waveshield.fillRect(140, 260, 10, 10, BLACK);
    Waveshield.fillRect(140, 270, 10, 10, GREEN);
    Waveshield.fillRect(140, 280, 10, 10, BLACK);
    Waveshield.fillRect(140, 290, 10, 10, GREEN);
    Waveshield.fillRect(150, 250, 10, 50, GREEN);
    Waveshield.fillRect(170, 250, 10, 10, GREEN);
    Waveshield.fillRect(170, 290, 10, 10, GREEN);
    Waveshield.fillRect(160, 260, 10, 10, GREEN);
    Waveshield.fillRect(160, 280, 10, 10, GREEN);

    }

    }

    if (p.x <= 160 && p.y <= 80 && p.x > 80 && p.y >= 0 ) {   ///Si is wonderful original Gamen
   // Waveshield.fillRect(80, 0, 80, 80, WHITE);
   //Waveshield.fillCircle(200, 200, 40, WHITE);
   // Waveshield.fillCircle(200, 400, 40, WHITE);
    
    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);

   j=0;
   app_select=1;
    Waveshield.fillRect(100, 100, 400, 400, WHITE);
    Waveshield.setRotation(1);
    Waveshield.fillRect(60, 230, 100, 50, CYAN);

    Waveshield.setCursor(50, 150);
    Waveshield.setTextColor(BLACK);
    Waveshield.setTextSize(3);
    Waveshield.print("Si is Wonderful!");

    Waveshield.setTextSize(2);
    Waveshield.setCursor(100, 250);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("OK");
    Waveshield.setCursor(200, 250);
    Waveshield.fillRect(185, 230, 100, 50, CYAN);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("Cancel");
    }
    if (app_select==1){
    if (p.x <= 295 && p.y <= 300 && p.x > 235 && p.y >= 200){  ///Si Wonderful Select menu gamen
        
        Waveshield.setRotation(1);



        if(j==2){

      Waveshield.setCursor(70, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.setTextSize(3);
      Waveshield.print("Sustainable!");
        }

      
      Waveshield.setTextSize(3);
      Waveshield.setCursor(50, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.print("Si is Wonderful!");
      Waveshield.setCursor(30, 150);
      Waveshield.setTextColor(BLACK);
      Waveshield.print("Let`s Start WWIII !");
      j=1;

    }
    }
    if (app_select==1){
      if (p.x <= 295 && p.y <= 450 && p.x > 235 && p.y >= 350){  ///Si Wonderful Select menu gamen
     Waveshield.setRotation(1);


        if(j==1){
      Waveshield.setCursor(30, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.setTextSize(3);
      Waveshield.print("Let`s Start WWIII !");    
        }

      
      Waveshield.setTextSize(3);
      Waveshield.setCursor(50, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.print("Si is Wonderful!");
      Waveshield.setCursor(70, 150);
      Waveshield.setTextColor(BLACK);
      Waveshield.print("Sustainable!");
      j=2;
      }
    }
    

      Waveshield.setRotation(0);
    if (p.x <= 240 && p.y <= 80 && p.x > 160 && p.y >= 0 ) {  ////Block Kuzushi Gamen
    j=1;
    j=2;
    posx=50;
    posy=50;

     app_select=2;
    Waveshield.fillScreen(BLACK);

    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 
    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);

    Waveshield.fillRect(90, 370, 20, 80, RED);
    Waveshield.fillRect(90, 280, 20, 80, MAGENTA);
    Waveshield.fillRect(90, 190, 20, 80, YELLOW);
    Waveshield.fillRect(90, 100, 20, 80, GREEN);

    Waveshield.fillRect(120, 370, 20, 80, RED);
    Waveshield.fillRect(120, 280, 20, 80, MAGENTA);
    Waveshield.fillRect(120, 190, 20, 80, YELLOW);
    Waveshield.fillRect(120, 100, 20, 80, GREEN);

    Waveshield.fillRect(150, 370, 20, 80, RED);
    Waveshield.fillRect(150, 280, 20, 80, MAGENTA);
    Waveshield.fillRect(150, 190, 20, 80, YELLOW);
    Waveshield.fillRect(150, 100, 20, 80, GREEN);

    //Waveshield.fillCircle(190, 230, 9, WHITE);
    k=0;
    }
    if (app_select==2){

  Waveshield.drawLine(170, 100, 170, 450, WHITE);   //upper Yoko Line
  Waveshield.drawLine(170, 100, 310, 100, WHITE);   //right Tate Line
  Waveshield.drawLine(170, 450, 310, 450, WHITE);   //left Tate Line
  Waveshield.drawLine(310, 100, 310, 450, WHITE);   //lower Yoko Line

    if (p.x <= 380 && p.y <= 470 && p.x > 70 && p.y >= 290){
    k=k+24;
    if (k >= 24*2){
      k=40;
    }
    }
    if (p.x <= 380 && p.y <= 270 && p.x > 70 && p.y >= 110){
    k=k-24;
    if (k <= -24*9){
      k=-224;
    }
    }

    Waveshield.fillRect(280, 330+k, 20, 80, WHITE);
    delay(150);
    Waveshield.fillRect(280, 330+k, 20, 80, BLACK);

  Waveshield.fillRect(130+posy, 105+posx, 10, 10, WHITE);
  delay(150);
  Waveshield.fillRect(130+posy, 105+posx, 10, 10, BLACK);
  
  posx=posx+dx;
  posy=posy+dy;

  if (posx>=330 or posx<=0){  //Yoko limit
    dx=-dx;
  }

  if (posy>=170 or posy<=40){  //Tate limit
    dy=-dy;
  }


    }
    

  if (p.x <= 320 && p.y <= 80 && p.x > 240 && p.y >= 0 ){  //touch calculator gamen
   j=1;
   j=2;

    app_select=5;


    Waveshield.fillScreen(BLACK);

            Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    //Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    //Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);

    Waveshield.drawRect(0,150,60,240, MAGENTA);

    Waveshield.fillRect(80,160,60,60, WHITE);
    Waveshield.setCursor(280,90);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("3");
    Waveshield.setRotation(0);

    Waveshield.fillRect(80,240,60,60, WHITE);
    Waveshield.setCursor(200,90);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("2");
    Waveshield.setRotation(0);

    Waveshield.fillRect(80,320,60,60, WHITE);
    Waveshield.setCursor(120,90);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("1");
    Waveshield.setRotation(0);

    Waveshield.fillRect(160,160,60,60, WHITE);
    Waveshield.setCursor(280,170);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("6");
    Waveshield.setRotation(0);

    Waveshield.fillRect(160,240,60,60, WHITE);
    Waveshield.setCursor(200,170);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("5");
    Waveshield.setRotation(0);

    Waveshield.fillRect(160,320,60,60, WHITE);
    Waveshield.setCursor(120,170);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("4");
    Waveshield.setRotation(0);

    Waveshield.fillRect(240,160,60,60, WHITE);
    Waveshield.setCursor(280,250);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("9");
    Waveshield.setRotation(0);


    Waveshield.fillRect(240,240,60,60, WHITE);
    Waveshield.setCursor(200,250);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("8");
    Waveshield.setRotation(0);

    Waveshield.fillRect(240,320,60,60, WHITE);
    Waveshield.setCursor(120,250);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("7");
  }
   
   if (app_select==5){
    if (p.x <= 140 && p.y <= 400 && p.x > 80 && p.y > 340) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("1");
   }

   if (p.x <= 140 && p.y <= 320 && p.x > 80 && p.y > 260) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("2");
   }

    if (p.x <= 140 && p.y <= 220 && p.x > 80 && p.y > 160) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("3");
   }

    if (p.x <= 240 && p.y <= 380 && p.x > 180 && p.y > 320) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("4");
   }

    if (p.x <= 240 && p.y <= 300 && p.x > 180 && p.y > 240) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("5");
   }

    if (p.x <= 240 && p.y <= 220 && p.x > 180 && p.y > 160) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("6");
   }

    if (p.x <= 320 && p.y <= 360 && p.x > 260 && p.y > 300) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("7");
   }

    if (p.x <= 320 && p.y <= 300 && p.x > 260 && p.y > 240) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("8");
   }

    if (p.x <= 320 && p.y <= 220 && p.x > 260 && p.y > 160) {    //80,320,60,60
    //Waveshield.fillScreen(BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.fillRect(0,150,60,240, BLACK);
    Waveshield.drawRect(0,150,60,250, MAGENTA);
    Waveshield.setRotation(1);
    Waveshield.setTextSize(5);
    Waveshield.setCursor(200,8);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("9");
    }
   
   
  }

  if (p.x <= 80 && p.y <= 320 && p.x > 0 && p.y >= 240 && app_select !=5){  //Pong

  Waveshield.fillScreen(BLACK);
    posx=50;
    posy=50;
  app_select=6;
  Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);
  }

  if (app_select==6){

  Waveshield.drawLine(140, 127, 140, 465, WHITE);   //upper Yoko Line
  Waveshield.drawLine(140, 127, 290, 127, WHITE);   //right Tate Line
  Waveshield.drawLine(140, 465, 290, 465, WHITE);   //left Tate Line
  Waveshield.drawLine(290, 127, 290, 465, WHITE);   //lower Yoko Line

  Waveshield.fillRect(100+posy, 130+posx, 10, 10, WHITE);
  delay(100);
  Waveshield.fillRect(100+posy, 130+posx, 10, 10, BLACK);
  
  posx=posx+dx;
  posy=posy+dy;

  if (posx>=320 or posx<=0){  //Tate limit
    dx=-dx;
  }

  if (posy>=180 or posy<=40){  //Tate limit
    dy=-dy;
  }
  
  

  }

  if (p.x <= 80 && p.y <= 400 && p.x > 0 && p.y >= 320 && app_select !=5){  //Logikara
  Waveshield.fillScreen(BLACK);
  app_select=7;
  Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);

  
  Waveshield.setRotation(1);
  Waveshield.drawFastHLine(0, 118, 260, WHITE);  // 線（指定座標から平行線）
  Waveshield.drawFastHLine(0, 119, 260, WHITE);  // 線（指定座標から平行線）
  Waveshield.drawFastVLine(120, 124, 43, WHITE);  // 線（指定座標から垂線）
  Waveshield.drawFastVLine(121, 124, 43, WHITE);  // 線（指定座標から垂線）
  Waveshield.drawFastHLine(0, 170, 260, WHITE);  // 線（指定座標から平行線）
  Waveshield.drawFastHLine(0, 171, 260, WHITE);  // 線（指定座標から平行線）
  Waveshield.drawFastHLine(0, 215, 260, WHITE); // 線（指定座標から平行線）
  Waveshield.drawFastHLine(0, 216, 260, WHITE); // 線（指定座標から平行線）

  Waveshield.setTextSize(2);
  Waveshield.setCursor(28,125);
  Waveshield.setTextColor(GREEN);
  Waveshield.print("LCD"); // 文字表示関数呼び出し
  Waveshield.setCursor(25,145);
  Waveshield.print("Touch");
  Waveshield.setCursor(135,150);
  Waveshield.setTextColor(WHITE);
  Waveshield.setTextSize(2);
  Waveshield.print("ILI9341");
  Waveshield.setCursor(45,195);
  Waveshield.setTextColor(YELLOW);
  Waveshield.setTextSize(2);
  Waveshield.print("LogikaraBlog");

  Waveshield.fillCircle(40, 270, 40, WHITE); // 外枠
  Waveshield.fillCircle(40, 270, 36, BLUE);    // 境界線

  Waveshield.fillRect(265, 118, 55, 200, WHITE); // スライドエリア
  Waveshield.fillRect(287, 128, 11, 182, BLUE);    // 縦ライン枠
  Waveshield.fillRect(290, 132, 5, 175, BLACK);     // 縦ライン
  Waveshield.fillRect(270, slideYValue+80, 45, 20, BLUE);   // ボリュームつまみ
  Waveshield.fillRect(278, slideYValue + 88, 29, 3, WHITE);  // ボリュームつまみライン

  Waveshield.fillRect(85, 225, 85, 85, WHITE); // ONボタン
  Waveshield.fillRect(90, 230, 75, 75, GREEN); // ONボタン
  Waveshield.setCursor(105,255);
  Waveshield.setTextSize(4);
  Waveshield.setTextColor(WHITE);
  Waveshield.print("ON");

  Waveshield.fillRect(175, 225, 85, 85, WHITE); // OFFボタン
  Waveshield.fillRect(180, 230, 75, 75, RED); //OFFボタン
  Waveshield.setCursor(183,255);
  Waveshield.setTextSize(4);
  Waveshield.setTextColor(WHITE);
  Waveshield.print("OFF");

  }
  if (app_select==7){
        Waveshield.setRotation(1);
    //  Get raw touchscreen values.
    TSPoint p = Waveshield.getPoint();

    //  Remaps raw touchscreen values to screen co-ordinates.  Automatically handles
    //  rotation!
    Waveshield.normalizeTsPoint(p);
    
    Waveshield.setRotation(1);
    Waveshield.fillRect(270, slideYValue+80, 45, 20, BLUE);   // ボリュームつまみ
    Waveshield.fillRect(278, slideYValue + 88, 29, 3, WHITE);  // ボリュームつまみライン
    
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(WHITE);
    Waveshield.setCursor(0,100);
    Waveshield.print("x=");
    Waveshield.print(p.x);
    Waveshield.setCursor(100,100);
    Waveshield.print("y=");
    Waveshield.print(p.y);

    Waveshield.setTextSize(2);
    Waveshield.setTextColor(WHITE);
    Waveshield.setCursor(280,100);
    Waveshield.print(slideYValue);

    delay(100);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.setCursor(0,100);
    Waveshield.print("x=");
    Waveshield.print(p.x);
    Waveshield.setCursor(100,100);
    Waveshield.print("y=");
    Waveshield.print(p.y);

    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.setCursor(280,100);
    Waveshield.print(slideYValue);
  
    Waveshield.setRotation(1);
   if (p.x <= 165 && p.y <= 305 && p.x > 90 && p.y >= 230) {  //ON press
    Waveshield.fillCircle(40, 270, 40, WHITE); // 外枠
    Waveshield.fillCircle(40, 270, 36, BLUE);    // 境界線
   }

   if (p.x <= 255 && p.y <= 305 && p.x > 180 && p.y >= 230) {  //OFF press
    Waveshield.fillCircle(40, 270, 40, WHITE); // 外枠
    Waveshield.fillCircle(40, 270, 36, YELLOW);    // 境界線
   }
   if (p.x <= 310 && p.y <= 300 && p.x > 270 && p.y >= 118) {
    slideYValue=p.y-80;
     Waveshield.fillRect(270, slideYValue+80, 45, 20, BLUE);   // ボリュームつまみ
     Waveshield.fillRect(278, slideYValue + 88, 29, 3, WHITE);  // ボリュームつまみライン
     delay(10);
     Waveshield.fillRect(265, 118, 55, 200, WHITE); // スライドエリア
     Waveshield.fillRect(287, 128, 11, 182, BLUE);    // 縦ライン枠
     Waveshield.fillRect(290, 132, 5, 175, BLACK);     // 縦ライン

  }
  }
	  if (p.x <= 80 && p.y <= 480 && p.x > 0 && p.y >= 400 && app_select !=5){  //Logikara
  Waveshield.fillScreen(BLACK);
  app_select=8;
  Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    Waveshield.fillRect(240, 0, 80, 80, CYAN);
    Waveshield.fillRect(0, 240, 80, 80, RED);
    Waveshield.fillRect(0, 320, 80, 80, SILVER);
		Waveshield.fillRect(0, 400, 80, 80, ORANGE);
		}
		if (app_select==8){

		Waveshield.setRotation(1);
    //  Get raw touchscreen values.
    TSPoint p = Waveshield.getPoint();

    //  Remaps raw touchscreen values to screen co-ordinates.  Automatically handles
    //  rotation!
    Waveshield.normalizeTsPoint(p);
		Waveshield.drawCircle(p.x, p.y, 5, WHITE);

		}

}

    
