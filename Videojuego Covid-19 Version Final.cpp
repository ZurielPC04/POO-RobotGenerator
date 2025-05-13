#include <stdio.h>
#include <conio.h>
#include <winbgim.h>
#include <dos.h>
#define GREEN 2
#define WHITE 2
#define WHITEE 7
#define LIGHTGREEN 10
#define LIGHTMAGENTA 13
#define YELLOW 6
#define LIGHTBLUE 9

int Portada(){

    delay(250);
    settextstyle(GOTHIC_FONT,0,2);
    setcolor(3);
    outtextxy(125,120, "C O V I D   V I D E O G A M E");
    delay(120);
    setcolor(15);
    outtextxy(50,160, "R E A L I Z A D O  P O R: ");
    delay(120);
    setcolor(15);
    outtextxy(150,200, "P A L A F O X");
    delay(120);
    outtextxy(150,240, "C U A P I O");
    delay(120);
    outtextxy(150,280,"I S A I");
    delay(120);
    outtextxy(150,320,"Z U R I E L");
    delay(1000);
    getch();

}

int x, y, seve=0;

void died(){

    setcolor(2);
    settextstyle(1,0,5);
    outtextxy(30,200,"TE CONTAGIASTE");
    outtextxy(30,300,"PRESIONA");
    outtextxy(30,350,"CUALQUIER");
    outtextxy(30,400,"TECLA");

}

void end(){

    delay(10000);
    getch();	
    setcolor(12);
    settextstyle(1,0,5);
    outtextxy(30,200,"END GAME");
    outtextxy(30,300,"PRESIONA");
    outtextxy(30,350,"CUALQUIER");
    outtextxy(30,400,"TECLA");

}

void vereins(){

    setcolor(1);
    setfillstyle(1,getcolor());
    rectangle(x,y,x+50,y+10);
    floodfill(x+1,y+1,getcolor());
    seve=1;
    
}

void keinvereins(){

    unsigned int guardacolor=getcolor();
    if(seve==1){

        setcolor(getbkcolor());
        setfillstyle(1,getbkcolor());
        rectangle(x,y,x+50,y+10);
        floodfill(x+1,y+1,getbkcolor());
        seve=0;
        setcolor(guardacolor);

    }

}

void mueveins(int nx,int ny){

    if(seve==1){

        keinvereins();
        x=nx;
        y=ny;
        vereins();

    } else {
        
        x=nx;
        y=ny;

    }

}

int zx, zy, zseve=0;

