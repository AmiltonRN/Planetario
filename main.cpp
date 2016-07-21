#include <windows.h>
#include <GL/glut.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

/** -------------------------------------------------------
 ** Desenvolvido para a Disciplina de Computação Grafica **
 ** Por: Amilton Nunes, Railana Santana                  ** 
 ** -------------------------------------------------------
 */

//GLint view_w, view_h, primitiva;

//posição inicial do quadrado 1 e posicao do mouse
GLfloat x1=-320,  x2= -300, y1=300 , y2=320;
GLfloat x1m= 25 , x2m = 45, y1m=15, y2m=35;

//posição inicial do quadrado 2 e posicao do mouse
GLfloat z1=-320,  z2= -300, w1=270 , w2=290;
GLfloat z1m= 25 , z2m = 45, w1m=45, w2m=65;

//posição inicial do quadrado 3 e posicao do mouse
GLfloat p1=-320,  p2= -300, q1=240 , q2=260;
GLfloat p1m= 25 , p2m = 45, q1m=75, q2m=95;

//posição inicial do quadrado 4 e posicao do mouse
GLfloat o1=-320,  o2= -300, l1=210 , l2=230;
GLfloat o1m=25 , o2m = 45, l1m=100, l2m=115;

//posição inicial do quadrado 5 e posicao do mouse
GLfloat h1=-320,  h2= -300, j1=180 , j2=200;
GLfloat h1m=25 , h2m = 45, j1m=125, j2m=145;

//posição inicial do quadrado 6 e posicao do mouse
GLfloat a1=-320,  a2= -300, b1=150 , b2=170;
GLfloat a1m=25 , a2m = 40, b1m=155, b2m=175;

// fim botões
//rotação;
GLfloat rotaSol = 0,rotaMercurio = 0, rotaVenus = 0, rotaTerra = 0, rotaMarte = 0, rotaJupiter = 0, rotaCometa = 0;
//radius;
GLfloat radSol = 40,radMercurio = 6, radVenus = 8, radTerra = 9,radMarte = 6,radJupiter = 18, rdCometa = 12, gl_Translate = 200;

// ILUMINAÇÃO
GLfloat mat_diffuse [] = {0.0, 0.0, 1.0, 1.0};
GLfloat mat_specular [] = {0.5, 0.5, 0.5, 1.0};
GLfloat mat_shininess [] = {50};
GLfloat mat_emission [] = {0.5, 0.2, 0.2, 1.0};

// variaveis de controle;
double velocidade = 1.0;
int stop = 0;
int ok = 0;

// reiniciando os valores das variaveis;
void inicializa(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    rotaSol = 0;
    rotaMercurio = 0;
    rotaVenus = 0;
    rotaTerra = 0;
    rotaMarte = 0;
    rotaJupiter = 0;
    rotaCometa = 0;
    radSol = 40;
    radMercurio = 6;
    radVenus = 8;
    radTerra = 9;
    radMarte = 6;
    radJupiter = 18;
    rdCometa = 12;
    int stop = 0;
    ok = 0;
    gl_Translate = 200;
}

// limpa as cores da tela;
void init(void) {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glShadeModel (GL_SMOOTH | GL_FLAT); // Habilita sombreamento suavizado
}

// redimensionar a tela;
void redimensionar(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-350, 350, -350, 350, -350, 350);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    glDepthFunc(GL_LEQUAL); 
    gluLookAt (0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	 
}

