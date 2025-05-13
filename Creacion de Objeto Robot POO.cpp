#include <iostream>
#include <graphics.h>
#include <conio.h>
#define R 400
using namespace std;

class Robot{
	private:
		char nombre[50];
		int colorr, t;
		
	public:
		Robot(){}
		void name();
		void coloor();
		void tamano();
		void pintarRobot();
};
void Robot::name(){
	cout<<"Ingresar el nombre del Robot\n";
	cin>>nombre;	
}
void Robot::coloor(){
		int color;
		cout<<"Dar el color, escoger de los sig colores:\n1 Azul\n2 Amarillo\n3 Rojo \n4 Verde\n5 Azul Claro\n (Presionar el numero segun corresponda al color)";
		cin>>color;		
		switch(color){
			case 1:
				colorr=1;
			break;	
			case 2:
				colorr=14;
			break;
			case 3:
				colorr=4;
			break;
			case 4:
				colorr=2;
			break;		
			case 5:
				colorr=9;
			break;	
		}
}
void Robot::tamano(){
		int size;
		cout<<"De que tama�o quiere su Robot: ";
		cout<<"\n1. Grande \n2. Mediano \n3. Chico";
		cout<<"\n(Presionar el numero segun corresponda al tama�o deseado[1-3]: )";
		cin>>size;
		switch(size){
			case 1:
				t=1;
				break;
			case 2:
				t=2;
				break;
			case 3:
				t=3;
				break;
		}		
}
class Figura{
	protected:	//Todos conozcan las variables
     	int x,y;
     	int vis;
    public:   	
    	virtual void Muestra()=0;
		virtual void Oculta()=0;
		Figura(int, int){}
		int Darx(){return x;}
		int Dary(){return y;}
		int Darvis(){return vis;}	
};

class Circulo: private Figura{
		int radio, zx, zy;
	public:	
		Circulo(int r, int ox, int oy):Figura(ox,oy){
			radio=r;
			zx= ox;
			zy= oy;			
		}
		void Muestra()
		{
			setcolor(15);
			vis=1;
			setfillstyle(1,getcolor());
			circle(zx, zy, (int)radio);
			floodfill(zx, zy, getcolor()); 
		}
		void Oculta()
		{
			if(vis)
			{		
				unsigned gc=getcolor();
				setcolor(getbkcolor());
				vis=0;
				setfillstyle(1,getcolor());
				circle(zx, zy, radio);
				floodfill(zx, zy, getcolor()); 
				setcolor(gc);
						
			 }
		}
};
class Rectangulo: private Figura{
		float base, altura, zx, zy;
		int col;
	public:
		Rectangulo(int colr, int ox, int oy, int ob, int oa):Figura(ox,oy)
		{
			base=ob;
			altura=oa;
			zx=ox;
			zy=oy;
			col=colr;
		} 
		void Muestra()
		{
			
			setcolor(col);
			vis=1;
			setfillstyle(1,getcolor());
			rectangle(zx, zy, (zx+base), (zy+altura));
			floodfill((zx+1), (zy+1), getcolor()); 
		}   
	    void Oculta()
		{
			if(vis)
			{
				unsigned gc=getcolor();
				setcolor(getbkcolor());
	    		vis=0;			
				setfillstyle(1,getcolor());
				rectangle(zx, zy, (zx+base), (zy+altura));
				floodfill((zx+1), (zy+1), getcolor()); 
				setcolor(gc);
				
			}
		}		
};
class Triangulo: private Figura
{
		float base, altura, zx, zy;
		int col;
	public:
		
		Triangulo(int colr, int ox, int oy, int ob, int oa):Figura(ox,oy)
		{
			base=ob;
			altura=oa;
			zx= ox;
			zy= oy;
			col=colr;
		}  
		
		void Muestra()
		{		
			vis=1;
			int vector[8];
			vector[0]=zx;
			vector[1]=zy;
			vector[2]=(zx+(base/2));
			vector[3]=(zy+altura);
			vector[4]=vector[2]+(base/2);
			vector[5]=vector[1];	
			vector[6]=vector[0];
			vector[7]=vector[1];	
			setcolor(col);	
			setfillstyle(1,getcolor());
			fillpoly(3,vector);
			floodfill((zx+1),(zy+1),getcolor());
		}
	     