void fondocorona(){

	setfillstyle(1,2);
    circle(50,110,12);
    floodfill(50,110,getcolor());

	line(55,110,65,115);
	putpixel(65,115,GREEN); //pinta un pixel
	putpixel(65,116,GREEN);
	putpixel(65,114,GREEN);
	putpixel(66,115,GREEN);
    line(50,100,50,93);
    putpixel(50,93,GREEN);
    putpixel(50,94,GREEN);
    putpixel(50,92,GREEN);
    putpixel(51,93,GREEN);
    line(40,110,30,110);
    putpixel(30,110,GREEN);
    putpixel(30,111,GREEN);
    putpixel(30,109,GREEN);
    putpixel(31,110,GREEN);
    line(48,113,46,125);
    putpixel(46,125,GREEN);
    putpixel(46,124,GREEN);
    putpixel(46,123,GREEN);
    putpixel(47,125,GREEN);
   
    circle(95,138,12);
    floodfill(95,138,getcolor());
    
    line(94,136,93,124);
    putpixel(93,124,GREEN);
    putpixel(93,125,GREEN);
    putpixel(93,123,GREEN);
    putpixel(94,124,GREEN);
    line(83,138,75,138);
    putpixel(75,138,GREEN);
    putpixel(75,139,GREEN);
	putpixel(75,137,GREEN);
	putpixel(76,138,GREEN);
    line(92,150,95,157);
    putpixel(95,157,GREEN);
    putpixel(95,158,GREEN);
    putpixel(95,156,GREEN);
    putpixel(96,157,GREEN);
    line(104,138,115,138);
    putpixel(115,138,GREEN);
    putpixel(115,139,GREEN);
    putpixel(115,137,GREEN);
    putpixel(116,138,GREEN);
 
    circle(37,250,12);
    floodfill(37,250,getcolor());
    
    line(33,261,32,270);
    putpixel(32,270,GREEN);
    putpixel(32,271,GREEN);
    putpixel(32,269,GREEN);
    putpixel(33,270,GREEN);
    line(24,250,16,250);
    putpixel(16,270,GREEN);
    putpixel(16,271,GREEN);
    putpixel(16,269,GREEN);
    putpixel(17,270,GREEN);
    line(37,237,39,230);
    putpixel(39,230,GREEN);
    putpixel(39,231,GREEN);
    putpixel(39,229,GREEN);
    putpixel(40,230,GREEN);
    line(37,249,52,244);
    putpixel(52,244,GREEN);
    putpixel(52,245,GREEN);
    putpixel(52,243,GREEN);
    putpixel(53,244,GREEN);
    line(50,257,55,260);
    putpixel(55,260,GREEN);
    putpixel(55,261,GREEN);
    putpixel(55,259,GREEN);
    putpixel(56,260,GREEN);
 
    circle(89,317,12);
    floodfill(89,317,getcolor());
  
    line(89,313,91,297);
    putpixel(91,297,GREEN);
    putpixel(91,298,GREEN);
    putpixel(91.,96,GREEN);
    putpixel(92,297,GREEN);
    line(99,317,109,319);
    putpixel(109,319,GREEN);
    putpixel(109,320,GREEN);
    putpixel(109,318,GREEN);
    putpixel(110,319,GREEN);
    line(87,327,85,333);
    putpixel(85,333,GREEN);
    putpixel(85,334,GREEN);
    putpixel(85,332,GREEN);
    putpixel(86,333,GREEN);
    line(76,316,70,315);
    putpixel(70,315,GREEN);
    putpixel(70,316,GREEN);
    putpixel(70,314,GREEN);
    putpixel(71,315,GREEN);
 
    circle(77,400,16);
    floodfill(77,400,getcolor());
  
    line(77,387,77,378);
    putpixel(77,378,GREEN);
    putpixel(77,379,GREEN);
    putpixel(77,376,GREEN);
    putpixel(78,378,GREEN);
    line(80,400,99,402);
    putpixel(99,402,GREEN);
    putpixel(99,403,GREEN);
    putpixel(99,401,GREEN);
    putpixel(100,402,GREEN);
    line(78,412,78,421);
    putpixel(78,421,GREEN);
    putpixel(78,422,GREEN);
    putpixel(78,420,GREEN);
    putpixel(79,421,GREEN);
    line(62,400,52,401);
    putpixel(52,401,GREEN);
    putpixel(52,402,GREEN);
    putpixel(52,400,GREEN);
    putpixel(53,401,GREEN);
 
    circle(95,452,9);
    floodfill(95,452,getcolor());
 
    line(93,448,95,438);
    putpixel(95,438,GREEN);
    putpixel(95,439,GREEN);
    putpixel(95,437,GREEN);
    putpixel(96,438,GREEN);
    line(102,451,112,452);
    putpixel(112,452,GREEN);
    putpixel(112,453,GREEN);
    putpixel(112,451,GREEN);
    putpixel(113,452,GREEN);
    line(96,458,95,467);
    putpixel(95,467,GREEN);
    putpixel(95,468,GREEN);
    putpixel(95,466,GREEN);
    putpixel(96,467,GREEN);
    line(87,449,80,448);
    putpixel(80,448,GREEN);
    putpixel(80,449,GREEN);
    putpixel(80,447,GREEN);
    putpixel(81,448,GREEN);
 
    circle(129,195,12);
    floodfill(129,195,getcolor());

    line(129,184,129,176);
    putpixel(129,176,GREEN);
    putpixel(129,177,GREEN);
    putpixel(129,175,GREEN);
    putpixel(130,176,GREEN);
    line(140,195,147,196);
    putpixel(147,196,GREEN);
    putpixel(147,197,GREEN);
    putpixel(147,195,GREEN);
    putpixel(148,196,GREEN);
    line(127,202,126,210);
    putpixel(126,210,GREEN);
    putpixel(126,211,GREEN);
    putpixel(126,209,GREEN);
    putpixel(127,210,GREEN);
    line(118,195,110,195);
    putpixel(110,195,GREEN);
    putpixel(110,196,GREEN);
    putpixel(110,194,GREEN);
    putpixel(111,195,GREEN);
    
    circle(35,145,12);
    floodfill(35,145,getcolor());

    line(35,134,33,126);
    putpixel(33,126,GREEN);
    putpixel(33,127,GREEN);
    putpixel(33,125,GREEN);
    putpixel(34,126,GREEN);
    line(42,146,52,148);
    putpixel(52,148,GREEN);
    putpixel(52,149,GREEN);
    putpixel(52,147,GREEN);
    putpixel(53,148,GREEN);
    line(34,156,34,164);
    putpixel(34,164,GREEN);
    putpixel(34,165,GREEN);
    putpixel(34,163,GREEN);
    putpixel(35,164,GREEN);
    line(24,144,17,142);
    putpixel(17,142,GREEN);
    putpixel(17,143,GREEN);
    putpixel(17,141,GREEN);
    putpixel(18,142,GREEN);
    	
    circle(73,275,12);
    floodfill(73,275,getcolor());

    line(73,272,74,260);
    putpixel(74,260,GREEN);
    putpixel(74,261,GREEN);
    putpixel(74,259,GREEN);
    putpixel(75,260,GREEN);
    line(84,279,93,277);
    putpixel(93,277,GREEN);
    putpixel(93,278,GREEN);
    putpixel(93,276,GREEN);
    putpixel(94,277,GREEN);
    line(72,286,71,294);
    putpixel(71,294,GREEN);
    putpixel(71,295,GREEN);
    putpixel(71,293,GREEN);
    putpixel(72,294,GREEN);
    line(65,278,55,279);
    putpixel(55,279,GREEN);
    putpixel(55,280,GREEN);
    putpixel(55,278,GREEN);
    putpixel(56,279,GREEN);
    
    circle(62,300,12);
    floodfill(62,300,getcolor());

    line(62,286,60,279);
    putpixel(60,279,GREEN);
    putpixel(60,280,GREEN);
    putpixel(60,278,GREEN);
    putpixel(61,279,GREEN);
    line(73,301,81,302);
    putpixel(81,302,GREEN);
    putpixel(81,303,GREEN);
    putpixel(81,301,GREEN);
    putpixel(82,302,GREEN);
    line(61,307,60,315);
    putpixel(60,315,GREEN);
    putpixel(60,316,GREEN);
    putpixel(60,314,GREEN);
    putpixel(61,315,GREEN);
    line(52,299,44,299);
    putpixel(44,299,GREEN);
    putpixel(44,300,GREEN);
    putpixel(44,298,GREEN);
    putpixel(45,299,GREEN);
    
    circle(90,370,12);
    floodfill(90,370,getcolor());
 
    line(90,357,90,348);
    putpixel(90,348,GREEN);
    putpixel(90,349,GREEN);
    putpixel(90,347,GREEN);
    putpixel(91,348,GREEN);
	line(98,370,108,368);
	putpixel(108,368,GREEN);
	putpixel(108,369,GREEN);
	putpixel(108,367,GREEN);
    putpixel(109,368,GREEN);
	line(88,381,87,389);
	putpixel(87,389,GREEN);
	putpixel(87,390,GREEN);
	putpixel(87,388,GREEN);
	putpixel(88,389,GREEN);
	line(77,370,68,368);
	putpixel(68,368,GREEN);
	putpixel(68,369,GREEN);
	putpixel(68,367,GREEN);
	putpixel(69,368,GREEN);
	   
    circle(100,430,12);
    floodfill(100,430,getcolor());

    line(101,417,99,409);
    putpixel(99,409,GREEN);
    putpixel(99,410,GREEN);
    putpixel(99,408,GREEN);
    putpixel(100,409,GREEN);
    line(111,430,119,429);
    putpixel(119,429,GREEN);
    putpixel(119,430,GREEN);
    putpixel(119,428,GREEN);
    putpixel(120,429,GREEN);
    line(100,441,100,449);
    putpixel(100,449,GREEN);
    putpixel(100,450,GREEN);
    putpixel(100,448,GREEN);
    putpixel(101,449,GREEN);
    line(95,430,82,430);
    putpixel(82,430,GREEN);
    putpixel(82,431,GREEN);
    putpixel(82,429,GREEN);
    putpixel(83,430,GREEN);

    circle(40,425,15);
    floodfill(40,425,getcolor());

    line(40,418,40,401);
    putpixel(40,401,GREEN);
    putpixel(40,402,GREEN);
    putpixel(40,400,GREEN);
    putpixel(41,401,GREEN);
    line(54,424,64,425);
    putpixel(64,425,GREEN);
    putpixel(64,426,GREEN);
    putpixel(64,424,GREEN);
    putpixel(65,425,GREEN);
    line(39,439,38,447);
    putpixel(38,447,GREEN);
    putpixel(38,448,GREEN);
    putpixel(38,446,GREEN);
    putpixel(39,447,GREEN);
    line(26,425,18,424);
    putpixel(18,424,GREEN);
    putpixel(18,425,GREEN);
    putpixel(18,423,GREEN);
    putpixel(19,424,GREEN);

    circle(45,187,18);
    floodfill(45,187,getcolor());

    line(46,170,45,159);
    putpixel(45,159,GREEN);
    putpixel(45,160,GREEN);
    putpixel(45,158,GREEN);
    putpixel(46,159,GREEN);
    line(62,187,72,189);
    putpixel(72,189,GREEN);
    putpixel(72,190,GREEN);
    putpixel(72,188,GREEN);
    putpixel(73,190,GREEN);
    line(44,195,45,215);
    putpixel(45,215,GREEN);
    putpixel(45,216,GREEN);
    putpixel(45,214,GREEN);
    putpixel(46,215,GREEN);
    line(28,187,18,185);
    putpixel(18,185,GREEN);
    putpixel(18,186,GREEN);
    putpixel(18,184,GREEN);
    putpixel(19,185,GREEN);
    
    circle(74,225,15);
    floodfill(74,225,getcolor());

    line(74,211,75,203);
    putpixel(75,203,GREEN);
    putpixel(75,204,GREEN);
    putpixel(75,202,GREEN);
    putpixel(76,203,GREEN);
    line(87,225,97,226);
    putpixel(97,226,GREEN);
    putpixel(97,227,GREEN);
    putpixel(97,225,GREEN);
    putpixel(98,226,GREEN);
    line(73,239,73,249);
    putpixel(73,249,GREEN);
    putpixel(73,250,GREEN);
    putpixel(73,248,GREEN);
    putpixel(74,249,GREEN);
    line(66,225,51,222);
    putpixel(51,222,GREEN);
    putpixel(51,223,GREEN);
    putpixel(51,221,GREEN);
    putpixel(52,222,GREEN);
    
    circle(40,350,18);
    floodfill(40,350,getcolor());

    line(40,341,40,327);
    putpixel(40,327,GREEN);
    putpixel(40,328,GREEN);
    putpixel(40,326,GREEN);
    putpixel(41,327,GREEN);
    line(57,350,69,352);
    putpixel(69,352,GREEN);
    putpixel(69,353,GREEN);
    putpixel(69,351,GREEN);
    putpixel(70,352,GREEN);
    line(39,367,40,379);
    putpixel(40,379,GREEN);
    putpixel(40,380,GREEN);
    putpixel(40,378,GREEN);
    putpixel(41,379,GREEN);
    line(23,349,11,347);
    putpixel(11,347,GREEN);
    putpixel(11,348,GREEN);
    putpixel(11,346,GREEN);
    putpixel(12,347,GREEN);
   
}

