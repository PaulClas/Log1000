#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "../Vector.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class insertTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(insertTest);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);
	CPPUNIT_TEST(test3);
	CPPUNIT_TEST(test4);
	CPPUNIT_TEST(test5);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void test1(void);
    void test2(void);
	void test3(void);
	void test4(void);
	void test5(void);
    
private:
    
    Vector *vec;
};

// ------------------------ IMPLEMENTATION ------------------------

void insertTest::test1(void)
{
	//index>count
    CPPUNIT_ASSERT(vec->insert(1)==true);
}

void insertTest::test2(void)
{
	//index < count
    CPPUNIT_ASSERT(vec->insert(1)==false);
}

void insertTest::test3(void)
{
	//index > count
	CPPUNIT_ASSERT(vec->insert(0) == false);
}

void insertTest::test4(void)
{
	//index < count
	//i>index
	CPPUNIT_ASSERT(vec->insert(0) == true);
}

void insertTest::test5(void)
{
	//index < count
	//i<index
	CPPUNIT_ASSERT(vec->insert(0)==true);
}

void insertTest::setUp(void)
{
    vec = new Vector();
}

void insertTest::tearDown(void)
{
    delete vec;
}