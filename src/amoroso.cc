#include <Module.h> // JAGS module base class
#include <distributions/DAmoroso.h> // Amoroso distribution class

namespace amoroso { // module namespace

class WALDModule : public Module { // module class
  public:
    WALDModule(); // constructor
    ~WALDModule(); // destructor
};

WALDModule::WALDModule() : Module("amoroso") {
  insert(new DAmoroso); // inherited function to load JAGS objects
}
WALDModule::~WALDModule() {
  std::vector<Distribution*> const &dvec = distributions();
  for (unsigned int i = 0; i < dvec.size(); ++i) {
    delete dvec[i];
  } // deletes instantiated distribution objects
}

}

amoroso::WALDModule _amoroso_module;
