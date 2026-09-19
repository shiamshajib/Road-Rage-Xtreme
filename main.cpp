#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include<mmsystem.h>
GLfloat positiontree = 2.0f;
GLfloat speedtree = 0.029f;
/// Score
int score = 0,s;
///Distance
float distancee = 0.0f,d;
float moveAmount = 0.001f;
bool moveLeft = false;
bool moveRight = false;

float main_car_x = -0.00014f;
float main_car_y = -0.8;
float position1_x =0.2f;
float position1 = 0.0f;
float position2 = 1.20f;
float position3 = 1.50f;
float position4 = 1.90f;
float position1_x_1 =-0.425f;
float position1_x_2 =0.425f;


float H1=0.2f;

int lives = 3;
float B1=0.2f;
float B2=1.2f;
bool collisionOccurred = false;
time_t collisionStartTime;

float distance(float x1, float y1, float x2, float y2)
{

    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

}

void increaseLife()
{
    lives+=1;
}

bool checkCollision()
{

    float collisionThreshold = 0.14f;

    // Check for collision with other car

    if (distance(position1_x, position1, main_car_x, main_car_y) < collisionThreshold ||
            distance(position1_x_1, position2, main_car_x, main_car_y) < collisionThreshold ||
            distance(position1_x_2, position3, main_car_x, main_car_y) < collisionThreshold ||
            distance(B1, B2, main_car_x, main_car_y) < collisionThreshold

       )

    {

        if (!collisionOccurred)
        {

            collisionOccurred = true;
            collisionStartTime = time(NULL);
        }

        return true; // Collision detected with other objects
    }

    // Check for collision with Live object

    if (distance(H1, position4, main_car_x, main_car_y) < collisionThreshold)

    {
        increaseLife(); // Increase life if collision with Live object

        return true; // Collision detected with Live object
    }

/// to make the car invisible

    if (distance(position1_x, position1, main_car_x, main_car_y) < collisionThreshold ||

            distance(position1_x_1, position2, main_car_x, main_car_y) < collisionThreshold ||
            distance(position1_x_2, position3, main_car_x, main_car_y) < collisionThreshold ||
            distance(B1, B2, main_car_x, main_car_y) < collisionThreshold)

    {

        if (!collisionOccurred)
        {
            collisionOccurred = false;
            collisionStartTime = time(NULL);
        }

        return true; // Collision detected with other objects

    }

    // Handle collision duration and life deduction

    if (collisionOccurred)

    {
        lives--;

        collisionOccurred = false;
    }

    return false; // No collision detected

}


///reduce heart




///reduce heart

void drawHearts()
{

    int maxHearts = 4; // Maximum number of hearts to display

    // Ensure lives doesn't exceed the maximum hearts
    if (lives > maxHearts) {
        lives = maxHearts;
    }
    for (int i = 0; i < lives ; i++) {
    glPushMatrix();
    glTranslatef(-0.94f + i * 0.05f, 0.71f, 0.0f); // Adjust heart positions
        glColor3f(1.0f, 0.84f, 0.0f);
        glScalef(0.07,0.07,0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0.5);   //1
        glVertex2f(0.1248, 0.5541);   //2
        glVertex2f(0.2434, 0.5333); //3
        glVertex2f(0.3162, 0.4397);     //4
        glVertex2f(0.3162, 0.3273);    //5
        glVertex2f(0.2704, 0.2296);   //6
        glVertex2f(0.1914, 0.1318);//o
        glVertex2f(0.1144, 0.0444);//o
        glVertex2f(0, -0.0388);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0,0.5);   //1
        glVertex2f(-0.1248, 0.5541);   //2
        glVertex2f(-0.2434, 0.5333); //3
        glVertex2f(-0.3162, 0.4397);     //4
        glVertex2f(-0.3162, 0.3273);    //5
        glVertex2f(-0.2704, 0.2296);   //6
        glVertex2f(-0.1914, 0.1318);//o
        glVertex2f(-0.1144, 0.0444);//o
        glVertex2f(0, -0.0388);
        glEnd();
        glPopMatrix();

    }

}

