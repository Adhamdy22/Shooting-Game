#include <GL/glut.h>
#include<math.h>
#include <cstdlib>

// G KEY USED TO SHOOT FIRST POINT INTO HEAD OF HOME 
// F KEY USED TO SHOOT FOURTH POINT INTO DOOR OF HOME 
// D KEY USED TO SHOOT THIRD POINT INTO RIGHT WINDOW OF HOME 
// S KEY USED TO SHOOT SECOND POINT INTO LEFT WINDOW OF HOME 
// A KEY USED TO SHOOT LEFT BALL INTO  ALL HOME OR ANY THING STILL IN HOME NOT DAMAGED 
// ESC KEY USED TO CLOSE THE GAME
//UP KEY TO MOVE UP
//DOWN KEY TO MOVE DOWN
//LEFT KEY TO MOVE LEFT
//RIGHT KEY TO MOVE RIGHT
//ENJOY THE GAME

float rlang = 0, rlangsp = 0.5;
float llang = 0, llangsp = 0.5;
float mspeedx = 1.0;
float mposx = 0;
float mposy = 0;
float mspeedy = 1.0;
float righthandpointx = 5.0;
float righthandpointx2 = 5.0;
float pointballx = -3.4;

float homey = 0.9;
float heady = 0.9;

float window1y = 1.1;
float window2y = 2.6;

float doory = 1.9;

float lefthandpointx = 5.0;
float lefthandpointx2 = 5.0;

int score = 0;




bool Gkey = false;
bool fkey = false;
bool dkey = false;
bool skey = false;
bool akey = false;

bool lose = true;

bool Win = true;

bool lose2 = true;

void body()
{
    //body
    glColor3f(0.3f, 0.2f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-3.4, -3.8);
    glVertex2f(3.4, -3.8);
    glVertex2f(3.4, 3.2);
    glVertex2f(-3.4, 3.2);
    glEnd();
}
void righthand() {
    //right hand
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(3.4, 0.8);
    glVertex2f(3.4, -0.1);
    glVertex2f(5.5, 0.0);
    glVertex2f(5.0, -1.0);
    glEnd();
}
void lefthand() {
    //left hand
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-3.4, 0.8);
    glVertex2f(-3.4, -0.1);
    glVertex2f(-5.5, 0.0);
    glVertex2f(-5.0, -1.0);
    glEnd();
}

void centerline() {
    //line center
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-3.4, -2.8);
    glVertex2f(3.4, -2.8);
    glEnd();
}

void righthandline() {
    //line right
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(4.9, -0.9);
    glVertex2f(4.9, 0.0);
    glEnd();
}

void lefthandline() {
    //line left
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-4.9, -0.9);
    glVertex2f(-4.9, 0.0);
    glEnd();
}

void rightblackeye() {
    //right black circle
    glPointSize(3);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(2.1f + 1.0f * cos(deginrad), 2.1f + 1.0f * sin(deginrad));
    }
    glEnd();
}
void rightgreeneye() {
    //right green circle
    glPointSize(3);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(2.1f + 0.3f * cos(deginrad), 2.1f + 0.3f * sin(deginrad));
    }
    glEnd();
}

void leftblackeye() {
    //left black circle
    glPointSize(3);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-2.1f + 1.0f * cos(deginrad), 2.1f + 1.0f * sin(deginrad));
    }
    glEnd();
}

void leftgreeneye() {
    //left green circle
    glPointSize(3);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-2.1f + 0.3f * cos(deginrad), 2.1f + 0.3f * sin(deginrad));
    }
    glEnd();
}

void nose() {
    //centre yellow semi circle
    glPointSize(3);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-0.1f + 0.5f * cos(deginrad), 0.4f + 0.5f * sin(deginrad));
    }
    glEnd();
}

void mouth() {
    //centre blue semi circle
    glPointSize(3);
    glColor3f(1.0f, 0.1f, 0.6f);
    glBegin(GL_POINTS);
    for (int i = 180;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-0.1f + 0.5f * cos(deginrad), -0.6f + 0.5f * sin(deginrad));
    }
    glEnd();
}

