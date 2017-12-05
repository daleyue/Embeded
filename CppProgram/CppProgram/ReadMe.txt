========================================================================
    CONSOLE APPLICATION : CppProgram Project Overview
========================================================================

AppWizard has created this CppProgram application for you.

This file contains a summary of what you will find in each of the files that
make up your CppProgram application.


CppProgram.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

CppProgram.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

CppProgram.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named CppProgram.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

C++ Notes with Example codes:
The test case in in CppProgram.cpp.

1) class tempClass:  used to show the sizeof sizeof empty class is 1; sizeof class with virtual is 8 (x64) 
   defined in CppProgram.cpp
2) class CMyString:  to show default constructor, Copy construct(to show deep/shallow copy)
                             Assignment operator(to show deep/shallow copy), use case
                             Bracket [] operator
                     to show the destructor in case of new/delete is involved.
   defined in CppProgram.cpp
3) class Time: to show operator +/-/* and <<, friend function usage
   defined in mytimer0.h
4) class Vector: to show namespace VECTOR usage, vector operation.
                         random numbers algorithm
                 testcase includes a drunk walking simulation
   defined in vect.h


/////////////////////////////////////////////////////////////////////////////
