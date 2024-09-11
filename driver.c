#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int iPriority; /* Priority of the student to be enrolled */
    int iStudentID; /* ID of the student */
} WaitlistEntry;

WaitlistEntry createWL1( int iPriority, int iStudentID )
{
    WaitlistEntry w;
    w.iPriority = iPriority;
    w.iStudentID = iStudentID;
    return w;
}

WaitlistEntry* createWL2( int iPriority, int iStudentID )
{
    WaitlistEntry *pw = (WaitlistEntry*) malloc( sizeof(WaitlistEntry) );
    pw->iPriority = iPriority;
    pw->iStudentID = iStudentID;
    return pw;
}

WaitlistEntry* createWL3( int iPriority, int iStudentID )
{
    WaitlistEntry w;
    w.iPriority = iPriority;
    w.iStudentID = iStudentID;
    return &w;
}

void createWL4( WaitlistEntry w, int iPriority, int iStudentID )
{
    w.iPriority = iPriority;
    w.iStudentID = iStudentID;
}

WaitlistEntry createWL5( int iPriority, int iStudentID )
{
    WaitlistEntry *pw = (WaitlistEntry*) malloc( sizeof(WaitlistEntry) );
    pw->iPriority = iPriority;
    pw->iStudentID = iStudentID;
    return *pw;
}

/* precondition: pw is not NULL */
void createWL6( WaitlistEntry *pw, int iPriority, int iStudentID )
{
    pw->iPriority = iPriority;
    pw->iStudentID = iStudentID;
}

void createWL7( WaitlistEntry *pw, int iPriority, int iStudentID )
{
    pw = (WaitlistEntry*) malloc( sizeof(WaitlistEntry) );
    pw->iPriority = iPriority;
    pw->iStudentID = iStudentID;
}

/* precondition: ppw is not NULL */
void createWL8( WaitlistEntry **ppw, int iPriority, int iStudentID )
{
    *ppw = (WaitlistEntry*) malloc( sizeof(WaitlistEntry) );
    (*ppw)->iPriority = iPriority;
    (*ppw)->iStudentID = iStudentID;
}

int main( int argc, char *argv[] )
{
    WaitlistEntry     w;
    WaitlistEntry*   pw;
    WaitlistEntry** ppw;

    w = createWL1( 10, 1337 );
    printf( "createWL1: %d %d\n", w.iPriority, w.iStudentID );

    pw = createWL2( 10, 1337 );
    printf( "createWL2: %d %d\n", pw->iPriority, pw->iStudentID );
    free( pw );

    pw = createWL3( 10, 1337 );
    printf( "createWL3: %d %d\n", pw->iPriority, pw->iStudentID );
    //free( pw ); /* wasn't malloc-ed so not needed */

    w.iPriority = -1;
    w.iStudentID = -1;
    createWL4( w, 10, 1337 );
    printf( "createWL4: %d %d\n", w.iPriority, w.iStudentID );


    w = createWL5( 10, 1337 );
    printf( "createWL5: %d %d\n", w.iPriority, w.iStudentID );

    w.iPriority = -1;
    w.iStudentID = -1;
    createWL6( &w, 10, 1337 );
    printf( "createWL6: %d %d\n", w.iPriority, w.iStudentID );

    w.iPriority = -1;
    w.iStudentID = -1;
    pw = &w;
    createWL7( pw, 10, 1337 );
    printf( "createWL7: %d %d\n", pw->iPriority, pw->iStudentID );

    w.iPriority = -1;
    w.iStudentID = -1;
    pw = &w;
    createWL8( &pw, 10, 1337 );
    printf( "createWL8: %d %d\n", pw->iPriority, pw->iStudentID );
    free( pw );

    return 0;
}
