// OpenglTestView.cpp : implementation of the COpenglTestView class
//

#include "stdafx.h"
#include "OpenglTest.h"

#include "OpenglTestDoc.h"
#include "OpenglTestView.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

float Objective(GAGenome&);

/////////////////////////////////////////////////////////////////////////////
// COpenglTestView

IMPLEMENT_DYNCREATE(COpenglTestView, CView)

BEGIN_MESSAGE_MAP(COpenglTestView, CView)
	//{{AFX_MSG_MAP(COpenglTestView)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenglTestView construction/destruction

COpenglTestView::COpenglTestView()
{
	//����ڰ� ������ ������ COpenglTestView.h ���Ͽ��� 
	//������ �������� �ʱ�ȭ�մϴ�.
	popsize = 30;
	ngen = 50;
	pmut = 0.01;
	pcross = 0.60;
	nvar = 2;
	min = -5.00;   
	max = 5.00; 
	nbit = 16;
	for(int i=0;i<nvar;i++)
		map.add(nbit,min,max);
	genome = new GABin2DecGenome(map,Objective);

	ga = new GASimpleGA(*genome);
	ga->scaling(scaling);
	ga->populationSize(popsize);
	ga->pMutation(pmut);
	ga->pCrossover(pcross);
	ga->nGenerations(ngen);

	// TODO: add construction code here
	X1 = -5.0*3;
	X2 = -5.0*3;
	Y = (-X1*X1-X2*X2)/50.0;

	m_spinx=0;
	m_spiny=0;
	m_lbutton=FALSE;

	double n1,n2;

	// �׷����� �׸��� ���� y���� ����ϰ� �����մϴ�.
	for(i=0;i<30;i++)
	{
		for(int j=0;j<30;j++)
		{
			n1=i-15.0;
			n2=j-15.0;
			m_y[i][j] = (-n1*n1-n2*n2)/50.0;
		}
	}

	m_Exec = FALSE;

}

COpenglTestView::~COpenglTestView()
{
	//�������� �Ҵ�� �޸𸮸� �����մϴ�.
	delete genome;
	delete ga;
	if(m_Exec)
		delete MyBar;
}

BOOL COpenglTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COpenglTestView drawing

void COpenglTestView::OnDraw(CDC* pDC)
{
	COpenglTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	// ���ο� ����� ���� �÷� ���ۿ� ���� ���۸� �ʱ�ȭ�մϴ�.
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); 
	                                                     
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	InitProjection();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawScene();

	glFlush();			
	SwapBuffers(hDC);	
	                    
}

/////////////////////////////////////////////////////////////////////////////
// COpenglTestView printing

BOOL COpenglTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpenglTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpenglTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COpenglTestView diagnostics

#ifdef _DEBUG
void COpenglTestView::AssertValid() const
{
	CView::AssertValid();
}

void COpenglTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenglTestDoc* COpenglTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenglTestDoc)));
	return (COpenglTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Objective Function

float Objective(GAGenome& c)
{
	//TODO : Add your own Objective function here
	float y;
	GABin2DecGenome & genome = (GABin2DecGenome &)c;
	y=-genome.phenotype(0)*genome.phenotype(0);
	y-=genome.phenotype(1)*genome.phenotype(1);
	return y;
}

void COpenglTestView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_Exec)
	{
		MyBar = new CProgressBar(_T("Optimizing..."),90,ngen);
		CString Coord;
	
		// ������ �˰����� ������ ���ϱ� ���� initialize ����Լ���
		// ������� �ʰ� ���� ǥ������ �����մϴ�.
		for(int i=0;i<popsize;i++)
		{
			GABin2DecGenome & genome = (GABin2DecGenome &)(ga->population().individual(i));
			genome.phenotype(0,-15.0+0.01*i);
			genome.phenotype(1,-15.0+0.01*i);
		}
		//ga->initialize();
		//DrawSphere();
		while(!ga->done())
		{
			ga->step();
			DrawSphere();
			Coord.Format("(%6.5f,%6.5f)",X1,X2);
			MyBar->SetText(Coord);					// ���� ��ǥ�� ����մϴ�.
			MyBar->StepIt();						// ���α׷��� �ٸ� �Ѵܰ� �����ŵ�ϴ�.
		}

		m_Exec = TRUE;
	}

		CView::OnRButtonDown(nFlags, point);
}