void reglas(){

    setcolor(1);
    settextstyle(1,0,1);
    outtextxy(30,00,"Presiona cualquier tecla para empezar");
    getch();
    setcolor(2);
    outtextxy(50,30,"Presiona W para ir arriba");
    outtextxy(50,50,"Presiona S para ir abajo");
    outtextxy(50,70,"Presiona D para ir a la derecha");
    outtextxy(50,90,"Presiona A para ir a la izquierda");
    outtextxy(50,110,"En caso de presionar otra tecla");
    outtextxy(55,130,"terminara el juego");
    setcolor(12);

    outtextxy(70,160,"EL ESCAPE PERFECTO");
    setcolor(1);
    setfillstyle(1,getcolor());
    rectangle(100,250,400,370);
    floodfill(101,311,getcolor());

    getch();

}

void casita(){

    setcolor(LIGHTGREEN);
    rectangle(0,455,430,475);
    setfillstyle(1,LIGHTGREEN);
    floodfill(1,456,LIGHTGREEN);

    setcolor(LIGHTMAGENTA);
    rectangle(431,300,600,475);
    setfillstyle(1,getcolor());
    floodfill(432,301,getcolor());

    setcolor(WHITEE);
    rectangle(416,300,615,320);
    setfillstyle(1,getcolor());
    floodfill(417,301,getcolor());

    setcolor(WHITE);
    rectangle(460,360,570,475);
    setfillstyle(1,getcolor());
    floodfill(461,361,getcolor());

    setcolor(YELLOW);
    circle(555,425,5);
    setfillstyle(1,getcolor());
    floodfill(556,426,getcolor());

    setcolor(LIGHTBLUE);
    rectangle(500,385,535,425);
    setfillstyle(1,getcolor());
    floodfill(501,386,getcolor());

    setcolor(LIGHTGREEN);
    circle(450,455,20);
    setfillstyle(1,getcolor());
    floodfill(451,456,getcolor());

    setcolor(LIGHTGREEN);
    circle(580,455,20);
    setfillstyle(1,getcolor());
    floodfill(581,456,getcolor());

    getch();

}