///main car movement
void Main_car()
{
       glPushMatrix();
    glTranslatef(main_car_x, main_car_y, 0.0f); // Move car

    // ---------------- Down Body ----------------
    glScalef(0.8f, 1.3f, 0.0f);
    glColor3f(0.13f, 0.17f, 0.62f); // Blue body
    glBegin(GL_POLYGON);
        glVertex2f(0.08f, 0.10f);
        glVertex2f(0.09f, 0.09f);
        glVertex2f(0.25f, 0.09f);
        glVertex2f(0.26f, 0.10f);
        glVertex2f(0.25f, 0.08f);
        glVertex2f(0.09f, 0.08f);
    glEnd();

    // ---------------- Mid Body ----------------
    glBegin(GL_POLYGON);
        glVertex2f(0.08f, 0.10f);
        glVertex2f(0.26f, 0.10f);
        glVertex2f(0.26f, 0.44f);
        glVertex2f(0.25f, 0.45f);
        glVertex2f(0.09f, 0.45f);
        glVertex2f(0.08f, 0.44f);
    glEnd();

    // ---------------- Upper Body ----------------
    glBegin(GL_POLYGON);
        glVertex2f(0.09f, 0.46f);
        glVertex2f(0.25f, 0.46f);
        glVertex2f(0.25f, 0.45f);
        glVertex2f(0.09f, 0.45f);
    glEnd();

    // ---------------- Windows ----------------
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan windows

    // Main back window
    glBegin(GL_POLYGON);
        glVertex2f(0.10f, 0.12f);
        glVertex2f(0.123f, 0.11f);
        glVertex2f(0.22f, 0.11f);
        glVertex2f(0.24f, 0.12f);
        glVertex2f(0.23f, 0.14f);
        glVertex2f(0.11f, 0.14f);
    glEnd();

    // Small windows
    glBegin(GL_POLYGON);
        glVertex2f(0.25f, 0.14f);
        glVertex2f(0.25f, 0.19f);
        glVertex2f(0.23f, 0.19f);
        glVertex2f(0.23f, 0.16f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.09f, 0.14f);
        glVertex2f(0.09f, 0.19f);
        glVertex2f(0.11f, 0.19f);
        glVertex2f(0.11f, 0.16f);
    glEnd();

    // Bigger side windows
    glBegin(GL_POLYGON);
        glVertex2f(0.09f, 0.21f);
        glVertex2f(0.09f, 0.33f);
        glVertex2f(0.11f, 0.29f);
        glVertex2f(0.11f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.25f, 0.21f);
        glVertex2f(0.25f, 0.33f);
        glVertex2f(0.23f, 0.29f);
         glVertex2f(0.23f, 0.21f);
    glEnd();

    // Front window
    glBegin(GL_POLYGON);
        glVertex2f(0.11f, 0.33f);
        glVertex2f(0.23f, 0.33f);
        glVertex2f(0.24f, 0.34f);
         glVertex2f(0.25f, 0.38f);
        glVertex2f(0.09f, 0.38f);
        glVertex2f(0.10f, 0.34f);
    glEnd();

    // ---------------- Headlights ----------------
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow headlights

    // Right headlight
    glBegin(GL_POLYGON);
        glVertex2f(0.23f, 0.43f); glVertex2f(0.25f, 0.43f);
        glVertex2f(0.23f, 0.45f);
    glEnd();

    // Left headlight
    glBegin(GL_POLYGON);
        glVertex2f(0.12f, 0.43f); glVertex2f(0.10f, 0.43f);
        glVertex2f(0.12f, 0.45f);
    glEnd();

    glPopMatrix();
    glLoadIdentity();

}



///control function

GLfloat position = 0.0f;

GLfloat speed = 0.1f;

GLfloat speed1 = 0.05f;

GLfloat speed2 = 0.05f;

GLfloat speed3 = 0.05f;

GLfloat speed4 = 0.05f;
///My car movement
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            speedtree += 0.005f; // increase car speed
            break;
        case GLUT_KEY_DOWN:
            speedtree -= 0.005f; // decrease car speed
            break;
        case GLUT_KEY_LEFT:
            if (main_car_x > -0.4f) // limit car movement left to -0.4
                main_car_x -= 0.1f; // move the car left
            break;
        case GLUT_KEY_RIGHT:
            if (main_car_x < 0.1f) // limit car movement right to +0.2
                main_car_x += 0.1f; // move the car right
            break;
                }

    glutPostRedisplay(); // redraw the scene
}


///

void update(int value)
{
    if(positiontree <-1.0)
        positiontree = 1.0f;
    positiontree -= speedtree;

    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}

///enviroment

void env()

{

    glClearColor(0.2f, 0.8f, 0.2f, 1.0f); // Set background color to a shade of green

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    //glLoadIdentity(); // Reset the transformation matrix

     glPushMatrix();
    //road side color
    glBegin(GL_POLYGON);
    glColor3f(0.33f, 0.42f, 0.18f);
    glVertex2f(1.0f,1.0f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();
    glPopMatrix();

   //road
   //Red part road boarder
    glScalef(.8,1,0);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.55f,1.0f);
    glVertex2f(-0.55f,1.0f);
    glVertex2f(-0.55f,-1.0f);
    glVertex2f(0.55f,-1.0f);
    glEnd();
    glLoadIdentity();

    //white part road boarder
    glScalef(.8,1,0);
    glTranslatef(+0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();

    glTranslatef(+0.0f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.55f,0.9f);
    glVertex2f(0.55f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.55f,0.9f);
    glEnd();
    glLoadIdentity();


    ///Translation black
    //glTranslatef(0.0f,position, 0.0f);
    //black part
    glScalef(.8,1,0);
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.5f,1.0f);
    glVertex2f(-0.5f,1.0f);
    glVertex2f(-0.5f,-1.0f);
    glVertex2f(0.5f,-1.0f);
    glEnd();
    glLoadIdentity();

    //inside left side traffic border
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.19f,1.0f);
    glVertex2f(-0.195f,1.0f);
    glVertex2f(-0.195f,-1.0f);
    glVertex2f(-0.19f,-1.0f);
    glEnd();

    //inside right side traffic border
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.19f,1.0f);
    glVertex2f(0.195f,1.0f);
    glVertex2f(0.195f,-1.0f);
    glVertex2f(0.19f,-1.0f);
    glEnd();

    //inside middle traffic border
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.005f,1.0f);
    glVertex2f(0.0f,1.0f);
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.005f,-1.0f);
    glEnd();



    glLoadIdentity();

    glFlush();

}