//OpenGL ���� �Լ�.

void COpenglTestView::SetDCPixelFormat(HDC hDC)
{
    int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),	// PIXELFORMATDESCRIPTOR�� ũ��
		1,					// ����	
		PFD_DRAW_TO_WINDOW |		// support window
		PFD_SUPPORT_OPENGL |		// Support OpenGL 
		PFD_DOUBLEBUFFER,			// Double buffered mode
		PFD_TYPE_RGBA,			// RGBA type
		16,					// 16 bit color depth
		0,0,0,0,0,0,		// color bits ignored
		0,					// no alpha buffer
		0,					// shift bit ignored
		0,					// no accumulation buffer
		0,0,0,0,			// accum bits ignored
		24,					// Size of depth buffer
		0,					// Not used to select mode
		PFD_MAIN_PLANE,		// Draw in main plane
		0,					// Not used to select mode
		0,					// Not used to select mode
		0,0,0 };			// Not used to select mode

	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

	SetPixelFormat(hDC, nPixelFormat, &pfd);
}

void COpenglTestView::InitOpenGL(void)
{
	glEnable(GL_DEPTH_TEST);		// depth buffering(z-buffering) ����

	glEnable(GL_NORMALIZE);			// ������ ���Ե� vector���� �ڵ����� unit vector�� ��ȯ�մϴ�.
	glEnable(GL_COLOR_MATERIAL);

	Obj=gluNewQuadric();
	
	InitLight();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);	// projection matrix�� �ʱ�ȭ
	glLoadIdentity();

	InitProjection();

	glMatrixMode(GL_MODELVIEW);		// modelview matrix�� �ʱ�ȭ
	glLoadIdentity();
}

void COpenglTestView::InitLight()
{
	// ���� ������ ���� �迭
	GLfloat lightposition[4] = {10.0f, 10.0f, 10.0f, 1.0f};
	GLfloat globalambient[4] = {0.3f, 0.3f, 0.3f, 1.0f};
	GLfloat lightcolor[4] = {0.9f, 0.9f, 0.9f, 1.0f};

	// ���� ������ ���� �迭
	GLfloat matambient[4] = {0.1f, 0.1f, 0.1f, 0.6f};
	GLfloat matdiffuse[4] = {0.6f, 0.8f, 0.6f, 0.6f};
	GLfloat matspecular[4] = {0.9f, 0.9f, 0.9f, 0.7f};
	GLbyte shine = 40;

	glEnable(GL_LIGHTING);                                        // ����ȿ�� �̿�
	glEnable(GL_LIGHT0);                                          // ����0 ON

	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);             // ������ ��ġ����
	glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, lightcolor);     // ������ �� ����
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalambient);        // ambient ������ ����


	glMaterialfv(GL_FRONT, GL_AMBIENT, matambient);               // ��ü�� Ambient color���� ����
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matdiffuse);               // ��ü�� diffuse color���� ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, matspecular);             // ��ü�� spectular color���� ����
	glMaterialf(GL_FRONT, GL_SHININESS, shine);                   // ��ü�� shininess���� ����
}

void COpenglTestView::InitProjection()
{
	glShadeModel(GL_SMOOTH);     
	gluPerspective( 45.0f, (float)width/height, 2.0f, 100.0f );		// �þ߰��� 45���� ��ü���� projection
	gluLookAt( 2.0f, 4.0f, 17.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f );
																	// (2,4,17)���� (0,0,0)�� y�� orientation���� �ٶ�
}

