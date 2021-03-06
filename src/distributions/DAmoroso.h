#ifndef DAMOROSO_H_
#define DAMOROSO_H_
#include <distribution/ScalarDist.h> // JAGS scalar distribution base class

namespace jags {
namespace amoroso {

class DAmoroso : public ScalarDist // scalar distribution class
{
  public:
    DAmoroso(); // constructor
    double damoroso(double t, std::vector<double const *> const &parameters) const;
    double logDensity(double x, PDFType type,
                      std::vector<double const *> const &parameters,
                      double const *lower, double const *upper) const;
    double randomSample(std::vector<double const *> const &parameters,
                        double const *lower, double const *upper,
                        RNG *rng) const;
    double typicalValue(std::vector<double const *> const &parameters,
                        double const *lower, double const *upper) const;
    /** Checks that p lies in the open interval (0,1) */
    bool checkParameterValue(std::vector<double const *> const &parameters) const;
    /** Distribution is discrete valued */
    bool isDiscreteValued(std::vector<bool> const &mask) const;
};

} // namespace amoroso
} // namespace jags

#endif /* DAMOROSO_H_ */