// iluminação dos objetos e da tela;
void iluminacao() {
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

/*PLANETAS*/
void sol() {
    glColor3f(1.0, 0.8, 0.0);
    glRotatef ((GLfloat) 180, 0.0, 1.0, 0.0);
    glutSolidSphere(radSol, 60, 60); // renderiza um solido;
}

// cria o solido do planeta mercurio
void mercurio() {
    glColor3f(0.4, 0.4, 0.4);
    glRotatef(rotaMercurio, 0, 0, 1);
	glTranslatef(49, 0, 0); 
    glutSolidSphere(radMercurio, 60, 60);  // renderiza um solido;
}

// cria o solido do planeta venus
void venus() {
    glColor3f(1.0, 0.2, 0.0);
    glRotatef(rotaVenus, 0, 0, 1);
	glTranslatef(70, 0, 0); 
    glutSolidSphere(radVenus, 60, 60);
}

// cria o solido do planeta terra
void terra() {
    glColor3f(0.0, 0.4, 1.0);
	glRotatef(rotaTerra, 0, 0, 1);
	glTranslatef(91, 0, 0);    
    glutSolidSphere(radTerra, 60, 60);
}

// cria o solido do planeta marte
void marte() {
    glColor3f(0.2, 0.7, 0.4);
	glRotatef(rotaMarte, 0, 0, 1);
	glTranslatef(110, 0, 0);    
    glutSolidSphere(radMarte, 60, 60);
}

// cria o solido do planeta jupiter
void jupiter() {
    glColor3f(0.2, 0.2, 0.2);
	glRotatef(rotaJupiter, 0, 0, 1);
	glTranslatef(140, 0, 0);    
    glutSolidSphere(radJupiter, 60, 60);
}

// criando o cometa
void cometa() {
    glColor3f(1.0,2.0,10.0);
	glRotatef(rotaCometa-120, 0, 1, 1);
	glTranslatef(gl_Translate, 0, 0); 
	glutSolidSphere(rdCometa,7,3);
}

// Desenha os "botoes" na tela	
void desenhaQuadrado1(void){    
	 glLoadIdentity();
	 
	 glColor3f(1.0, 0.2, 0.2);
	 glPushMatrix();
	 	glBegin(GL_QUADS);
	        glVertex2f(x1, y1);
	        glVertex2f(x1, y2);
	        glVertex2f(x2, y2);
	        glVertex2f(x2, y1);         
	     glEnd();
     glPopMatrix();
     
     glColor3f(0.5, 0.7, 0.2);
     glPushMatrix();
	 	glBegin(GL_QUADS);     
	    	glVertex2f(z1, w1);
	        glVertex2f(z1, w2);
	        glVertex2f(z2, w2);
	        glVertex2f(z2, w1);        
	     glEnd();
     glPopMatrix();
     
     glColor3f(1.0, 0.5, 1.0);
     glPushMatrix();
	     glBegin(GL_QUADS);  
	        glVertex2f(p1, q1);
	        glVertex2f(p1, q2);
	        glVertex2f(p2, q2);
	        glVertex2f(p2, q1);      
	     glEnd();
     glPopMatrix();
     
     glColor3f(0.6, 1.0, 0.7);
     glPushMatrix();
     glBegin(GL_QUADS);  
            glVertex2f(o1, l1);
            glVertex2f(o1, l2);
            glVertex2f(o2, l2);
            glVertex2f(o2, l1);     
     glEnd();
     glPopMatrix();
     
     glColor3f(1.0, 0.4, 0.2);
     glPushMatrix();
	     glBegin(GL_QUADS);  
	     	glVertex2f(h1, j1);
	        glVertex2f(h1, j2);
	        glVertex2f(h2, j2);
	        glVertex2f(h2, j1);      
	     glEnd();
	 glPopMatrix();
     
     glColor3f(1.0, 0.7, 0.3);
     glPushMatrix();
	     glBegin(GL_QUADS);  
	     	glVertex2f(a1, b1);
	        glVertex2f(a1, b2);
	        glVertex2f(a2, b2);
	        glVertex2f(a2, b1);     
	     glEnd();
     glPopMatrix();
     
     glutPostRedisplay();
}

// desenhas as estrelas em posiçoes aleatorias na tela;
void estrelas() {
    int i, j, k;
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POINTS);
	    for(int h=0; h < 50; h++) {
	        i = (rand() % 300);
	        j = (rand() % 300);
	        k = (rand() % 300);
	        glColor3f(1, 1, 1);
	        glVertex3f(i, j, k);
	        glVertex3f(i, -j, k);
	        glColor3f(0, 1, 0);
	        glVertex3f(-i, -j, k);
	        glColor3f(0, 0, 1);
	        glVertex3f(-i, j, -k);
	    }
	glEnd();
    desenhaQuadrado1();
}

// incrementa ou decrementa a velocidade dos planetas e do cometa;
void movimentar(void){
	if(stop == 1) {
	    rotaMercurio = rotaMercurio + 0.685;
	    rotaVenus = rotaVenus + 0.267;
	    rotaTerra = rotaTerra + 0.165;
	    rotaMarte = rotaMarte + 0.088;
	    rotaJupiter = rotaJupiter + 0.014;
	    
	    if(rotaCometa < 250.0 && ok == 0) {
			rotaCometa = rotaCometa + 0.1215;
		} else {
			if((rand()%5998) % 23 == 0 && gl_Translate != 200 && ok == 1){
				ok = 0;
				rotaCometa =0;
				gl_Translate = 200;
			} else {
			    ok = 1;
			    gl_Translate = 900;
			}
		}
	} else if(stop == 2) {
	    rotaMercurio = rotaMercurio + (0.685 * velocidade);
	    rotaVenus = rotaVenus + (0.267 * velocidade);
	    rotaTerra = rotaTerra + (0.165 * velocidade);
	    rotaMarte = rotaMarte + (0.088 * velocidade);
	    rotaJupiter = rotaJupiter + (0.014 * velocidade);
	    
		if(rotaCometa < 250.0 && ok == 0) {
			rotaCometa = rotaCometa + (0.1215 * velocidade);
		} else {
			if((rand()%5998) % 23 == 0 && gl_Translate != 200 && ok == 1) {
				ok = 0;
				rotaCometa = 0;
				gl_Translate = 200;
			} else {
			    ok = 1;
			    gl_Translate = 900;
			}
		}
	}
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
  	iluminacao();
  	estrelas();
   
    // desenha o sol e os aneis ao redor do sol;
    // o glutSolidTorus gera os aneis;
    glPushMatrix();
        sol();
        glRotatef(rotaSol, 0, 0, 1);
	    glutSolidTorus(1.0, 49, 2,100);
	    glutSolidTorus(1.0, 72, 2,100);
	    glutSolidTorus(1.0, 92, 2,100);
	    glutSolidTorus(1.0, 110, 2,100);
	    glutSolidTorus(1.0, 140, 2,100);
     glPopMatrix();
    
    // desenha mercurio na tela;
    glPushMatrix();
	    mercurio();
    glPopMatrix();
    
    // desenha venus na tela;
    glPushMatrix();
	    venus();
    glPopMatrix();

	// desenha a terra;
    glPushMatrix();
	    terra();
    glPopMatrix();

	// desenha marte;
    glPushMatrix();
	    marte();
    glPopMatrix();

	// desenha jupter na tela;
    glPushMatrix();
	    jupiter();
    glPopMatrix();
    
    // desenha o cometa na tela;
    glPushMatrix();
    	cometa();
    glPopMatrix();	
	
	// chamada da função;
	movimentar();
	
    glutSwapBuffers(); // desenha no buffer escondido e depois mostra o desenho pronto.   
}