void COpenglTestView::DrawScene()
{
	glPushMatrix();

		glRotatef(m_spinx, 0.0f, 1.0f, 0.0f);		// OnMouseMove���� ���� ȸ������ ���� rotation�� �����մϴ�.
		glRotatef(m_spiny-90.0f, 1.0f, 0.0f, 0.0f);

		double n1,n2;
		glBegin(GL_LINES);
		glColor3d(0.5, 0.5, 0.5);
		for(int i=0;i<29;i++)
		{
			for(int j=0;j<29;j++)
			{				
				n1 = (i-15.0)/2.5;
				n2 = (j-15.0)/2.5;				
				glVertex3d(n1,n2,m_y[i][j]+5);
				glVertex3d(n1+0.4,n2,m_y[i+1][j]+5);
				glVertex3d(n1,n2,m_y[i][j]+5);
				glVertex3d(n1,n2+0.4,m_y[i][j+1]+5);
			}
		}
		for(i=0;i<29;i++)
		{
			n1=(i-15.0)/2.5;
			glVertex3d(n1,6.0-0.4,m_y[i][29]+5);
			glVertex3d(n1+0.4,6.0-0.4,m_y[i+1][29]+5);
			glVertex3d(6.0-0.4,n1,m_y[29][i]+5);
			glVertex3d(6.0-0.4,n1+0.4,m_y[29][i+1]+5);
		}
		glEnd();
		
		// ������ �˰����� �̿��Ͽ� ���� ��ǥ���� �̿��Ͽ� ���� �׸��ϴ�.
		glColor3d(1.0, 0.0, 0.0);
		glTranslatef(X1/2.5,X2/2.5,Y+5);
		gluQuadricDrawStyle(Obj, GLU_FILL);
		gluSphere(Obj, 0.3f, 10, 10 );

	glPopMatrix();
}

void COpenglTestView::DrawSphere()
{
	// �� ������ ���� ��ü�� �̿��Ͽ� ��ǥ���� ���� �� OnDraw�Լ��� ȣ���մϴ�.
	GABin2DecGenome & genome = (GABin2DecGenome &)(ga->population().best());
	X1 = genome.phenotype(0)*3.0;
	X2 = genome.phenotype(1)*3.0;
	Y = -X1*X1 - X2*X2;
	Y /= 50.0;
	InvalidateRect(NULL, FALSE);
    UpdateWindow();
	
}


void COpenglTestView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_lbutton = TRUE; 
	m_prevpoint.x=point.x;
	m_prevpoint.y=point.y;
	CView::OnLButtonDown(nFlags, point);
}

void COpenglTestView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_lbutton = FALSE; 
	CView::OnLButtonUp(nFlags, point);
}

void COpenglTestView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_lbutton)
	{
		m_spinx += (float)point.x-(float)m_prevpoint.x;
		m_spiny += (float)point.y-(float)m_prevpoint.y;

		m_prevpoint.x = point.x;
		m_prevpoint.y = point.y;

		InvalidateRect(NULL, FALSE);
	}
	CView::OnMouseMove(nFlags, point);
}

int COpenglTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	hDC = ::GetDC(m_hWnd);			// ����̽� ���ؽ�Ʈ�� ����ϴ�.
	SetDCPixelFormat(hDC);			// �ȼ� ���� ����	
	hRC = wglCreateContext(hDC);	// ������ ���ؽ�Ʈ�� ����ϴ�.
	wglMakeCurrent(hDC, hRC);		// ������ ������ ���ؽ�Ʈ�� ����ϴ�.
	InitOpenGL();
	
	return 0;
}

void COpenglTestView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	
	CWnd::OnDestroy();
	wglMakeCurrent(hDC,NULL);		// ���� ������ ���ؽ�Ʈ ����
	wglDeleteContext(hRC);			// ������ ���ؽ�Ʈ ����
	::ReleaseDC( m_hWnd, hDC );		// ����̽� ���ؽ�Ʈ ����
}

void COpenglTestView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	width=cx;
	height=cy;
	
	if(cx && cy)                            // ���� �������� ���γ� ���� ���̰� 0 �� �ƴ϶��
	{                                       // �׿� ���� OpenGL�� ViewPort�� �������Ѵ�.
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		InitProjection();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();					// Matrix �ʱ�ȭ

		glViewport(0, 0, cx, cy);			// viewport�� ũ�⸦ Ŭ���̾�Ʈ ��ü �������� ����
	}
}