void leftfoot() {
    //left foot
    glPointSize(3);
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-2.5f + 0.9f * cos(deginrad), -3.7f + 0.9f * sin(deginrad));
    }
    glEnd();
}

void rightfoot() {
    //right foot
    glPointSize(3);
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(2.5f + 0.9f * cos(deginrad), -3.7f + 0.9f * sin(deginrad));
    }
    glEnd();
}

void rightear() {
    //right ear
    glPointSize(3);
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(4.1f + 0.7f * cos(deginrad), 2.0f + 0.7f * sin(deginrad));
    }
    glEnd();
}

void leftear() {
    //left ear
    glPointSize(3);
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-4.1f + 0.7f * cos(deginrad), 2.0f + 0.7f * sin(deginrad));
    }
    glEnd();
}

void hair() {
    //hair 
    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-2.7f + 0.7f * cos(deginrad), 3.3f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-2.7f + 0.7f * cos(deginrad), 3.6f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-2.7f + 0.7f * cos(deginrad), 3.9f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(0.0f + 0.7f * cos(deginrad), 3.3f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(0.0f + 0.7f * cos(deginrad), 3.6f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(0.0f + 0.7f * cos(deginrad), 3.9f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-1.2f + 0.7f * cos(deginrad), 3.3f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-1.2f + 0.7f * cos(deginrad), 3.6f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-1.2f + 0.7f * cos(deginrad), 3.9f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(2.7f + 0.7f * cos(deginrad), 3.3f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(2.7f + 0.7f * cos(deginrad), 3.6f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(2.7f + 0.7f * cos(deginrad), 3.9f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(1.2f + 0.7f * cos(deginrad), 3.3f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(1.2f + 0.7f * cos(deginrad), 3.6f + 0.7f * sin(deginrad));
    }
    glEnd();

    glPointSize(3);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 180;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(1.2f + 0.7f * cos(deginrad), 3.9f + 0.7f * sin(deginrad));
    }
    glEnd();
}
void square() {


    glColor3f(0.90f, 0.91f, 0.98f);
    glBegin(GL_QUADS);
    glVertex2f(15.0f, 4.0f);
    glVertex2f(15.0f, -7.0f);
    glVertex2f(20.0f, -7.0f);
    glVertex2f(20.0f, 4.0f);
    glEnd();


}


void homehead() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(17.0f, 6.0f);
    glVertex2f(15.0f, 4.0f);
    glVertex2f(20.0f, 4.0f);
    glEnd();
}

void window1() {
    glColor3f(0.89f, 0.47f, 0.20f);
    glTranslatef(14.0f, 1.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(1.5f, 0.5f);
    glVertex2f(1.5f, -1.0f);
    glVertex2f(3.0f, -1.0f);
    glVertex2f(3.0f, 0.5f);
    glEnd();
}
void window2() {
    glColor3f(0.89f, 0.47f, 0.20f);
    //glTranslatef(17.0f, 1.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(3.5f, 0.5f);
    glVertex2f(3.5f, -1.0f);
    glVertex2f(5.0f, -1.0f);
    glVertex2f(5.0f, 0.5f);
    glEnd();
}

void door() {
    glColor3f(0.5f, 0.0f, 1.5f);
    glTranslatef(0.0f, -0.9f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(2.5f, -5.0f);
    glVertex2f(2.5f, -7.0f);
    glVertex2f(4.0f, -7.0f);
    glVertex2f(4.0f, -5.0f);
    glEnd();
}

void pointsrighthand() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(righthandpointx, -0.3);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(lefthandpointx, -0.8);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(righthandpointx2, -1.3);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(lefthandpointx2, -1.8);
    glEnd();

}

void ball() {
    glPointSize(3);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(pointballx + 0.9f * cos(deginrad), -1.2f + 0.9f * sin(deginrad));
    }
    glEnd();
}

void islose() {
    
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(6, 6);
    glVertex2f(6, -6);
    glVertex2f(-6, -6);
    glVertex2f(-6 ,6);
    glEnd();

    glColor3f(1, 1, 1);
    glRasterPos2f(-2.8, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
    glRasterPos2f(-2.3, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
    glRasterPos2f(-1.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');
    glRasterPos2f(-0.3, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
    glRasterPos2f(0.3, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');
    glRasterPos2f(1.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'K');
    glRasterPos2f(2.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');
    glRasterPos2f(2.5, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
    glRasterPos2f(3.7, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
    glRasterPos2f(4.3, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
    glRasterPos2f(4.8, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
    glRasterPos2f(5.3, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');

}
void gameover() {
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(20, 20);
    glVertex2f(20, -20);
    glVertex2f(-20, -20);
    glVertex2f(-20, 20);
    glEnd();

    glColor3f(0, 0, 0);
    glRasterPos2f(-1.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
    glRasterPos2f(-0.2, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
    glRasterPos2f(0.6, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'M');
    glRasterPos2f(1.4, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
    glRasterPos2f(2.1, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
    glRasterPos2f(2.9, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'V');
    glRasterPos2f(3.7, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
    glRasterPos2f(4.5, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');

}
void scoretotal() {
    while (score<5) {
        score++;
    }
}


void iswin() {
   // score += 5;
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(6, 6);
    glVertex2f(6, -6);
    glVertex2f(-6, -6);
    glVertex2f(-6 ,6);
    glEnd();

    glColor3f(0, 0, 0);
    glRasterPos2f(-2.2, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');
    glRasterPos2f(-1.6, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
    glRasterPos2f(-1.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'U');
    glRasterPos2f(0.1, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'W');
    glRasterPos2f(0.8, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'I');
    glRasterPos2f(1.2, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
    glRasterPos2f(-2.2, 2.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
    glRasterPos2f(-1.6, 2.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');
    glRasterPos2f(-1.0, 2.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
    glRasterPos2f(-0.5, 2.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
    glRasterPos2f(0.0, 2.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
    glRasterPos2f(1.0, 2.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+(score));

}

void man() {
    glPushMatrix();
    glTranslatef(-13.0f, -0.9f, 0.0f);
    //glScalef(-0.5f, 0.5f, 1.0f);
    hair();

    body();

    rightblackeye();

    rightgreeneye();

    leftblackeye();

    leftgreeneye();

    rightear();

    leftear();

    righthand();

    lefthand();

    righthandline();

    lefthandline();

    centerline();

    nose();

    mouth();



    glRotatef(llang, 0, 0, 1);
    leftfoot();
    if (llang < 0 || llang >5) {
        llangsp *= -1;
    }
    //llang += llangsp;
    glRotatef(rlang, 0, 0, 1);
    rightfoot();
    if (rlang > 0 || rlang < -5) {
        rlangsp *= -1;
    }
    //rlang += rlangsp;
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15.0f, -0.9f, 0.0f);
    ball();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13.0f, -0.9f, 0.0f);
    pointsrighthand();
    glPopMatrix();
}

void land() {
    glColor3f(0.184314f, 0.309804f, 0.184314f);
    glRectf(-20.0f, 0.0f, 20.0f, -7.0f);
}

void sun() {
    glPointSize(8);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0;i < 360;i++) {
        float deginrad = i * 3.14 / 180;
        glVertex2f(-15.0 + 1.5f * cos(deginrad), 17.0f + 1.5f * sin(deginrad));
    }
    glEnd();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(0.91, 0.76, 0.65, 1.0);
    glMatrixMode(GL_MODELVIEW); // To operate on Model-View matrix

    glPushMatrix();
    glScalef(0.7f, 0.7f, 1.0f);
    glTranslatef(mposx, mposy, 0.0f);
    man();
    /*
    if (mposx > 30) {
        mposx -= mspeedx;
    }
    if (mposx < -10) {
        mposx += mspeedx;
    }
    if (mposy < -14) {
        mposy += mspeedy;
    }
    if (mposy > 10) {
        mposy -= mspeedy;
    }
    */
    if (mposx < -10 || mposy < -5 || mposy > 10) {
        lose = false;
        //Gkey = false;
        //fkey = false;
        //dkey = false;
        //skey = false;
        //akey = false;
    }
    else {
        lose = true;
    }
    if (mposx > 30) {
        lose2 = false;
    }
    //mposx += mspeedx;
    //mposy += mspeedy;
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1f, homey, 0.0f);
    square();
    if (pointballx > 40) {
        homey -= 0.01;
        heady -= 0.01;
        window1y -= 0.01;
        window2y -= 0.01;
        doory -= 0.01;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1f, heady, 0.0f);
    homehead();
    if (righthandpointx > 40) {
        heady -= 0.01;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, window1y, 0.0f);
    window1();
    if (righthandpointx2 > 40) {
        window1y -= 0.01;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14.0f, window2y, 0.0f);
    window2();
    if (lefthandpointx > 40) {
        window2y -= 0.01;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14.0f, doory, 0.0f);
    door();
    if (lefthandpointx2 > 40) {
        doory -= 0.01;
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -13.0f, 0.0f);
    land();
    glPopMatrix();

    sun();

    if ((pointballx > 40 && righthandpointx > 40 && righthandpointx2 > 40 && lefthandpointx > 40 && lefthandpointx2 > 40) || pointballx > 40) {
        //score = score + 5;
        Win = false;
        //score += 5;
    }


    if (Gkey == true) {
        righthandpointx += 0.1;
    }
    if (fkey == true) {
        lefthandpointx2 += 0.1;
    }
    if (dkey == true) {
        lefthandpointx += 0.1;
    }
    if (skey == true) {
        righthandpointx2 += 0.1;
    }
    if (akey == true) {
        pointballx += 0.1;
    }

    if (lose == false) {
        islose();
        
        //exit(0);
    }

    if (Win == false) {
       
        
        iswin();
        scoretotal();
        lose2 = true;
        
    }

    if (lose2 == false) {
        gameover();
    }

    glutPostRedisplay(); // Post a re-paint request to activate display()
    glutSwapBuffers(); // Double buffered - swap the front and back buffers

    glFlush();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
    glMatrixMode(GL_MODELVIEW);
}

void windowkey(unsigned char key, int x, int y);
void windowspecial(int key, int x, int y);



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480); // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Shooting Game");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(windowkey);
    glutSpecialFunc(windowspecial);
    glutFullScreen();
    glutMainLoop();
}

void windowkey(unsigned char key, int x, int y) {
    if (key == 'g' || key == 'G') {
        Gkey = true;
        //righthandpointx += 1.0;
    }

    else if (key == 'f' || key == 'F') {
        fkey = true;
        // lefthandpointx2 += 1.0;
    }
    else if (key == 'd' || key == 'D') {
        dkey = true;
        //lefthandpointx += 0.1;
    }
    else if (key == 's' || key == 'S') {
        skey = true;
        //righthandpointx2 += 0.1;
    }
    else if (key == 'a' || key == 'A') {
        akey = true;
        // pointballx += 0.1;
    }
    else if (key == 27) {
        exit(0);
    }
    glutPostRedisplay();
}
void windowspecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        mposy += mspeedy;
    }
    else if (key == GLUT_KEY_DOWN) {
        mposy -= mspeedy;
    }
    else if (key == GLUT_KEY_RIGHT) {
        mposx += mspeedx;
        //llang -= llangsp;
        rlang += rlangsp;
    }
    else if (key == GLUT_KEY_LEFT) {
        mposx -= mspeedx;
        llang -= llangsp;
        //rlang -= rlangsp;
    }

    glutPostRedisplay();
}



