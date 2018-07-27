#include <windows.h>
#include <gl/gl.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>


void circlePlotPoints(int xCenter, int yCenter, int x, int y);
void glPoint(int x,int y)
{
	glBegin(GL_POINTS);
		 glVertex2f(x,y);//A
	glEnd();
}
void circleMidpoint(int xCenter, int yCenter, int radius)
{
	int x = 0;
	int y = radius;
	int p = 1 - radius;
	void circlePlotPoints(int xCenter, int yCenter, int x, int y);

	/* Plot first set of points */
	circlePlotPoints(xCenter, yCenter, x, y);

	while (x < y) {
		x++;
		if (p < 0)
			p += 2*x + 1;
		else {
			y--;
			p += 2 * (x-y) + 1;
		}
		circlePlotPoints(xCenter, yCenter, x, y);
	}
}
void circlePlotPoints(int xCenter, int yCenter, int x, int y)
{
	glPoint(xCenter + x, yCenter + y);
	glPoint(xCenter - x, yCenter + y);
	glPoint( xCenter + x, yCenter - y);
	glPoint(xCenter - x, yCenter - y);
	glPoint(xCenter + y, yCenter + x);
	glPoint(xCenter - y, yCenter + x);
	glPoint(xCenter + y, yCenter - x);
	glPoint(xCenter - y, yCenter - x);
}
void Render()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();
	glTranslatef(0,0,0);
	circleMidpoint(200,200,100);
}



LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta,x = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          1000,
                          500,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);



            glPushMatrix();

///sodasy
            glBegin(GL_POLYGON);

                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(   0.4f,   0.5f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(  -0.4f,   0.5f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(  -0.6f,   0.0f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(  -0.4f,  -0.5f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(   0.4f,  -0.5f);
                glColor3f(1.0f, 1.0f, 1.0f);   glVertex2f(   0.6f,   0.0f);
                //glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(   0.5f,   0.5f);



            glEnd();

///Rwindow
            glBegin(GL_POLYGON);

                glColor3f(0.0f, 0.9f, 0.9f);   glVertex2f(  0.05f,  0.4f);
                glColor3f(0.0f, 0.8f, 0.9f);   glVertex2f(  0.05f,  0.0f);
                glColor3f(0.0f, 0.7f, 0.9f);   glVertex2f(  0.5f ,  0.0f);
                glColor3f(0.0f, 0.6f, 0.9f);   glVertex2f(  0.34f ,  0.4f);

            glEnd();


///Lwindow
            glBegin(GL_POLYGON);

                glColor3f(0.0f, 0.6f, 0.9f);   glVertex2f( -0.05f,   0.4f);
                glColor3f(0.0f, 0.7f, 0.9f);   glVertex2f(  -0.05f,   0.0f);
                glColor3f(0.0f, 0.8f, 0.9f);   glVertex2f(-0.5f, 0.0f);
                glColor3f(0.0f, 0.9f, 0.9f);   glVertex2f( -0.34f, 0.4f);

            glEnd();


///backcar
            glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(   0.6f,   0.0f);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(   0.4f,  -0.5f);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(  0.85f,  -0.5f);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(   0.7f,   0.0f);
            glEnd();


///frontcar
            glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(  -0.6f,   0.0f);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(  -0.9f,   0.0f);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(  -1.0f,  -0.5f);
                glColor3f(0.0f, 0.2f, 0.3f);   glVertex2f(  -0.4f,  -0.5f);
            glEnd();





//RIghtHand
            glBegin(GL_POLYGON);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(   0.5f, -0.05f);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(   0.5f, -0.08f);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(   0.4f, -0.08f);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(   0.4f, -0.05f);
            glEnd();


///leftHand
            glBegin(GL_POLYGON);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(  -0.05f,  -0.05f);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(  -0.05f,  -0.08f);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(  -0.15f,  -0.08f);
                glColor3f(0.6f, 0.3f, 0.2f);   glVertex2f(  -0.15f,  -0.05f);
            glEnd();



///redLight

            glBegin(GL_POLYGON);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(  0.06f,   0.6f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(   0.1f,   0.5f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(   0.0f,   0.5f);
                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(   0.0f,   0.6f);
            glEnd();


///BlueRight

            glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f( -0.06f,   0.6f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(  -0.1f,   0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(   0.0f,   0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(   0.0f,   0.6f);
            glEnd();




///rightWheel
            glBegin(GL_POLYGON);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f( 0.4f,   -0.36f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f( 0.45f,   -0.38f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(     0.47f,   -0.5f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(  0.45f,  -0.62f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(   0.4f,  -0.64f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(  0.35f,  -0.62f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(        0.33f, -0.5f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(  0.35f,  -0.38f);

            glEnd();

//leftwheel
             glBegin(GL_POLYGON);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(-0.4f,   -0.36f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(-0.34f,   -0.38f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(  -0.32f,   -0.5f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f( -0.34f,  -0.62f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(  -0.4f,  -0.64f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f( -0.44f,  -0.62f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f(  -0.46f, -0.5f);
                glColor3f(0.4f, 0.5f, 0.5f);   glVertex2f( -0.44f,  -0.38f);



            glEnd();


//cover left
            glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f(-0.32f,   -0.39f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f(-0.4f,   -0.36f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f( -0.46f,  -0.39f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f(-0.44f,   -0.34f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f(-0.4f,   -0.32f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f(-0.34f,   -0.34f);


            glEnd();


//cover right
            glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f( 0.47f,   -0.39f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f( 0.33f,  -0.39f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f( 0.35f,   -0.34f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f( 0.4f,   -0.32f);
                glColor3f(0.0f, 0.0f, 0.0f);   glVertex2f( 0.45f,   -0.34f);

            glEnd();



float a=1.0;
float x=0.9;
            glBegin(GL_LINES);

                    glColor3f(a, a, a);   glVertex2f( x,  -0.7f);
                    glColor3f(a, a, a);   glVertex2f(  x-0.2,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-0.3,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-0.5f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-0.6f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-0.8f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-0.9f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-1.1f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-1.2f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-1.4f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-1.5f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-1.7f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-1.8f,  -0.7f);
                    glColor3f(a,a,a);   glVertex2f(  x-1.9f,  -0.7f);

                glEnd();

            glPushMatrix();
            glRotatef(theta, 0.8f,0.6f, 0.0f);
///star
            glBegin(GL_POLYGON);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.29f,  -0.12f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.3f,  -0.07f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.31f,  -0.12f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.34f,  -0.12f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.325f,  -0.17f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.34f,  -0.22f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.31f,  -0.22f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.3f,  -0.27f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.29f,  -0.22f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.26f,  -0.22f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.28f,  -0.17f);
                glColor3f(0.8f, 0.6f, 0.2f);   glVertex2f(  -0.26f,  -0.12f);
            glEnd();


            glPopMatrix();
            SwapBuffers(hDC);
            theta += 0.1f;
            Sleep (0.2);


        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}