void Tree(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);

    // ===== Tree 1 =====
    glPushMatrix();
    // Foliage
    glColor3f(0.18f, 0.54f, 0.34f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, -0.02f);
        glVertex2f(-0.74f, -0.06f);
        glVertex2f(-0.66f, -0.06f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, -0.04f);
        glVertex2f(-0.76f, -0.10f);
        glVertex2f(-0.64f, -0.10f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, -0.07f);
        glVertex2f(-0.78f, -0.14f);
        glVertex2f(-0.62f, -0.14f);
    glEnd();

    // Trunk
    glColor3f(0.80f, 0.52f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(-0.71f, -0.12f);
        glVertex2f(-0.71f, -0.20f);
        glVertex2f(-0.69f, -0.20f);
        glVertex2f(-0.69f, -0.12f);
    glEnd();
    glPopMatrix();
    // ===== End Tree 1 =====


    // ===== Tree 2 =====
    glPushMatrix();
    glTranslatef(0.18f, 0.54f, 0.34f); // Move second tree up
    glColor3f(0.18f, 0.85f, 0.15f);

    // Foliage
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, -0.02f);
        glVertex2f(-0.74f, -0.06f);
        glVertex2f(-0.66f, -0.06f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, -0.04f);
        glVertex2f(-0.76f, -0.10f);
        glVertex2f(-0.64f, -0.10f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, -0.07f);
        glVertex2f(-0.78f, -0.14f);
        glVertex2f(-0.62f, -0.14f);
    glEnd();

    // Trunk
    glColor3f(0.80f, 0.52f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(-0.71f, -0.12f);
        glVertex2f(-0.71f, -0.20f);
        glVertex2f(-0.69f, -0.20f);
        glVertex2f(-0.69f, -0.12f);
    glEnd();
    glPopMatrix();
    // ===== End Tree 2 =====

    glPopMatrix(); // Restore main matrix
}
void Tree1(float x, float y, float z)
{
    glTranslatef(x, y, z);
    glPushMatrix();

    //// Body
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.2f, 0.2f); // red shirt
    glVertex2f(-0.74f, -0.80f);
    glVertex2f(-0.72f, -0.80f);
    glVertex2f(-0.72f, -0.72f);
    glVertex2f(-0.74f, -0.72f);
    glEnd();

    //// Legs
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); // black pants
    glVertex2f(-0.74f, -0.88f);
    glVertex2f(-0.73f, -0.88f);
    glVertex2f(-0.73f, -0.80f);
    glVertex2f(-0.74f, -0.80f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(-0.73f, -0.88f);
    glVertex2f(-0.72f, -0.88f);
    glVertex2f(-0.72f, -0.80f);
    glVertex2f(-0.73f, -0.80f);
    glEnd();

    //// Head
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.8f, 0.6f); // skin color
    glVertex2f(-0.735f, -0.72f);
    glVertex2f(-0.725f, -0.72f);
    glVertex2f(-0.73f, -0.68f);
    glEnd();

    glPopMatrix();
    glLoadIdentity();
}


void Home(float x, float y, float z)
{
    glTranslatef(x, y, z);
    glPushMatrix();

    //// Trunk
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.27f, 0.07f); // brown trunk
    glVertex2f(-0.88f, -0.46f);
    glVertex2f(-0.86f, -0.46f);
    glVertex2f(-0.86f, -0.38f);
    glVertex2f(-0.88f, -0.38f);
    glEnd();

    //// Leaves (lower layer)
    glBegin(GL_TRIANGLES);
    glColor3f(0.18f, 0.54f, 0.34f); // green
    glVertex2f(-0.90f, -0.38f);
    glVertex2f(-0.84f, -0.38f);
    glVertex2f(-0.87f, -0.32f);
    glEnd();

    //// Leaves (middle layer)
    glBegin(GL_TRIANGLES);
    glColor3f(0.16f, 0.50f, 0.30f); // darker green
    glVertex2f(-0.89f, -0.35f);
    glVertex2f(-0.85f, -0.35f);
    glVertex2f(-0.87f, -0.28f);
    glEnd();

    //// Leaves (top layer)
    glBegin(GL_TRIANGLES);
    glColor3f(0.12f, 0.45f, 0.25f); // darkest green
    glVertex2f(-0.88f, -0.31f);
    glVertex2f(-0.86f, -0.31f);
    glVertex2f(-0.87f, -0.25f);
    glEnd();

    glPopMatrix();
}