// controle de açoes dos "botoes";
void gerenciaMouse(int button, int state, int x, int y){        
    if (button == GLUT_LEFT_BUTTON){  
           //ligar           
           if(x>=x1m && x<=x2m && y>=y1m && y<=y2m ){
                stop = 1;
                glutPostRedisplay(); 
           }  
           //desligar
           if(x>=z1m && x<=z2m && y>=w1m && y<=w2m ){
                stop = 0;
           }
           //iniciar do zero
           if(x>=p1m && x<=p2m && y>=q1m && y<=q2m ){
                stop = 1;
                inicializa();
                glutPostRedisplay(); 
           } 
           //aumenta a velocidade
           if(x>=o1m && x<=o2m && y>=l1m && y<=l2m && stop != 0 ){
                velocidade*=1.05;
                stop=2;
           }
           //diminui velocidade
           if(x>=h1m && x<=h2m && y>=j1m && y<=j2m && stop != 0 &&  velocidade >= 0.1){
                velocidade/=1.05;
                stop=2;
           }
           //sair
           if((x>=a1m && x<=a2m) && (y>=b1m && y<=b2m)){
                exit(0);
           }        
     }
     
    glutPostRedisplay(); // redesenha a tela;
}   

//função que direciona o item clicado para a função especificada;
void right_menu(int id) {
	switch(id) {
		case 1:
			stop = 1;
         	glutPostRedisplay();
		break;
		case 2:
			stop = 0;
		break;
		case 3:
			stop = 1;
	        inicializa();
	        glutPostRedisplay();
		break;
		case 4:
		    velocidade*=1.05;
	    	stop = 2;
	    	movimentar();
		break;
		case 5:
	    	velocidade/=1.05;
	    	stop = 2;
	    	movimentar();		
		break;
		case 6:
			exit(0);
		break;	
	}
}

// funcao principal do programa;
int main(int argc, char *argv[]) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("SISTEMA SOLAR"); 
    init();
    glutDisplayFunc(display);
	glutReshapeFunc(redimensionar); // função de redesenho;
    glutMouseFunc(gerenciaMouse);  // gerenciar os botoes e o click do mouse;

	// adicionando o menu do botao direito do mouse;
    glutCreateMenu(right_menu);
    glutAddMenuEntry("Iniciar", 1);
    glutAddMenuEntry("Parar", 2);
    glutAddMenuEntry("Reiniciar", 3);
    glutAddMenuEntry("Velocidade +", 4);
    glutAddMenuEntry("Velocidade -", 5);
    glutAddMenuEntry("Sair", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	//-----------------------------------------------------------
	// responsavel por remover a opção de maximizar e minimizar a janela e impedir que o usuario redimensione a tela;
	//http://www.portugal-a-programar.pt/topic/2666-c-e-opengl-ajuda-nao-deixar-redimensionar-a-janela-resolvido/
	HWND hWnd=FindWindow(TEXT("GLUT"), TEXT("SISTEMA SOLAR"));
    LONG gwl=GetWindowLong(hWnd, GWL_STYLE);
    gwl&=(~WS_MAXIMIZEBOX);
    gwl&=(~WS_MINIMIZEBOX);
    gwl&=(~WS_THICKFRAME);
    SetWindowLong(hWnd, GWL_STYLE, gwl);
    //-----------------------------------------------------------
    PlaySound(".\\planeta.wav", NULL,  SND_ASYNC | SND_FILENAME | SND_LOOP); // som de fundo do programa;
    glutMainLoop(); // entrar em um processo de loop;	
}
