#if defined(WIN32)
#include <windows.h>
#endif

#include <ctype.h>


#include "YourInterceptor.h"

// Cleanup class -- suggested
class Cleanup
{
    public:
    Cleanup() {}
    ~Cleanup()
    {
        // <<<Fill in your code here>>>

    }
};
static Cleanup CleanupOnImageExit;

#define SECURITY_BUFFSIZE   100

#if defined(WIN32)
// suggestion for standard DLL processing

BOOL WINAPI DllMain( HANDLE hDLL,
             DWORD  dwReason,
             LPVOID lpReserved )
{
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
            break;
    case DLL_PROCESS_DETACH:
            break;
    case DLL_THREAD_ATTACH:
            break;
    case DLL_THREAD_DETACH:
            break;
    }

    // Return that the operation was successful
    return( TRUE );
    }
#endif  /* WIN32 */

/*************************************************************

   FUNCTION NAME:       YourInterceptorInit
   @CESARVERSATTI  
 
   FUNCTIONAL DESCRIPTION:
 
        Initialization routine called by the ORB during initialization.
        This routine will create and return instances of the 
        RequestLevelInterceptor classes that it supports.

        NOTE: An interceptor library can support more than one set of 
        interceptors by supplying multiple initialization entry points 
        (each initialization entry must be separately registered with the 
        ORB) Also, it is legal for only one kind of interceptor to be 
        supplied (i.e. only a client or only a target.)

***************************************************************/
#ifdef  WIN32
extern "C" __declspec(dllexport) void __cdecl
#else
extern "C" void
#endif
YourInterceptorInit(
    CORBA::ORB_ptr                                       TheORB,
    RequestLevelInterceptor::ClientRequestInterceptor ** ClientPtr,
    RequestLevelInterceptor::TargetRequestInterceptor ** TargetPtr,
    CORBA::Boolean *                                     RetStatus)
{
    // <<<Fill in your code here>>>

}

/*************************************************************

   FUNCTION NAME:       YourInterceptorClient constructor
 
   FUNCTIONAL DESCRIPTION:
 
***************************************************************/
YourInterceptorClient::YourInterceptorClient(CORBA::ORB_ptr TheOrb) 
{
    // This next line is useful, but not absolutely necessary.

    m_orb = TheOrb;

    // <<<Fill in your code here>>> 
}

/*************************************************************

   FUNCTION NAME:       YourInterceptorClient::shutdown
 
   FUNCTIONAL DESCRIPTION:
 
        The shutdown operation is used by the ORB to notify an 
        implementation of an interceptor that the interceptor 
        is being shutdown. The ORB will destroy the instance 
        of the interceptor once control is returned from the
        operation back to the ORB.

***************************************************************/

Interceptors::ShutdownReturnStatus YourInterceptorClient::shutdown(
    Interceptors::ShutdownReason    reason,
    CORBA::Exception_ptr &          excep_val)
{
    // The following lines are a suggestion only. Replace them if you wish.

    Interceptors::ShutdownReturnStatus ret_status = Interceptors::SHUTDOWN_NO_EXCEPTION;
    switch (reason)


 

