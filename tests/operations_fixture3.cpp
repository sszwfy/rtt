#define BOOST_FUSION_INVOKE_MAX_ARITY 8
#define BOOST_FUSION_UNFUSED_MAX_ARITY 7

#include "operations_fixture.hpp"
#include <iostream>
#include <TaskContext.hpp>
#include <OperationCaller.hpp>
#include <Operation.hpp>
#include <Service.hpp>

using namespace std;
using namespace boost;
using namespace RTT;
using namespace RTT::detail;

void OperationsFixture::createOperationCallerFactories3(TaskContext* target)
{
    Service::shared_ptr to = target->provides("methods");
    // ClientThread
    to->addOperation("m3", &OperationsFixture::m3, this).doc("M3").arg("a", "ad").arg("a", "ad").arg("a", "ad");

    // OwnThread
    to->addOperation("o3", &OperationsFixture::m3, this, OwnThread).doc("M3").arg("a", "ad").arg("a", "ad").arg("a", "ad");
}