void Home1(float x, float y,float z)
{
    glTranslatef(x, y, z);
    // 2ND HOUSE

    // 1st part (walls)
    glBegin(GL_QUADS);
    glColor3f(0.55f, 0.27f, 0.07f); // brown wall
    glVertex2f(-0.6f, -0.3f);
    glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.74f, -0.36f);
    glVertex2f(-0.64f, -0.36f);
    glEnd();

    // 2nd part with door
    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.32f, 0.17f); // lighter brown
    glVertex2f(-0.72f, -0.36f);
    glVertex2f(-0.72f, -0.44f);
    glVertex2f(-0.64f, -0.44f);
    glVertex2f(-0.64f, -0.36f);
    glEnd();

    // 3rd part (another wall section)
    glBegin(GL_QUADS);
    glColor3f(0.60f, 0.35f, 0.20f); // medium brown
    glVertex2f(-0.64f, -0.36f);
    glVertex2f(-0.56f, -0.36f);
    glVertex2f(-0.56f, -0.44f);
    glVertex2f(-0.64f, -0.44f);
    glEnd();

    // 4th part (ground detail)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.64f, -0.44f);
    glVertex2f(-0.64f, -0.46f);
    glVertex2f(-0.735f, -0.46f);
    glVertex2f(-0.735f, -0.44f);
    glEnd();

    // 5th part (ground detail)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.64f, -0.44f);
    glVertex2f(-0.64f, -0.46f);
    glVertex2f(-0.56f, -0.46f);
    glVertex2f(-0.56f, -0.44f);
    glEnd();

    // Door 1
    glBegin(GL_QUADS);
    glColor3f(0.36f, 0.25f, 0.20f); // dark brown door
    glVertex2f(-0.59f, -0.39f);
    glVertex2f(-0.59f, -0.44f);
    glVertex2f(-0.61f, -0.44f);
    glVertex2f(-0.61f, -0.39f);
    glEnd();

    // Door 2
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.52f, 0.25f); // light brown door/window
    glVertex2f(-0.67f, -0.39f);
    glVertex2f(-0.69f, -0.39f);
    glVertex2f(-0.69f, -0.44f);
    glVertex2f(-0.67f, -0.44f);
    glEnd();

    // Roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.45f, 0.26f, 0.15f); // brown roof
    glVertex2f(-0.56f, -0.36f);
    glVertex2f(-0.6f, -0.3f);
    glVertex2f(-0.64f, -0.36f);
    glEnd();

    glLoadIdentity();
    // 2ND HOUSE END
}


/// car 1

void car1(int a)
{
    glPushMatrix();
    glScalef(0.8, 1.3, 0);
    glTranslatef(position1_x, position1, 0.0f);

    // Down body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.9f, 0.42f); // Fixed RGB
    glVertex2f(0.08f, 0.10f);
    glVertex2f(0.09f, 0.09f);
    glVertex2f(0.25f, 0.09f);
    glVertex2f(0.26f, 0.10f);
    glVertex2f(0.25f, 0.08f);
    glVertex2f(0.09f, 0.08f);
    glEnd();

    // Mid body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f, 0.10f);
    glVertex2f(0.26f, 0.44f);
    glVertex2f(0.25f, 0.45f);
    glVertex2f(0.09f, 0.45f);
    glVertex2f(0.08f, 0.44f);
    glVertex2f(0.08f, 0.10f);
    glVertex2f(0.09f, 0.09f);
    glVertex2f(0.25f, 0.09f);
    glEnd();

    // Upper body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f, 0.44f);
    glVertex2f(0.25f, 0.45f);
    glVertex2f(0.09f, 0.45f);
    glVertex2f(0.08f, 0.44f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.25f, 0.46f);
    glEnd();

    // Windows
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON); // 1 back
    glVertex2f(0.11f, 0.14f);
    glVertex2f(0.23f, 0.14f);
    glVertex2f(0.24f, 0.12f);
    glVertex2f(0.22f, 0.11f);
    glVertex2f(0.123f, 0.11f);
    glVertex2f(0.10f, 0.12f);
    glEnd();

    glBegin(GL_POLYGON); // 2 back right small
    glVertex2f(0.25f, 0.14f);
    glVertex2f(0.25f, 0.19f);
    glVertex2f(0.23f, 0.19f);
    glVertex2f(0.23f, 0.16f);
    glEnd();

    glBegin(GL_POLYGON); // 3 back left small
    glVertex2f(0.09f, 0.14f);
    glVertex2f(0.09f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.11f, 0.16f);
    glEnd();

    glBegin(GL_POLYGON); // 4 back left big
    glVertex2f(0.09f, 0.21f);
    glVertex2f(0.09f, 0.33f);
    glVertex2f(0.11f, 0.29f);
    glVertex2f(0.11f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON); // 4 back right big
    glVertex2f(0.25f, 0.21f);
    glVertex2f(0.25f, 0.33f);
    glVertex2f(0.23f, 0.29f);
    glVertex2f(0.23f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON); // 5 front
    glVertex2f(0.23f, 0.33f);
    glVertex2f(0.11f, 0.33f);
    glVertex2f(0.10f, 0.34f);
    glVertex2f(0.09f, 0.38f);
    glVertex2f(0.25f, 0.38f);
    glVertex2f(0.24f, 0.34f);
    glEnd();

    // Lights
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON); // Right light
    glVertex2f(0.23f, 0.43f);
    glVertex2f(0.25f, 0.43f);
    glVertex2f(0.23f, 0.45f);
    glEnd();

    glBegin(GL_POLYGON); // Left light
    glVertex2f(0.12f, 0.43f);
    glVertex2f(0.10f, 0.43f);
    glVertex2f(0.12f, 0.45f);
    glEnd();



    glPopMatrix();
    glutSwapBuffers();
}


