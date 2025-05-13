#include <winbgim.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
int x, y, seve=0;

void died(){

	setcolor(4);
	settextstyle(1,0,5);
	outtextxy(30,200,"YOU DIED LOSER");		
}

void end(){

	setcolor(12);
	settextstyle(1,0,5);
	outtextxy(30,200,"END GAME");	
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

void fire(){

	int vector[23];
		vector[0]=0;
		vector[1]=100;
		vector[2]=90;
		vector[3]=90;
		vector[4]=60;
		vector[5]=150;
		vector[6]=125;
		vector[7]=215;	
		vector[8]=60;
		vector[9]=245;
		vector[10]=140;
		vector[11]=292;	
		vector[12]=110;
		vector[13]=360;
		vector[14]=160;	
		vector[15]=400;
		vector[16]=110;
		vector[17]=455;
		vector[18]=160;
		vector[19]=468;
		vector[20]=0;
		vector[21]=468;
		vector[22]=vector[0];
		vector[23]=vector[1];	
	setcolor(4);	
	setfillstyle(1, getcolor());
	fillpoly(11, vector);
	floodfill(1, 101, getcolor());
}

void fire2(){

	int vector[23];
		vector[0]=0;
		vector[1]=95;
		vector[2]=100;
		vector[3]=85;
		vector[4]=70;
		vector[5]=145;
		vector[6]=135;
		vector[7]=215;	
		vector[8]=70;
		vector[9]=245;
		vector[10]=150;
		vector[11]=292;	
		vector[12]=130;
		vector[13]=360;
		vector[14]=180;	
		vector[15]=400;
		vector[16]=130;
		vector[17]=455;
		vector[18]=180;
		vector[19]=468;
		vector[20]=0;
		vector[21]=468;
		vector[22]=vector[0];
		vector[23]=vector[1];	
	setcolor(14);	
	setfillstyle(1, getcolor());
	fillpoly(11, vector);
	floodfill(1, 101, getcolor());
} 

void reglas(){

	setcolor(1);
	settextstyle(1, 0, 1);
	outtextxy(30, 0, "Presiona cualquier tecla para empezar");
	getch(); 
	setcolor(2);
	outtextxy(50, 30, "Presiona W para ir arriba"); 
	outtextxy(50, 50, "Presiona S para ir abajo");
	outtextxy(50, 70, "Presiona D para ir a la derecha");
	outtextxy(50, 90, "Presiona A para ir a la izquierda");
	outtextxy(50, 110, "En caso de presionar otra tecla");
	outtextxy(55, 130, "terminara el juego");
	setcolor(12);

	outtextxy(70, 160, "EL ESCAPE PERFECTO");
	setcolor(1);
	setfillstyle(1, getcolor());
	rectangle(100, 250, 400, 370);
	floodfill(101, 311, getcolor());

	getch();	
}
void structuras(){

	cleardevice();
	setcolor(12);
	setfillstyle(4, getcolor());
	rectangle(300, 100, 310, 120);
	floodfill(301, 111, getcolor());
	setfillstyle(4, getcolor());
	rectangle(587, 80, 597, 450);
	floodfill(588, 81, getcolor());
	setcolor(9);
	setfillstyle(6, getcolor());
	rectangle(200, 198, 527, 208);
	floodfill(251, 201, getcolor());
	setfillstyle(6, getcolor());
	rectangle(200, 220, 587, 230);
	floodfill(251, 226, getcolor()); 
	setcolor(5);
	setfillstyle(6, getcolor());
	rectangle(200, 230, 470, 239);
	floodfill(201, 231, getcolor()); 
	setfillstyle(6, getcolor());
	rectangle(200, 251, 350, 261);
	floodfill(201, 252, getcolor()); 
	setfillstyle(6, getcolor());
	rectangle(405, 251, 500, 261);
	floodfill(406, 252, getcolor()); 
	setcolor(14);
	outtextxy(451, 235, "?"); 

	setcolor(10);
	setfillstyle(6, getcolor());
	rectangle(200, 300, 470, 310);
	floodfill(201, 301, getcolor()); 
	setfillstyle(6, getcolor());
	rectangle(200, 270, 350, 280);
	floodfill(201, 271, getcolor()); 
	setfillstyle(6, getcolor());
	rectangle(405, 270, 500, 280);
	floodfill(406, 271, getcolor()); 
	fire2(); 
	fire();	
}
void win(){

	setcolor(2);
	settextstyle(1, 0, 5);
	outtextxy(30, 200, "LLEGASTE A CASA");
	outtextxy(30, 250, "LAVATE LAS MANOS Y NO SALGAS");

}

main(){

	int monitor=DETECT, modo;
	int w, s, d, a;
	initgraph(&monitor, &modo, "\\TC\\BGI");
	reglas();
	structuras();
	x=100;
	y=100;  
	vereins();
	

	for(int i=1;i<17;i++){

		mueveins(x+i, y);
		delay(70);

	}

	if(kbhit()){

		char tecla = getch();
		if(tecla == 'w'||'W'){

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