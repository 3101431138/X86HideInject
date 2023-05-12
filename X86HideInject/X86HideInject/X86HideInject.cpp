#include "X86HideInject.h"

X86HideInject::X86HideInject()
{
}

X86HideInject::~X86HideInject()
{
}

VOID X86HideInject::SetRunLogHandler(std::function<RunLogHandler> runlogHander)
{
    runlogHander_ = runlogHander;
    runlogValid_  = true;
}

VOID X86HideInject::SetErrorLogHandler(std::function<ErrorLogHandler> errorlogHander)
{
    errorlogHander_ = errorlogHander;
    errorlogValid_  = true;
}
