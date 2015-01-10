SUBDIRS = distributions

jagsmod_LTLIBRARIES = amoroso.la

amoroso_la_SOURCES = amoroso.cc

amoroso_la_CPPFLAGS = -I$(includedir)/JAGS

amoroso_la_LIBADD = distributions/amorosodist.la

if WINDOWS
amoroso_la_LIBADD += -ljags-$(JAGS_MAJOR) -ljrmath-0
else
amoroso_la_LIBADD += -ljags -ljrmath
endif

amoroso_la_LDFLAGS = -module -avoid-version
if WINDOWS
amoroso_la_LDFLAGS += -no-undefined
endif
