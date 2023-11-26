// Exercise4.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

void CExercise4App::AddLine()
{
    // Get the current database 
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    // Open the Block Table for read-only
    AcDbBlockTable* pBlockTable;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    // Get the Model Space block
    AcDbBlockTableRecord* pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE,
        pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();
    // Define the points that will be used to define the Line object
    AcGePoint3d startPt(7.0, 3.0, 0.0);
    AcGePoint3d endPt(11.0, 3.0, 0.0);
    // Create the new Line object in memory
    AcDbLine* pLine = new AcDbLine(startPt, endPt);
    // Add the new Line object to Model space
    pBlockTableRecord->appendAcDbEntity(pLine);
    // Close the Model space block
    pBlockTableRecord->close();
    // Close the new line object
    pLine->close();
}

extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
    switch (Msg) {
    case AcRx::kInitAppMsg:
        acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        // below line for registering new command
        acedRegCmds->addCommand(L"AUCommands", _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CExercise4App::AddLine);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

BEGIN_MESSAGE_MAP(CExercise4App, CWinApp)
END_MESSAGE_MAP()


// CExercise4App construction

CExercise4App::CExercise4App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise4App object

CExercise4App theApp;


// CExercise4App initialization

BOOL CExercise4App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
