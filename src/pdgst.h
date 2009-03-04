/* ********************************************** */
/* the Pd GST external                            */
/* ********************************************** */
/*                          forum::fuer::umlaeute */
/* ********************************************** */

/* Pd GST is a gstreamer-binding for Pure data
 *
 * relevant links:
 * Pd: http://puredata.info/
 * gstreamer: http://www.gstreamer.net/
 * IEM: http://iem.at
 */



#ifndef INCLUDE_PDGST_H__
#define INCLUDE_PDGST_H__

#ifdef __WIN32__
# ifndef NT
#  define NT
# endif
# ifndef MSW
#  define MSW
# endif
#endif

#ifdef _MSC_VER
# pragma warning( disable : 4018 )
# pragma warning( disable : 4244 )
# pragma warning( disable : 4305 )
# pragma warning( disable : 4996)  /* deprecated functions */
#endif

/*
 * to use the config.h compile-time configurations, you have to set HAVE_CONFIG_H
 * usually this is done in Make.config by configure
 */
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#include "m_pd.h"
#include <gst/gst.h>

#if PD_MAJOR_VERSION == 0 && PD_MINOR_VERSION > 41
/* fine */
#else
# error need at least Pd 0.41
#endif /* PD_VERSION_CHECK */



typedef struct _pdgst_prop {
  struct _pdgst_prop*next;
  t_symbol*name;
  int flags;
  GType type;
} t_pdgst_property;
t_pdgst_property*pdgst_addproperty(t_pdgst_property*props, GParamSpec*param);
t_pdgst_property*pdgst_getproperty(t_pdgst_property*props, t_symbol*name);
void pdgst_killproperties(t_pdgst_property*props);

t_class*pdgst_findclass(t_symbol*s);
t_class*pdgst_addclass(t_symbol*s);


void pdgst_element_setup(void);
int pdgst_element_setup_class(char*classname);

void pdgst_capsfilter_setup(void);
int pdgst_capsfilter_setup_class(char*classname);


static char *pdgst_version = "$Revision: 0.0 $";


#endif /* INCLUDE_PDGST_H__ */
