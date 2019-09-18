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

#include "../Joueur.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class JoueurTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(JoueurTest);
    CPPUNIT_TEST(testgetters);
    CPPUNIT_TEST(trouverJoueur);
    CPPUNIT_TEST(trouverJoueur2);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void testgetters(void);
    void trouverJoueur(void);
    void trouverJoueur2(void);
    
private:
    
    Joueur *jr;
};
// ------------------------ IMPLEMENTATION ------------------------

void JoueurTest::testgetters(void)
{
    string nom = jr->getNom();
    string prenom = jr->getPrenom();
    int age = jr->getAge();
    string nomEquipe = jr->getNomEquipe();
    string paysEquipe = jr->getPaysEquipe();
    
    if (nom == "nomTest"
        && prenom == "prenomTest"
        && age == 23
        && nomEquipe == "nomEquipeTest"
        && paysEquipe == "paysEquipeTest") {
        CPPUNIT_ASSERT(true);
    } else {
        CPPUNIT_ASSERT(false);
    }  
}

void JoueurTest::trouverJoueur(void)
{
    Joueur * a = jr->trouverJoueur ("../DB.txt", "test","test");
    if (a == NULL) {
        CPPUNIT_ASSERT(true);
    } else {
        CPPUNIT_ASSERT(false);
    }
}


void JoueurTest::trouverJoueur2(void)
{
    Joueur * a = jr->trouverJoueur ("../DB.txt", "nomTest","prenomTest");
    if (a != NULL) {
        CPPUNIT_ASSERT(true);
    } else {
        CPPUNIT_ASSERT(false);
    }
}

void JoueurTest::setUp(void)
{
    jr = new Joueur("nomTest",
                      "prenomTest",
                      23,
                      "nomEquipeTest",
                      "paysEquipeTest");
}

void JoueurTest::tearDown(void){
    delete jr;
}
