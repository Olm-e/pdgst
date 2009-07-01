/******************************************************
 *
 * pdgst - implementation file
 *
 * copyleft (c) 2009 IOhannes m zm�lnig
 *
 *   forum::f�r::uml�ute
 *
 *   institute of electronic music and acoustics (iem)
 *   university of music and performing arts
 *
 ******************************************************
 *
 * license: GNU General Public License v.2 or later
 *
 ******************************************************/

#warning add docs

#include "pdgst/pdgst.h"

static t_clock*s_clock=NULL;

typedef struct _pdgst_loop
{
  t_clock*x_clock;
  GMainContext*x_gcontext;
} t_pdgst_loop;

static t_pdgst_loop*pdgst_loop=NULL;


static void pdgst_loop_tick(t_pdgst_loop*x)
{
  if(g_main_context_iteration(x->x_gcontext, FALSE)) {
    //    post("gstloop: processed events");
  } else {
    //    post("gstloop: nada");
  }

  clock_delay(x->x_clock, 1);
}


void pdgst_loop_setup(void)
{
  if(NULL==pdgst_loop) {
    pdgst_loop=(t_pdgst_loop*)getbytes(sizeof(t_pdgst_loop));
    pdgst_loop->x_gcontext=g_main_context_default();
    pdgst_loop->x_clock=clock_new(pdgst_loop, (t_method)pdgst_loop_tick);
    clock_delay(pdgst_loop->x_clock, 1);

  } else {
    error("refusing to re-initialize pdgst main loop");
    return;
  }
}
