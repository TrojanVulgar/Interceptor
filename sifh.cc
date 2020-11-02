#include <CORBA.h>
#include <RequestLevelInterceptor.h>
#include <security_c.h>      //used with security

class YourInterceptorClient : public virtual RequestLevelInterceptor::ClientRequestInterceptor
{
private:
    YourInterceptorClient() {}
    CORBA::ORB_ptr  m_orb;
public:
    YourInterceptorClient(CORBA::ORB_ptr TheOrb);
    ~YourInterceptorClient() {}
    Interceptors::ShutdownReturnStatus shutdown(
        Interceptors::ShutdownReason reason,
        CORBA::Exception_ptr & excep_val);
    CORBA::String id();
    void exception_occurred (
        const RequestLevelInterceptor::ReplyContext & reply_context,
        CORBA::Exception_ptr excep_val);
    Interceptors::InvokeReturnStatus client_invoke (
        const RequestLevelInterceptor::RequestContext & request_context,
        RequestLevelInterceptor::ServiceContextList_ptr service_context,
        CORBA::DataInputStream_ptr request_arg_stream,
        CORBA::DataOutputStream_ptr reply_arg_stream,
        CORBA::Exception_ptr & excep_val);
    Interceptors::ResponseReturnStatus client_response (
        const RequestLevelInterceptor::ReplyContext & reply_context,
        RequestLevelInterceptor::ServiceContextList_ptr service_context,
        CORBA::DataInputStream_ptr arg_stream,
        CORBA::Exception_ptr & excep_val);
    
};

class YourInterceptorTarget : public virtual RequestLevelInterceptor::TargetRequestInterceptor
{
private:



    YourInterceptorTarget() {}
    CORBA::ORB_ptr  m_orb;
    SecurityLevel1::Current_ptr m_security_current;       //used with security
    Security::AttributeTypeList * m_attributes_to_get;    //used with security
public:
    YourInterceptorTarget(CORBA::ORB_ptr TheOrb);
    ~YourInterceptorTarget();
    Interceptors::ShutdownReturnStatus shutdown(
        Interceptors::ShutdownReason reason,
        CORBA::Exception_ptr & excep_val);
    CORBA::String id();
    void exception_occurred (
        const RequestLevelInterceptor::ReplyContext & reply_context,
        CORBA::Exception_ptr excep_val);
    Interceptors::InvokeReturnStatus target_invoke (
        const RequestLevelInterceptor::RequestContext & request_context,
        RequestLevelInterceptor::ServiceContextList_ptr service_context,
        CORBA::DataInputStream_ptr request_arg_stream,
        CORBA::DataOutputStream_ptr reply_arg_stream,
        CORBA::Exception_ptr & excep_val);
    Interceptors::ResponseReturnStatus target_response (
        const RequestLevelInterceptor::ReplyContext & reply_context,
        RequestLevelInterceptor::ServiceContextList_ptr service_context,
        CORBA::DataInputStream_ptr arg_stream,
        CORBA::Exception_ptr & excep_val);
    
};