/// car 2

void car2(int c)
{
    glPushMatrix();
    glScalef(0.8, 1.3, 0);
    glTranslatef(position1_x_1, position2, 0.0f);

    // Down body
    glBegin(GL_POLYGON);
    glColor3f(0.92f, 0.14f, 0.26f); // Fixed RGB
    glVertex2f(0.08f, 0.10f);
    glVertex2f(0.09f, 0.09f);
    glVertex2f(0.25f, 0.09f);
    glVertex2f(0.26f, 0.10f);
    glVertex2f(0.25f, 0.08f);
    glVertex2f(0.09f, 0.08f);
    glEnd();

    // Mid body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f, 0.10f);
    glVertex2f(0.26f, 0.44f);
    glVertex2f(0.25f, 0.45f);
    glVertex2f(0.09f, 0.45f);
    glVertex2f(0.08f, 0.44f);
    glVertex2f(0.08f, 0.10f);
    glVertex2f(0.09f, 0.09f);
    glVertex2f(0.25f, 0.09f);
    glEnd();

    // Upper body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f, 0.44f);
    glVertex2f(0.25f, 0.45f);
    glVertex2f(0.09f, 0.45f);
    glVertex2f(0.08f, 0.44f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.25f, 0.46f);
    glEnd();

    // Windows
    glColor3f(0.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON); // 1 back
    glVertex2f(0.11f, 0.14f);
    glVertex2f(0.23f, 0.14f);
    glVertex2f(0.24f, 0.12f);
    glVertex2f(0.22f, 0.11f);
    glVertex2f(0.123f, 0.11f);
    glVertex2f(0.10f, 0.12f);
    glEnd();

    glBegin(GL_POLYGON); // 2 back right small
    glVertex2f(0.25f, 0.14f);
    glVertex2f(0.25f, 0.19f);
    glVertex2f(0.23f, 0.19f);
    glVertex2f(0.23f, 0.16f);
    glEnd();

    glBegin(GL_POLYGON); // 3 back left small
    glVertex2f(0.09f, 0.14f);
    glVertex2f(0.09f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.11f, 0.16f);
    glEnd();

    glBegin(GL_POLYGON); // 4 back left big
    glVertex2f(0.09f, 0.21f);
    glVertex2f(0.09f, 0.33f);
    glVertex2f(0.11f, 0.29f);
    glVertex2f(0.11f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON); // 4 back right big
    glVertex2f(0.25f, 0.21f);
    glVertex2f(0.25f, 0.33f);
    glVertex2f(0.23f, 0.29f);
    glVertex2f(0.23f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON); // 5 front
    glVertex2f(0.23f, 0.33f);
    glVertex2f(0.11f, 0.33f);
    glVertex2f(0.10f, 0.34f);
    glVertex2f(0.09f, 0.38f);
    glVertex2f(0.25f, 0.38f);
    glVertex2f(0.24f, 0.34f);
    glEnd();

    // Lights
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON); // Right light
    glVertex2f(0.23f, 0.43f);
    glVertex2f(0.25f, 0.43f);
    glVertex2f(0.23f, 0.45f);
    glEnd();

    glBegin(GL_POLYGON); // Left light
    glVertex2f(0.12f, 0.43f);
    glVertex2f(0.10f, 0.43f);
    glVertex2f(0.12f, 0.45f);
    glEnd();

    // Wheels


    glPopMatrix();
    glutSwapBuffers();
}


/// car 3