	    void Oculta()
		{
			if(vis)
			{
				unsigned gc=getcolor();
				setcolor(getbkcolor());
	    		vis=0;
	    		int vector[8];
				vector[0]=zx;
				vector[1]=zy;
				vector[2]=(zx+(base/2));
				vector[3]=(zy+altura);
				vector[4]=vector[2]+(base/2);
				vector[5]=vector[1];	
				vector[6]=vector[0];
				vector[7]=vector[1];				
				setfillstyle(1,getcolor());
				fillpoly(3,vector);
				floodfill((zx+1),(zy+1),getcolor());			
				setcolor(gc);
			}
		} 
};

void Robot::pintarRobot(){
	int colo, ta, i;
	ta=t;
	colo=colorr;
	
	
	if(ta==1){
				Rectangulo cabeza(colo,533,10,297,140);
				cabeza.Muestra();
				Circulo ojod(30,607,90);
				ojod.Muestra();
				Circulo ojoi(30,756,90);
				ojoi.Muestra();
				Rectangulo cuello(colo,607,150,149,23);
				cuello.Muestra();
				Rectangulo cuerpo(colo,458,173,449,228);
				cuerpo.Muestra();
				Circulo corazon(50,682,230);
				corazon.Muestra();
				Rectangulo brazd(colo,309,173,149,200);
				brazd.Muestra();
				Rectangulo brazi(colo,907,173,149,200);
				brazi.Muestra();
				Rectangulo piernad(colo,508,401,174,228);
				piernad.Muestra();
				Rectangulo piernai(colo,682,401,174,228);
				piernai.Muestra();
				Rectangulo cohad(colo,229,249,60,76);
				cohad.Muestra();
				Rectangulo cohai(colo,1075,249,60,76);
				cohai.Muestra();
				Rectangulo cohpd(colo,388,524,120,76);
				cohpd.Muestra();
				Rectangulo cohpi(colo,857,524,120,76);
				cohpi.Muestra();
				Triangulo alad(colo,150,173,318,152);
				alad.Muestra();
				Triangulo alai(colo,897,173,318,152);
				alai.Muestra();
				Triangulo pied(colo,508,629,174,66);
				pied.Muestra();
				Triangulo piei(colo,682,629,174,66);
				piei.Muestra();
				getch();	
				cabeza.Oculta();
				ojod.Oculta();
				ojoi.Oculta();
				cuello.Oculta();
				cuerpo.Oculta();
				corazon.Oculta();
				brazd.Oculta();
				brazi.Oculta();
				piernad.Oculta();
				piernai.Oculta();
				cohpd.Oculta();
				cohpi.Oculta();
				cohad.Oculta();
				cohai.Oculta();	
				alad.Oculta();
				alai.Oculta();
				pied.Oculta();		
				piei.Oculta();
					i=R/2;
					Rectangulo cabezao(colo,533+i,10,297,140);
					cabezao.Muestra();
					Circulo ojodo(30,607+i,90);
					ojodo.Muestra();
					Circulo ojoio(30,756+i,90);
					ojoio.Muestra();
					Rectangulo cuelloo(colo,607+i,150,149,23);
					cuelloo.Muestra();
					Rectangulo cuerpoo(colo,458+i,173,449,228);
					cuerpoo.Muestra();
					Circulo corazono(50,682+i,230);
					corazono.Muestra();
					Rectangulo brazdo(colo,309+i,173,149,200);
					brazdo.Muestra();
					Rectangulo brazio(colo,907+i,173,149,200);
					brazio.Muestra();
					Rectangulo piernado(colo,508+i,401,174,228);
					piernado.Muestra();
					Rectangulo piernaio(colo,682+i,401,174,228);
					piernaio.Muestra();
					Rectangulo cohado(colo,229+i,249,60,76);
					cohado.Muestra();
					Rectangulo cohaio(colo,1075+i,249,60,76);
					cohaio.Muestra();
					Rectangulo cohpdo(colo,388+i,524,120,76);
					cohpdo.Muestra();
					Rectangulo cohpio(colo,857+i,524,120,76);
					cohpio.Muestra();
					Triangulo alado(colo,150+i,173,318,152);
					alado.Muestra();
					Triangulo alaio(colo,897+i,173,318,152);
					alaio.Muestra();
					Triangulo piedo(colo,508+i,629,174,66);
					piedo.Muestra();
					Triangulo pieio(colo,682+i,629,174,66);
					pieio.Muestra();
					settextstyle(GOTHIC_FONT,0,2);
					setcolor(3);
					outtextxy(1030,120, "Hola mi nombre es ");
					outtextxy(1030+279,120,nombre);	
					
					}			
			if(ta==2)
			{
				Rectangulo cabeza(colo,368,115,198,93);
				cabeza.Muestra();
				Circulo ojod(20,417,148);
				ojod.Muestra();
				Circulo ojoi(20,516,148);
				ojoi.Muestra();
				Rectangulo cuello(colo,417,208,100,15);
				cuello.Muestra();
				Rectangulo cuerpo(colo,317,223,300,152);
				cuerpo.Muestra();
				Circulo corazon(33,467,261);
				corazon.Muestra();
				Rectangulo brazd(colo,218,223,99,133);
				brazd.Muestra();
				Rectangulo brazi(colo,617,223,99,133);
				brazi.Muestra();
				Rectangulo piernad(colo,351,375,116,152);
				piernad.Muestra();
				Rectangulo piernai(colo,467,375,116,152);
				piernai.Muestra();
				Rectangulo cohpd(colo,271,457,80,50);
				cohpd.Muestra();
				Rectangulo cohpi(colo,583,457,80,50);
				cohpi.Muestra();
				Rectangulo cohad(colo,165,273,40,50);
				cohad.Muestra();
				Rectangulo cohai(colo,722,273,40,50);
				cohai.Muestra();
				Triangulo alad(colo,112,223,212,101);
				alad.Muestra();
				Triangulo alai(colo,600,223,212,101);
				alai.Muestra();
				Triangulo pied(colo,351,527,116,66);
				pied.Muestra();
				Triangulo piei(colo,467,527,116,66);
				piei.Muestra();
				getch();	
				cabeza.Oculta();
				ojod.Oculta();
				ojoi.Oculta();
				cuello.Oculta();
				cuerpo.Oculta();
				corazon.Oculta();
				brazd.Oculta();
				brazi.Oculta();
				piernad.Oculta();
				piernai.Oculta();
				cohpd.Oculta();
				cohpi.Oculta();
				cohad.Oculta();
				cohai.Oculta();	
				alad.Oculta();
				alai.Oculta();
				pied.Oculta();		
				piei.Oculta();
					i=R;
					Rectangulo cabezao(colo,368+i,115,198,93);
					cabezao.Muestra();
					Circulo ojodo(20,417+i,148);
					ojodo.Muestra();
					Circulo ojoio(20,516+i,148);
					ojoio.Muestra();
					Rectangulo cuelloo(colo,417+i,208,100,15);
					cuelloo.Muestra();		
					Rectangulo cuerpoo(colo,317+i,223,300,152);
					cuerpoo.Muestra();
					Circulo corazono(33,467+i,261);
					corazono.Muestra();
					Rectangulo brazdo(colo,218+i,223,99,133);
					brazdo.Muestra();
					Rectangulo brazio(colo,617+i,223,99,133);
					brazio.Muestra();
					Rectangulo piernado(colo,351+i,375,116,152);
					piernado.Muestra();
					Rectangulo piernaio(colo,467+i,375,116,152);
					piernaio.Muestra();
					Rectangulo cohpdo(colo,271+i,457,80,50);
					cohpdo.Muestra();
					Rectangulo cohpio(colo,583+i,457,80,50);
					cohpio.Muestra();
					Rectangulo cohado(colo,165+i,273,40,50);
					cohado.Muestra();
					Rectangulo cohaio(colo,722+i,273,40,50);
					cohaio.Muestra();
					Triangulo alado(colo,112+i,223,212,101);
					alado.Muestra();
					Triangulo alaio(colo,600+i,223,212,101);
					alaio.Muestra();	
					Triangulo piedo(colo,351+i,527,116,66);
					piedo.Muestra();
					Triangulo pieio(colo,467+i,527,116,66);
					pieio.Muestra();
					settextstyle(GOTHIC_FONT,0,2);
					setcolor(3);
					outtextxy(966,120, "Hola mi nombre es ");
					outtextxy(1245,120,nombre);
				
				
				}
			if(t==3){
			
				Rectangulo cabeza(colo,476,215,99,46);
				cabeza.Muestra();
				Circulo ojod(10,500,241);
				ojod.Muestra();
				Circulo ojoi(10,549,241);
				ojoi.Muestra();
				Rectangulo cuello(colo,501,261,49,7);
				cuello.Muestra();
				Rectangulo cuerpo(colo,451,268,149,76);
				cuerpo.Muestra();
				Circulo corazon(16,525,287);
				corazon.Muestra();
				Rectangulo brazd(colo,402,268,49,66);
				brazd.Muestra();
				Rectangulo brazi(colo,600,268,49,66);
				brazi.Muestra();
				Rectangulo piernad(colo,467,344,58,76);
				piernad.Muestra();
				Rectangulo piernai(colo,525,344,58,76);
				piernai.Muestra();
				Rectangulo cohad(colo,376,293,20,25);
				cohad.Muestra();
				Rectangulo cohai(colo,658,293,20,25);
				cohai.Muestra();
				Rectangulo cohpd(colo,427,385,40,25);
				cohpd.Muestra();
				Rectangulo cohpi(colo,583,385,40,25);
				cohpi.Muestra();
				Triangulo alad(colo,349,268,106,50);
				alad.Muestra();
				Triangulo alai(colo,596,268,106,50);
				alai.Muestra();
				Triangulo pied(colo,467,420,58,22);
				pied.Muestra();
				Triangulo piei(colo,525,420,58,22);
				piei.Muestra();
				getch();	
				cabeza.Oculta();
				ojod.Oculta();
				ojoi.Oculta();
				cuello.Oculta();
				cuerpo.Oculta();
				corazon.Oculta();
				brazd.Oculta();
				brazi.Oculta();
				piernad.Oculta();
				piernai.Oculta();
				cohpd.Oculta();
				cohpi.Oculta();
				cohad.Oculta();
				cohai.Oculta();	
				alad.Oculta();
				alai.Oculta();
				pied.Oculta();		
				piei.Oculta();
					i=R*2;
					Rectangulo cabezao(colo,476+i,215,99,46);
					cabezao.Muestra();
					Circulo ojodo(10,500+i,241);
					ojodo.Muestra();
					Circulo ojoio(10,549+i,241);
					ojoio.Muestra();
					Rectangulo cuelloo(colo,501+i,261,49,7);
					cuelloo.Muestra();
					Rectangulo cuerpoo(colo,451+i,268,149,76);
					cuerpoo.Muestra();
					Circulo corazono(16,525+i,287);
					corazono.Muestra();
					Rectangulo brazdo(colo,402+i,268,49,66);
					brazdo.Muestra();
					Rectangulo brazio(colo,600+i,268,49,66);
					brazio.Muestra();
					Rectangulo piernado(colo,467+i,344,58,76);
					piernado.Muestra();
					Rectangulo piernaio(colo,525+i,344,58,76);
					piernaio.Muestra();
					Rectangulo cohado(colo,376+i,293,20,25);
					cohado.Muestra();
					Rectangulo cohaio(colo,658+i,293,20,25);
					cohaio.Muestra();
					Rectangulo cohpdo(colo,427+i,385,40,25);
					cohpdo.Muestra();
					Rectangulo cohpio(colo,583+i,385,40,25);
					cohpio.Muestra();
					Triangulo alado(colo,349+i,268,106,50);
					alado.Muestra();
					Triangulo alaio(colo,596+i,268,106,50);
					alaio.Muestra();
					Triangulo piedo(colo,467+i,420,58,22);
					piedo.Muestra();
					Triangulo pieio(colo,525+i,420,58,22);
					pieio.Muestra();
					
					settextstyle(GOTHIC_FONT,0,2);
					setcolor(3);
					outtextxy(907,215, "Hola mi nombre es ");
					outtextxy(907+279,215,nombre);
		}	
}		
	
main(){
	int monitor=DETECT, modo;
	initgraph(&monitor, &modo, "\\TC\\BGI");
	char resp;	
	do{
		Robot r1;
		r1.name();
	    r1.coloor();
		r1.tamano();		
		r1.pintarRobot();
		
		cout<<"\nDesea construir otro Robot? (s=si, n=no): ";
		cin>>resp;
		if(resp=='s'){
			fflush(stdin);
			cleardevice();
			
		}
	}while(resp=='s');
}