void structuras(){

    cleardevice();
    setcolor(12);
    setfillstyle(4,getcolor());
    rectangle(300,100,310,120);
    floodfill(301,111,getcolor());
    setfillstyle(4,getcolor());
    rectangle(587,80,597,450);
    floodfill(588,81,getcolor());
    setcolor(9);
    setfillstyle(6,getcolor());
    rectangle(200,198,527,208);
    floodfill(251,201,getcolor());
    setfillstyle(6,getcolor());
    rectangle(200,220,587,230);
    floodfill(251,226,getcolor());
    setcolor(5);
    setfillstyle(6,getcolor());
    rectangle(200,230,470,239);
    floodfill(201,231,getcolor());
    setfillstyle(6,getcolor());
    rectangle(200,251,350,261);
    floodfill(201,252,getcolor());
    setfillstyle(6,getcolor());
    rectangle(405,251,500,261);
    floodfill(406,252,getcolor());
    setcolor(14);
    outtextxy(451,235,"?");

    fondocorona();
    casita();

}

void win(){

    setcolor(2);
    settextstyle(1,0,5);
    outtextxy(10,200,"LLEGASTE A CASA");
    outtextxy(10,250,"LAVATE LAS");
    outtextxy(10,300,"MANOS Y");
    outtextxy(10,350,"NO SALGAS");

}

