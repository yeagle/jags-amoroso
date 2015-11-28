#include <module/Module.h> // JAGS module base class
#include <distributions/DAmoroso.h> // Amoroso distribution class

namespace jags { // jags namespace
namespace amoroso { // module namespace

class AMOROSOModule : public Module { // module class
  public:
    AMOROSOModule(); // constructor
    ~AMOROSOModule(); // destructor
};

AMOROSOModule::AMOROSOModule() : Module("amoroso") {
  insert(new DAmoroso); // inherited function to load JAGS objects
}
AMOROSOModule::~AMOROSOModule() {
  std::vector<Distribution*> const &dvec = distributions();
  for (unsigned int i = 0; i < dvec.size(); ++i) {
    delete dvec[i];
  } // deletes instantiated distribution objects
}

} // namespace amoroso
} // namespace jags

jags::amoroso::AMOROSOModule _amoroso_module;