void car3(int d)
{
    glLoadIdentity();
    glPushMatrix();
    glScalef(0.8f, 1.3f, 0);  // Keep original proportions
    glTranslatef(position1_x_2, position3, 0.0f);

    // Down body
    glBegin(GL_POLYGON);
    glColor3f(0.58f, 0.42f, 0.27f); // Brownish color
    glVertex2f(0.08f, 0.10f);
    glVertex2f(0.09f, 0.09f);
    glVertex2f(0.25f, 0.09f);
    glVertex2f(0.26f, 0.10f);
    glVertex2f(0.25f, 0.08f);
    glVertex2f(0.09f, 0.08f);
    glEnd();

    // Mid body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f, 0.10f);
    glVertex2f(0.26f, 0.44f);
    glVertex2f(0.25f, 0.45f);
    glVertex2f(0.09f, 0.45f);
    glVertex2f(0.08f, 0.44f);
    glVertex2f(0.08f, 0.10f);
    glVertex2f(0.09f, 0.09f);
    glVertex2f(0.25f, 0.09f);
    glEnd();

    // Upper body
    glBegin(GL_POLYGON);
    glVertex2f(0.26f, 0.44f);
    glVertex2f(0.25f, 0.45f);
    glVertex2f(0.09f, 0.45f);
    glVertex2f(0.08f, 0.44f);
    glVertex2f(0.09f, 0.46f);
    glVertex2f(0.25f, 0.46f);
    glEnd();

    // Windows
    glColor3f(0.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON); // 1 back
    glVertex2f(0.11f, 0.14f);
    glVertex2f(0.23f, 0.14f);
    glVertex2f(0.24f, 0.12f);
    glVertex2f(0.22f, 0.11f);
    glVertex2f(0.123f, 0.11f);
    glVertex2f(0.10f, 0.12f);
    glEnd();

    glBegin(GL_POLYGON); // 2 back right small
    glVertex2f(0.25f, 0.14f);
    glVertex2f(0.25f, 0.19f);
    glVertex2f(0.23f, 0.19f);
    glVertex2f(0.23f, 0.16f);
    glEnd();

    glBegin(GL_POLYGON); // 3 back left small
    glVertex2f(0.09f, 0.14f);
    glVertex2f(0.09f, 0.19f);
    glVertex2f(0.11f, 0.19f);
    glVertex2f(0.11f, 0.16f);
    glEnd();

    glBegin(GL_POLYGON); // 4 back left big
    glVertex2f(0.09f, 0.21f);
    glVertex2f(0.09f, 0.33f);
    glVertex2f(0.11f, 0.29f);
    glVertex2f(0.11f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON); // 4 back right big
    glVertex2f(0.25f, 0.21f);
    glVertex2f(0.25f, 0.33f);
    glVertex2f(0.23f, 0.29f);
    glVertex2f(0.23f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON); // 5 front
    glVertex2f(0.23f, 0.33f);
    glVertex2f(0.11f, 0.33f);
    glVertex2f(0.10f, 0.34f);
    glVertex2f(0.09f, 0.38f);
    glVertex2f(0.25f, 0.38f);
    glVertex2f(0.24f, 0.34f);
    glEnd();

    // Lights
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON); // Right light
    glVertex2f(0.23f, 0.43f);
    glVertex2f(0.25f, 0.43f);
    glVertex2f(0.23f, 0.45f);
    glEnd();

    glBegin(GL_POLYGON); // Left light
    glVertex2f(0.12f, 0.43f);
    glVertex2f(0.10f, 0.43f);
    glVertex2f(0.12f, 0.45f);
    glEnd();



    glPopMatrix();
    glLoadIdentity();
    glutSwapBuffers();
}


/// bomb
void bomb()
{
    // Draw bomb body
    glPushMatrix();
    glTranslatef(-0.1 + B1, B2, 0.0f); // Apply translation
    glScalef(0.38, 0.38, 0.0f);

    // Red color for bomb
    glColor3f(0.0f, 0.0f, 0.0f); // Dark red

    // Draw a more circular bomb using polygon
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) // 36 points around a circle
    {
        float theta = i * 3.14159 / 180;
        float x = 0.44f + 0.08f * cos(theta); // 0.08 = radius
        float y = 0.50f + 0.08f * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Optional: highlight for 3D effect
    glColor3f(1.0f, 0.3f, 0.3f); // brighter red
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 15)
    {
        float theta = i * 3.14159 / 180;
        float x = 0.44f + 0.04f * cos(theta); // smaller radius
        float y = 0.52f + 0.04f * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Fuse at the top
    glColor3f(0.9f, 0.5f, 0.0f); // orange fuse
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(0.44f, 0.58f);
    glVertex2f(0.44f, 0.65f);
    glEnd();

    glPopMatrix();
    glLoadIdentity();
    glutSwapBuffers();
}


///live

