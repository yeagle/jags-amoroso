#include <config.h>
#include "DAmoroso.h"
#include <rng/RNG.h>
#include <util/nainf.h>

#include <JRmath.h>
#include <cmath>

using std::vector;

#define A(par) (*par[0])
#define THETA(par) (*par[1])
#define ALPHA(par) (*par[2])
#define BETA(par) (*par[3])

namespace jags {
namespace amoroso {

DAmoroso::DAmoroso() : ScalarDist("damoroso", 4, DIST_PROPORTION)
{}

bool DAmoroso::checkParameterValue (vector<double const *> const &parameters) const
{
    return  (true);
}

double DAmoroso::damoroso(double x, vector<double const *> const &parameters) const
{
  double a = A(parameters); 
  double theta = THETA(parameters); 
  double alpha = ALPHA(parameters); 
  double beta = BETA(parameters);

  double d;
  double logd;

  d = 1 / gammafn(alpha) * fabs(beta / theta) * 
      pow(( (x - a) / theta), (alpha * beta - 1)) *
      exp(- pow(((x - a) / theta), beta) );
  logd = log(d);
  
  return d;
}

double DAmoroso::logDensity(double x, PDFType type,
       vector<double const *> const &parameters,
       double const *lbound, double const *ubound) const 
{
    double d = 0;

    d = damoroso(x , parameters);
    
    return d;
}

double DAmoroso::randomSample(vector<double const *> const &parameters, 
         double const *lbound, double const *ubound,
         RNG *rng) const
{
    return fabs( rng->uniform() );
}

double DAmoroso::typicalValue(vector<double const *> const &parameters,
         double const *lbound, double const *ubound) const
{
    return 0.5;
}

bool DAmoroso::isDiscreteValued(vector<bool> const &mask) const
{
    return true;
}

} // namespace amoroso
} // namespace jags