main(){
        
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int w,s,d,a;
    Portada();
    cleardevice();
    reglas();
    structuras();
    x=100;
    y=100;  
    vereins();

    for(int i=1;i<17;i++){

        mueveins(x+i,y);
        delay(70);

    }

    if(kbhit()){

        char tecla=getch();
        if(tecla=='w'||'W'){

            for(int i=18;i<30;i++){

                mueveins(x+i,80);
                delay(90);

            }

            if(kbhit()){

                char tecla=getch();
                if(tecla=='s'||'S'){

                    for(int i=1;i<130;i++){

                        mueveins(530,80+i);
                        delay(10);

                    }

                    if(kbhit()){

                        char tecla=getch();
                        if(tecla=='a'||'A'){    
                            
                            for(int i=28;i<383;i++){

                                mueveins(518-i,209);
                                delay(5);

                            }

                            fflush(stdin);
                            if(kbhit()){

                                char tecla=getch();
                                if(tecla=='s'||'S'){

                                    for(int i=1;i<35;i++){

                                        mueveins(140,205+i);
                                        delay(15);

                                    }
                                    
                                    if(kbhit()){

                                        char tecla=getch();
                                        if(tecla=='d'||'D'){

                                            for(int i=1;i<213;i++){

                                                mueveins(140+i,240);
                                                delay(20);

                                            }
                                            
                                            fflush(stdin);
                                            if(kbhit()){

                                                char tecla=getch();
                                                if(tecla=='s'||'S'){
                                                    
                                                    for(int i=1;i<213;i++){

                                                        mueveins(352,240+i);
                                                        delay(20);

                                                    }
                                            
                                                    win();
                                                
                                                } else {
                                                    
                                                    end();

                                                }
                                            } else {
                                                
                                                for(int i=1;i<60;i++){

                                                    mueveins(350+i,240);
                                                    delay(20);
                                                }

                                                died();

                                            }

                                        } else {

                                            end();

                                        }

                                    } else {

                                        for(int i=50;i<75;i++){

                                            mueveins(140,200+i);
                                            delay(30);
                                        
                                        }

                                        keinvereins();
                                        int vector[19];
                                            vector[0]=150;
                                            vector[1]=245;
                                            vector[2]=172;
                                            vector[3]=254;
                                            vector[4]=172;
                                            vector[5]=250;
                                            vector[6]=167;
                                            vector[7]=267;
                                            vector[8]=174;
                                            vector[9]=277;
                                            vector[10]=162;
                                            vector[11]=280;
                                            vector[12]=137;
                                            vector[13]=292;
                                            vector[14]=127;
                                            vector[15]=272;
                                            vector[16]=137;
                                            vector[17]=267;
                                            vector[18]=vector[0];
                                            vector[19]=vector[1];
                                        setcolor(14);
                                        setfillstyle(1,getcolor());
                                        fillpoly(9,vector);
                                        floodfill(151,246,getcolor());
                                        died();

                                    }

                                } else {
                                
                                    end();

                                }
                            
                            } else {

                                keinvereins();
                                int vector[19];
                                    vector[0]=145;
                                    vector[1]=189;
                                    vector[2]=157;
                                    vector[3]=198;
                                    vector[4]=167;
                                    vector[5]=194;
                                    vector[6]=162;
                                    vector[7]=211;
                                    vector[8]=169;
                                    vector[9]=221;
                                    vector[10]=157;
                                    vector[11]=224;
                                    vector[12]=132;
                                    vector[13]=236;
                                    vector[14]=122;
                                    vector[15]=216;
                                    vector[16]=132;
                                    vector[17]=211;
                                    vector[18]=vector[0];
                                    vector[19]=vector[1];
                                setcolor(14);
                                setfillstyle(1,getcolor());
                                fillpoly(9,vector);
                                floodfill(146,210,getcolor());
                                died();
                            }
                        
                        } else {
                                                    
                            end();

                        }
                
                    } else {

                        keinvereins();
                        int vector[19];
                            vector[0]=545;
                            vector[1]=209;
                            vector[2]=557;
                            vector[3]=216;
                            vector[4]=567;
                            vector[5]=213;
                            vector[6]=562;
                            vector[7]=229;
                            vector[8]=569;
                            vector[9]=239;
                            vector[10]=557;
                            vector[11]=242;
                            vector[12]=532;
                            vector[13]=254;
                            vector[14]=522;
                            vector[15]=234;
                            vector[16]=532;
                            vector[17]=229;
                            vector[18]=vector[0];
                            vector[19]=vector[1];
                        setcolor(4);
                        setfillstyle(1,getcolor());
                        fillpoly(9,vector);
                        floodfill(546,210,getcolor());
                        died();
                    }

                } else {
                        
                    end();

                }
            
            } else {

                keinvereins();
                int vector[19];
                    vector[0]=587;
                    vector[1]=65;
                    vector[2]=597;
                    vector[3]=72;
                    vector[4]=607;
                    vector[5]=69;
                    vector[6]=602;
                    vector[7]=85;
                    vector[8]=609;
                    vector[9]=95;
                    vector[10]=597;
                    vector[11]=98;
                    vector[12]=572;
                    vector[13]=110;
                    vector[14]=562;
                    vector[15]=90;
                    vector[16]=572;
                    vector[17]=85;
                    vector[18]=vector[0];
                    vector[19]=vector[1];
                setcolor(4);
                setfillstyle(1,getcolor());
                fillpoly(9,vector);
                floodfill(588,90,getcolor());
                died();

            }
    
        } else {
                
            end();

        }
    
    } else {

        keinvereins();
        int vector[19];
            vector[0]=300;
            vector[1]=85;
            vector[2]=310;
            vector[3]=92;
            vector[4]=320;
            vector[5]=89;
            vector[6]=315;
            vector[7]=105;
            vector[8]=322;
            vector[9]=115;
            vector[10]=310;
            vector[11]=118;
            vector[12]=285;
            vector[13]=130;
            vector[14]=275;
            vector[15]=110;
            vector[16]=285;
            vector[17]=105;
            vector[18]=vector[0];
            vector[19]=vector[1];    
        setcolor(4);
        setfillstyle(1,getcolor());
        fillpoly(9,vector);
        floodfill(300,90,getcolor());
        died();

    }

    getch();
    closegraph();
    return 0;

}