void health(int a)
{

    glPushMatrix();
    glTranslatef(H1, position4, 0.0f); // Apply translation

    glColor3f(1.0f, 0.843f, 0.0f); // Red color for filling

    glScalef(0.1,0.1,0);

    glBegin(GL_POLYGON);

    glVertex2f(0,0.5);   //1

    glVertex2f(0.1248, 0.5541);   //2

    glVertex2f(0.2434, 0.5333); //3

    glVertex2f(0.3162, 0.4397);     //4

    glVertex2f(0.3162, 0.3273);    //5

    glVertex2f(0.2704, 0.2296);   //6

    glVertex2f(0.1914, 0.1318);//o

    glVertex2f(0.1144, 0.0444);//o

    glVertex2f(0, -0.0388);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,0.5);   //1
    glVertex2f(-0.1248, 0.5541);   //2
    glVertex2f(-0.2434, 0.5333); //3
    glVertex2f(-0.3162, 0.4397);     //4
    glVertex2f(-0.3162, 0.3273);    //5
    glVertex2f(-0.2704, 0.2296);   //6
    glVertex2f(-0.1914, 0.1318);//o
    glVertex2f(-0.1144, 0.0444);//o
    glVertex2f(0, -0.0388);

    glEnd();

    glPopMatrix();
    glLoadIdentity();

    glutSwapBuffers();

}

void update1(int value1) {

    // Unconditionally update positions of all cars and obstacles

    position1 -= speed1;

    position2 -= speed2;

    position3 -= speed3;

    position4 -= speed4;

    B2 -= speed4;

    // Check if any car is still on the road

    if (position1 > -1.0 || position2 > -1.0 || position3 > -1.0 || position4 > -1.0) {

        // Request a redraw

        glutPostRedisplay();

        // Schedule the next update

        glutTimerFunc(100, update1, 0);

    } else {

        // Generate a new random number to determine the type of car

        int randomCar = rand() % 4;

        // Update the position of the car and obstacles based on the random number

        if (randomCar == 0) {

            position1_x = 1.9f;

            B1 = 0.0f;

        } else if (randomCar == 1) {

            position1_x_1 = 1.5f;

        } else if (randomCar == 2) {

            position1_x_2 = 1.5f;

            B1 = 0.0f;

        } else if (randomCar == 3) {

            H1 = 1.5f;

        }

        // Reset positions

        position1 = 0.0f;
        position2 = 1.20f;
        position3 = 1.50f;
        position4 = 1.90f;
        B2 = 1.2f;

        // Request a redraw

        glutPostRedisplay();

        // Schedule the next update

        glutTimerFunc(100, update1, 0);

    }

}

