/**
 * @file graficos.c
 * @author Jose Luis Cruz (j0z3ph@gmail.com)
 * @brief Traduccion a C de MiniWin. Un mini-conjunto de funciones para abrir una ventana, pintar en
 *    ella y detectar la presión de algunas teclas. Básicamente para hacer
 *    juegos sencillos.
 *    Basado en el trabajo de Pau Fernández.
 * @version 0.2
 * @date 2023-12-09
 *
 *  MiniWin: Un mini-conjunto de funciones para abrir una ventana, pintar en
 *    ella y detectar la presión de algunas teclas. Básicamente para hacer
 *    juegos sencillos.
 *
 *  (c) Pau Fernández, licencia MIT: http://es.wikipedia.org/wiki/MIT_License
 *
 *
 * Git original: https://github.com/pauek/MiniWin
 * Git: https://github.com/j0z3ph/Miniwin
 */

#if defined(_WIN32)

// Windows ////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>
#include <stdarg.h>

#define _GRAFICOS_SOURCE_
#define CLASS_NAME "GraficosXD"
#include "graficos.h"

// Constantes

const struct Teclas TECLAS = {
    VK_ESCAPE,
    VK_LEFT,
    VK_RIGHT,
    VK_UP,
    VK_DOWN,
    VK_F1,
    VK_F2,
    VK_F3,
    VK_F4,
    VK_F5,
    VK_F6,
    VK_F7,
    VK_F8,
    VK_F9,
    VK_F10,
    VK_SPACE,
    VK_RETURN,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90,
    0};

const struct Colores COLORES = {0, 1, 2, 3, 4, 5, 6, 7};

// Estructuras

struct imagen
{
    HGDIOBJ hBitmap;
    HGDIOBJ hBitmap_mask;
    int alto;
    int ancho;

    HDC hdcimg;
    HDC hdcimg_mask;
};

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
} Queue;

// Variables globales

static HWND hWnd;                                 // ventana principal
static HBITMAP hBitmap;                           // bitmap para pintar off-screen
static int iWidth = 400;                          // ancho de la ventana
static int iHeight = 300;                         // alto de la ventana
static HDC hDCMem = NULL;                         // Device Context en memoria
static bool _raton_dentro;                        // el raton esta dentro del 'client area'
static int _xraton, _yraton;                      // posicion del raton
static bool _bot_izq, _bot_der;                   // botones izquierdo y derecho
static WINDOWPLACEMENT g_wpPrev;                  // respaldo de la posicion de la ventana antes de ir a fullscreen
static int iWidthPrev;                            // respaldo del ancho de la ventana antes de ir a fullscreen
static int iHeightPrev;                           // respaldo del alto de la ventana antes de ir a fullscreen
static bool _fullscreen = false;                  // modo fullscreen
static Queue *keyDownQueue = NULL;                // Cola para las teclas presionadas
static Queue *keyUpQueue = NULL;                  // Cola para las teclas soltadas
static COLORREF _color = RGB(255, 255, 255);      // Color de la brocha (blanco por defecto)
static COLORREF _back_color = RGB(255, 255, 255); // Color del fondo de la ventana (blanco por defecto)
static COLORREF _colores[] = {
    RGB(0, 0, 0),       // NEGRO
    RGB(255, 0, 0),     // ROJO
    RGB(0, 255, 0),     // VERDE
    RGB(0, 0, 255),     // AZUL
    RGB(255, 255, 0),   // AMARILLO
    RGB(255, 0, 255),   // MAGENTA
    RGB(0, 255, 255),   // CYAN
    RGB(255, 255, 255), // BLANCO
};

// Declaraciones de funciones

static LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
static VOID Thread(PVOID pvoid);
static void maybe_call_main();
static void frame_real(int w, int h, int *rw, int *rh);
static void newMemDC(int w, int h);
static bool validKey(const WPARAM *wParam);
static void queue_push(Queue **queue, int val);
static int queue_front(Queue **queue);
static int queue_pop(Queue **queue);
static bool queue_empty(Queue **queue);
static void queue_clear(Queue **queue);

