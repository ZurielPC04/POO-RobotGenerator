#include <winbgim.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stdio.h>
#define p1 960
#define p2 1280
#define R 250
#define PI 3.14159265358979323846
using namespace std;
//pixels 960 x 1280
//Radio 450 pixels

main(){
	int monitor=DETECT, modo;
	initgraph(&monitor, &modo, "\\TC\\BGI");
	int radio, *iVerx, *iVery, *iVerx1, *iVery1, *arregloVert, *arregloVertLl, **Mat, **MatA, **MatAd, **MatAc, **MatAcaux, **Aux, **Aux1, noVert, x, y, *bucl, paralelas;
	int Sal1=0, Lle1, sig=0, Sa, Lle, sig1=0;
	paralelas=0;
	int nV, nL, T, contra=0;
	double c, s;
	int resp;
	setcolor(15);
	settextstyle(1,0,3);
	outtextxy(2,2,"\t\t\tTEORIA DE GRAFICAS: ");

	setcolor(4);
	settextstyle(1,0,3);
	outtextxy(2,32,"\t\tCREADOR: ");

	setcolor(9);

	outtextxy(2,62,"PALAFOX");
	outtextxy(2,92,"CUAPIO");
	outtextxy(2,122,"ISAI");
	outtextxy(2,152,"ZURIEL");

	settextstyle(4,0,3);

	setcolor(15);
	outtextxy(2,202,"	Buen dia, este programa dibuja una grafica con su respectivas matrices y otorga los datos");
	outtextxy(2,232,"de dichas matrices\nde igual forma otorga todos los datos de la grafica, de favor ingresar los datos solicitados. ");
	outtextxy(2,262,"Presionar tecla para comenzar...");

	getch();

	do{



	cleardevice();
	cout<<"\n	CREADOR: ";

	cout<<"\n\t\t P A L A F O X  C U A P I O";
	cout<<"\n\t\t I S A I  Z U R I E L";

	cout<<"\n   Buen dia, este programa dibuja una grafica con su respectivas matrices y otorga los datos de dichas matrices\nde igual forma otorga todos los datos de la grafica, de favor ingresar los datos solicitados. ";

	cout<<"\n\nDar el numero de vertices: ";
	cin>>noVert;
	nV=noVert;
	cout<<"\nDar el numero de lineas: ";
	cin>>nL;

	cout<<"\nDirigida= 1, No Dirigida= 2 : ";
	cin>>T;


	//Tomamos memoria del monticulo para bucl
	bucl=new int[nL];
	for(int i=0;i<nL;i++){
		bucl[i]=0;
	}

	//Tomamos memoria del monticulo para arregloVert
	arregloVert=new int[noVert];
	for(int i=0;i<noVert;i++){
		arregloVert[i]=0;
	}


	//Tomamos memoria del monticulo para arregloVertLl
	arregloVertLl=new int[noVert];
	for(int i=0;i<noVert;i++){
		arregloVertLl[i]=0;
	}


	if(T==1){
		
		setcolor(15);
		settextstyle(1,0,3);
		outtextxy(2,2,"   En este programa las lineas son de color azul, los bucles son circulos de este color");
		outtextxy(2,32,"asi mismo las flechas se representan con lineas de color rojo y los nodos son verdes");
		outtextxy(2,62,"Nodo: ");
		outtextxy(150,62,"Bucle: ");
		outtextxy(330,62,"Linea: ");
		
		setcolor(12);
		settextstyle(1,0,3);

		outtextxy(330,150,"GRAFICA DIRIGIDA");
		//nodo	
		setcolor(2);
		circle(120,82,20);
		//bucle
		setcolor(9);
		circle(280,92,30);
		//linea 
		
		int a, b, c, d;
		
		a=450;
		b=78;
		
		
		setcolor(9);
		line(a,b,a+430,b);
					
		setcolor(4);
		line((a+430)-(((a+430)-a)/(4)),(b)-(((b)-b)/(4)),a+430,b);
					
		
		
		cout<<"\nGRAFICA DIRIGIDA";
		int i, j, Ver, Ver1, cont, sumaProd, k, kk, nC, nF, ii, jj;   
		
		
		//Inicio Proceso LLenar Dibujar Mat
		
				//Dibujar grafica de mas de 2 vertices
				//Tomamos memoria del monticulo para las coordenadas
				iVerx=new int[noVert];
				iVery=new int[noVert];
				
				iVerx1=new int[noVert];
				iVery1=new int[noVert];
				
				
				nC=nL;
				nF=nV;
				
				//Matriz de Incidencia
				//Reservamos memoria para la matriz de Incidencia
				Mat=new int*[nF];
				for(i=0;i<nF;i++){
					Mat[i]=new int[nC]; 	
				}
				//Inicializamos en 0
				for(i=0;i<nF;i++){
					for(j=0;j<nC;j++){
						*(*(Mat+i)+j)=0; //Mat[i][j]=0 
					}
				}
			
				//Matriz de Adyacencia
				//Reservamos memoria para la matriz de Adyacencia
				MatA=new int*[nF];
				for(i=0;i<nF;i++){
					MatA[i]=new int[nF]; 	
				}
				//Inicializamos en 0
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						*(*(MatA+i)+j)=0; //MatA[i][j]=0 
					}
				}

				//Asignamos las coordenadas de x, y
				for(i=0;i<noVert;i++){
					Ver=i+1;
					x=(p2/2)+(R*cos(2*PI*Ver/noVert));
					y=(p1/2)+(R*sin(2*PI*Ver/noVert));
					iVerx[i]=x;
					iVery[i]=y;	
		
					iVerx1[i]=x+20;
					iVery1[i]=y+20;
					
					setcolor(2);
					circle(iVerx[i],iVery[i],20);
					
					fflush(stdin);
					char cer[3];
						
					int nroDig=0;
					int auxx=Ver;
						
						
					while(auxx>0){
						auxx=auxx/10;
						nroDig++;
					}
											
					for(int iy=0;iy<=nroDig;iy++){
							
						cer[iy]=Ver+'0';
							
						if(iy==nroDig){
						cer[iy]='\0';
						}	
					}
						
					char cad[3];
					strcpy(cad,cer);
						
					setcolor(2);
					settextstyle(4,0,2);
					outtextxy(iVerx[i],iVery[i],cad);
					
				
				}
				
				for(i=0;i<nL;i++){
				
					
					cout<<"\nLa linea "<<i+1<<" sale del vertice: ";
					cin>>Ver;
				
						//Llevamos la cuenta de cuantas veces se usa el vertice
						arregloVert[Ver-1]=arregloVert[Ver-1]+1;	
						//Lenamos elemento de la matriz de Incidencia			
						*(*(Mat+Ver-1)+i)=1;	
				
					cout<<"y llega al vertice: ";
					cin>>Ver1;
				
						//Llevamos la cuenta de cuantas veces se usa el vertice
						arregloVertLl[Ver1-1]=arregloVertLl[Ver1-1]+1;
						//Lenamos elemento de la matriz de Incidencia
						*(*(Mat+Ver1-1)+i)=-1;
				
					if(Ver==Ver1){
						//Dibujamos Bucle
						
						bucl[i]=1;
						
						
						setcolor(9);
						circle(iVerx[Ver-1],iVery[Ver-1],30);
						
						fflush(stdin);
						char cer1[3];
						int ic=i+1;
					
						int nroDig1=0;
						int auxx1=ic;
						
						
						while(auxx1>0){
							auxx1=auxx1/10;
							nroDig1++;
						}
						
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig1;iy1++){
							
							cer1[iy1]=ic+'0';
							
							if(iy1==nroDig1){
								cer1[iy1]='\0';
							}	
							
						}
						char cad1[3];
						strcpy(cad1,cer1);
						
						setcolor(9);
						settextstyle(4,0,2);
						
						outtextxy(iVerx[Ver-1]-30,iVery[Ver-1]+30,cad1);
						
						
						//Lenamos elemento de la matriz de Incidencia
						*(*(Mat+Ver-1)+i)=2;
						
					}else{
						//Dibujamos linea
						
						
						setcolor(9);
						line(iVerx[Ver-1],iVery[Ver-1],iVerx[Ver1-1],iVery[Ver1-1]);
					
						setcolor(4);
						line(((iVerx[Ver1-1])-(((iVerx[Ver1-1])-(iVerx[Ver-1]))/(4))),((iVery[Ver1-1])-(((iVery[Ver1-1])-(iVery[Ver-1]))/(4))),iVerx[Ver1-1],iVery[Ver1-1]);
					
						fflush(stdin);
						char cer1[3];
						
						
						int ic=i+1;
						
						int nroDig1=0;
						int auxx1=ic;
						
						
						while(auxx1>0){
							auxx1=auxx1/10;
							nroDig1++;
						}
						
						
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig1;iy1++){
							
							cer1[iy1]=ic+'0';
							
							if(iy1==nroDig1){
								cer1[iy1]='\0';
							}	
						}
					
						char cad1[3];
						strcpy(cad1,cer1);
						
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx[Ver-1])+(((iVerx[Ver1-1])-(iVerx[Ver-1]))/(2))),((iVery[Ver-1])+(((iVery[Ver1-1])-(iVery[Ver-1]))/(2))),cad1);
				
					}
								
					//Lenamos elemento de la matriz de Adyacencia
					*(*(MatA+Ver1-1)+Ver-1)=1;
			
				}
				
		
				//Matriz Transpuesta de Adyacencia
				//Reservamos memoria para la matriz de Transpuesta de Adyacencia
				MatAd=new int*[nF];
				for(i=0;i<nF;i++){
					MatAd[i]=new int[nF]; 	
				}
				//Hacemos la transpuesta
				for(i=0; i<nF; i++){
					for(j=0; j<nF; j++){					
						*(*(MatAd+i)+j)=*(*(MatA+j)+i); //MatAd[i][j]=MatA[j][i]
					}
				}
				
				//Matriz de Accesibilidad
				//Reservamos memoria para la matriz de Accesibilidad
				MatAc=new int*[nF];
				for(i=0;i<nF;i++){
					MatAc[i]=new int[nF]; 	
				}
				//La nicializamos igual que la de Adyacencia
				for(i=0;i<nF;i++){
					for(j=0;j<nC;j++){
						*(*(MatAc+i)+j)=*(*(MatAd+i)+j); //MatAc[i][j]=MatAd[i][j] 
					}
				}
				
				//Hacemos la suma de potencias sucesivas hasta n-1, noVert-2
				//Reservamos memoria para la matriz aux de Accesibilidad
				MatAcaux=new int*[nF];
				for(i=0;i<nF;i++){
					MatAcaux[i]=new int[nF]; 	
				}
				//La nicializamos igual que la de Adyacencia
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						*(*(MatAcaux+i)+j)=*(*(MatAd+i)+j); //MatAcux[i][j]=MatAd[i][j]
					}
				}
				//Hacemos la potencia
				//Reservamos memoria para la matriz Aux
				Aux=new int*[nF];
				for(i=0;i<nF;i++){
					Aux[i]=new int[nF]; 	
				}
				for(int z=0;z<nF-2;z++){
					if(z<1){
						
						for (int i=0;i<nF;i++){
							for (int j=0;j<nF;j++){ 
								*(*(MatAcaux+i)+j)=0;		
								for (int k=0;k<nF;k++){
									*(*(MatAcaux+i)+j)=*(*(MatAcaux+i)+j)+(*(*(MatAd+i)+k))*(*(*(MatAc+k)+j)); //MatAd=X * MatAc=X -> MatAcaux=X^2	
								}
							}
						}
						
						for(int i=0;i<nF;i++){
							for(int j=0;j<nF;j++){
								*(*(MatAc+i)+j)=*(*(MatAc+i)+j)+(*(*(MatAcaux+i)+j));	
							}
						}
					
					}else{	
						int conta;
						conta=z%2;
						if(conta>0){
							//Casos nones 1, 3, 5
							for (int i=0;i<nF;i++){
								for (int j=0;j<nF;j++){ 
									*(*(Aux+i)+j)=0;	
									for (int k=0;k<nF;k++){
										*(*(Aux+i)+j)=*(*(Aux+i)+j)+*(*(MatAd+i)+k)*(*(*(MatAcaux+k)+j)); //MatAd=X * MatAcauc=X^2 -> Aux=X^3
									}
								}
							}
						
							for(int i=0;i<nF;i++){
								for(int j=0;j<nF;j++){
									*(*(MatAc+i)+j)=*(*(MatAc+i)+j)+*(*(Aux+i)+j);
								}
							}
							
						}else{
							//Casos pares 2, 4, 6
							for (int i=0;i<nF;i++){
								for (int j=0;j<nF;j++){ 
									*(*(MatAcaux+i)+j)=0;	
									for (int k=0;k<nF;k++){
										*(*(MatAcaux+i)+j)=*(*(MatAcaux+i)+j)+*(*(MatAd+i)+k)*(*(*(Aux+k)+j)); //MatAd=X * Aux=X^3 -> MatAcaux=X^4
									}
								}
							}
						
							for(int i=0;i<nF;i++){
								for(int j=0;j<nF;j++){
									*(*(MatAc+i)+j)=*(*(MatAc+i)+j)+*(*(MatAcaux+i)+j);	
								}
							}
							
							
						}
					}
						
				}
				//Matriz de Incidencia
				cout<<"\nMATRIZ DE INCIDENCIA\n";
				for(i=0;i<nF;i++){
					for(j=0;j<nC;j++){
						
						
						if(*(*(Mat+i)+j)==2){
							cout<<" +-1";
						}else if(*(*(Mat+i)+j)==-1){
							cout<<"  "<<*(*(Mat+i)+j);
						}else{
							cout<<"   "<<*(*(Mat+i)+j);	
						}
							
					}
					cout<<"\n";
				}
				
				//Matriz de Adyacencia
				cout<<"\nMATRIZ DE ADYACENCIA\n";
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
					cout<<"  "<<*(*(MatAd+i)+j);	
					}
					cout<<"\n";
				}
				
				//Matriz de Accesibilidad
				cout<<"\nMATRIZ DE ACCESIBILIDAD\n";
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						
					if(*(*(MatAc+i)+j)>0){
						cout<<"  +";			
					}else{
						cout<<"  0";
					}		
					}
					cout<<"\n";
				}
				
				//Fin Proceso LLenar Dibujar Mat
				
				
				//Inicio Proceso Info de Vertices
				
				
				cout<<"\n\n\tProcederemos a otorgar la informacion de la Grafica\n";
				cout<<"\n\tInformacion de Vertices: ";
				
				cout<<"\n\n\tGrados Externos de los Vertices:";
				for(int i=0;i<nV;i++){
					cout<<"\nEl grado Externo del vertice "<<i+1<<" es: ";
					cout<<arregloVert[i];
				}
				
				cout<<"\n\n\tGrados Internos de los Vertices:";
				for(int i=0;i<nV;i++){
					cout<<"\nEl grado Interno del vertice "<<i+1<<" es: ";
					cout<<arregloVertLl[i];
				}
				cout<<"\n\n\tTenemos los sig. vertices aislados:";
				for(int i=0;i<nV;i++){
					if((arregloVert[i]==0)&&(arregloVertLl[i]==0))
					cout<<"\nEl Vertice "<<i+1<<" es aislado";
				}
				
				//Inicial= Grado interno 0 y externo distinto de 0
				cout<<"\n\n\tTenemos los sig. vertices Iniciales:";
				for(int i=0;i<nV;i++){
					if((arregloVertLl[i]==0)&&(arregloVert[i]>0)){
						cout<<"\nEl Vertice "<<i+1<<" es Inicial";
					}
				}
				//Final=  interno 0, externo distinto de 0
				cout<<"\n\n\tTenemos los sig. vertices Finales:";
				for(int i=0;i<nV;i++){
					if((arregloVert[i]==0)&&(arregloVertLl[i]>0)){
						cout<<"\nEl Vertice "<<i+1<<" es Final";
					}
				}		
			
				cout<<"\n\n\tInformacion de Lineas: ";
				
				//Lineas Paralelas
				cout<<"\n\n\tTenemos las sig. lineas Paralelas:";	
				//Matriz Aux1
				//Reservamos memoria para la matriz Aux1
				Aux1=new int*[nF];
				for(int i=0;i<nF;i++){
					Aux1[i]=new int[nC]; 	
				}
				//Inicializamos igual que la de incidencia
				for(int i=0;i<nF;i++){
					for(int j=0;j<nC;j++){
						*(*(Aux1+i)+j)=*(*(Mat+i)+j); //Mat[i][j]=0 
					}
				}
			
				
				for(int ii=0;ii<nC-1;ii++){
				int J;
				J=ii+1;	
						
				for( J;J<nC;J++){  // [n][0]
				
					for(int I=0;I<nF;I++){  //[n][1]

						if(J!=nC){
						
							if((*(*(Mat+I)+ii))==(*(*(Aux1+I)+J))){
					
															
								sig=I+1;
					
								if(*(*(Mat+I)+ii)>0){
								
									Sal1=I+1;
						
								}else if(*(*(Mat+I)+ii)<0){
									
									Lle1=I+1;
								}
									
							}else {
								I=nF;	
							}
							
							
							if(sig==nF){
						cout<<"\n\nLas lineas "<<ii+1<<" y "<<J+1<<" son paralelas";
						sig=0;
					
						paralelas=paralelas+1;
						//Dibujamos linea
						setcolor(9);
						line(iVerx[Sal1-1],iVery[Sal1-1],iVerx[Lle1-1],iVery[Lle1-1]);
						setcolor(4);
						line(((iVerx[Lle1-1])-(((iVerx[Lle1-1])-(iVerx[Sal1-1]))/(4))),((iVery[Lle1-1])-(((iVery[Lle1-1])-(iVery[Sal1-1]))/(4))),iVerx[Lle1-1],iVery[Lle1-1]);
						fflush(stdin);
						char cer1[3];
						int ic=ii+1;
						int nroDig1=0;
						int auxx1=ic;
						while(auxx1>0){
							auxx1=auxx1/10;
							nroDig1++;
						}
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig1;iy1++){
							cer1[iy1]=ic+'0';
							if(iy1==nroDig1){
								cer1[iy1]='\0';
							}	
						}
						char cad1[3];
						strcpy(cad1,cer1);
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx[Sal1-1])+(((iVerx[Lle1-1])-(iVerx[Sal1-1]))/(2))),((iVery[Sal1-1])+(((iVery[Lle1-1])-(iVery[Sal1-1]))/(2))),cad1);
						setcolor(9);
						line(iVerx1[Sal1-1],iVery1[Sal1-1],iVerx1[Lle1-1],iVery1[Lle1-1]);
						setcolor(4);
						line(((iVerx1[Lle1-1])-(((iVerx1[Lle1-1])-(iVerx1[Sal1-1]))/(4))),((iVery1[Lle1-1])-(((iVery1[Lle1-1])-(iVery1[Sal1-1]))/(4))),iVerx1[Lle1-1],iVery1[Lle1-1]);
						fflush(stdin);
						char cer11[3];
						int iic=J+1;
						int nroDig11=0;
						int auxx11=iic;
						while(auxx11>0){
							auxx11=auxx11/10;
							nroDig11++;
						}
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig11;iy1++){
							cer11[iy1]=iic+'0';	
							if(iy1==nroDig11){
								cer11[iy1]='\0';
							}	
						}
						char cad11[3];
						strcpy(cad11,cer11);
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx1[Sal1-1])+(((iVerx1[Lle1-1])-(iVerx1[Sal1-1]))/(2))),((iVery1[Sal1-1])+(((iVery1[Lle1-1])-(iVery1[Sal1-1]))/(2))),cad11);					
									
					}
								
						}
															
				}
					
			
					}		
					
				}	
			
						
				for(int ii=0;ii<nC-1;ii++){
				int J;
				J=ii+1;	
						
				for( J;J<nC;J++){  // [n][0]
			
					for(int I=0;I<nF;I++){  //[n][1]

					
						if(J!=nC){
								
							if((*(*(Mat+I)+ii))==-(*(*(Aux1+I)+J))){	
													
								sig1=I+1;
							
								if(*(*(Mat+I)+ii)>0){
								
									Sa=I+1;
								}else if(*(*(Mat+I)+ii)<0){
									
									Lle=I+1;
								}
								
							}else {
								I=nF;	
							}
							
							
							if(sig1==nF){
						sig1=0;
						
						
									
						contra=contra+1;					
						setcolor(9);
						line(iVerx[Sa-1],iVery[Sa-1],iVerx[Lle-1],iVery[Lle-1]);
						setcolor(4);
						line(((iVerx[Lle-1])-(((iVerx[Lle-1])-(iVerx[Sa-1]))/(4))),((iVery[Lle-1])-(((iVery[Lle-1])-(iVery[Sa-1]))/(4))),iVerx[Lle-1],iVery[Lle-1]);
						fflush(stdin);
						char cer12[3];	
						int ic2=ii+1;
						int nroDig12=0;
						int auxx12=ic2;

						while(auxx12>0){
							auxx12=auxx12/10;
							nroDig12++;
						}
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig12;iy1++){
							
							cer12[iy1]=ic2+'0';
							
							if(iy1==nroDig12){
								cer12[iy1]='\0';
							}	
						}
						char cad12[3];
						strcpy(cad12,cer12);
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx[Sa-1])+(((iVerx[Lle-1])-(iVerx[Sa-1]))/(2))),((iVery[Sa-1])+(((iVery[Lle-1])-(iVery[Sa-1]))/(2))),cad12);
						setcolor(9);
						line(iVerx1[Sa-1],iVery1[Sa-1],iVerx1[Lle-1],iVery1[Lle-1]);
						setcolor(4);
						line(iVerx1[Sa-1],iVery1[Sa-1],((iVerx1[Sa-1])+(((iVerx1[Lle-1])-(iVerx1[Sa-1]))/(4))),((iVery1[Sa-1])+(((iVery1[Lle-1])-(iVery1[Sa-1]))/(4))));
						fflush(stdin);
						char cer112[3];
						int iic2=J+1;
						
						int nroDig112=0;
						int auxx112=iic2;
						while(auxx112>0){
							auxx112=auxx112/10;
							nroDig112++;
						}
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig112;iy1++){
							
							cer112[iy1]=iic2+'0';
							
							if(iy1==nroDig112){
								cer112[iy1]='\0';
							}	
						}
					
						char cad112[3];
						strcpy(cad112,cer112);
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx1[Sa-1])+(((iVerx1[Lle-1])-(iVerx1[Sa-1]))/(2))),((iVery1[Sa-1])+(((iVery1[Lle-1])-(iVery1[Sa-1]))/(2))),cad112);				
				
					}
								
						}
																
				}
				
					}		
					
				}
		
			//Bucles
				
				cout<<"\n\n\tTenemos los sig. Bucles:";
			
				for(int i=0;i<nL;i++){
					if(bucl[i]==1){
						cout<<"\nLa linea "<<i+1<<" es un bucle";
					}
				}
			
				//Clasificacion de la Grafica
				
				int Cone=0, Reg, Comp, Comp1, bu=0;	
				cout<<"\n\n\tClasificacion de la Grafica: ";
			
				cout<<"\n\nSimple: ";
			
				for(int i=0;i<nL;i++){
					if(bucl[i]==1){
						bu=bu+1;
					}
				}
				
				if(bu>0 && paralelas>0){
					cout<<"\nEs una grafica general ya que tiene: "<<bu<<" bucles y "<<paralelas+1<<" lineas paralelas";
					
				}else if(bu>0){
					cout<<"\nEs una grafica general ya que tiene: "<<bu<<" bucles";
				}else if(paralelas>0){
					cout<<"\nEs una grafica general ya que tiene: "<<paralelas+1<<" lineas paralelas";
				}else {
					cout<<"\nEs una grafica Simple ya que no tiene bucles o lineas paralelas";
				}
				
				
				cout<<"\n\nConectada: ";
				
				
				int Co;
				//Matriz de Accesibilidad
				for(int i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						
					if(*(*(MatAc+i)+j)==0){
						Cone=Cone+1;	
					}
					}
				}
				if(Cone>0){
					cout<<"\nEs una Grafica Desconectada ya que al menos un elemento de la matriz Accesibilidad es 0";
				} else{
					cout<<"\nEs una Grafica Conectada ya que todos los elementos de la matriz Accesibilidad son +";
					Co=1;
				}		
				
				cout<<"\n\nRegular: ";
			
				int ex=0;
				for(int i=0;i<nV-1;i++){
					if(arregloVert[i]==arregloVert[i+1]){
						ex=0;
					}else{
						ex=1;
					}
				}
				int in=0;
				for(int i=0;i<nV-1;i++){
					if(arregloVertLl[i]==arregloVertLl[i+1]){
						in=0;	
					}else{
						in=1;
					}
				}
				if(ex==0&&in==0){
					cout<<"\nEs una Grafica Regular ya que los grados de los vertices son iguales";
				}
				
				cout<<"\n\nCompleta: ";
						
				for(int i=0;i<nF;i++){
					for(int j=0;j<nF;j++){
						if(i>j){
							if(*(*(MatAd+i)+j)==1){
								Comp=0;
							}else{
								Comp=1;
							}
						}
					}
				}
				
				for(int i=0;i<nF;i++){
					for(int j=0;j<nF;j++){
						if(i<j){
							if(*(*(MatAd+i)+j)==1){
								Comp1=0;
							}else{
								Comp1=1;
							}
						}
					}
				}		
				
				if(Comp==0&&Comp1==0){
					cout<<"\nEs una Grafica Completa ya que todos los elementos debajo y arriba de la diagonal son 1";
				}
				
				cout<<"\n\nSimetrica: ";
				if(contra>0){
				float sime;
				sime = nL/contra;
				if(sime==2){
					cout<<"\nEs una Grafica Simetrica ya que por cada linea de ida hay una de regreso";
				}else{
					cout<<"\nNo es una Grafica Simetrica ya que por cada linea de ida hay una de regreso";
				}
							
				}
				
				cout<<"\n\nBalanceada: ";
		
				int bala;
				for(int i=0;i<nV;i++){
					if(arregloVert[i]==arregloVert[i]){
						bala=0;
					}else{
						bala=1;
					}
				}
				
				int B;
				
				if(bala==0){
					cout<<"\nEs una Grafica Balanceada ya que el grado exterior e interior de los vertices es el mismo";
					B=1;	
				}
		
				cout<<"\n\nEuleriana: ";
				
			//	cout<<"\n\nTeclea para continuar 5";
				
				//Una digrafica es euleriana si y s�lo si es balanceada y conectada
				
				if(B==1&&Co==1){
					cout<<"\nEs una Grafica Euleriana ya que es balanceada y conectada";
				}
				
				cout<<"\n\nUnicursal: ";
				
			//	cout<<"\n\nTeclea para continuar 6";
				
				//Una digr�fica es unicursal si y s�lo si todos los v�rtices tiene grado interno y externo igual, excepto dos el inicial y el final.
				
				int IniU=0, FinU=0, VA, VAa;
					
					//Inicial= Grado interno 0 y externo distinto de 0
				//cout<<"\n\n\tTenemos los sig. vertices Iniciales:";
				for(int i=0;i<nV;i++){
					if((arregloVertLl[i]==0)&&(arregloVert[i]>0)){
						IniU=IniU+1;
						VA=i;
					}
				}
				//Final=  interno 0, externo distinto de 0
				//cout<<"\n\n\tTenemos los sig. vertices Finales:";
				for(int i=0;i<nV;i++){
					if((arregloVert[i]==0)&&(arregloVertLl[i]>0)){
						FinU=FinU+1;
						VAa=i;
					}
				}
			
				if(IniU==1&&FinU==1){
				int exx=0;
				for(int i=0;i<nV-1;i++){
					
					if(i!=VA){
						if(arregloVert[i]==arregloVert[i+1]){
						exx=0;
					}else{
						exx=1;
					}	
					}
				}
				int inn=0;
				for(int i=0;i<nV-1;i++){
					
					if(i!=VAa){
						if(arregloVertLl[i]==arregloVertLl[i+1]){
						inn=0;	
					}else{
						inn=1;
					}
					}	
				}	
				if(exx==0&&inn==0){
					cout<<"\nEs una Grafica Unicursal ya que los grados de los vertices son iguales excepto el del vertice inicial y final";
				}
				}
		
			cout<<"\nHora de liberar memoria";
		
		
		for(int i=0;i<nF;i++){
			delete[] MatAc;
		}
		delete[] MatAc;
		
		for(int i=0;i<nF;i++){
			delete[] MatAcaux;
		}
		delete[] MatAcaux;
		
		for(int i=0;i<nF;i++){
			delete[] Aux;
		}
		delete[] Aux;
		
		for(int i=0;i<nF;i++){
			delete[] MatA;
		}
		delete[] MatA;

		for(int i=0;i<nF;i++){
			delete[] MatAd;
		}
		delete[] MatAd;

		for(int i=0;i<nC;i++){
			delete[] Aux1;
		}
		delete[] Aux1;


		for(int i=0;i<nC;i++){
			delete[] Mat;
		}
		delete[] Mat;
		
		delete[] iVerx; 
		delete[] iVery;
		delete[] iVerx1; 
		delete[] iVery1;
		delete[] arregloVert;
		delete[] arregloVertLl;
		delete[] bucl;
		
		cout<<"\nLiberada";		
			//}
	//Cierre notas


	cout<<"\nDeseas cerrar el grafico teclea";
	getch();
	cleardevice();

	cout<<"\nGrafico cerrado";

	}else{
		
		
			
		setcolor(15);
		settextstyle(1,0,3);
		outtextxy(2,2,"   En este programa las lineas son de color azul, los bucles son circulos de este color");
		outtextxy(2,32," y los nodos son verdes");
		
		outtextxy(2,62,"Nodo: ");
		outtextxy(150,62,"Bucle: ");
		outtextxy(330,62,"Linea: ");
		
		setcolor(12);
		settextstyle(1,0,3);
		outtextxy(330,150,"GRAFICA NO DIRIGIDA");
		//nodo	
		setcolor(2);
		circle(120,82,20);
		//bucle
		setcolor(9);
		circle(280,92,30);
		//linea 
		
		int a, b, c, d;
		
		a=450;
		b=78;
		
		
		setcolor(9);
		line(a,b,a+430,b);
		
		
		cout<<"\nGRAFICA NO DIRIGIDA";
		int i, j, Ver, Ver1, cont, sumaProd, k, kk, nC, nF, ii, jj;   
		
		
		//Inicio Proceso LLenar Dibujar Mat

				//Dibujar grafica de mas de 2 vertices
				//Tomamos memoria del monticulo para las coordenadas
				iVerx=new int[noVert];
				iVery=new int[noVert];
				
				iVerx1=new int[noVert];
				iVery1=new int[noVert];
				
				
				nC=nL;
				nF=nV;
				
				//Matriz de Incidencia
				//Reservamos memoria para la matriz de Incidencia
				Mat=new int*[nF];
				for(i=0;i<nF;i++){
					Mat[i]=new int[nC]; 	
				}
				//Inicializamos en 0
				for(i=0;i<nF;i++){
					for(j=0;j<nC;j++){
						*(*(Mat+i)+j)=0; //Mat[i][j]=0 
					}
				}
			
				//Matriz de Adyacencia
				//Reservamos memoria para la matriz de Adyacencia
				MatA=new int*[nF];
				for(i=0;i<nF;i++){
					MatA[i]=new int[nF]; 	
				}
				//Inicializamos en 0
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						*(*(MatA+i)+j)=0; //MatA[i][j]=0 
					}
				}

				//Asignamos las coordenadas de x, y
				for(i=0;i<noVert;i++){
					Ver=i+1;
					x=(p2/2)+(R*cos(2*PI*Ver/noVert));
					y=(p1/2)+(R*sin(2*PI*Ver/noVert));
					iVerx[i]=x;
					iVery[i]=y;	
		
					iVerx1[i]=x+20;
					iVery1[i]=y+20;
					
					setcolor(2);
					circle(iVerx[i],iVery[i],20);
					
					fflush(stdin);
					char cer[3];
						
					int nroDig=0;
					int auxx=Ver;
						
						
					while(auxx>0){
						auxx=auxx/10;
						nroDig++;
					}
											
					for(int iy=0;iy<=nroDig;iy++){
							
						cer[iy]=Ver+'0';
							
						if(iy==nroDig){
						cer[iy]='\0';
						}	
					}
						
					char cad[3];
					strcpy(cad,cer);
						
					setcolor(2);
					settextstyle(4,0,2);
					outtextxy(iVerx[i],iVery[i],cad);
			
					
				}
				
				for(i=0;i<nL;i++){
				
					cout<<"\nLa linea "<<i+1<<" sale del vertice: ";
					cin>>Ver;
				
						//Llevamos la cuenta de cuantas veces se usa el vertice
						arregloVert[Ver-1]=arregloVert[Ver-1]+1;	
						//Lenamos elemento de la matriz de Incidencia			
						*(*(Mat+Ver-1)+i)=1;	
				
					cout<<"y llega al vertice: ";
					cin>>Ver1;
				
						//Llevamos la cuenta de cuantas veces se usa el vertice
						arregloVertLl[Ver1-1]=arregloVertLl[Ver1-1]+1;
						//Lenamos elemento de la matriz de Incidencia
						*(*(Mat+Ver1-1)+i)=1;
					if(Ver==Ver1){
						//Dibujamos Bucle
						
						bucl[i]=1;
						
						
						setcolor(9);
						circle(iVerx[Ver-1],iVery[Ver-1],30);
						
						fflush(stdin);
						char cer1[3];
						int ic=i+1;
						
						
						
						int nroDig1=0;
						int auxx1=ic;
						
						
						while(auxx1>0){
							auxx1=auxx1/10;
							nroDig1++;
						}
						
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig1;iy1++){
							
							cer1[iy1]=ic+'0';
							
							if(iy1==nroDig1){
								cer1[iy1]='\0';
							}	
							
						}
						char cad1[3];
						strcpy(cad1,cer1);
						
						setcolor(9);
						settextstyle(4,0,2);
						
						outtextxy(iVerx[Ver-1]-30,iVery[Ver-1]+30,cad1);
				
						//Lenamos elemento de la matriz de Incidencia
						*(*(Mat+Ver-1)+i)=1;
						
					}else{
						//Dibujamos linea
					
						setcolor(9);
						line(iVerx[Ver-1],iVery[Ver-1],iVerx[Ver1-1],iVery[Ver1-1]);
						fflush(stdin);
						char cer1[3];
					
						int ic=i+1;
						
						int nroDig1=0;
						int auxx1=ic;
						
						
						while(auxx1>0){
							auxx1=auxx1/10;
							nroDig1++;
						}
						
						
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig1;iy1++){
							
							cer1[iy1]=ic+'0';
							
							if(iy1==nroDig1){
								cer1[iy1]='\0';
							}	
						}
					
						char cad1[3];
						strcpy(cad1,cer1);
						
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx[Ver-1])+(((iVerx[Ver1-1])-(iVerx[Ver-1]))/(2))),((iVery[Ver-1])+(((iVery[Ver1-1])-(iVery[Ver-1]))/(2))),cad1);
						
						
						
					}
								
					//Lenamos elemento de la matriz de Adyacencia
					
					*(*(MatA+Ver1-1)+Ver-1)=1;
					*(*(MatA+Ver-1)+Ver1-1)=1;
					
				}
				
				//Matriz Transpuesta de Adyacencia
				//Reservamos memoria para la matriz de Transpuesta de Adyacencia
				MatAd=new int*[nF];
				for(i=0;i<nF;i++){
					MatAd[i]=new int[nF]; 	
				}
				//Hacemos la transpuesta
				for(i=0; i<nF; i++){
					for(j=0; j<nF; j++){					
						*(*(MatAd+i)+j)=*(*(MatA+j)+i); //MatAd[i][j]=MatA[j][i]
					}
				}
				
				//Matriz de Accesibilidad
				//Reservamos memoria para la matriz de Accesibilidad
				MatAc=new int*[nF];
				for(i=0;i<nF;i++){
					MatAc[i]=new int[nF]; 	
				}
				//La nicializamos igual que la de Adyacencia
				for(i=0;i<nF;i++){
					for(j=0;j<nC;j++){
						*(*(MatAc+i)+j)=*(*(MatAd+i)+j); //MatAc[i][j]=MatAd[i][j] 
					}
				}
				
				//Hacemos la suma de potencias sucesivas hasta n-1, noVert-2
				//Reservamos memoria para la matriz aux de Accesibilidad
				MatAcaux=new int*[nF];
				for(i=0;i<nF;i++){
					MatAcaux[i]=new int[nF]; 	
				}
				//La nicializamos igual que la de Adyacencia
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						*(*(MatAcaux+i)+j)=*(*(MatAd+i)+j); //MatAcux[i][j]=MatAd[i][j]
					}
				}
						
				//Hacemos la potencia hasta (n^2 + n)/2
				//Reservamos memoria para la matriz Aux
				Aux=new int*[nF];
				for(i=0;i<nF;i++){
					Aux[i]=new int[nF]; 	
				}
				
				
				int pot=((nF^2)+nF)/2;
				
				for(int z=0;z<pot;z++){
					if(z<1){
						
						for (int i=0;i<nF;i++){
							for (int j=0;j<nF;j++){ 
								*(*(MatAcaux+i)+j)=0;		
								for (int k=0;k<nF;k++){
									*(*(MatAcaux+i)+j)=*(*(MatAcaux+i)+j)+(*(*(MatAd+i)+k))*(*(*(MatAc+k)+j)); //MatAd=X * MatAc=X -> MatAcaux=X^2	
								}
							}
						}
						
						for(int i=0;i<nF;i++){
							for(int j=0;j<nF;j++){
								*(*(MatAc+i)+j)=*(*(MatAc+i)+j)+(*(*(MatAcaux+i)+j));	
							}
						}
					
					}else{	
						int conta;
						conta=z%2;
						if(conta>0){
							//Casos nones 1, 3, 5
							for (int i=0;i<nF;i++){
								for (int j=0;j<nF;j++){ 
									*(*(Aux+i)+j)=0;	
									for (int k=0;k<nF;k++){
										*(*(Aux+i)+j)=*(*(Aux+i)+j)+*(*(MatAd+i)+k)*(*(*(MatAcaux+k)+j)); //MatAd=X * MatAcauc=X^2 -> Aux=X^3
									}
								}
							}
						
							for(int i=0;i<nF;i++){
								for(int j=0;j<nF;j++){
									*(*(MatAc+i)+j)=*(*(MatAc+i)+j)+*(*(Aux+i)+j);
								}
							}
							
						}else{
							//Casos pares 2, 4, 6
							for (int i=0;i<nF;i++){
								for (int j=0;j<nF;j++){ 
									*(*(MatAcaux+i)+j)=0;	
									for (int k=0;k<nF;k++){
										*(*(MatAcaux+i)+j)=*(*(MatAcaux+i)+j)+*(*(MatAd+i)+k)*(*(*(Aux+k)+j)); //MatAd=X * Aux=X^3 -> MatAcaux=X^4
									}
								}
							}
						
							for(int i=0;i<nF;i++){
								for(int j=0;j<nF;j++){
									*(*(MatAc+i)+j)=*(*(MatAc+i)+j)+*(*(MatAcaux+i)+j);	
								}
							}
						
						}
					}
						
				}
		
				//Matriz de Incidencia
				cout<<"\nMATRIZ DE INCIDENCIA\n";
				for(i=0;i<nF;i++){
					for(j=0;j<nC;j++){
						
						
						if(*(*(Mat+i)+j)==2){
							cout<<" +-1";
						}else if(*(*(Mat+i)+j)==-1){
							cout<<"  "<<*(*(Mat+i)+j);
						}else{
							cout<<"   "<<*(*(Mat+i)+j);	
						}
							
					}
					cout<<"\n";
				}
				
				//Matriz de Adyacencia
				cout<<"\nMATRIZ DE ADYACENCIA\n";
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
					cout<<"  "<<*(*(MatAd+i)+j);	
					}
					cout<<"\n";
				}
				
				//Matriz de Accesibilidad
				cout<<"\nMATRIZ DE ACCESIBILIDAD\n";
				for(i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						
					if(*(*(MatAc+i)+j)>0){
						cout<<"  +";			
					}else{
						cout<<"  0";
					}		
					}
					cout<<"\n";
				}
				
				//Fin Proceso LLenar Dibujar Mat
			
				//Inicio Proceso Info de Vertices
			
				cout<<"\n\n\tProcederemos a otorgar la informacion de la Grafica\n";
				cout<<"\n\tInformacion de Vertices: ";
				
				cout<<"\n\n\tGrados de los Vertices:";
				for(int i=0;i<nV;i++){
					cout<<"\nEl grado del vertice "<<i+1<<" es: ";
					cout<<arregloVert[i]+arregloVertLl[i];
				}
				
				cout<<"\n\n\tTenemos los sig. vertices aislados:";
				for(int i=0;i<nV;i++){
					if((arregloVert[i]==0)&&(arregloVertLl[i]==0))
					cout<<"\nEl Vertice "<<i+1<<" es aislado";
				}
				
				
				int colgantev=0;
				//Inicial= Grado interno 0 y externo distinto de 0
				cout<<"\n\n\tTenemos los sig. vertices Colgantes:";
				for(int i=0;i<nV;i++){
					if((arregloVertLl[i]==1)||(arregloVert[i]==1)){
						
						
						//cout<<"\nMATRIZ DE INCIDENCIA\n";
						
						for(int j=0;j<nC;j++){
						
						
						if(*(*(Mat+i)+j)==1){
							colgantev=colgantev+1;
						}
							
						}
						
						
						if(colgantev==1){
						cout<<"\nEl Vertice "<<i+1<<" es Colgante";
						colgantev=0;	
						}
				
					}
				}
		
				cout<<"\n\n\tInformacion de Lineas: ";
				
				//Lineas Paralelas
				cout<<"\n\n\tTenemos las sig. lineas Paralelas:";	
				//Matriz Aux1
				//Reservamos memoria para la matriz Aux1
				Aux1=new int*[nF];
				for(int i=0;i<nF;i++){
					Aux1[i]=new int[nC]; 	
				}
				//Inicializamos igual que la de incidencia
				for(int i=0;i<nF;i++){
					for(int j=0;j<nC;j++){
						*(*(Aux1+i)+j)=*(*(Mat+i)+j); //Mat[i][j]=0 
					}
				}
		
				for(int ii=0;ii<nC-1;ii++){
				int J;
				J=ii+1;	
						
				for( J;J<nC;J++){  // [n][0]
			
					for(int I=0;I<nF;I++){  //[n][1]

					
						if(J!=nC){
					
							if((*(*(Mat+I)+ii))==(*(*(Aux1+I)+J))){
						
							sig=I+1;
						
							if(*(*(Mat+I)+ii)==1){
				
							Lle1=I+1;
							
							if(Sal1==0){
								Sal1=Lle1;
								
							}
							
								
							}
						
							}else {
								I=nF;	
							}
							
							
							if(sig==nF){
						cout<<"\n\nLas lineas "<<ii+1<<" y "<<J+1<<" son paralelas";
				
						sig=0;
					
						paralelas=paralelas+1;
						//Dibujamos linea
				
						setcolor(9);
						line(iVerx[Sal1-1],iVery[Sal1-1],iVerx[Lle1-1],iVery[Lle1-1]);
						
						fflush(stdin);
						char cer1[3];
						int ic=ii+1;
						int nroDig1=0;
						int auxx1=ic;
						while(auxx1>0){
							auxx1=auxx1/10;
							nroDig1++;
						}
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig1;iy1++){
							cer1[iy1]=ic+'0';
							if(iy1==nroDig1){
								cer1[iy1]='\0';
							}	
						}
						char cad1[3];
						strcpy(cad1,cer1);
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx[Sal1-1])+(((iVerx[Lle1-1])-(iVerx[Sal1-1]))/(2))),((iVery[Sal1-1])+(((iVery[Lle1-1])-(iVery[Sal1-1]))/(2))),cad1);
						setcolor(9);
						line(iVerx1[Sal1-1],iVery1[Sal1-1],iVerx1[Lle1-1],iVery1[Lle1-1]);
						fflush(stdin);
						char cer11[3];
						int iic=J+1;
						int nroDig11=0;
						int auxx11=iic;
						while(auxx11>0){
							auxx11=auxx11/10;
							nroDig11++;
						}
						//Dibujamos nombre linea
						for(int iy1=0;iy1<=nroDig11;iy1++){
							cer11[iy1]=iic+'0';	
							if(iy1==nroDig11){
								cer11[iy1]='\0';
							}	
						}
						char cad117[3];
						strcpy(cad117,cer11);
						setcolor(9);
						settextstyle(4,0,2);
						outtextxy(((iVerx1[Sal1-1])+(((iVerx1[Lle1-1])-(iVerx1[Sal1-1]))/(2))),((iVery1[Sal1-1])+(((iVery1[Lle1-1])-(iVery1[Sal1-1]))/(2))),cad117);					
									
					}
								
						}

				
																			
				}

				
					}		
					
				}	

			//Bucles
				
				cout<<"\n\n\tTenemos los sig. Bucles:";
			
				for(int i=0;i<nL;i++){
					if(bucl[i]==1){
						cout<<"\nLa linea "<<i+1<<" es un bucle";
					}
				}
			
				//Clasificacion de la Grafica
				
				int Cone=0, Reg, Comp, Comp1, bu=0, zimple;
					
				cout<<"\n\n\tClasificacion de la Grafica: ";
				
				cout<<"\n\nSimple: ";
				
				for(int i=0;i<nL;i++){
					if(bucl[i]==1){
						bu=bu+1;
					}
				}
				
				if(bu>0 && paralelas>0){
					cout<<"\nEs una grafica general ya que tiene: "<<bu<<" bucles y "<<paralelas+1<<" lineas paralelas";
					
				}else if(bu>0){
					cout<<"\nEs una grafica general ya que tiene: "<<bu<<" bucles";
				}else if(paralelas>0){
					cout<<"\nEs una grafica general ya que tiene: "<<paralelas+1<<" lineas paralelas";
				}else {
					cout<<"\nEs una grafica Simple ya que no tiene bucles o lineas paralelas";
					zimple=1;
				}
				
				
				cout<<"\n\n Conectada: ";
				
				int Co;
				//Matriz de Accesibilidad
				for(int i=0;i<nF;i++){
					for(j=0;j<nF;j++){
						
					if(*(*(MatAc+i)+j)==0){
						Cone=Cone+1;	
					}
					}
				}
				if(Cone>0){
					cout<<"\nEs una Grafica Desconectada ya que al menos un elemento de la matriz Accesibilidad es 0";
				} else{
					cout<<"\nEs una Grafica Conectada ya que todos los elementos de la matriz Accesibilidad son +";
					Co=1;
				}		
			
				cout<<"\n\n Regular: ";
			
				int ex=0;
				for(int i=0;i<nV-1;i++){
					if(arregloVert[i]==arregloVert[i+1]){
						ex=0;
					}else{
						ex=1;
					}
				}
				int in=0;
				for(int i=0;i<nV-1;i++){
					if(arregloVertLl[i]==arregloVertLl[i+1]){
						in=0;	
					}else{
						in=1;
					}
				}
				if(ex==0&&in==0){
					cout<<"\nEs una Grafica Regular ya que los grados de los vertices son iguales";
				}
				
				cout<<"\n\n Completa: ";
					
				for(int i=0;i<nF;i++){
					for(int j=0;j<nF;j++){
						if(i>j){
							if(*(*(MatAd+i)+j)==1){
								Comp=0;
							}else{
								Comp=1;
							}
						}
					}
				}
				
				for(int i=0;i<nF;i++){
					for(int j=0;j<nF;j++){
						if(i<j){
							if(*(*(MatAd+i)+j)==1){
								Comp1=0;
							}else{
								Comp1=1;
							}
						}
					}
				}		
				
				if(Comp==0&&Comp1==0){
					cout<<"\nEs una Grafica Completa ya que todos los elementos debajo y arriba de la diagonal son 1";
				}
		
				cout<<"\n\n Arbol: ";
		
				//Arbol
				
				int arbol;
				
				arbol=noVert-1;
				
				
				if(nL==arbol&&zimple==1){
					cout<<"\nEs un Arbol ya que ya que es simple y tiene n-1 lineas";
				}

			cout<<"\nHora de liberar memoria";
		
		
		for(int i=0;i<nF;i++){
			delete[] MatAc;
		}
		delete[] MatAc;
		
		for(int i=0;i<nF;i++){
			delete[] MatAcaux;
		}
		delete[] MatAcaux;
		
		for(int i=0;i<nF;i++){
			delete[] Aux;
		}
		delete[] Aux;
		
		for(int i=0;i<nF;i++){
			delete[] MatA;
		}
		delete[] MatA;

		for(int i=0;i<nF;i++){
			delete[] MatAd;
		}
		delete[] MatAd;

		for(int i=0;i<nC;i++){
			delete[] Aux1;
		}
		delete[] Aux1;


		for(int i=0;i<nC;i++){
			delete[] Mat;
		}
		delete[] Mat;
		
		delete[] iVerx; 
		delete[] iVery;
		delete[] iVerx1; 
		delete[] iVery1;
		delete[] arregloVert;
		delete[] arregloVertLl;
		delete[] bucl;
		

		cout<<"\nLiberada";		
			//}
	//Cierre notas


	cout<<"\nDeseas cerrar el grafico teclea";
	getch();
	cleardevice();

	cout<<"\nGrafico cerrado";
		
		

	}



	cout<<"\n\n\t\Desea hacer otra grafica? 1=Si, 0=No";
	cin>>resp;

	}while(resp>0);
	cout<<"\n\n	Gracias por utilizar este programa, buen dia. :)";


	cout<<"\n\nFinalizando...";


	closegraph();
	cout<<"\n\nFinalizado";
}