///Cover Page
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void instruction()
{



    glClearColor(0.0f,0.0f,0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glColor3f(1.0,1.0,1.0);
    renderBitmapString(-0.1f, 0.22f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "INSTRUCTIOS");
    renderBitmapString(-0.32f, 0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"Press S to start");
    renderBitmapString(-0.32f, 0.08f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"Press 'W' to speed");
    renderBitmapString(-0.32f, 0.01f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,"Press 'UP, DOWN, LEFT, RIGHT' to move your car");


    renderBitmapString(0.0f, -0.4f, 0.0f,GLUT_BITMAP_TIMES_ROMAN_24,"Press 'E' to go Exit");


    glFlush();
}
void coverpage()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glColor3f(0.0,0.0,0.0);

    renderBitmapString(-0.33f, 0.82f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Road Range Xtreme ");
    renderBitmapString(-0.3f, 0.72f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'R' to go Next");
    renderBitmapString(-0.3f, 0.62f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'E' to go Exit");


    glFlush();
}


///Scoreboard
void drawScoreboard()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    //glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //glLoadIdentity();

    // Set position and size for the scoreboard box
    int posX = 30; // X-coordinate
    int posY = 30; // Y-coordinate
    int width = 200; // Width of the box
    int height = 80; // Height of the box

    // Draw the scoreboard box
    glColor3f(1.3f, 1.3f, 1.3f); // Gray color for the box
    glBegin(GL_QUADS);
    glVertex2i(posX, posY);
    glVertex2i(posX + width+12, posY);
    glVertex2i(posX + width+12, posY + height);
    glVertex2i(posX, posY + height);
    glEnd();



    glColor3f(0.0f, 0.0f, 0.0f); // White color for text

    // Convert score and distance to strings
    std::string scoreStr = " YOur Score: " + std::to_string(score);
    std::string distanceStr = "Distance: " + std::to_string(distancee)+ " KM";

    // Set position for text
    int textPosX = posX + 10; // X-coordinate for text
    int textPosY = posY + 30; // Y-coordinate for text

    // Draw score
    glRasterPos2i(textPosX, textPosY);
    for (char const &c : scoreStr)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    // Draw distance
    glRasterPos2i(textPosX, textPosY + 20);
    for (char const &c : distanceStr)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

}

///Scoreboard Update
void updateScoreboard(int value)
{
    // Increment score and distance
    if (lives > 0) {
    score++;
    distancee += 0.01f; // You can adjust this increment value according to your needs
    }

    glutPostRedisplay();
    glutTimerFunc(100, updateScoreboard, 0); // Update every 1 second
}

///game over
void gameoverPage()
{

 glClear(GL_COLOR_BUFFER_BIT);
 glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // White

    // Draw game over title
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // Red
    renderBitmapString(-0.25f, 0.8f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
    glPopMatrix();

    // Draw final score and distance
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // White

    // Draw "Your Score" text with pulsating effect
    float pulse = sin(glutGet(GLUT_ELAPSED_TIME) / 200.0f);
    glColor3f(1.0f, 0.8f + 0.2f * pulse, 0.2f); // Yellow with pulsating alpha
    renderBitmapString(-0.33f, 0.82f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, " YOUR SCORE");
    // Draw actual score with bouncing effect
    //float bounce = sin(glutGet(GLUT_ELAPSED_TIME) / 300.0f);
    char scoreText[20];
    sprintf(scoreText, "%d", score);
    glColor3f(0.9f, 1.0f, 0.2f); // Yellow-green
    renderBitmapString(-0.3f, 0.72f, 0.0f , GLUT_BITMAP_TIMES_ROMAN_24,scoreText);

    // Draw "Distance Traveled" text with waving effect

    glColor3f(1.0f, 0.8f , 0.2f); // Yellow with waving alpha
    renderBitmapString(-0.3f, 0.62f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "DISTANCE TRAVELED");

    // Draw actual distance with spinning effect
    float spin = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    char distanceText[30];
    sprintf(distanceText, "%.2f KM", distancee);
    glColor3f(0.9f, 1.0f, 0.2f); // Yellow-green

    renderBitmapString(-0.28f, 0.52f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24,distanceText);
    glPopMatrix();

glutSwapBuffers();
}



void display()
{

    glClearColor(0.2f, 0.8f, 0.2f, 1.0f); // Set background color to a shade of green

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Draw environment (grass, road, dividers, borders, etc.)

    env();

    if (lives > 0)
    {
        car1(0);
        glPushMatrix();
        glTranslatef(0.06, 0.0, 0.0f);
        car2(0);
        glLoadIdentity();
        glPopMatrix();

        car3(0);
        health(0);
        bomb();
        glLoadIdentity();
         // Draw main car
        Main_car();

        if (checkCollision())
        {
            if (lives <= 0)

            {
                glutDisplayFunc(gameoverPage);

            }

        }

    }

    else
    {

        glutDisplayFunc(gameoverPage);

    }

    glLoadIdentity();

    Tree(0.0,positiontree,0.0);
    glLoadIdentity();

    Home(0.0,positiontree,0.0);
    glLoadIdentity();

    Home(0.0,-0.4+positiontree,0.0);
    glLoadIdentity();

    Home(0.0,0.4+positiontree,0.0);
    glLoadIdentity();


    Home(0.0,1.0+positiontree,0.0);
    glLoadIdentity();

    Tree1(0.0, positiontree,0.0);
    glLoadIdentity();

    Home1(0.0,0.07+positiontree,0.0);
    glLoadIdentity();

    Home1(0.06,-0.3+positiontree,0.0);
    glLoadIdentity();

    Home1(0.0,0.45+positiontree,0.0);
    glLoadIdentity();

    Home1(0.0,0.8+positiontree,0.0);
    glLoadIdentity();

    glLoadIdentity();

    Tree(1.4,positiontree,0.0);
    glLoadIdentity();

    Home(1.4,positiontree,0.0);
    glLoadIdentity();

    Home(1.4,0.4+positiontree,0.0);
    glLoadIdentity();

    Home(1.7,-0.4+positiontree,0.0);
    glLoadIdentity();

    Home1(1.4,positiontree,0.0);
    glLoadIdentity();


    Home1(1.5,1.2+positiontree,0.0);
    glLoadIdentity();

    Home1(1.4,0.5+positiontree,0.0);
    glLoadIdentity();

    Home1(1.2,0.99+positiontree,0.0);
    glLoadIdentity();

    Tree1(1.4, positiontree,0.0);
    glLoadIdentity();

    drawHearts(); // Draw hearts representing lives left
    drawScoreboard();

    glTranslatef(-0.1, 0.1, 0.0f);

    glLoadIdentity();

    glFlush();

}

void keyboardInput(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'r':
            glutDisplayFunc(instruction);
            glutPostRedisplay();
            break;
        case 's':
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 'e':
            exit(0);
            break;
        default:

            break;
    }
}


int main(int argc, char** argv)

{

    glutInit(&argc, argv);

    glutCreateWindow("Road Range Extreme");
    glutDisplayFunc(coverpage);

    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboardInput);
    glutFullScreen();
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(50, update, 0);
    glutTimerFunc(50, updateScoreboard, 0);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutMainLoop();


    return 0;

}