// Funcion Principal

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nFunsterStil)
{
    static WNDCLASSEX wincl;
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = CLASS_NAME;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);

    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

    if (!RegisterClassEx(&wincl))
        return 0;

    int w, h, xPos, yPos;
    frame_real(iWidth, iHeight, &w, &h);

    // Centra la ventana
    xPos = (GetSystemMetrics(SM_CXSCREEN) - w) / 2;
    yPos = (GetSystemMetrics(SM_CYSCREEN) - h) / 2;

    hWnd = CreateWindowEx(
        0,                                     /* Extended possibilites for variation */
        CLASS_NAME,                            /* Classname */
        _GRAFICOS_VERSION_,                    /* Title Text */
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, /* no resizable window */
        xPos,                                  /* The window position  */
        yPos,                                  /* in x and y coordinates */
        w,                                     /* The programs width */
        h,                                     /* and height in pixels */
        HWND_DESKTOP,                          /* The window is a child-window to desktop */
        NULL,                                  /* No menu */
        hThisInstance,                         /* Program Instance handler */
        NULL                                   /* No Window Creation data */
    );

    hBitmap = NULL;

    ShowWindow(hWnd, nFunsterStil);

    MSG messages;
    while (GetMessage(&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

// Definicion de funciones

static LRESULT CALLBACK WindowProcedure(HWND hWnd,
                                        UINT message,
                                        WPARAM wParam,
                                        LPARAM lParam)
{
    switch (message)
    {
    case WM_SIZE:
    {
        RECT R;
        GetClientRect(hWnd, &R);
        int w = R.right - R.left;
        int h = R.bottom - R.top;
        if (w == 0 && h == 0)
            break; // Al minimizar envia WM_SIZE(0,0)

        if (hDCMem == NULL || w != iWidth || h != iHeight)
        {
            newMemDC(w, h);
            maybe_call_main();
        }
        break;
    }
    case WM_SIZING:
    {
        RECT *pRECT = (RECT *)lParam;
        int w, h;
        frame_real(iWidth, iHeight, &w, &h);
        switch (wParam)
        {
        case WMSZ_BOTTOM:
            pRECT->bottom = pRECT->top + h;
            break;
        case WMSZ_TOP:
            pRECT->top = pRECT->bottom - h;
            break;
        case WMSZ_RIGHT:
            pRECT->right = pRECT->left + w;
            break;
        case WMSZ_LEFT:
            pRECT->left = pRECT->right - w;
            break;
        case WMSZ_TOPLEFT:
            pRECT->top = pRECT->bottom - h;
            pRECT->left = pRECT->right - w;
            break;
        case WMSZ_TOPRIGHT:
            pRECT->top = pRECT->bottom - h;
            pRECT->right = pRECT->left + w;
            break;
        case WMSZ_BOTTOMLEFT:
            pRECT->bottom = pRECT->top + h;
            pRECT->left = pRECT->right - w;
            break;
        case WMSZ_BOTTOMRIGHT:
            pRECT->bottom = pRECT->top + h;
            pRECT->right = pRECT->left + w;
            break;
        }

        return TRUE;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        HGDIOBJ oldBitmap = SelectObject(hDCMem, hBitmap);
        if (hBitmap != NULL)
        {
            BitBlt(hdc, 0, 0, iWidth, iHeight, hDCMem, 0, 0, SRCCOPY);
        }
        SelectObject(hDCMem, oldBitmap);
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_MOUSEMOVE:
    {
        _raton_dentro = true;
        _xraton = GET_X_LPARAM(lParam);
        _yraton = GET_Y_LPARAM(lParam);
        _bot_izq = wParam & MK_LBUTTON;
        _bot_der = wParam & MK_RBUTTON;
        break;
    }
    case WM_MOUSELEAVE:
    {
        _raton_dentro = false;
        break;
    }
    case WM_LBUTTONDOWN:
    {
        _bot_izq = true;
        break;
    }
    case WM_LBUTTONUP:
    {
        _bot_izq = false;
        break;
    }
    case WM_RBUTTONDOWN:
    {
        _bot_der = true;
        break;
    }
    case WM_RBUTTONUP:
    {
        _bot_der = false;
        break;
    }
    case WM_KEYDOWN:
    {
        if (validKey(&wParam))
            queue_push(&keyDownQueue, wParam);

        break;
    }
    case WM_KEYUP:
    {
        if (validKey(&wParam))
            queue_push(&keyUpQueue, wParam);

        break;
    }

    case WM_DESTROY:
    {
        DeleteObject(hBitmap);
        DeleteDC(hDCMem);
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

static bool validKey(const WPARAM *wParam)
{
    bool push_it = false;

    // Escape
    push_it |= (*wParam == VK_ESCAPE);

    // Flechas
    push_it |= (*wParam == VK_LEFT ||
                *wParam == VK_RIGHT ||
                *wParam == VK_UP ||
                *wParam == VK_DOWN);

    // Barra espaciadora
    push_it |= (*wParam == VK_SPACE);

    // Enter
    push_it |= (*wParam == VK_RETURN);

    // Numeros 0-9
    push_it |= (*wParam >= 48 && *wParam <= 57);

    // Letras A-Z
    push_it |= (*wParam >= 65 && *wParam <= 90);

    // Teclas de funcion
    for (int i = 0; i < 10; i++)
        push_it |= (*wParam == (VK_F1 + i));

    return push_it;
}

static VOID Thread(PVOID pvoid)
{
    Sleep(50); // FIXME
    _main_();
}

static void maybe_call_main()
{
    static bool started = false;
    if (!started)
    {
        _beginthread(Thread, 0, NULL); // Llama a 'main' (realmente  '_main_')
        started = true;
    }
}

static void frame_real(int w, int h, int *rw, int *rh)
{
    RECT frame = {0, 0, w, h};
    AdjustWindowRect(&frame, WS_OVERLAPPEDWINDOW, FALSE);
    *rw = frame.right - frame.left;
    *rh = frame.bottom - frame.top;
}

static void newMemDC(int w, int h)
{
    if (hDCMem != NULL)
    {
        DeleteObject(hBitmap);
        DeleteDC(hDCMem);
    }
    HDC hDC = GetDC(hWnd);
    hDCMem = CreateCompatibleDC(hDC);
    hBitmap = CreateCompatibleBitmap(hDC, w, h);
    SelectObject(hDCMem, hBitmap);
    SetBkMode(hDCMem, TRANSPARENT);
    ReleaseDC(hWnd, hDC);
}

// Funciones para la Cola

static void queue_push(Queue **queue, int val)
{
    if (*queue == NULL)
    {
        *queue = (Queue *)malloc(sizeof(Queue));
        (*queue)->head = (Node *)malloc(sizeof(Node));
        (*queue)->head->value = val;
        (*queue)->head->next = NULL;
        (*queue)->tail = (*queue)->head;
    }
    else
    {
        (*queue)->tail->next = (Node *)malloc(sizeof(Node));
        (*queue)->tail = (*queue)->tail->next;
        (*queue)->tail->value = val;
        (*queue)->tail->next = NULL;
    }
}

static int queue_front(Queue **queue)
{
    int val = -1;
    if (*queue != NULL)
    {
        val = (*queue)->head->value;
    }

    return val;
}

static int queue_pop(Queue **queue)
{
    int val = -1;
    if (*queue != NULL)
    {
        val = (*queue)->head->value;
        Node *tmp = (*queue)->head;
        (*queue)->head = (*queue)->head->next;
        free(tmp);
        if ((*queue)->head == NULL)
        {
            free(*queue);
            *queue = NULL;
        }
    }

    return val;
}

static bool queue_empty(Queue **queue)
{
    return *queue == NULL;
}

static void queue_clear(Queue **queue)
{
    if (*queue != NULL)
    {
        Queue *q = *queue;
        *queue = NULL;
        Node *tmp;
        while (q->head != NULL)
        {
            tmp = q->head;
            q->head = q->head->next;
            free(tmp);
        }
        free(q);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//   Funciones del API
//
////////////////////////////////////////////////////////////////////////////////

void imprimeEnConsola(const char *format, ...)
{
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdOut == NULL || stdOut == INVALID_HANDLE_VALUE)
    {
        AllocConsole();
        stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    if (stdOut != NULL && stdOut != INVALID_HANDLE_VALUE)
    {
        DWORD written = 0;
        static char buffer[4096];
        va_list args;
        va_start(args, format);
        memset(buffer, 0, sizeof(buffer));
        vsnprintf(buffer, sizeof(buffer), format, args);

        WriteConsoleA(stdOut, buffer, strlen(buffer), &written, NULL);

        va_end(args);
    }
}

int teclaPresionada()
{
    if (queue_empty(&keyDownQueue))
        return TECLAS.NINGUNA;

    return queue_pop(&keyDownQueue);
}

int teclaSoltada()
{
    if (queue_empty(&keyUpQueue))
        return TECLAS.NINGUNA;

    int key = queue_pop(&keyUpQueue);

    while(queue_front(&keyDownQueue) == key) queue_pop(&keyDownQueue);

    return key;
}

bool raton(int *x, int *y)
{
    if (!_raton_dentro)
        return false;

    *x = _xraton;
    *y = _yraton;
    return true;
}

bool ratonEnVentana()
{
    return _raton_dentro;
}

int ratonX()
{
    return _xraton;
}

int ratonY()
{
    return _yraton;
}

void ratonBotones(bool *izq, bool *der)
{
    *izq = _bot_izq;
    *der = _bot_der;
}

bool ratonBotonIzquierdo()
{
    return _bot_izq;
}

bool ratonBotonDerecho()
{
    return _bot_der;
}

void espera(int miliseg)
{
    Sleep(miliseg);
}

void muestraMensaje(const char *msj)
{
    MessageBox(hWnd, msj, "Mensaje...", MB_OK);
}

void muestraMensaje1(const char *msj, const char *titulo)
{
    MessageBox(hWnd, msj, titulo, MB_OK);
}

bool muestraPregunta(const char *msj)
{
    return MessageBox(hWnd, msj, "Pregunta...", MB_OKCANCEL) == IDOK;
}

bool muestraPregunta1(const char *msj, const char *titulo)
{
    return MessageBox(hWnd, msj, titulo, MB_OKCANCEL) == IDOK;
}

void limpiaVentana()
{
    RECT R;
    SetRect(&R, 0, 0, iWidth, iHeight);
    HBRUSH hBrush = CreateSolidBrush(_back_color);
    FillRect(hDCMem, &R, hBrush);
    DeleteObject(hBrush);
}

void actualizaVentana()
{
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_INTERNALPAINT);
}

void punto(int x, int y)
{
    SetPixel(hDCMem, x, y, _color);
}

void linea(int x1, int y1, int x2, int y2)
{
    BeginPath(hDCMem);
    MoveToEx(hDCMem, x1, y1, NULL);
    LineTo(hDCMem, x2, y2);
    EndPath(hDCMem);
    HPEN hPen = CreatePen(PS_SOLID, 1, _color);
    HGDIOBJ orig = SelectObject(hDCMem, hPen);
    StrokePath(hDCMem);
    SelectObject(hDCMem, orig);
    DeleteObject(hPen);
}

static void _rect(int x1, int y1, int x2, int y2, bool fill)
{
    RECT rect = {x1, y1, x2, y2};
    HBRUSH brush = CreateSolidBrush(_color);
    if (fill)
        FillRect(hDCMem, &rect, brush);
    else
        FrameRect(hDCMem, &rect, brush);
    DeleteObject(brush);
}

void rectangulo(int x1, int y1, int x2, int y2)
{
    _rect(x1, y1, x2, y2, false);
}

void rectanguloRelleno(int x1, int y1, int x2, int y2)
{
    _rect(x1, y1, x2, y2, true);
}

static void _circ(int x, int y, int radio, bool fill)
{
    HPEN hPen = CreatePen(PS_SOLID, 1, _color);
    HGDIOBJ orig = SelectObject(hDCMem, hPen);

    if (fill)
    {
        HBRUSH brush = CreateSolidBrush(_color);
        SelectObject(hDCMem, brush);
        Ellipse(hDCMem, x - radio, y - radio, x + radio, y + radio);
        DeleteObject(brush);
    }
    else
    {
        SelectObject(hDCMem, GetStockObject(NULL_BRUSH));
        Ellipse(hDCMem, x - radio, y - radio, x + radio, y + radio);
    }
    SelectObject(hDCMem, orig);
    DeleteObject(hPen);
}

void circulo(int x, int y, int radio)
{
    _circ(x, y, radio, false);
}

void circuloRelleno(int x, int y, int radio)
{
    _circ(x, y, radio, true);
}

void texto(int x, int y, const char *texto)
{
    SetTextColor(hDCMem, _color);
    TextOut(hDCMem, x, y, texto, strlen(texto));
}

void texto1(int x, int y, const char *texto, int tamanioFuente, const char *fuente)
{
    HFONT hf, hforiginal;
    hf = CreateFont(tamanioFuente, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, fuente);
    hforiginal = (HFONT)SelectObject(hDCMem, hf);
    SetTextColor(hDCMem, _color);
    TextOut(hDCMem, x, y, texto, strlen(texto));
    SelectObject(hDCMem, hforiginal);
    DeleteObject(hf);
}

void texto2(int x, int y, const char *texto, int tamanioFuente, const char *fuente,
            bool italica, bool negrita, bool subrayada)
{
    HFONT hf, hforiginal;
    hf = CreateFont(tamanioFuente, 0, 0, 0, (negrita ? FW_BOLD : FW_NORMAL), italica, subrayada, 0, 0, 0, 0, 0, 0, fuente);
    hforiginal = (HFONT)SelectObject(hDCMem, hf);
    SetTextColor(hDCMem, _color);
    TextOut(hDCMem, x, y, texto, strlen(texto));
    SelectObject(hDCMem, hforiginal);
    DeleteObject(hf);
}

Imagen *creaImagenConMascara(const char *ruta, const char *ruta_mask)
{
    Imagen *image = (Imagen *)malloc(sizeof(Imagen));
    BITMAP bitmap;
    image->alto = 0;
    image->ancho = 0;
    image->hBitmap = (HBITMAP)LoadImageA(NULL, ruta, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    image->hBitmap_mask = (HBITMAP)LoadImageA(NULL, ruta_mask, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    if (image->hBitmap == NULL || image->hBitmap_mask == NULL)
    {
        free(image);
        image = NULL;
    }
    GetObject(image->hBitmap, sizeof(bitmap), &bitmap);
    image->ancho = bitmap.bmWidth;
    image->alto = bitmap.bmHeight;

    image->hdcimg = CreateCompatibleDC(NULL);
    SelectObject(image->hdcimg, image->hBitmap);

    image->hdcimg_mask = CreateCompatibleDC(NULL);
    SelectObject(image->hdcimg_mask, image->hBitmap_mask);

    return image;
}

Imagen *creaImagen(const char *ruta)
{
    return creaImagenConMascara(ruta, ruta);
}

void eliminaImagen(Imagen *imagen)
{
    if (imagen != NULL)
    {
        DeleteObject(imagen->hBitmap);
        DeleteObject(imagen->hBitmap_mask);
        DeleteDC(imagen->hdcimg);
        DeleteDC(imagen->hdcimg_mask);
        free(imagen);
        imagen = NULL;
    }
}

static void _renderImage(int x, int y, int w, int h, const Imagen *imagen)
{
    if (imagen != NULL)
    {
        SetStretchBltMode(hDCMem, COLORONCOLOR);

        if (imagen->hBitmap_mask != NULL)
        {
            if (imagen->alto == h && imagen->ancho == w)
            {
                BitBlt(hDCMem, x, y, w, h,
                       imagen->hdcimg_mask, 0, 0, SRCAND);
            }
            else
            {
                StretchBlt(hDCMem, x, y, w, h,
                           imagen->hdcimg_mask, 0, 0, imagen->ancho, imagen->alto, SRCAND);
            }
            if (imagen->hBitmap != NULL)
            {
                if (imagen->alto == h && imagen->ancho == w)
                {
                    BitBlt(hDCMem, x, y, w, h,
                               imagen->hdcimg, 0, 0, SRCPAINT);
                }
                else
                {
                    StretchBlt(hDCMem, x, y, w, h,
                               imagen->hdcimg, 0, 0, imagen->ancho, imagen->alto, SRCPAINT);
                }
            }
        }
    }
}

void muestraImagen(int x, int y, const Imagen *imagen)
{
    _renderImage(x, y, imagen->ancho, imagen->alto, imagen);
}

void muestraImagenEscalada(int x, int y, int ancho, int alto, const Imagen *imagen)
{
    _renderImage(x, y, ancho, alto, imagen);
}

int altoImagen(const Imagen *imagen)
{
    return imagen->alto;
}

int anchoImagen(const Imagen *imagen)
{
    return imagen->ancho;
}

void color(int c)
{
    if (c >= 0 && c <= 7)
        _color = _colores[c];
    else
        _color = _colores[0];
}

void colorRGB(UINT8 r, UINT8 g, UINT8 b)
{
    _color = RGB(r, g, b);
}

void colorFondo(int c)
{
    if (c >= 0 && c <= 7)
        _back_color = _colores[c];
    else
        _back_color = _colores[0];
}

void colorFondoRGB(UINT8 r, UINT8 g, UINT8 b)
{
    _back_color = RGB(r, g, b);
}

int anchoVentana()
{
    return iWidth;
}

int altoVentana()
{
    return iHeight;
}

void tamanioVentana(int ancho, int alto)
{
    iWidth = ancho;
    iHeight = alto;
    int w, h;
    int xPos;
    int yPos;

    frame_real(iWidth, iHeight, &w, &h);

    // Centra la ventana
    xPos = (GetSystemMetrics(SM_CXSCREEN) - w) / 2;
    yPos = (GetSystemMetrics(SM_CYSCREEN) - h) / 2;

    SetWindowPos(hWnd, HWND_TOP, xPos, yPos, w, h, SWP_FRAMECHANGED);
    newMemDC(w, h);
}

void pantallaCompleta(bool fullscreenOn)
{
    DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE);
    if (fullscreenOn && !_fullscreen)
    {
        MONITORINFO mi = {sizeof(mi)};
        if (GetWindowPlacement(hWnd, &g_wpPrev) &&
            GetMonitorInfo(MonitorFromWindow(hWnd, MONITOR_DEFAULTTOPRIMARY), &mi))
        {
            SetWindowLong(hWnd, GWL_STYLE,
                          dwStyle & ~WS_OVERLAPPEDWINDOW);
            SetWindowPos(hWnd, HWND_TOP,
                         mi.rcMonitor.left, mi.rcMonitor.top,
                         mi.rcMonitor.right - mi.rcMonitor.left,
                         mi.rcMonitor.bottom - mi.rcMonitor.top,
                         SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
            iWidthPrev = iWidth;
            iHeightPrev = iHeight;
            iWidth = mi.rcMonitor.right - mi.rcMonitor.left;
            iHeight = mi.rcMonitor.bottom - mi.rcMonitor.top;
            _fullscreen = true;
            limpiaVentana();
            actualizaVentana();
        }
    }
    else if (!fullscreenOn && _fullscreen)
    {
        SetWindowLong(hWnd, GWL_STYLE,
                      dwStyle | WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX);
        SetWindowPlacement(hWnd, &g_wpPrev);
        iWidth = iWidthPrev;
        iHeight = iHeightPrev;
        _fullscreen = false;
        tamanioVentana(iWidth, iHeight);
        limpiaVentana();
        actualizaVentana();
    }
}

void cierraVentana()
{
    PostMessage(hWnd, WM_CLOSE, 0, 0);
}

void tituloVentana(const char *titulo)
{
    SetWindowTextA(hWnd, titulo);
}

// Estructura de Ventana

const struct Ventana ventana = {
    imprimeEnConsola,
    pantallaCompleta,
    colorFondo,
    colorFondoRGB,
    creaImagen,
    creaImagenConMascara,
    eliminaImagen,
    muestraImagen,
    muestraImagenEscalada,
    altoImagen,
    anchoImagen,
    texto1,
    texto2,
    teclaSoltada,
    teclaPresionada,
    limpiaVentana,
    actualizaVentana,
    muestraMensaje,
    muestraMensaje1,
    muestraPregunta,
    muestraPregunta1,
    espera,
    anchoVentana,
    altoVentana,
    tamanioVentana,
    cierraVentana,
    tituloVentana,
    color,
    colorRGB,
    punto,
    linea,
    rectangulo,
    rectanguloRelleno,
    circulo,
    circuloRelleno,
    texto,
    raton,
    ratonEnVentana,
    ratonX,
    ratonY,
    ratonBotones,
    ratonBotonIzquierdo,
    ratonBotonDerecho};

///////////////////////////////////////////////////////////////////////////////////////

#else

#error "Graficos no funciona en esta plataforma"

#endif
